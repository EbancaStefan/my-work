package repository;

import model.Car;
import model.CarReservation;

import java.util.List;

public interface CarReservationRepository extends Repository<Integer, CarReservation>{
    List<CarReservation> filterByAdress(String adress);
    List<CarReservation> filterByDate(String date);
    List<CarReservation> getAllReservations();
}
