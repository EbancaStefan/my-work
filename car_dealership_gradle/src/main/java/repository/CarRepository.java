package repository;

import model.Car;
import model.ReservationStatus;

import java.util.List;

public interface CarRepository extends Repository<Integer,Car>{
    List<Car> findByBrand(String brand);
    List<Car> findByModel(String model);
    List<Car> filterdByStatus(ReservationStatus status);
    List<Car> filterByBrandAndStatus(String model,ReservationStatus status);
    List<Car> getAllCars();
    List<Car> filterByPrice(int price);
    List<Car> filterByYear(int year);
}
