INSERT INTO chef(CID,chef_style,chef_stars,chef_name) 
VALUES 
(1,'english cuisine',3,'Gordon Ramsay'),
(2,'french cuisine',3,'Marco Pierre White'),
(3,'italian cuisine',3,'Joe Bastianich'),
(4,'french cuisine',3,'Anthony Bourdain');

UPDATE chef
SET chef_stars = 0
WHERE chef_name = 'Gordon Ramsay' and chef_stars=3

UPDATE chef
SET chef_style = null
WHERE CID BETWEEN 0 AND 2 

DELETE 
FROM chef
WHERE chef_style IS NULL

INSERT INTO cooking_show(/*sponsorID,channelID,*/showID,show_name)
VALUES
(3,'KITCHEN NIGHTMARES'),
(1,'Masterchef USA'),
(2,'Masterchef AU')

UPDATE cooking_show
SET show_name = null
WHERE show_name in ('Masterchef AU','KITCHEN NIGHTMARES')

INSERT INTO participant(PID,showID,participant_name,participant_age,participant_city) 
VALUES 
(7,1,'American Ion2',56,'Satu de sus'),
(6,2,'Gimi2',31,'Satu de jos'),
(5,2,'Gimi',31,'Satu de jos'),
(1,1,'Ion',30,'Satu de jos'),
(2,1,'Ion2',31,'Satu de jos'),
(3,1,'American Ion',32,'Satu de sus'),
(4,2,'Australian Ion',29,'Satu de Australia');

UPDATE participant
SET participant_name = 'generic'
WHERE participant_name LIKE 'i%'

--a
SELECT showID from participant
UNION
select showID from cooking_show

SELECT showID from participant
INTERSECT
select showID from cooking_show

SELECT P.participant_name from participant P,cooking_show C
WHERE P.showID = C.showID 
EXCEPT
select P2.participant_name from participant P2, cooking_show C2
WHERE P2.showID = C2.showID and P2.participant_name = 'American Ion'

--b
SELECT*
FROM participant P INNER JOIN cooking_show C on P.showID = C.showID

SELECT*
FROM participant P LEFT JOIN cooking_show C on P.showID = C.showID

SELECT*
FROM cooking_show C LEFT JOIN participant P on P.showID = C.showID

SELECT*
FROM participant P RIGHT JOIN cooking_show C on P.showID = C.showID

SELECT*
FROM cooking_show C RIGHT JOIN participant P on P.showID = C.showID
--full join 3 tabele
select* from appeared_on

select* from chef

select* from cooking_show

INSERT INTO appeared_on(CID,showID) 
VALUES 
(3,1),
(4,2);
SELECT chef_name,show_name
FROM chef
 FULL JOIN appeared_on 
ON chef.CID = appeared_on.CID 
 FULL JOIN cooking_show
ON appeared_on.showID = cooking_show.showID

--c
SELECT P.participant_name
FROM participant P
WHERE P.showID in
	(SELECT C.showID 
	FROM cooking_show C
	where C.showID = 2)

SELECT P.participant_name
FROM participant P
WHERE EXISTS
	(SELECT*
	FROM cooking_show C
	where C.showID = 2 AND C.showID=P.showID)
select* from participant
select* from cooking_show

--d
Select C.*
From cooking_show C INNER JOIN
	(Select*
	From participant P
	where P.PID=2)t
on C.showID = t.showID

--e 3 group by
SELECT DISTINCT TOP 10 P.participant_name,P.participant_age
FROM participant P
ORDER BY P.participant_age

--the age of participants who are atleast 18 years old and are atleast 2 of the same age
SELECT P.participant_age,Max(P.participant_age) as MaxAge
FROM participant P
WHERE P.participant_age >= 18 and P.participant_city is not null
GROUP BY P.participant_age
HAVING COUNT(*)>=2

--the city and the maximum age of participants who are atleast 18 years old and are atleast 2 from the same city
select* from participant
SELECT P.participant_city,Max(P.participant_age) as MaxAge
FROM participant P
WHERE P.participant_age >= 18 and P.participant_city is not null
GROUP BY P.participant_city
HAVING 2<=(Select count(*)
			From participant P2
			where P2.participant_city=P.participant_city)

--the city and the minimum age of participants who are atleast 18 years old and are atleast 2 from the same city
select* from participant
SELECT P.participant_city,Min(P.participant_age) as MinAge
FROM participant P
WHERE P.participant_age >= 18 and P.participant_city is not null
GROUP BY P.participant_city
HAVING 2<=(Select count(*)
			From participant P2
			where P2.participant_city=P.participant_city)

--the city and the sum of ages of participants who are atleast 18 years old and are atleast 2 from the same city
select* from participant
SELECT P.participant_city,Sum(P.participant_age) as SumAge
FROM participant P
WHERE P.participant_age >= 18 and P.participant_city is not null
GROUP BY P.participant_city
HAVING 2<=(Select count(*)
			From participant P2
			where P2.participant_city=P.participant_city)