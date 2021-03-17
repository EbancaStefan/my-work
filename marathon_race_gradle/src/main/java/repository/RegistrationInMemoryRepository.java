package repository;

import model.Registration;

import java.util.List;
import java.util.stream.Collectors;

public class RegistrationInMemoryRepository extends AbstractRepository<Integer, Registration> implements RegistrationRepository {
    @Override
    public List<Registration> filterByAdress(String adress) {
        return getAll().stream().filter(x->x.getPhoneNumber().toLowerCase().equals(adress.toLowerCase())).collect(Collectors.toList());
    }

/*    @Override
    public List<Enrollment> filterByDate(String date) {
        return getAll().stream().filter(x->x.getAge().equals(date)).collect(Collectors.toList());
    }*/

    @Override
    public List<Registration> getAllRegistrations(){
        return getAll().stream().collect(Collectors.toList());
    }

}
