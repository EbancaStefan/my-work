package model;

import java.io.Serializable;

public class CarReservation implements Identifiable<Integer>, Serializable {
    private int ID;
    private String ownerName,date,adress;
    private Car car;

    public CarReservation() {
        ID = 0;
        ownerName = "";
        car=null;
        date = "";

    }

    public CarReservation(int ID, String ownerName,String adress, Car car, String date) {
        this.ID = ID;
        this.ownerName = ownerName;
        this.adress = adress;
        this.car=car;
        this.date = date;

    }

    public CarReservation(String ownerName,String adress, Car car, String date) {
        this.ownerName = ownerName;
        this.adress = adress;
        this.car=car;
        this.date = date;

    }

    @Override
    public Integer getID() {
        return ID;
    }

    @Override
    public void setID(Integer Id) {
        this.ID = Id;
    }

    public String getOwnerName() {
        return ownerName;
    }

    public String getAdress() {
        return adress;
    }

    public String getDate() {
        return date;
    }

    public Car getCar() {
        return car;
    }

    public void setOwnerName(String ownerName) {
        this.ownerName = ownerName;
    }

    public void setAdress(String adress) {this.adress=adress;}

    public void setDate(String date) {
        this.date = date;
    }

    public void setCar(Car car) {
        this.car = car;
    }

    @Override
    public String toString()
    {
        String str = ownerName + "," + ID + ","+car;
        return str;
    }
    @Override
    public boolean equals(Object obj)
    {
        if(obj instanceof CarReservation)
        {
            CarReservation c=(CarReservation)obj;
            return c.ID==this.ID;
        }
        return false;
    }
}
