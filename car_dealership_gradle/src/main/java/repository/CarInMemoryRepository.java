package repository;

import model.Car;
import model.ReservationStatus;

import java.util.List;
import java.util.stream.Collectors;

public class CarInMemoryRepository extends AbstractRepository<Integer, Car> implements CarRepository{
    public CarInMemoryRepository(){}

    @Override
    public List<Car> findByBrand(String brand) {
        return getAll().stream().filter(x->x.getBrand().toLowerCase().contains(brand.toLowerCase())).collect(Collectors.toList());
    }

    @Override
    public List<Car> findByModel(String model) {
        return getAll().stream().filter(x->x.getModel().toLowerCase().contains(model.toLowerCase())).collect(Collectors.toList());
    }

    @Override
    public List<Car> filterdByStatus(ReservationStatus status) {
        return getAll().stream().filter(x->x.getStatus()==status).collect(Collectors.toList());
    }

    @Override
    public List<Car> filterByBrandAndStatus(String model, ReservationStatus status) {
        return getAll().stream().filter(x->x.getBrand().toLowerCase().contains(model.toLowerCase()) && x.getStatus()==status).collect(Collectors.toList());
    }

    @Override
    public List<Car> getAllCars()
    {
        return getAll().stream().collect(Collectors.toList());
    }
    @Override
    public List<Car> filterByPrice(int price) {
        return getAll().stream().filter(x->x.getPrice()==price).collect(Collectors.toList());
    }

    @Override
    public List<Car> filterByYear(int year) {
        return getAll().stream().filter(x->x.getYear()==year).collect(Collectors.toList());
    }
}
