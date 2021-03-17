package repository;

import model.Registration;
import model.MarathonRace;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class RegistrationFileRepository extends RegistrationInMemoryRepository {
    private String filename;
    private MarathonRaceRepository marathonRaceRepository;
    private static int idGenerator=0;

    private static int getNextId(){
        return idGenerator++;
    }

    public RegistrationFileRepository(String filename, MarathonRaceRepository marathonRaceRepository) {
        this.filename = filename;
        this.marathonRaceRepository = marathonRaceRepository;
        readFromFile();
    }
    private void readFromFile(){
        try(BufferedReader br=new BufferedReader(new FileReader(filename))){
            String line=br.readLine();
            try{
                idGenerator=Integer.parseInt(line);
            }catch (NumberFormatException ex){
                System.err.println("Invalid Value for idGenerator, starting from 0");
            }
            while((line=br.readLine())!=null){
                String[] elems=line.split(";");
                if (elems.length!=6){
                    System.err.println("Invalid line ..."+line);
                    continue;
                }
                try {
                    //              0               1                           2                       3                           4                   5
                    //pw.println(rez.getID()+";"+rez.getRace().getID()+";"+rez.getPersonName()+";"+rez.getPhoneNumber()+";"+";"+rez.getAddress()+";"+rez.getAge());
                    int id = Integer.parseInt(elems[0]);
                    int rID=Integer.parseInt(elems[1]);
                    int age = Integer.parseInt(elems[5]);
                    MarathonRace marathonRace = marathonRaceRepository.findById(rID);
                    Registration rez=new Registration(id,elems[2],elems[3],elems[4],marathonRace,age);
                    super.add(rez);

                }catch(NumberFormatException ex){
                    System.err.println("Invalid data "+ex);
                }catch (RepositoryException ex){
                    System.err.println("Repository Error "+ex);
                }
            }
        }catch (IOException ex){
            throw new RepositoryException("Error reading "+ex);
        }

    }
    @Override
    public Registration add(Registration el) {
        el.setID(getNextId());
        super.add(el);
        writeToFile();
        return el;
    }

    @Override
    public void delete(Registration el) {
        super.delete(el);
        writeToFile();
    }

    @Override
    public void update(Registration el, Integer integer) {
        super.update(el, integer);
        writeToFile();
    }

    private void writeToFile(){
        try(PrintWriter pw=new PrintWriter(filename)){
            pw.println(idGenerator);
            for(Registration rez:findAll()){
                pw.println(rez.getID()+";"+rez.getRace().getID()+";"+rez.getPersonName()+";"+rez.getPhoneNumber()+";"+rez.getAddress()+";"+rez.getAge());
            }
        }catch(IOException ex){
            throw new RepositoryException("Error writing "+ex);
        }

    }
}
