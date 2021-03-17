--add a table
CREATE OR ALTER PROCEDURE AddTable AS
	CREATE TABLE UndoTable(
		versiune int,
		procedureName varchar(50)
	);

	CREATE TABLE RedoTable(
		versiune int,
		procedureName varchar(50)
	);
	CREATE TABLE test(
		id INT not null,
		CONSTRAINT PK_test PRIMARY KEY(id),
		versiune INT,
		coloana1 INT,
		coloana2 VARCHAR(100)
	);
	CREATE TABLE test_secundar(
		id_secundar INT not null,
		CONSTRAINT PK_test_secundar PRIMARY KEY(id_secundar)
	)

	INSERT INTO test values(1,1,200,'pra')
	INSERT INTO test_secundar values(200)
GO

--drop a table
CREATE OR ALTER PROCEDURE DelTable AS
	DROP TABLE test
	DROP TABLE UndoTable
	DROP TABLE RedoTable
	DROP TABLE test_secundar
GO

--add column
CREATE or ALTER PROCEDURE AddColumn AS
	ALTER TABLE test
	ADD numar INT
	DECLARE @versiune int
	SELECT @versiune = versiune FROM test
	DECLARE @procedureName_invers varchar(50)
	SET @procedureName_invers = 'RemoveColumn'
	INSERT into UndoTable values(@versiune+1,@procedureName_invers)
	DECLARE @procedureName varchar(50)
	SET @procedureName = 'AddColumn'
	INSERT INTO RedoTable values(@versiune+1,@procedureName)
	UPDATE test SET versiune = versiune + 1
GO
CREATE or ALTER PROCEDURE AddColumn1 AS
	ALTER TABLE test
	ADD numar INT
GO

--del column
CREATE or ALTER PROCEDURE RemoveColumn AS
	ALTER TABLE test
	DROP COLUMN numar;
	DECLARE @versiune int
	SELECT @versiune = versiune FROM test
	DECLARE @procedureName_invers varchar(50)
	SET @procedureName_invers = 'AddColumn'
	INSERT into UndoTable values(@versiune+1,@procedureName_invers)
	DECLARE @procedureName varchar(50)
	SET @procedureName = 'RemoveColumn'
	INSERT INTO RedoTable values(@versiune+1,@procedureName)
	UPDATE test SET versiune = versiune + 1
GO
CREATE or ALTER PROCEDURE RemoveColumn1 AS
	ALTER TABLE test
	DROP COLUMN numar;
GO

--add primary key
CREATE or ALTER PROCEDURE AddPrimaryKey AS
	ALTER TABLE test
	ADD CONSTRAINT PK_test PRIMARY KEY (id)
	DECLARE @versiune int
	SELECT @versiune = versiune FROM test
	DECLARE @procedureName_invers varchar(50)
	SET @procedureName_invers = 'RemovePrimaryKey'
	INSERT into UndoTable values(@versiune+1,@procedureName_invers)
	DECLARE @procedureName varchar(50)
	SET @procedureName = 'AddPrimaryKey'
	INSERT INTO RedoTable values(@versiune+1,@procedureName)
	UPDATE test SET versiune = versiune + 1
GO
CREATE or ALTER PROCEDURE AddPrimaryKey1 AS
	ALTER TABLE test
	ADD CONSTRAINT PK_test PRIMARY KEY (id)
GO

--del primary key
CREATE or ALTER PROCEDURE RemovePrimaryKey AS
	ALTER TABLE test
	DROP CONSTRAINT PK_test
	DECLARE @versiune int
	SELECT @versiune = versiune FROM test
	DECLARE @procedureName_invers varchar(50)
	SET @procedureName_invers = 'AddPrimaryKey'
	INSERT into UndoTable values(@versiune+1,@procedureName_invers)
	DECLARE @procedureName varchar(50)
	SET @procedureName = 'RemovePrimaryKey'
	INSERT INTO RedoTable values(@versiune+1,@procedureName)
	UPDATE test SET versiune = versiune + 1
GO
CREATE or ALTER PROCEDURE RemovePrimaryKey1 AS
	ALTER TABLE test
	DROP CONSTRAINT PK_test
GO

--add foreign key
CREATE or ALTER PROCEDURE AddForeignKey AS
	ALTER TABLE test
	ADD CONSTRAINT FK_test_coloana1
	FOREIGN KEY (coloana1) REFERENCES test_secundar(id_secundar)
	DECLARE @versiune int
	SELECT @versiune = versiune FROM test
	DECLARE @procedureName_invers varchar(50)
	SET @procedureName_invers = 'RemoveForeignKey'
	INSERT into UndoTable values(@versiune+1,@procedureName_invers)
	DECLARE @procedureName varchar(50)
	SET @procedureName = 'AddForeignKey'
	INSERT INTO RedoTable values(@versiune+1,@procedureName)
	UPDATE test SET versiune = versiune + 1
GO
CREATE or ALTER PROCEDURE AddForeignKey1 AS
	ALTER TABLE test
	ADD CONSTRAINT FK_test_coloana1
	FOREIGN KEY (coloana1) REFERENCES test_secundar(id_secundar)
GO

--del foreign key
CREATE or ALTER PROCEDURE RemoveForeignKey AS
	ALTER TABLE test
	DROP CONSTRAINT FK_test_coloana1
	DECLARE @versiune int
	SELECT @versiune = versiune FROM test
	DECLARE @procedureName_invers varchar(50)
	SET @procedureName_invers = 'AddForeignKey'
	INSERT into UndoTable values(@versiune+1,@procedureName_invers)
	DECLARE @procedureName varchar(50)
	SET @procedureName = 'RemoveForeignKey'
	INSERT INTO RedoTable values(@versiune+1,@procedureName)
	UPDATE test SET versiune = versiune + 1
GO
CREATE or ALTER PROCEDURE RemoveForeignKey1 AS
	ALTER TABLE test
	DROP CONSTRAINT FK_test_coloana1
GO

EXEC AddTable
EXEC DelTable

EXEC AddColumn
EXEC RemoveColumn

EXEC RemovePrimaryKey
EXEC AddPrimaryKey

EXEC AddForeignKey
EXEC RemoveForeignKey

EXEC toVersion 1
CREATE or ALTER PROCEDURE toVersion(@version int) AS
	DECLARE @currentVersion int
	select @currentVersion = versiune from test
	DECLARE @procedureName varchar(50)
	DECLARE @stop int
	IF @currentVersion > @version --daca versiunea din tabel > decat cea aleasa
		BEGIN
		WHILE @currentVersion!=@version BEGIN
			SELECT @procedureName=U.procedureName from UndoTable U where U.versiune = @currentVersion
			SET @currentVersion=@currentVersion-1
			IF (@procedureName = 'AddColumn')
			BEGIN
				EXEC AddColumn1
			END

			IF (@procedureName = 'RemoveColumn')
			BEGIN
				EXEC RemoveColumn1
			END

			IF (@procedureName = 'AddPrimaryKey')
			BEGIN
				EXEC AddPrimaryKey1
			END

			IF (@procedureName = 'RemovePrimaryKey')
			BEGIN
				EXEC RemovePrimaryKey1
			END

			IF (@procedureName = 'AddForeignKey')
			BEGIN
				EXEC AddForeignKey1
			END

			IF (@procedureName = 'RemoveForeignKey')
			BEGIN
				EXEC RemoveForeignKey1
			END
		END
		END
	ELSE
		BEGIN
		WHILE @currentVersion!=@version BEGIN
			SELECT @procedureName=R.procedureName from RedoTable R where R.versiune = @currentVersion+1
			SET @currentVersion=@currentVersion+1
			IF (@procedureName = 'AddColumn')
			BEGIN
				EXEC AddColumn1
			END

			IF (@procedureName = 'RemoveColumn')
			BEGIN
				EXEC RemoveColumn1
			END

			IF (@procedureName = 'AddPrimaryKey')
			BEGIN
				EXEC AddPrimaryKey1
			END

			IF (@procedureName = 'RemovePrimaryKey')
			BEGIN
				EXEC RemovePrimaryKey1
			END

			IF (@procedureName = 'AddForeignKey')
			BEGIN
				EXEC AddForeignKey1
			END

			IF (@procedureName = 'RemoveForeignKey')
			BEGIN
				EXEC RemoveForeignKey1
			END
		END
		END
	  UPDATE test SET versiune = @currentVersion
GO
			












--undo tabel / redo tabel
CREATE TABLE UndoTable(
versiune int,
procedureName varchar(50)
);

CREATE TABLE RedoTable(
versiune int,
procedureName varchar(50)
);
insert into UndoTable values(1,'da');