package repository;

import model.MarathonRace;

import java.util.List;
import java.util.stream.Collectors;

public class MarathonRaceInMemoryRepository extends AbstractRepository<Integer, MarathonRace> implements MarathonRaceRepository {
    public MarathonRaceInMemoryRepository(){}

    @Override
    public List<MarathonRace> findByName(String name) {
        return getAll().stream().filter(x->x.getName().toLowerCase().contains(name.toLowerCase())).collect(Collectors.toList());
    }

    @Override
    public List<MarathonRace> getAllRaces()
    {
        return getAll().stream().collect(Collectors.toList());
    }

    @Override
    public List<MarathonRace> filterByName(String name){
        return getAll().stream()
                .filter(n->n.getName().toLowerCase().equals(name.toLowerCase()))
                .collect(Collectors.toList());
    }

}
