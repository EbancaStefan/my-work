--create database sem7

--Indexed View
--Unique Clustered Index

SET ANSI_NULLS ON --OFF

CREATE TABLE T1
	(a INT NULL)
INSERT T1 VALUES(NULL),(0),(1)
SELECT * FROM T1

SELECT *
FROM T1
WHERE a = NULL
--return 0 rows
--daca e setat ala la off mere

SELECT *
FROM T1
WHERE a <> NULL
--similar as above
--daca e setat ala la off merge

SELECT *
FROM T1
WHERE a IS NULL
--merge si daca e on si off

DROP TABLE T1

SET ANSI_PADDING ON
CREATE TABLE t1
	(a CHAR(3) NULL,
	b VARCHAR(3) NULL)

INSERT t1 VALUES ('1','1')
INSERT t1 VALUES ('1 ','1 ')

SELECT '>' + a + '<', '>' + b + '<'
FROM t1
--daca padding e on pune TRAILING BLANKS pana la lungimea 3 pentru char
--pentru varchar nu pune nimic 

SET ANSI_PADDING OFF
CREATE TABLE t2
	(a CHAR(3) NULL,
	b VARCHAR(3) NULL)

INSERT t2 VALUES ('1','1')
INSERT t2 VALUES ('1 ','1 ')

SELECT '>' + a + '<', '>' + b + '<'
FROM t2
--nu mai adauga spatii libere nici la alea care au deja spatii

drop table t1
set ansi_warnings ON

CREATE TABLE t1
	(a INT,
	b INT NULL,
	c VARCHAR(20))

INSERT t1 VALUES
	(1,NULL,''),(1,0,''),
	(2,1,''),(2,2,'')
SELECT * FROM t1

SELECT a,SUM(b)
FROM t1
GROUP BY a

INSERT t1 VALUES
	(3, 3, 'Something that is longer than 20 characters.')
	--daca e off adauga ceva truncated

DROP TABLE t2

SET CONCAT_NULL_YIELDS_NULL ON
SELECT 'abc' + NULL --daca e off afiseaza abc altfel NULL

SET NUMERIC_ROUNDABORT OFF
DECLARE @result DECIMAL(5, 3), @value_1 DECIMAL(5,4), @value_2 DECIMAL(5,4)
SET @value_1 = 1.1111
SET @value_2 = 1.1111
SELECT @result = @value_1 + @value_2
SELECT @result --daca e on primim eroare

SET QUOTED_IDENTIFIER ON
--daca e off eroare aici
CREATE TABLE "SELECT"
	("IDENTITY" INT IDENTITY NOT NULL,
	"ORDER" INT NOT NULL)

SELECT "IDENTITY", "ORDER"
FROM "SELECT"

DROP TABLE "SELECT"

--WITH SCHEMABINDING
CREATE TABLE chef
(
CID INT PRIMARY KEY,
chef_style VARCHAR(30),
chef_stars INT,
chef_name VARCHAR(30)
);

CREATE TABLE sponsor
(
sponsorID INT PRIMARY KEY,
sponsor_name VARCHAR(30),
);
CREATE TABLE channel
(
channelID INT PRIMARY KEY,
channel_name VARCHAR(30),
channel_revenue INT,
channel_country VARCHAR(30),
);
CREATE TABLE cooking_show
(
sponsorID INT,
FOREIGN KEY(sponsorID) REFERENCES sponsor(sponsorID) ON DELETE CASCADE,
channelID INT,
FOREIGN KEY(channelID) REFERENCES channel(channelID) ON DELETE CASCADE,
showID INT PRIMARY KEY,
show_name VARCHAR(30)
);

CREATE TABLE participant
(
PID INT PRIMARY KEY ,
showID INT,
FOREIGN KEY (showID) REFERENCES cooking_show(showID) ON DELETE CASCADE,
participant_name VARCHAR(30),
participant_age INT,
participant_city VARCHAR(30)
);
CREATE TABLE appeared_on
(
CID INT,
showID INT,
FOREIGN KEY (CID) REFERENCES chef(CID) ON DELETE CASCADE,
FOREIGN KEY (showID) REFERENCES cooking_show(showID) ON DELETE CASCADE,
PRIMARY KEY (CID,showID),
DOA DATE
);
CREATE TABLE dishes
(
DID INT PRIMARY KEY ,
dish_name VARCHAR(30)
);


CREATE TABLE dish_participant
(
DID INT,
PID INT,
FOREIGN KEY (DID) REFERENCES dishes(DID) ON DELETE CASCADE,
FOREIGN KEY (PID) REFERENCES participant(PID) ON DELETE CASCADE,
PRIMARY KEY (DID,PID)
);


INSERT INTO cooking_show(sponsorID,/*channelID,*/showID,show_name)
VALUES
(1,3,'KITCHEN NIGHTMARES'),
(1,1,'Masterchef USA'),
(1,2,'Masterchef AU')
INSERT INTO participant(PID,showID,participant_name,participant_age,participant_city) 
VALUES 
(7,1,'American Ion2',56,'Satu de sus'),
(6,2,'Gimi2',31,'Satu de jos'),
(5,2,'Gimi',31,'Satu de jos'),
(1,1,'Ion',30,'Satu de jos'),
(2,1,'Ion2',31,'Satu de jos'),
(3,1,'American Ion',32,'Satu de sus'),
(4,2,'Australian Ion',29,'Satu de Australia');

insert into sponsor
 values
 (1,'RedBull'),
 (2,'BudWeiser')

 --WITH SCHEMABINDING
CREATE OR ALTER VIEW vPartShowSponsor
WITH SCHEMABINDING 
AS
SELECT P.showID,P.participant_name,COUNT_BIG(*) numS, SUM(ISNULL(P.participant_age,0)) numV
FROM dbo.participant P INNER JOIN dbo.cooking_show C ON P.showID = C.showID
	INNER JOIN dbo.sponsor S ON S.sponsorID = C.sponsorID
GROUP BY P.showID, P.participant_name
GO

CREATE UNIQUE CLUSTERED INDEX idx_cl_part
	ON vPartShowSponsor(participant_name)

SELECT *
FROM vPartShowSponsor
WITH(NOEXPAND)
WHERE numV>1
--mai erau ceva chestii aici check vod

--fragmentation
----internal frag
----extent frag
----logical frag
