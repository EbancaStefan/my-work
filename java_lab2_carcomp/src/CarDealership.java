import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
public interface CarDealership{
    boolean addCar(Car car);
    boolean removeCar(Car car);
    boolean createRez(Car car);
    boolean cancelRez(Car car);
    void cars_by_brand(String brand);
    Car OldestCar();
    Car Most_expensive();

}
