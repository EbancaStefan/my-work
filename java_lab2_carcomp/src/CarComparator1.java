import java.util.Comparator;

public class CarComparator1 implements Comparator<Car> {
    public CarComparator1() {
    }

    public int compare(Car c1, Car c2) {
        return c1.getPrice() - c2.getPrice();
    }
}