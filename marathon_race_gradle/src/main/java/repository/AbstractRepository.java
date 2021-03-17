package repository;

import model.Identifiable;

import java.util.Collection;
import java.util.Map;
import java.util.TreeMap;

public abstract class AbstractRepository<ID,T extends Identifiable<ID>> implements Repository<ID,T> {
    protected Map<ID,T> map;

    public AbstractRepository()
    {
        map= new TreeMap<>();
    }
    public T add(T newt)
    {
        if (map.containsKey(newt.getID())==true)
            throw new RuntimeException("it already exists");
        else
            map.put(newt.getID(), newt);
        return newt;
    }
    public void delete(T newt)
    {
        if(map.containsKey(newt.getID()))
            map.remove(newt.getID());
    }
    public void update(T newt,ID id)
    {
        if(map.containsKey(id))
            map.put(newt.getID(),newt);
        else
            throw new RuntimeException("it is not in the repo");
    }
    public T findById(ID id)
    {
        if(map.containsKey(id))
            return map.get(id);
        else
            return null;
    }
    public Iterable<T> findAll()
    {
        return map.values();
    }
    @Override
    public Collection<T> getAll() {
        return map.values();
    }



}
