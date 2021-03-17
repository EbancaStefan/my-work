package repository;

import model.Car;
import model.ReservationStatus;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class CarFileRepository extends CarInMemoryRepository{
    private String filename;
    private static int idGenerator = 0;
    public CarFileRepository(String filename) {
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
                if (elems.length != 6) {
                    System.err.println("Invalid line ..." + line);
                    continue;
                }
                try {
                    int id = Integer.parseInt(elems[0]);
                    int price = Integer.parseInt(elems[3]);
                    int year = Integer.parseInt(elems[4]);
                    ReservationStatus status = ReservationStatus.valueOf(ReservationStatus.class, elems[5]);
                    Car c = new Car(id, elems[1], elems[2], price, year);
                    c.setStatus(status);
                    super.add(c);
                } catch (NumberFormatException ex) {
                    System.err.println("Error converting " + elems[0]);
                } catch (IllegalArgumentException ex) {
                    System.err.println("Error converting " + elems[5]);
                }
            }
        } catch (IOException ex) {
            throw new RepositoryException("Error reading " + ex);
        }
    }
    private void writeToFile(){
        try(PrintWriter pw=new PrintWriter(filename)){
            pw.println(idGenerator);
            for(Car c:findAll()){
                pw.println(c.getID()+";"+c.getBrand()+";"+c.getModel()+";"+c.getPrice()+";"+c.getYear()+";"+c.getStatus());
            }
        }catch(IOException ex){
            throw new RepositoryException("Error writing "+ex);
        }
    }
    @Override
    public Car add(Car el) {
        el.setID(getNextId());
        super.add(el);
        writeToFile();
        return el;
    }
    @Override
    public void delete(Car el) {
        super.delete(el);
        writeToFile();
    }
    @Override
    public void update(Car el, Integer id) {
        super.update(el, id);
        writeToFile();
    }

    private static int getNextId(){
        return idGenerator++;
    }
}
