//Design and implement a Java solution for managing the
// reservations for car rentals.The program should allow adding
// a new car for renting, creating a reservation, cancelling a
// reservation, creating different reports, etc.
public class Car implements Comparable<Car>{
    private int price;
    private String brand;
    private String model;
    private int year;
    private boolean is_rented;

    public Car()
    {
        this.price=0;
        this.brand="";
        this.model="";
        this.year=0;
        this.is_rented=false;
    }

    public Car(String brand1,String model1,int price1,int year1,boolean rent)
    {
        this.price=price1;
        this.year=year1;
        this.model=model1;
        this.is_rented=rent;
        this.model=model1;
        this.brand=brand1;
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

    public void setIs_rented(boolean is_rented) {this.is_rented = is_rented;}
    public boolean isIs_rented() {return this.is_rented;}

    public void setModel(String model) {this.model = model;}
    public String getModel(){return this.model;}

    public String toString()
    {
        StringBuffer str=new StringBuffer();
        str.append(this.brand);
        str.append(" ");
        str.append(this.model);
        str.append(" ");
        str.append(this.year);
        str.append(" costs ");
        str.append(this.price);
        if(this.is_rented==true)
            str.append(" IS RENTED.");
        else
            str.append(" IS NOT RENTED.");
        return str.toString();
    }
    public boolean equals(Object obj)
    {
        if(!(obj instanceof Car))
        {
            return false;
        }
        else
        {
            Car c = (Car)obj;
            return this.year == c.year && this.model.equals(c.model) && this.brand.equals(c.brand);
        }
    }
    public int compareTo(Car c)
    {
        if(c.year > this.year)
            return -1;
        if(c.year<this.year)
            return 1;
        return 0;
        //return c.year-this.year
    }
}
