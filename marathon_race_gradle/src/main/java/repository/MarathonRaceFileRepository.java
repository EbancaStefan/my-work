package repository;

import model.MarathonRace;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class MarathonRaceFileRepository extends MarathonRaceInMemoryRepository {
    private String filename;
    private static int idGenerator = 0;
    public MarathonRaceFileRepository(String filename) {
        this.filename = filename;
        readFromFile();
    }

    private void readFromFile() {
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line = br.readLine();
            try {
                idGenerator = Integer.parseInt(line);
            } catch (NumberFormatException ex) {
                System.err.println("Invalid Value for idGenerator, starting from 0");
            }
            while ((line = br.readLine()) != null) {
                String[] elems = line.split(";");
                if (elems.length != 5) {
                    System.err.println("Invalid line ..." + line);
                    continue;
                }
                try {
                    int id = Integer.parseInt(elems[0]);
                    int distance = Integer.parseInt(elems[4]);
                    MarathonRace c = new MarathonRace(id,elems[1],elems[2],elems[3],distance);
                    super.add(c);
                } catch (NumberFormatException ex) {
                    System.err.println("Error converting " + elems[0]);
                } catch (IllegalArgumentException ex) {
                    System.err.println("Error converting " + elems[4]);
                }
            }
        } catch (IOException ex) {
            throw new RepositoryException("Error reading " + ex);
        }
    }
    private void writeToFile(){
        try(PrintWriter pw=new PrintWriter(filename)){
            pw.println(idGenerator);
            for(MarathonRace c:findAll()){
                //             0            1               2               3                   4
                pw.println(c.getID()+";"+c.getName()+";"+c.getType()+";"+c.getDate()+";"+c.getDistance());
            }
        }catch(IOException ex){
            throw new RepositoryException("Error writing "+ex);
        }
    }
    @Override
    public MarathonRace add(MarathonRace el) {
        el.setID(getNextId());
        super.add(el);
        writeToFile();
        return el;
    }
    @Override
    public void delete(MarathonRace el) {
        super.delete(el);
        writeToFile();
    }
    @Override
    public void update(MarathonRace el, Integer id) {
        super.update(el, id);
        writeToFile();
    }

    private static int getNextId(){
        return idGenerator++;
    }
}
