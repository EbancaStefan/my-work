package repository;

import model.MarathonRace;

import java.util.List;

public interface MarathonRaceRepository extends Repository<Integer, MarathonRace>{
    public List<MarathonRace> filterByName(String name);
    public List<MarathonRace> getAllRaces();
    public List<MarathonRace> findByName(String name);

}
