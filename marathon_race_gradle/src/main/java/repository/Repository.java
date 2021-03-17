package repository;
import model.Identifiable;

import java.util.Collection;

public interface Repository<ID,T extends Identifiable<ID>> {
    T add(T newT);
    void delete(T t);
    void update(T newT,ID id);
    T findById(ID id);
    Iterable<T> findAll();
    Collection<T> getAll();
}
