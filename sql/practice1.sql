CREATE TABLE T(
 ID1 INT,
 ID2 INT,
 ID3 INT,
 C1 VARCHAR(100),
 C2 INT,
 C3 INT,
 C4 INT,
 PRIMARY KEY(ID1,ID2,ID3)
)
select* from T
INSERT INTO T VALUES
(1,1,1,'Pe copite iau in fuga fata negrului pamant',-2,null,0);
INSERT INTO T VALUES
(1,1,2,'Lanci scinteie lungi in soare,arcuri se intind in vint,',-1,2,1),
(1,2,1,'Si ca nouri de arama si ca ropotul de grindeni,',0,null,0),
(1,2,2,'Orizontu-ntunecindu-l, vin sageti de pretutindeni,',1,null,-1),
(2,1,1,'Vijiind ca vijelia si ca plesnetul de ploaie...',2,4,-1),
(2,1,2,'Urla cimpul si de tropot si de strigat de bataie.',3,4,-1)

--2. C
SELECT AVG(C3)
FROM T
WHERE C2>1
GROUP BY ID1,ID2,ID3
HAVING SUM(C2) <=1

--3.
--a returns 4 true or false
 SELECT * FROM T WHERE C3>5 --FALSE

--b returns 0 true or false
 SELECT * FROM T WHERE C1 LIKE '%_' --FALSE

--c returns 1 true or false
SELECT * FROM T WHERE ID1 = ID2
INTERSECT
SELECT * FROM T WHERE ID2 = ID3 --TRUE

--d returns 0 true or false
 SELECT * FROM T t1
WHERE t1.C4 > (SELECT MAX(t2.C4)
 FROM T t2) --TRUE

 --CEVA TESTE
 CREATE TABLE TEST1(
	TID INT,
	PRIMARY KEY(TID)
 )

 CREATE TABLE ZUP(
	ZID INT,
	TID INT,
	PRIMARY KEY(ZID),
	FOREIGN KEY(TID) REFERENCES TEST1(TID) ON DELETE CASCADE
 )
 SELECT* FROM TEST1
 SELECT* FROM ZUP

 INSERT INTO TEST1
 VALUES (1),(2),(3),(80)

 INSERT INTO ZUP(ZID,TID)
 VALUES(2,1)

 DELETE FROM TEST1 WHERE TID=1
 SELECT * 
 FROM TEST1 t1
 WHERE NOT EXISTS
 (SELECT TID
 FROM ZUP z
 WHERE t1.TID=z.TID)

 CREATE OR ALTER PROCEDURE uspTest(@TID INT, @no INT OUTPUT)
 AS
BEGIN
	SELECT @no =COUNT(*)
	FROM TEST1
	WHERE TID>@TID

	IF @no = 0
		RAISERROR ('THERE ARE NO IDS GREATER THAN THE ONE INSERTED',16,1)
	PRINT(@no)

END

DECLARE @number int = 0
EXEC uspTest 89,@no=@number OUTPUT


--testul 2
CREATE TABLE R(
RID INT,
A1 VARCHAR(300),
K2 INT,
A2 INT,
A3 INT,
A4 INT,
A5 VARCHAR(10),
A6 INT,
PRIMARY KEY(RID)
)
INSERT INTO R VALUES
(2,'Punctu-acela de miscare, mult mai slab ca boaba spumii,',100,1,3,3,'M1',22),
(4, 'De-atunci negura eterna se desface in fasii,', 150, 2 ,3,4,'M1' ,23),
(5, 'De atunci rasare lumea, luna, soare si stihii...' ,700, 2, 4, 4, 'M2',29),
(6, 'De atunci si pana astazi colonii de lumi pierdute' ,300 ,3 ,4 ,5 ,'M2' ,29),
(7, 'Vin din sure vai de chaos pe carari necunoscute', 350, 3, 4, 5, 'M5', 23),
(8,'Si in roiuri luminoase izvorand din infinit,', 400, 3, 5, 7, 'M5', 29),
(9, 'Sunt atrase in viata de un dor nemarginit.', 500, 4, 5, 7, 'M2' ,30),
(10, 'Iar in lumea asta mare, noi copii ai lumii mici,' ,450, 4, 5, 7, 'M7', 30),
(11, 'Facem pe pamantul nostru musunoaie de furnici;', 250 ,4, 6, 7, 'M7', 30),
(12, 'Microscopice popoare, regi, osteni si invatati', 800, 5, 6, 7, 'M6' ,22),
(13, 'Ne succedem generatii si ne credem minunati;', 750, 5, 6, 7, 'M6', 23)
SELECT * FROM R
SELECT *
FROM R r1 INNER JOIN R r2 on r1.A2=r2.A3
INNER JOIN R r3 ON r2.A3 = r3.A4
WHERE r1.A1 LIKE '_%'

SELECT * FROM R WHERE A1 LIKE '_%'

SELECT r1.RID, r1.K2, COUNT(*) NumRows
FROM R r1 INNER JOIN R r2 ON r1.A2 = r2.A3
 INNER JOIN R r3 ON r2.A3 = r3.A4
WHERE r1.A1 LIKE '_%'
GROUP BY r1.RID, r1.K2
HAVING COUNT(*) >= 6

--2
SELECT r1.A6, MAX(r1.A2) MaxA2
FROM R r1
WHERE r1.A5 IN ('M1', 'M2')
GROUP BY r1.A6
SELECT DISTINCT r2.A6, r2.A2
FROM R r2

SELECT r1.A6, MAX(r1.A2) MaxA2
FROM R r1
WHERE r1.A5 IN ('M1', 'M2')
GROUP BY r1.A6
EXCEPT
SELECT DISTINCT r2.A6, r2.A2
FROM R r2
RETURNS INT
BEGIN
RETURN
 (SELECT COUNT(*)
 FROM R
 WHERE A5 = @A5)
END
 ON R
 FOR INSERT
AS
 INSERT InsertLog(A5Value, NumRows, DateTimeOp)
 SELECT i.A5, dbo.ufF1(i.A5), GETDATE()
 FROM inserted i
 (14, 14, 'M1'),(15, 15, 'M1'),(16, 16, 'M2')
INSERT R(RID, K2, A5) VALUES
 (17, 17, 'M1'), (18, 18, 'M3')
 FROM R
 WHERE A5 = 'M1'
--corresponding delivery to the database.
--number of drones used by the startup.
--Example: suppose the startup has partnerships with 3 manufacturers: M1, M2, M3; it has 10 drones from M1, 10
--drones from M2, and 8 drones from M3. M1 and M2 are the manufacturers with the largest number of drones. 

SELECT * FROM Drones
SELECT * FROM DroneModels
SELECT * FROM DroneManufacturers

SELECT * FROM view2
CREATE OR ALTER VIEW view2
AS	
SELECT DMName 
FROM DroneManufacturers 
WHERE DMID IN(
SELECT dmn.DMID
FROM DRoneManufacturers dmn
INNER JOIN DroneModels dm
ON dmn.DMID=dm.DMID
INNER JOIN Drones d
ON d.MID=dm.MID
GROUP BY dmn.DMID
HAVING COUNT(*)=
	(SELECT MAX(S.e)
	FROM
	(SELECT dmn.DMID,COUNT(*) as e
	FROM DroneManufacturers dmn
	INNER JOIN DroneModels dm
	on dmn.DMID=dm.DMID
	INNER JOIN Drones d
	on dm.MID=d.MID
	GROUP BY dmn.DMID)as S))

--d. Implement a function that lists the names of the customers who received at least D deliveries, where D is a
--function parameter.
SELECT * FROM Deliveries
CREATE OR ALTER FUNCTION ufDeliveries(@D INT)
RETURNS TABLE
AS
RETURN
 SELECT D.CName
 FROM Deliveries D
 GROUP BY D.CName
 HAVING COUNT(*) > @D

 SELECT* FROM ufDeliveries(1)


 SELECT * FROM Deliveries

 CREATE OR ALTER FUNCTION ufFunction2 (@D INT)
 RETURNS TABLE
 AS
 DECLARE @D INT
 SET @D = 1
 SELECT d.CNAME
 FROM Deliveries d,Deliveries d1
 WHERE d.CName = d1.CName
 GROUP BY d.CName
 HAVING @D<COUNT(*)

 --redo
SELECT * FROM Drones
SELECT * FROM DroneModels
SELECT * FROM DroneManufacturers
/*c. Create a view that shows the names of the startup�s favorite drone manufacturers, i.e., those with the largest
number of drones used by the startup.
Example: suppose the startup has partnerships with 3 manufacturers: M1, M2, M3; it has 10 drones from M1, 10
drones from M2, and 8 drones from M3. M1 and M2 are the manufacturers with the largest number of drones.*/

CREATE OR ALTER VIEW viewRedo
AS
Select dmn.DMName
FROM DroneManufacturers dmn
WHERE dmn.DMID in(
	SELECT dm.DMID
	FROM DroneModels dm,Drones d
	WHERE dm.MID = d.MID
	GROUP BY dm.DMID
	HAVING COUNT(*)=
		(SELECT MAX(S.e)
		FROM
			(SELECT COUNT(*) as e
			FROM Drones d,DroneModels dm,DroneManufacturers dmn
			WHERE d.MID=dm.MID AND dm.DMID=dmn.DMID
			GROUP BY dmn.DMID)as S
		)
	)

--d. Implement a function that lists the names of the customers who received at least D deliveries, where D is a
--function parameter.
SELECT * FROM Deliveries
CREATE OR ALTER FUNCTION ufFunctionRedo(@D INT)
RETURNS TABLE
AS
RETURN SELECT DISTINCT d.CName
FROM Deliveries d
WHERE d.CName in (
	SELECT d.CName
	FROM Deliveries d
	GROUP BY d.CName
	HAVING COUNT(*)>@D
	)
GO
SELECT * FROM ufFunctionRedo(2)

SELECT * FROM Drones
SELECT * FROM DroneModels
SELECT * FROM DroneManufacturers
/*c. Create a view that shows the names of the startup�s favorite drone manufacturers, i.e., those with the largest
number of drones used by the startup.
Example: suppose the startup has partnerships with 3 manufacturers: M1, M2, M3; it has 10 drones from M1, 10
drones from M2, and 8 drones from M3. M1 and M2 are the manufacturers with the largest number of drones.*/

CREATE OR ALTER VIEW viewRedo2
AS
SELECT dbm.DMName
FROM DroneManufacturers dbm
WHERE dbm.DMID in(
	SELECT dbm.DMID
	FROM DroneManufacturers dbm
	INNER JOIN DroneModels dm on dbm.DMID=dm.DMID
	INNER JOIN Drones d on dm.MID = d.MID
	GROUP BY dbm.DMID
	HAVING COUNT(*)=
		(Select Max(s.e)
		FROM(
			SELECT COUNT(*) as e
			FROM DroneManufacturers dbm
			INNER JOIN DroneModels dm on dbm.DMID=dm.DMID
			INNER JOIN Drones d on dm.MID = d.MID
			GROUP BY dbm.DMID
			)as s
		)
	)

--ceva cu studenti
CREATE TABLE Students(
sid INT,
sname VARCHAR(100),
email VARCHAR(100),
age INT,
sgroup INT,
PRIMARY KEY(sid)
)

INSERT INTO Students VALUES
(1,'s1','e1',20,811),
(2,'s2','e2',22,821),
(3,'s3','e3',22,821),
(4,'s4','e4',23,811)

--Q16. Find the name and age of the oldest student.
SELECT S.sname, S.age
FROM Students S
WHERE S.age = ANY
(SELECT MAX(S2.age)
 FROM Students S2)
CREATE TABLE Programs
(id SMALLINT PRIMARY KEY,
name VARCHAR(70))

CREATE TABLE Students
(program SMALLINT REFERENCES Programs(id),
reg_number CHAR(10),
last_name CHAR(30),
first_name CHAR(30),
cnp CHAR(13) UNIQUE,
PRIMARY KEY(program, reg_number))

CREATE TABLE Groups
(acad_year SMALLINT,
program SMALLINT REFERENCES Programs(id),
year_of_study SMALLINT,
id CHAR(10),
PRIMARY KEY (acad_year, program, id))

CREATE TABLE Courses
(id CHAR(10) PRIMARY KEY,
name VARCHAR(70))

CREATE TABLE Trajectory
(id INT PRIMARY KEY IDENTITY(1,1),
acad_year SMALLINT,
program SMALLINT,
reg_number CHAR(10),
sgroup CHAR(10),
FOREIGN KEY(program, reg_number) REFERENCES
Students(program, reg_number),
FOREIGN KEY(acad_year, program, sgroup)
REFERENCES Groups(acad_year, program, id))

CREATE TABLE Results
(id INT PRIMARY KEY IDENTITY(1,1),
program SMALLINT,
reg_number CHAR(10),
acad_year SMALLINT,
semester SMALLINT,
course CHAR(10) REFERENCES Courses(id),
no_credits DECIMAL(3,1),
grade SMALLINT,
FOREIGN KEY(program, reg_number) REFERENCES
Students(program, reg_number))

INSERT INTO Programs Values(2,'dota3'),(3,'dota4')
INSERT INTO Students VALUES
(1,'2','bradson','brad','1111111111112'),
(1,'3','topson','top','1111111111113'),
(2,'3','topson','top','1111111111114'),
(3,'3','topson','top','1111111111115')

SELECT * FROM Students
SELECT * FROM Programs
--� For each student name that appears at least 3 times, retrieve all students
--with that name.
--corresponding delivery to the database.
--number of drones used by the startup.
--Example: suppose the startup has partnerships with 3 manufacturers: M1, M2, M3; it has 10 drones from M1, 10
--drones from M2, and 8 drones from M3. M1 and M2 are the manufacturers with the largest number of drones
--function parameter.
SELECT * FROM Deliveries
SELECT * FROM Customer
CREATE OR ALTER FUNCTION ufFunction213(@D INT)
RETURNS TABLE
AS
RETURN
 SELECT CNmae
 FROM Customer
 WHERE CID in
	(
		SELECT CID 
		FROM Deliveries
		GROUP BY CID
		HAVING COUNT(*)>=@D
	)
SELECT * FROM ufFunction213(2)

--1 to 1
CREATE TABLE one2(
OID2 INT,
PRIMARY KEY(OID2)
)

CREATE TABLE one1(
OID INT,
OID2 INT UNIQUE,
PRIMARY KEY(OID),
FOREIGN KEY (OID2) REFERENCES one2(OID2) 
)