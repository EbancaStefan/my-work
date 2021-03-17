--cu in cooking_database creat in cooking_show.sql
create procedure participant123 as
select *
from participant
exec participant123
GO

select* from participant
GO

CREATE or ALTER PROCEDURE uspGet_participants(@participantcity varchar(30)) AS
	SELECT participant_name,participant_age
	FROM participant
	WHERE participant_city=@participantcity
EXEC uspGet_participants 'Satu de sus'
GO

CREATE or ALTER PROCEDURE uspGet_participants(@participantcity varchar(30),@numberofparticipants int OUTPUT) AS
	SELECT @numberofparticipants=COUNT(*)
	FROM participant
	WHERE participant_city=@participantcity
DECLARE @number int = 0 --sau set
EXEC uspGet_participants 'Satu de jos',@numberofparticipants=@number OUTPUT
PRINT @number
GO

CREATE or ALTER PROCEDURE uspGet_participants(@participantcity varchar(30),@numberofparticipants int OUTPUT) AS
	SELECT @numberofparticipants=COUNT(*)
	FROM participant
	WHERE participant_city=@participantcity
	IF @numberofparticipants=0
		RAISERROR ('No participants found from that town',11,1)--'mesaj',severity,state
DECLARE @number int = 0
EXEC uspGet_participants 'Satu de jos23',@numberofparticipants=@number OUTPUT
PRINT @number
GO

--cursor prints the id and name of participants without select
DECLARE @PID int,@Pname varchar(30)
DECLARE CursorParticipant CURSOR FOR
	SELECT PID,participant_name
	FROM participant

OPEN CursorParticipant
	FETCH NEXT FROM CursorParticipant
	INTO @PID,@Pname
	WHILE @@FETCH_STATUS = 0 --exec 1st fetch next if its successful we get a 0
		BEGIN --this is mandatory
			--PRINT @PID + ' ' + @Pname --daca PID era char mergea
			--la mine e int decit trebuie facut string
			
			PRINT CAST(@PID AS varchar(3)) + ' ' + @Pname
			FETCH NEXT FROM CursorParticipant
			INTO @PID, @Pname
		END
CLOSE CursorParticipant
DEALLOCATE CursorParticipant

--DYNAMIC EXEC /sp_executesql
DECLARE @ParticipantID VARCHAR(35) = '1',@SqlSt VARCHAR(250)
SET @SqlST='Select* From participant'
sp_executesql [
