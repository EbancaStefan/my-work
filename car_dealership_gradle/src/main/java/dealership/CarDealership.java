package dealership;

import model.Car;
import model.CarReservation;
import model.ReservationStatus;
import repository.CarRepository;
import repository.CarReservationRepository;
import repository.RepositoryException;

import java.util.List;

public class CarDealership {

    private CarRepository carRepository;

    private CarReservationRepository reservationRepository;

    public CarDealership(CarRepository carRepository, CarReservationRepository reservationRepository) {
        this.carRepository = carRepository;
        this.reservationRepository = reservationRepository;
    }

    public int addCar(String brand, String model, int price, int year) throws DealershipException{
        try {
            Car car = new Car(brand, model, price, year);
            Car newCar = carRepository.add(car);
            return newCar.getID();
        }catch (RepositoryException ex){
            throw new DealershipException("Error adding car"+ex);
        }
    }
    public int delCar(String brand, String model,int price, int year) throws DealershipException{
        try {
            int ok = 0;
            for(Car e: carRepository.getAllCars())
            {
                if(e.getBrand().equals(brand)&& e.getModel().equals(model) && e.getYear()==year && e.getPrice()==price) {
                    carRepository.delete(e);
                    for(CarReservation rezerv: reservationRepository.getAllReservations()) {
                        if(rezerv.getCar().getID()==e.getID()) {
                            reservationRepository.delete(rezerv);
                        }
                    }
                    ok = 1;
                }
            }
            return ok;
        }catch (RepositoryException ex){
            throw new DealershipException("Error deleting car"+ex);
        }
    }

    public void updateCar(String brand, String model, int price, int year,Integer i,int ok) throws DealershipException{
        try {
            Car car = new Car(brand, model, price, year);
            car.setID(i);
            if(ok==1) {
                carRepository.update(car, i);
            }
            else {
                car.setStatus(ReservationStatus.Reserved);
                carRepository.update(car, i);
            }
/*            for(CarReservation rezerv: reservationRepository.getAllReservations()) {
                if (rezerv.getCar().getID() == i) {
                    CarReservation rezerv2 = new CarReservation(rezerv.getOwnerName(), rezerv.getAdress(), car,rezerv.getDate());
                    reservationRepository.update(rezerv2,i);
                }
            }*/

        }catch (RepositoryException ex){
            throw new DealershipException("Error adding car"+ex);
        }
    }
    public int delRes(String name,String adress,String date,Integer i) throws DealershipException{
        try {
            int ok = 0;
            for(CarReservation res: reservationRepository.getAllReservations()){
                if(res.getDate().equals(date)&&res.getAdress().equals(adress)&&res.getOwnerName().equals(name)&&res.getCar().getID()==i)
                {
                    carRepository.findById(i).setStatus(ReservationStatus.NotReserved);
                    reservationRepository.delete(res);
                    ok=1;
                }
            }
            return ok;
        }catch (RepositoryException ex){
            throw new DealershipException("Error deleting car"+ex);
        }
    }

    public List<Car> getNotReservedCarsByBrand(String model){
        return carRepository.filterByBrandAndStatus(model, ReservationStatus.NotReserved);

    }
    public List<Car> getAllCars()
    {
        return carRepository.getAllCars();
    }
    public List<CarReservation> getAllReservations()
    {
        return reservationRepository.getAllReservations();
    }


    public void addCarReservation(String ownerName,String adress, Car car, String date) throws DealershipException{
        try {
            car.setStatus(ReservationStatus.Reserved);
            CarReservation rez = new CarReservation(ownerName,adress,car,date);
            carRepository.update(car, car.getID());
            reservationRepository.add(rez);
        }catch (RepositoryException er){
            throw  new DealershipException("Error adding reservation"+er);
        }

    }

    public List<Car> getCarsYear(int year) {
        return carRepository.filterByYear(year);
    }
    public List<CarReservation> getCarsDate(String date) {
        return reservationRepository.filterByDate(date);
    }
    public List<Car> getCarsPrice(int price) {return carRepository.filterByPrice(price);}
    public List<CarReservation> getReservationAdress(String adress){return reservationRepository.filterByAdress(adress);}
}
