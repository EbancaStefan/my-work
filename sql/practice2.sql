USE MIPRACTICAL_TEST
GO

DROP TABLE StationsRoutes
DROP TABLE Stations
DROP TABLE Routes
DROP TABLE Trains
DROP TABLE TrainTypes
GO
--subiectul 2
--1
CREATE TABLE TrainTypes
	(TTID INT PRIMARY KEY,
	TTName VARCHAR(50),
	TTDescription VARCHAR(100))

CREATE TABLE Trains
	(TID INT PRIMARY KEY,
	TName VARCHAR(50),
	TTID INT REFERENCES TrainTypes(TTID))

CREATE TABLE Stations
	(SID INT PRIMARY KEY,
	SName VARCHAR(50) UNIQUE)

CREATE TABLE Routes
	(RID INT PRIMARY KEY,
	RName VARCHAR(50) UNIQUE,
	TID INT REFERENCES Trains(TID))

CREATE TABLE StationsRoutes
	(SID INT REFERENCES Stations(SID),
	RID INT REFERENCES Routes(RID),
	Arrival TIME,
	Departure TIME,
	PRIMARY KEY(SID,RID))
GO

--2
--Implement a stored procedure that receives a route, a station, arrival and departure times, and adds the station
--to the route. If the station is already on the route, the departure and arrival times are updated
CREATE OR ALTER PROC uspUpdateRoute (@RName VARCHAR(50), @SName VARCHAR(50), @Arrival TIME, @Departure TIME)
AS
	DECLARE @SID INT, @RID INT

	IF NOT EXISTS(SELECT * FROM Stations WHERE SName = @SName)
	BEGIN
		RAISERROR('Invalid station name.',16,1)
		RETURN
	END
		IF NOT EXISTS(SELECT * FROM Routes WHERE RName = @RName)
	BEGIN
		RAISERROR('Invalid route name.',16,1)
		RETURN
	END

	SELECT @SID = (SELECT SID FROM Stations WHERE SName = @SName),
		@RID = (SELECT RID FROM Routes WHERE RName = @RName)

	IF EXISTS (SELECT *
				FROM StationsRoutes
				WHERE SID = @SID AND RID = @RID)
			UPDATE StationsRoutes
			SET Arrival = @Arrival, Departure = @Departure
			WHERE SID = @SID AND RID = @RID
	ELSE
		INSERT StationsRoutes(SID,RID,Arrival,Departure)
		VALUES(@SID, @RID, @Arrival, @Departure)
GO

--testare 2
SELECT * FROM TrainTypes
SELECT * FROM Trains
SELECT * FROM Routes
SELECT * FROM Stations
SELECT * FROM StationsRoutes
ORDER BY RID

INSERT TrainTypes VALUES(1,'type1','descr'),(2,'type2','descr')
INSERT Trains VALUES(1,'t1',1),(2,'t2',1),(3,'t3',1)
INSERT Routes VALUES(1,'r1',1),(2,'r2',2),(3,'r3',3)
INSERT Stations VALUES(1,'s1'),(2,'s2'),(3,'s3')

EXEC uspUpdateRoute @RName = 'r1', @SName = 's8', @Arrival = '6:10', @Departure = '6:20'

EXEC uspUpdateRoute @RName = 'r1', @SName = 's1', @Arrival = '7:30', @Departure = '7:40'
EXEC uspUpdateRoute @RName = 'r1', @SName = 's2', @Arrival = '8:00', @Departure = '8:10'
EXEC uspUpdateRoute @RName = 'r1', @SName = 's3', @Arrival = '8:30', @Departure = '8:40'

EXEC uspUpdateRoute @RName = 'r2', @SName = 's1', @Arrival = '7:30', @Departure = '7:40'
EXEC uspUpdateRoute @RName = 'r2', @SName = 's2', @Arrival = '8:00', @Departure = '8:10'
EXEC uspUpdateRoute @RName = 'r2', @SName = 's3', @Arrival = '8:30', @Departure = '8:40'

EXEC uspUpdateRoute @RName = 'r3', @SName = 's1', @Arrival = '7:30', @Departure = '7:40'
GO
--3
--r1 si r2 trec prin toate statiile
SELECT * FROM Stations
SELECT * FROM Routes
SELECT * FROM StationsRoutes
SELECT SID
FROM Stations
EXCEPT
SELECT SID
FROM StationsRoutes
WHERE RID = 3

--aici e rezolvarea
CREATE OR ALTER VIEW vRoutesWithAllStations
AS
	SELECT r.Rname
	FROM Routes r
	WHERE NOT EXISTS
		(SELECT SID
		FROM Stations
		EXCEPT
		SELECT SID
		FROM StationsRoutes
		WHERE RID = r.RID)
GO

SELECT *
FROM vRoutesWithAllStations
GO

--4
SELECT *
FROM StationsRoutes

CREATE OR ALTER FUNCTION ufFilterStationsByNumberOfRoutes(@R INT)
RETURNS TABLE
RETURN SELECT S.SName
	FROM Stations S
	WHERE S.SID IN
		(SELECT SR.SID
		FROM StationsRoutes SR
		GROUP BY SR.SID
		HAVING COUNT(*) > @R)
GO

SELECT *
FROM ufFilterStationsByNumberOfRoutes(2)

--3. Create a view that shows the names of the routes that pass through all the stations
SELECT * FROM Stations
SELECT * FROM Routes
SELECT * FROM StationsRoutes

CREATE OR ALTER VIEW v2
AS
SELECT r.RName
FROM Routes r
WHERE r.RID IN(
	SELECT r.RID
	FROM StationsRoutes r
	GROUP BY r.RID
	HAVING COUNT(*)=(
		Select COUNT(*)
		FROM Stations r
		)
	)
SELECT * FROM v2
SELECT SID FROM Stations
EXCEPT
SELECT SID FROM StationsRoutes
WHERE RID=3

--4. Implement a function that lists the names of the stations with more than R routes, where R is a function
--parameter.
SELECT * FROM Stations
SELECT * FROM Routes
SELECT * FROM StationsRoutes
CREATE OR ALTER FUNCTION ufFunction(@R INT)
RETURNS TABLE
AS
RETURN Select s.SName
From Stations s
WHERE s.SID in
	(
	SELECT s.SID
	FROM StationsRoutes s
	GROUP BY s.SID
	HAVING COUNT(*)>@R)
GO

SELECT * FROM ufFunction(2)
	
--3. Create a view that shows the names of the routes that pass through all the stations
SELECT * FROM Stations
SELECT * FROM Routes
SELECT * FROM StationsRoutes
SELECT r.RName
FROM Routes r
WHERE r.RID in
	(SELECT sr.RID
	FROM StationsRoutes sr
	GROUP BY sr.RID
	HAVING COUNT(*)=
		(SELECT COUNT(*)
		FROM Stations s
		)
	)
