--scalar function
CREATE OR ALTER FUNCTION CountParticipantsByAge(@Age INT)
RETURNS INT
BEGIN --mandatory for scalar functions
	RETURN (SELECT COUNT(*)
			FROM participant
			WHERE participant_age=@Age)
END --mandatory for scalar functions
--Select* from participant
PRINT dbo.CountParticipantsByAge(31) --fara dbo. nu mergea
GO--pentru a crea un alt batch

--inline table valued function
CREATE OR ALTER FUNCTION AllParticipantsWithGivenAge(@Age INT)
RETURNS TABLE
--BEGIN --error if we keep BEGIN & END
	RETURN (SELECT*
			FROM participant
			WHERE participant_age=@Age)
--END
SELECT* FROM AllParticipantsWithGivenAge(31)

--multi statement table valued function
CREATE OR ALTER FUNCTION ufParticipantsFilteredByAge(@Age INT)
RETURNS @ParticipantsFilteredByAge Table(PID INT,partname varchar(100),partcity varchar(100))
BEGIN
	INSERT @ParticipantsFilteredByAge
		SELECT PID,participant_name,participant_city
		FROM participant
		WHERE participant_age=@Age

		IF @@ROWCOUNT = 0--nr of rows affected
			INSERT @ParticipantsFilteredByAge
			VALUES(0,'NO PART WITH SUFICIENT AGE',NULL)
		RETURN
END
SELECT* FROM ufParticipantsFilteredByAge(31)

--VIEWS
CREATE OR ALTER VIEW chef_details AS
	SELECT chef_name,show_name
	FROM chef
	FULL JOIN appeared_on 
	ON chef.CID = appeared_on.CID 
	FULL JOIN cooking_show
	ON appeared_on.showID = cooking_show.showID
SELECT * FROM chef_details

--SYSTEM CATALOG
SELECT m.definition, o.name, o.type, o.type_desc
FROM sys.sql_modules m INNER JOIN sys.objects o
	ON m.object_id = o.object_id
WHERE o.type IN ('FN','IF','TF','P','V','TR')
ORDER BY o.type

--TRIGGERS
CREATE TABLE Product(
	PID INT,
	PName VARCHAR(100),
	PQuantity INT
	)
CREATE TABLE LogBuy(
	PName VARCHAR(100),
	OpDate DATE,
	Quantity INT
)
INSERT Product VALUES
(1,'a',20),
(2,'b',23),
(3,'c',25)

SELECT GETDATE()

CREATE OR ALTER TRIGGER WhenAddingProduct
	ON Product
	FOR INSERT --trigger fires in response to INSERT events on this table
		AS INSERT INTO LogBuy(PName,OpDate,Quantity) --inserez rezultatul selectului in LogBuy
		SELECT PName,GETDATE(),PQuantity
		FROM inserted

INSERT Product VALUES
(4,'a',5),
(5,'b',5)

SELECT * FROM Product
SELECT * FROM LogBuy --o sa avem doar 2 elemente in LogBuy pentru ca inseram dupa ce am creat triggerul

CREATE TABLE LogSell(
	PName VARCHAR(100),
	OpDate DATE,
	Quantity INT
)
--pentru delete
CREATE OR ALTER TRIGGER WhenDeletingProduct
	ON Product
	FOR DELETE --trigger fires in response to delete events on this table
		AS INSERT INTO LogSell(PName,OpDate,Quantity) --inserez rezultatul selectului in LogSell
		SELECT PName,GETDATE(),PQuantity
		FROM deleted
DELETE FROM Product WHERE PQuantity = 5
SELECT * FROM LogSell
SELECT * FROM Product
SELECT * FROM LogBuy
--pentru update
CREATE OR ALTER TRIGGER WhenChangingProduct
	ON Product
	FOR UPDATE
AS
	INSERT LogSell(PName,OpDate,Quantity)
	SELECT d.PName,GETDATE(),d.PQuantity-i.PQuantity
	FROM deleted d INNER JOIN inserted i on d.PID = i.PID
	WHERE i.PQuantity < d.PQuantity --its a sell

	INSERT LogBuy(PName,OpDate,Quantity)
	SELECT d.PName,GETDATE(),i.PQuantity-d.PQuantity
	FROM deleted d INNER JOIN inserted i on d.PID = i.PID
	WHERE i.PQuantity > d.PQuantity --its a buy
SELECT * FROM Product
SELECT * FROM LogSell
SELECT * FROM LogBuy

UPDATE PRODUCT SET PQuantity = 30