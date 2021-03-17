--create DATABASE COOKING_DATABASE;
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
