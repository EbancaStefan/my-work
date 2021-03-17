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
(2,'Punctu-acela de miscare, mult mai slab ca boaba spumii,',100,1,3,3,'M1',22),(3,'E stapanul fara margini peste marginile lumii...',200,1,3,3,'M1',22),
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
FROM R r2--3CREATE TABLE InsertLog(A5Value VARCHAR(10),NumRows INT,DateTimeOp DATETIME)CREATE OR ALTER FUNCTION ufF1(@A5 CHAR(2))
RETURNS INT
BEGIN
RETURN
 (SELECT COUNT(*)
 FROM R
 WHERE A5 = @A5)
ENDCREATE OR ALTER TRIGGER TrOnInsert
 ON R
 FOR INSERT
AS
 INSERT InsertLog(A5Value, NumRows, DateTimeOp)
 SELECT i.A5, dbo.ufF1(i.A5), GETDATE()
 FROM inserted i INSERT R(RID, K2, A5) VALUES
 (14, 14, 'M1'),(15, 15, 'M1'),(16, 16, 'M2')
INSERT R(RID, K2, A5) VALUES
 (17, 17, 'M1'), (18, 18, 'M3') SELECT * FROM R SELECT COUNT(*)
 FROM R
 WHERE A5 = 'M1' SELECT * FROM InsertLog --SUBIECTUL 2 CREATE TABLE DroneManufacturers( DMID INT, DMName VARCHAR(70), PRIMARY KEY(DMID) ) CREATE TABLE DroneModels( MID INT, DMID INT, MName VARCHAR(70), MBatteryLife INT, MSpeed INT, PRIMARY KEY(MID), FOREIGN KEY(DMID) REFERENCES DroneManufacturers(DMID) ) CREATE TABLE Drones( DID INT, MID INT, PRIMARY KEY(DID), FOREIGN KEY(MID) REFERENCES DroneManufacturers(MID) ) CREATE TABLE PizzaShops( PizzaName VARCHAR(100) UNIQUE, PizzaAdress VARCHAR(100), PRIMARY KEY(PizzaName) ) CREATE TABLE Customers( CName VARCHAR(100) UNIQUE, CScore INT, PRIMARY KEY(CName) ) CREATE TABLE Deliveries( CName VARCHAR(100), PizzaName VARCHAR(100), DID INT, DateTimeOP DATETIME, FOREIGN KEY(CName) REFERENCES Customers(CName), FOREIGN KEY(PizzaName) REFERENCES PizzaShops(PizzaName), FOREIGN KEY(DID) REFERENCES Drones(DID) ) --1 practic gata --2 . Implement a stored procedure that receives a customer, a pizza shop, a drone, a date and time and adds the
--corresponding delivery to the database.CREATE OR ALTER PROCEDURE uspAddDeliveries(@CUSTOMER VARCHAR(100),@PIZZASHOP VARCHAR(100),@DID INT,@DATETIME DATETIME)ASBEGININSERT INTO Deliveries VALUES(@CUSTOMER,@PIZZASHOP,@DID,@DATETIME)ENDSELECT * FROM DeliveriesSELECT * FROM CustomersSELECT * FROM PizzaShopsINSERT INTO Customers VALUES('Ian',3),('Azteca',3)INSERT INTO PizzaShops VALUES ('prauau','Pra Street'),('skrr','Skrr Street')INSERT INTO DroneManufacturers VALUES(2,'alta')--(1,'20cm')INSERT INTO DroneModels VALUES (3,2,'dronastraina',10,10)--(2,1,'drona2',30000,30)--(1,1,'drona bomba',30000,30)INSERT INTO Drones VALUES (4,3)--(3,2)--(2,1)--(1,1)SELECT * FROM PizzaShops where PizzaName='skrr'EXEC uspAddDeliveries @CUSTOMER='Ian', @PIZZASHOP = 'skrr',@DID = 1,@DATETIME = '01.01.2021 7:20'EXEC uspAddDeliveries @CUSTOMER='Azteca', @PIZZASHOP = 'skrr',@DID = 1,@DATETIME = '01.01.2021 7:50'EXEC uspAddDeliveries @CUSTOMER='Ian', @PIZZASHOP = 'prauau',@DID = 1,@DATETIME = '01.01.2021 8:50'--3 Create a view that shows the names of the startup’s favorite drone manufacturers, i.e., those with the largest
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
/*c. Create a view that shows the names of the startup’s favorite drone manufacturers, i.e., those with the largest
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
/*c. Create a view that shows the names of the startup’s favorite drone manufacturers, i.e., those with the largest
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
 FROM Students S2) --sau SELECT S.sname,S.age FROM Students S WHERE S.age =	(Select MAX(AGE)	FROM Students)
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
--• For each student name that appears at least 3 times, retrieve all students
--with that name.SELECT *FROM Students WHERE last_name in	(SELECT last_name	FROM Students	GROUP BY last_name	HAVING COUNT(*)>=3)GO--do it without in --ezzzzSELECT * FROM Students sWHERE s.last_name in(	SELECT s.last_name	FROM Students s	INNER JOIN Students s1	ON s.last_name = s1.last_name	GROUP BY s.last_name	HAVING COUNT(*)>=3	)--testare inserare sub1CREATE TABLE T(RID INT,A1 VARCHAR(100),K2 INT,A2 INT,A3 INT,A4 INT,A5 VARCHAR(10),A6 INT,PRIMARY KEY(RID))INSERT INTO T VALUES(2,'Punctu-acela de miscare,mult mai slab ca boaba spumii',100,1,3,3,'M1',22),(3,'E stapanul fara margini peste marginile lumii...',200,1,3,3,'M1',22),(4,'De-atunci negare eterna se desface in fasii,',150,2,3,4,'M1',23),(5,'De atunci rasare lumea, luna,soare si stihii...',700,2,4,4,'M2',29),(6,'De atunci si pana astazi colonii de lumi pierdute',300,3,4,5,'M2',29),(7,'Vin de sure vai de chaos de carari necunoscute',350,3,4,5,'M5',23),(8,'Si in roiuri luminoase izvorand din infinit,',400,3,5,7,'M5',29),(9,'Sunt atrase in viata de un dor nemarginit.',500,4,5,7,'M2',30),(10,'Iar in lumea asta mare, noi copii ai lumii mici,',450,4,5,7,'M7',30),(11,'Facem pe pamantul nostru musunoaie de furnici;',250,4,6,7,'M7',30),(12,'Microscopice popoare, regi, osteni si invatati',800,5,6,7,'M6',22),(13,'Ne succedem  generatii si ne credem minunati;',750,5,6,7,'M6',23)SELECT * FROM T--1SELECT r1.RID,r1.K2, COUNT(*) NumRowsFROM T r1 INNER JOIN T r2 ON r1.A2 = r2.A3INNER JOIN T r3 on r2.A3 =r3.A4WHERE r1.A1 like '_%'GROUP BY r1.RID,r1.K2HAVING COUNT(*)>=6--2SELECT r1.A6,MAX(r1.A2) MaxA2FROM T r1WHERE r1.A5 in ('M1','M2')GROUP BY r1.A6EXCEPTSELECT DISTINCT r2.A6,r2.A2FROM T r2--3CREATE OR ALTER FUNCTION ufF1(@A5 CHAR(2))RETURNS INTBEGINRETURN 	(SELECT COUNT(*)	FROM R	WHERE A5=@A5)ENDCREATE TABLE InsertLog(A5Value VARCHAR(10),NumRows INT,DateTimeOP DATETIME,)CREATE OR ALTER TRIGGER TrOnInsert1ON TFOR INSERTAS INSERT InsertLog(A5Value,NumRows,DateTimeOp) SELECT i.A5,dbo.ufF1(i.A5),GETDATE() FROM inserted i INSERT T(RID,K2,A5) VALUES	(14,14,'M1'),(15,15,'M1'),(16,16,'M2')INSERT T(RID,K2,A5) VALUES	(17,17,'M1'),(18,18,'M3')SELECT * FROM InsertLog--sub2CREATE TABLE DroneManufacturer(DMID INT,DMName Varchar(100),PRIMARY KEY(DMID))CREATE TABLE DroneModel(MID INT,DMID INT,MName VARCHAR(100),MBattery INT,MSpeed INT,PRIMARY KEY(MID),FOREIGN KEY(DMID) REFERENCES DroneManufacturer(DMID))CREATE TABLE Drone(DID INT,MID INT,DNumber INT,PRIMARY KEY(DID),FOREIGN KEY(MID) REFERENCES DroneModel(MID))CREATE TABLE PizzaShop(PID INT,PName VARCHAR(100) UNIQUE,PAdress Varchar(100),PRIMARY KEY(PID))CREATE TABLE Customer(CID INT,CNmae VARCHAR(100) UNIQUE,CLoyalty INT,PRIMARY KEY(CID))CREATE TABLE Deliveries(CID INT,PID INT,DID INT,DATETIMEOP DATETIME,FOREIGN KEY(CID) REFERENCES Customer(CID),FOREIGN KEY(PID) REFERENCES PizzaShop(PID),FOREIGN KEY(DID) REFERENCES Drone(DID))INSERT INTO PizzaShop VALUES (1,'shop1','st1'),(2,'shop2','st2')INSERT INTO Customer VALUES (1,'Nume1',10),(2,'Nume2',20),(3,'Nume3',30)INSERT INTO DroneManufacturer VALUES (1,'m1'),(2,'m2')INSERT INTO DroneModel VALUES (1,1,'model1',1000,10),(2,1,'model2',1000,20),(3,1,'model3',2000,10),(4,2,'modelpt2',3000,5)INSERT INTO Drone VALUES (1,1,243),(2,1,222),(3,2,111),(4,4,444)--b. Implement a stored procedure that receives a customer, a pizza shop, a drone, a date and time and adds the
--corresponding delivery to the database.CREATE OR ALTER PROCEDURE proc1(@CID INT,@PID INT,@DID INT,@DATETIME DATETIME)ASBEGIN	IF @CID NOT IN(		SELECT CID		FROM Customer)	BEGIN	RAISERROR('CUSTOMER NOT FOUND',16,1)	END	IF @PID NOT IN(		SELECT PID		FROM PizzaShop)	BEGIN	RAISERROR('PizzaShop NOT FOUND',16,1)	END	IF @DID NOT IN(		SELECT DID		FROM Drone)	BEGIN	RAISERROR('DRONE NOT FOUND',16,1)	END	INSERT INTO Deliveries VALUES (@CID,@PID,@DID,@DATETIME)ENDEXEC proc1 @CID=1, @PID=1, @DID=1, @DATETIME='01.01.2021 7:20'EXEC proc1 @CID=2, @PID=1, @DID=1, @DATETIME='01.01.2021 7:30'EXEC proc1 @CID=3, @PID=1, @DID=2, @DATETIME='01.01.2021 7:20'SELECT * FROM Deliveries--c. Create a view that shows the names of the startup’s favorite drone manufacturers, i.e., those with the largest
--number of drones used by the startup.
--Example: suppose the startup has partnerships with 3 manufacturers: M1, M2, M3; it has 10 drones from M1, 10
--drones from M2, and 8 drones from M3. M1 and M2 are the manufacturers with the largest number of dronesSELECT * FROM DroneManufacturerSELECT * FROM DroneModelSELECT * FROM DroneCREATE OR ALTER VIEW v9ASSELECT DMNameFROM DroneManufacturerWHERE DMID IN	(SELECT dmn.DMID	FROM DroneManufacturer dmn	WHERE dmn.DMID IN(		SELECT dm.DMID		FROM Drone d,DroneModel dm		WHERE d.MID=dm.MID		GROUP BY dm.DMID		HAVING COUNT(*) = 		(SELECT MAX(S.e)		FROM			(SELECT COUNT(*) as e			FROM  Drone d,DroneModel dm,DroneManufacturer dmn			WHERE d.MID= dm.MID AND dmn.DMID = dm.DMID			GROUP BY dmn.DMID 			)as S		)	)	)SELECT * FROM v9--d. Implement a function that lists the names of the customers who received at least D deliveries, where D is a
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
