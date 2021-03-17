--date pentru lab4

CREATE TABLE channel
(
channelID INT IDENTITY(1,1) PRIMARY KEY ,
channel_name VARCHAR(100),
channel_revenue INT,
channel_country VARCHAR(100),
);
CREATE TABLE sponsor
(
sponsorID INT IDENTITY(1,1) PRIMARY KEY,
sponsor_name VARCHAR(30),
);

CREATE TABLE cooking_show
(
sponsorID INT,
FOREIGN KEY(sponsorID) REFERENCES sponsor(sponsorID) ON DELETE CASCADE,
channelID INT,
FOREIGN KEY(channelID) REFERENCES channel(channelID) ON DELETE CASCADE,
showID INT IDENTITY(1,1) PRIMARY KEY,
show_name VARCHAR(100)
);

CREATE TABLE participant
(
PID INT IDENTITY(1,1) PRIMARY KEY,
showID INT,
FOREIGN KEY (showID) REFERENCES cooking_show(showID) ON DELETE CASCADE,
participant_name VARCHAR(100),
participant_age INT,
participant_city VARCHAR(100)
);

CREATE TABLE LogTable
(
	OpType VARCHAR(100),
	OpDate DATETIME,
	TableName VARCHAR(100),
	numberOfRows INT
);
--inserturi
insert into sponsor
 values
 ('RedBull'),
 ('BudWeiser')

 insert into channel 
 values
 ('PRO TV',100000,'ROMANIA'),
 ('FOX',300000,'USA'),
 ('NETWORK 10',250000,'AUSTRALIA')

 insert into cooking_show (sponsorID,channelID,show_name)
 values
 (1,1,'Masterchef RO'),
 (2,2,'Hells Kitchen'),
 (1,3,'Masterchef AU')

 insert into participant (showID,participant_name,participant_age,participant_city)
 values
 (1,'Ion',29,'Satu de Sus'),
 (1,'Ion al doilea',30,'Satu de Jos'),
 (1,'Ion al treilea',31,'Satu de Jos'),
 (2,'John',28,'City'),
 (2,'John the second',29,'City two'),
 (3,'Australian John',45,'Australian City'),
 (3,'Australian John the second',45,'Australian City two')

--1
--verifica daca un string e format doar din numere
Go
CREATE OR ALTER FUNCTION checkNumber(@string VARCHAR(100))
RETURNS INT
BEGIN
	DECLARE @ok INT
	SET @ok=0
	IF @string not like '%[^0-9]%'
	BEGIN
		SET @ok=1
	END
	ELSE
	BEGIN
		SET @ok=0
	END
	RETURN (@ok)
END
GO
SELECT * FROM participant
where participant_name  not like '%[^a-z -]%'
GO
CREATE OR ALTER FUNCTION checkLitere(@string VARCHAR(100))
RETURNS INT
BEGIN
	DECLARE @ok INT
	SET @ok=0
	IF @string not like '%[^a-z -]%'
	BEGIN
		SET @ok=1
	END
	ELSE
	BEGIN
		SET @ok=0
	END
	RETURN (@ok)
END
GO
PRINT dbo.checkLitere('a-1amnele dasda')

GO
--verifica daca exista un show cu id-ul introdus
CREATE OR ALTER FUNCTION checkShowId(@id INT)
RETURNS INT AS
BEGIN
	DECLARE @no INT
	SET @no = 0
	SELECT @no = Count(*)
	FROM cooking_show
	WHERE showID=@id
	RETURN @no
END
GO
PRINT dbo.checkShowId (1)

GO
CREATE OR ALTER PROCEDURE uspInsertParticipant (@showID INT,@name VARCHAR(100),@age INT,@city VARCHAR(100))
AS
BEGIN 
	DECLARE @ok INT
	DECLARE @ok1 INT
	DECLARE @ok2 INT
	SET @ok= dbo.checkNumber(@name)
	SET @ok1= dbo.checkShowId(@showID)
	SET @ok2= dbo.checkLitere(@name)
	IF @ok=0 AND @ok1>0 AND @ok2=1
	BEGIN
	INSERT INTO Participant(showID,participant_name,participant_age,participant_city) VALUES
    (
        @showID, 
        @name , 
        @age,
        @city
    )
	END
	ELSE
	BEGIN
	RAISERROR('ERROR',16,1)
	END
END
GO

EXEC uspInsertParticipant 2,'Ana Maria',30,'Random'

--2 view
CREATE OR ALTER VIEW myview
AS
	SELECT P.PID, P.participant_name, P.participant_city, CS.showID,CS.show_name,C.channel_name,S.sponsor_name
	FROM participant P --1
	FULL JOIN cooking_show CS --2
	ON P.showID= CS.showID
	Full JOIN channel C --3	ON CS.channelID = C.channelID 	Full JOIN sponsor S --4	ON CS.sponsorID = S.sponsorID
GO
CREATE OR ALTER VIEW myview2
AS
	SELECT P.PID, P.participant_name, P.participant_city, CS.showID,CS.show_name,C.channel_name,S.sponsor_name
	From participant P,cooking_show CS,channel C,sponsor S
GO


SELECT *
FROM myview

--3 trigger
--insert
CREATE OR ALTER TRIGGER WhenAddingParticipant
	ON participant --trigger fires in response to INSERT events on this table
	FOR INSERT
		AS INSERT INTO LogTable(OpType,OpDate,TableName,numberOfRows)  --inserez rezultatul selectului in LogBuy
		SELECT 'INSERT',GETDATE(),'participant',@@ROWCOUNT
		FROM inserted
Go

--delete
CREATE OR ALTER TRIGGER WhenDeletingParticipant
	ON Participant
	FOR DELETE
		AS INSERT INTO LogTable(OpType,OpDate,TableName,numberOfRows) 
		SELECT 'DELETE',GETDATE(),'participant',@@ROWCOUNT
		FROM deleted
GO

--update
CREATE OR ALTER TRIGGER WhenUpdateParticipant
	ON participant
	FOR UPDATE
		AS INSERT INTO LogTable(OpType,OpDate,TableName,numberOfRows) 
		SELECT 'UPDATE',GETDATE(),'participant',@@ROWCOUNT
		FROM deleted
Go

EXEC uspInsertParticipant 2,'New too',30,'Oras two'
 insert into participant (showID,participant_name,participant_age,participant_city)
 values
 (1,'Ionut',29,'Satu de Sus'),
 (1,'Ionut al doilea',30,'Satu de Jos'),
 (1,'Ionut al treilea',31,'Satu de Jos')

 delete from participant where participant_name = 'Ionut' or participant_name = 'Ionut al doilea' or participant_name = 'Ionut al treilea'
 
 UPDATE participant
 SET participant_name='updated name'
 where participant_name='New too'

  UPDATE participant
 SET participant_name='updated_name'
 where participant_city='Satu de Jos'

 --4
 --create clustered index
ALTER TABLE participant
DROP CONSTRAINT PK__particip
GO

CREATE CLUSTERED INDEX Index_Name
ON participant(participant_age)

ALTER TABLE participant
ADD CONSTRAINT [PK__particip] PRIMARY KEY (PID)
GO

/*
CREATE CLUSTERED INDEX index_id
ON participant(PID)
*/

--create nonclustered index
CREATE NONCLUSTERED INDEX index_noncl
ON participant(participant_name)
--Clustered index scan
SELECT *
FROM participant

--Clustered Index Seek
Select *
From  participant
Where participant_age='30'

/*
--sau -pt PID
Select *
From  participant
Where PID=3000
*/

--Nonclustered Index Scan
SELECT participant_name
FROM participant

--Nonclustered Index Seek
SELECT participant_name
FROM participant
WHERE participant_name='a'

--Key lookup
SELECT *
FROM participant
WHERE PID=100

sp_helpindex participant