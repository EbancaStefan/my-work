package repository;

import model.CarReservation;

import java.util.List;
import java.util.stream.Collectors;

public class CarReservationInMemoryRepository extends AbstractRepository<Integer, CarReservation> implements CarReservationRepository {
    @Override
    public List<CarReservation> filterByAdress(String adress) {
        return getAll().stream().filter(x->x.getAdress().toLowerCase().equals(adress.toLowerCase())).collect(Collectors.toList());
    }

    @Override
    public List<CarReservation> filterByDate(String date) {
        return getAll().stream().filter(x->x.getDate().equals(date)).collect(Collectors.toList());
    }

    @Override
    public List<CarReservation> getAllReservations(){
        return getAll().stream().collect(Collectors.toList());
    }
}
