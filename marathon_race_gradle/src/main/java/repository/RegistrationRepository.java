package repository;

import model.Registration;

import java.util.List;

public interface RegistrationRepository extends Repository<Integer, Registration>{
    List<Registration> filterByAdress(String adress);
   // List<Enrollment> filterByDate(String date);
    List<Registration> getAllRegistrations();
}
