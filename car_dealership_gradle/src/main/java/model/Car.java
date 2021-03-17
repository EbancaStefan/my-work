package model;


import java.io.Serializable;

public class Car implements Identifiable<Integer>, Serializable {
    private int price,ID;
    private String brand;
    private String model;
    private int year;
    private ReservationStatus status;

    public Car()
    {
        this.ID=0;
        this.price=0;
        this.brand="";
        this.model="";
        this.year=0;
        this.status = ReservationStatus.NotReserved;
    }

    public Car(int id1,String brand1,String model1,int price1,int year1)
    {
        this.ID=id1;
        this.price=price1;
        this.year=year1;
        this.model=model1;
        this.brand=brand1;
        this.status=ReservationStatus.NotReserved;
    }
    public Car(String brand1,String model1,int price1,int year1)
    {
        this.price=price1;
        this.year=year1;
        this.model=model1;
        this.model=model1;
        this.brand=brand1;
        this.status=ReservationStatus.NotReserved;
    }
    public void setYear(int year1) {
        this.year = year1;
    }
    public int getYear() {
        return this.year;
    }

    public void setPrice(int price1) {
        this.price = price1;
    }
    public int getPrice() {
        return this.price;
    }

    public void setBrand(String brand){this.brand=brand;}
    public String getBrand(){return this.brand;}


    public void setModel(String model) {this.model = model;}
    public String getModel(){return this.model;}

    public ReservationStatus getStatus() {
        return status;
    }

    public void setStatus(ReservationStatus NewStatus) {
        this.status = NewStatus;
    }
    @Override
    public String toString()
    {
        StringBuffer str=new StringBuffer();
        str.append(this.ID);
        str.append(" ");
        str.append(this.brand);
        str.append(" ");
        str.append(this.model);
        str.append(" ");
        str.append(this.year);
        str.append(" costs ");
        str.append(this.price);
        str.append(" ->");
        str.append(this.status);
        return str.toString();
    }
    @Override
    public boolean equals(Object obj)
    {
        if(!(obj instanceof Car))
        {
            return false;
        }
        else
        {
            Car c = (Car)obj;
            return this.ID==c.ID;
        }
    }

    @Override
    public Integer getID() {
        return ID;
    }

    @Override
    public void setID(Integer ID) {
        this.ID=ID;
    }
}
