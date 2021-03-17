import java.util.Comparator;

public class CarComparator implements Comparator<Car> {
    public CarComparator() {
    }

    public int compare(Car c1, Car c2) {
        return c1.getYear() - c2.getYear();
    }
}
