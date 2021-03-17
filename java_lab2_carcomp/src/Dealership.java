import java.util.ArrayList;
import java.util.Collections;

public class Dealership implements CarDealership
{
    private ArrayList<Car> cars = new ArrayList();
    public boolean addCar(Car car) {
        return cars.add(car);
    }

    public boolean removeCar(Car car)
    {
        return cars.remove(car);
    }

    public boolean createRez(Car car)
    {
        for (int i=0;i<cars.size();i++)
        {
            if(this.cars.get(i).getBrand().equals(car.getBrand()) && this.cars.get(i).getModel().equals(car.getModel()) && this.cars.get(i).getYear() == car.getYear())
            {
                this.cars.get(i).setIs_rented(true);
                return true;
            }
        }
        return false;
       /*
       !!!!sau asa!!!

        for(Car elem: cars)
        {
            if(elem.getBrand().equals(car.getBrand()));
        }
        */

    }
    public int getSize()
    {
        return this.cars.size();
    }
    public Car getCar(int index)
    {
        return cars.get(index);
    }
    public boolean cancelRez(Car car)
    {
        for (int i=0;i<cars.size();i++)
        {
            if(this.cars.get(i).getBrand().equals(car.getBrand()) && this.cars.get(i).getModel().equals(car.getModel()) && this.cars.get(i).getYear() == car.getYear())
            {
                this.cars.get(i).setIs_rented(false);
                return true;
            }
        }
        return false;
    }
    public void cars_by_brand(String brand)
    {
        for (int i=0; i<cars.size();i++)
        {
            if(this.cars.get(i).getBrand().equals(brand))
                System.out.println(cars.get(i).toString());
        }
    }
    public Car OldestCar(){return (Car) Collections.min(this.cars, new CarComparator());}
    public Car Most_expensive(){return (Car) Collections.max(this.cars, new CarComparator1());}

}
