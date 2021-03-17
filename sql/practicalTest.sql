--CREATE DATABASE practicalTest
CREATE TABLE S(
ID1 INT NOT NULL,
ID2 INT NOT NULL,
A INT,
B INT,
C INT,
D INT,
E INT,
F INT
PRIMARY KEY(ID1,ID2)
)
INSERT INTO S VALUES
(2,2,2,5,1,2,700,5),
(3,1,3,10,3,2,800,9),
(3,2,3,11,4,2,800,9),
(3,3,10,3,0,2,50,1),
(4,1,3,7,1,2,800,6),
(6,1,10,4,1,1,800,3),
(6,3,3,9,3,2,100,9),
(7,1,10,2,0,1,100,1),
(8,1,2,4,1,2,100,4),
(8,2,3,8,2,1,300,7),
(8,4,3,6,1,2,100,7),
(9,2,2,6,1,2,120,6)

SELECT * FROM S
--1
SELECT COUNT(*) NumRows
FROM S s1 FULL JOIN S s2 ON s1.ID1 = s2.ID1
	AND s1.ID2 = s2.ID2
GROUP BY s1.ID1
HAVING MIN(s2.E)>50
-- Q RETURNS 6 RECORDS AND TUPLES <1> AND <3> ARE IN INTS RESULT SET
--2
SELECT *
FROM S s3
INTERSECT
SELECT *
FROM S s1
WHERE NOT EXISTS
 (SELECT *
 FROM S s2
 WHERE s1.ID1 = s2.ID1 AND s1.ID2 = s2.ID2)
 --0 RECORDS
 --3
 CREATE OR ALTER TRIGGER TrOnInsert
 ON S
 FOR INSERT
 AS
  DECLARE @total INT = 0
  SELECT @total=SUM(F)
  FROM inserted
  WHERE C<5
  PRINT @total

INSERT S(ID1,ID2,C,F) VALUES
(10,1,5,5),
(10,2,4,5),
(10,3,3,5)
--10

--subiectul 2
--a. Write an SQL script that creates the corresponding relational data model. 
CREATE TABLE Hotels(
HID INT,
HName VARCHAR(100),
HStars INT,
PRIMARY KEY(HID)
)--can be associated with multiple packages so 1:n
CREATE TABLE Offices(
OID INT,
OAdress VARCHAR(100),
PRIMARY KEY(OID)
)
CREATE TABLE Customers(
CID INT,
CName VARCHAR(100),
CEmail VARCHAR(100),
PRIMARY KEY(CID)
)
CREATE TABLE TravelPackages(
PID INT,
HID INT,
PStart DATE,
PEnd DATE,
PPrice INT,
PRIMARY KEY(PID),
FOREIGN KEY(HID) REFERENCES Hotels(HID)
)
CREATE TABLE Booking(
CID INT,
OID INT,
PID INT,
BDate DATE,
BPay VARCHAR(20),
FOREIGN KEY(CID) REFERENCES Customers(CID),
FOREIGN KEY(OID) REFERENCES Offices(OID),
FOREIGN KEY(PID) REFERENCES TravelPackages(PID)
)
--b. Implement a stored procedure that receives an office, a customer, 
--a travel package, a date, a payment method, and adds the corresponding booking to the database.
INSERT INTO Hotels VALUES
(1,'Hotel1',5),
(2,'Hotel2',4),
(3,'Hotel3',3)
INSERT INTO OFFICES VALUES
(1,'Location1'),
(2,'Location2'),
(3,'Location3'),
(4,'Location4')
INSERT INTO Customers VALUES
(1,'Ion','Ion@gmail.com'),
(2,'Jon','Jon@gmail.com'),
(3,'Andrei','Andrei@gmail.com'),
(4,'Ioan','Ioan@gmail.com'),
(5,'Ionel','Ionel@gmail.com')
INSERT INTO TravelPackages VALUES
(1,1,'01.01.2021','02.02.2021',1000),
(2,1,'02.02.2021','02.02.2021',1200),
(3,1,'03.03.2021','04.04.2021',1000),
(4,2,'01.01.2022','02.02.2022',2000)

CREATE OR ALTER PROCEDURE uspAddBooking(@CID INT,@OID INT,@PID INT,@DATE DATE,@method VARCHAR(20))
AS
BEGIN
	IF @CID NOT IN(
		SELECT CID 
		FROM Customers)
	BEGIN
		RAISERROR('CUSTOMER NOT FOUND',16,1)
	END
	IF @OID NOT IN(
		SELECT OID
		FROM Offices)
	BEGIN
		RAISERROR('OFFICE NOT FOUND',16,1)
	END
	IF @PID NOT IN(
		SELECT PID
		FROM TravelPackages)
	BEGIN
		RAISERROR('PACKAGE NOT FOUND',16,1)
	END
	INSERT INTO Booking VALUES(@CID,@OID,@PID,@DATE,@method)
END
SELECT * FROM Customers
SELECT * FROM Offices
SELECT * FROM TravelPackages
SELECT * FROM Booking
EXEC uspAddBooking @CID=1,@OID=1,@PID=1,@DATE='12.12.2020',@method='CASH'
EXEC uspAddBooking @CID=1,@OID=1,@PID=2,@DATE='01.01.2021',@method='CASH'
EXEC uspAddBooking @CID=1,@OID=1,@PID=3,@DATE='01.01.2020',@method='CASH'
EXEC uspAddBooking @CID=1,@OID=1,@PID=3,@DATE='01.02.2020',@method='CASH'
EXEC uspAddBooking @CID=1,@OID=1,@PID=3,@DATE='01.03.2020',@method='CASH'
EXEC uspAddBooking @CID=1,@OID=1,@PID=3,@DATE='01.04.2020',@method='CASH'
EXEC uspAddBooking @CID=1,@OID=1,@PID=3,@DATE='02.01.2020',@method='CASH'
EXEC uspAddBooking @CID=1,@OID=1,@PID=3,@DATE='03.01.2020',@method='CASH'
EXEC uspAddBooking @CID=1,@OID=1,@PID=3,@DATE='04.01.2020',@method='CASH'
EXEC uspAddBooking @CID=1,@OID=1,@PID=3,@DATE='04.04.2020',@method='CASH'
EXEC uspAddBooking @CID=1,@OID=1,@PID=3,@DATE='01.05.2020',@method='CASH'
EXEC uspAddBooking @CID=1,@OID=1,@PID=3,@DATE='01.06.2020',@method='CASH'
--c. Create a view that shows the names of the customers with at least 10 bookings made after 01.01.2018 for 1 or 2 star hotels.
SELECT * FROM Hotels
SELECT * FROM Customers
SELECT * FROM Offices
SELECT * FROM TravelPackages
SELECT * FROM Booking
--eu am inserat >10 valori pentru hotel cu 5 stele si am testat pentru hotel cu stele 3 sau 5
CREATE OR ALTER VIEW myView
AS
SELECT CName
FROM Customers
WHERE CID IN(
	SELECT CID
	FROM Booking
	WHERE BDate>'01.01.2018' AND PID IN(
			SELECT PID
			FROM TravelPackages
			WHERE HID IN(
				SELECT HID
				FROM Hotels
				WHERE HStars = 1 or Hstars = 2 --era HStars=3 or Hstars=5 pentru ce am testat eu
				)
			)
	GROUP BY CID
	HAVING COUNT(*)>=10
	)
SELECT* FROM myView

/*d. Implement a function that lists the hotels (name and number of stars) that have at least one travel package with
a price per person greater than 4000 lei and have no packages with a price per person < 2000 lei*/
SELECT * FROM Hotels
SELECT * FROM Customers
SELECT * FROM Offices
SELECT * FROM TravelPackages
SELECT * FROM Booking
CREATE OR ALTER FUNCTION ufFunction()
RETURNS TABLE 
AS
RETURN SELECT HName,HStars
FROM Hotels
WHERE HID IN(
	SELECT HID
	FROM TravelPackages
	WHERE EXISTS(
		SELECT HID
		FROM TravelPackages
		WHERE PPrice>4000) --am testat pentru PPrice>400
	AND NOT EXISTS(
		SELECT HID
		FROM TravelPackages
		WHERE PPrice<2000) --si pentru PPrice<200 aici si am obtinut toate Hotelurile pentru ca ele satisfac conditiile
	)
SELECT * FROM ufFunction()