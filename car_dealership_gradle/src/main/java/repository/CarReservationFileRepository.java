package repository;

import model.Car;
import model.CarReservation;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class CarReservationFileRepository extends CarReservationInMemoryRepository{
    private String filename;
    private CarRepository carRepository;
    private static int idGenerator=0;

    private static int getNextId(){
        return idGenerator++;
    }

    public CarReservationFileRepository(String filename,CarRepository carRepository) {
        this.filename = filename;
        this.carRepository=carRepository;
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
                if (elems.length!=5){
                    System.err.println("Invalid line ..."+line);
                    continue;
                }
                try {
                    //id;carID;ownerName;adress;date
                    //0 ;   1 ;   2     ; 3    ;  4
                    int id = Integer.parseInt(elems[0]);
                    int carID=Integer.parseInt(elems[1]);
                    Car car=carRepository.findById(carID);
                    CarReservation rez=new CarReservation(id,elems[2],elems[3],car,elems[4]);
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
    public CarReservation add(CarReservation el) {
        el.setID(getNextId());
        super.add(el);
        writeToFile();
        return el;
    }

    @Override
    public void delete(CarReservation el) {
        super.delete(el);
        writeToFile();
    }

    @Override
    public void update(CarReservation el, Integer integer) {
        super.update(el, integer);
        writeToFile();
    }

    private void writeToFile(){
        try(PrintWriter pw=new PrintWriter(filename)){
            pw.println(idGenerator);
            for(CarReservation rez:findAll()){
                //id;carID;ownerName;adress;date
                pw.println(rez.getID()+";"+rez.getCar().getID()+";"+rez.getOwnerName()+";"+rez.getAdress()+";"+rez.getDate());
            }
        }catch(IOException ex){
            throw new RepositoryException("Error writing "+ex);
        }

    }
}
