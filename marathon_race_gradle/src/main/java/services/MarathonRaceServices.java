package services;

import model.Registration;
import model.MarathonRace;
import repository.RegistrationRepository;
import repository.RepositoryException;
import repository.MarathonRaceRepository;

import java.util.List;

public class MarathonRaceServices {

    private MarathonRaceRepository marathonRaceRepository;

    private RegistrationRepository registrationRepository;

    public MarathonRaceServices(MarathonRaceRepository marathonRaceRepository, RegistrationRepository registrationRepository) {
        this.marathonRaceRepository = marathonRaceRepository;
        this.registrationRepository = registrationRepository;
    }

    public int addRace(String name, String type, String date, int a1) throws ServicesException {
        try {
            MarathonRace marathonRace = new MarathonRace(name, type, date, a1);
            MarathonRace newMarathonRace = marathonRaceRepository.add(marathonRace);
            return newMarathonRace.getID();
        }catch (RepositoryException ex){
            throw new ServicesException("Error adding race"+ex);
        }
    }
    public List<MarathonRace> getAllRaces()
    {
        return marathonRaceRepository.getAllRaces();
    }
    public List<Registration> getAllRegistrations()
    {
        return registrationRepository.getAllRegistrations();
    }


    public void addRegistration(String personName, String phoneNumber,String adress, MarathonRace marathonRace, int age) throws ServicesException {
        try {
            Registration rez = new Registration(personName,phoneNumber,adress,marathonRace,age);
            marathonRaceRepository.update(marathonRace, marathonRace.getID());
            registrationRepository.add(rez);
        }catch (RepositoryException er){
            throw  new ServicesException("Error adding registration"+er);
        }

    }
    public List<MarathonRace> getRacesByName(String name){return marathonRaceRepository.filterByName(name);}
   /* public List<Enrollment> getCarpetsDate(String date) {
        return enrollmentRepository.filterByDate(date);
    }*/
    //public List<CarpetOrder> getReservationAdress(String adress){return orderRepository.filterByAdress(adress);}

    /*public List<Car> getNotReservedCarsByBrand(String model) {
        return carRepository.filterByBrandAndStatus(model, ReservationStatus.NotReserved);
    }*/
}
