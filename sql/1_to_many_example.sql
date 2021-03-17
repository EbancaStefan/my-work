CREATE TABLE Vendor(
    VendorNumber int PRIMARY KEY,
    Name varchar(20),
    Address varchar(20),
    City varchar(15),
    Street varchar(2),
    ZipCode varchar(10),
    Contact varchar(16),
    PhoneNumber varchar(12),
    Status varchar(8),
    StampDate date
);

CREATE TABLE Inventory(
    Item varchar(6) PRIMARY KEY,
    Description varchar(30),
    CurrentQuantity int NOT NULL,
    VendorNumber int REFERENCES Vendor(VendorNumber),
    ReorderQuantity int NOT NULL
);