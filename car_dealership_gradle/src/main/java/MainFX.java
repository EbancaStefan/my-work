import ctrl.CarDealershipController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.stage.Stage;
import model.Car;
import model.CarReservation;
import model.ReservationStatus;
import repository.CarFileRepository;
import repository.CarRepository;
import repository.CarReservationFileRepository;
import dealership.CarDealership;
import dealership.DealershipException;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;

public class MainFX extends Application{
    @Override
    public void start(Stage primaryStage) throws Exception {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("DealershipWindow.fxml"));
            Parent root = loader.load();
            CarDealershipController ctrl = loader.getController();
            ctrl.setDealership(getDealership());
            Scene scene = new Scene(root);
            primaryStage.setScene(scene);
            primaryStage.setTitle("Car Dealership");
            primaryStage.show();
        }catch(Exception e){
            Alert alert=new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error ");
            alert.setContentText("Error while starting app "+e);
            alert.showAndWait();
        }
    }
    public static void main(String[] args) {
        launch(args);
    }

    static CarDealership getDealership() throws DealershipException{
        try {
            Properties properties = new Properties();
            properties.load(new FileInputStream("Dealership.properties"));
            String requestFileName=properties.getProperty("CarsFile");
            if (requestFileName==null){
                requestFileName="CarsFile.txt";
                System.err.println("CarsFile file not found. Using default "+requestFileName);
            }
            String formsFileName=properties.getProperty("ReservationsFile");
            if (formsFileName==null){
                formsFileName="ReservationsFile.txt";
                System.err.println("ReservationsFile file not found. Using default "+formsFileName);
            }
            CarRepository carRepo = new CarFileRepository(requestFileName);

            CarReservationFileRepository rezRepo = new CarReservationFileRepository(formsFileName, carRepo);
            return new CarDealership(carRepo, rezRepo);
        }catch (IOException ex){
            throw new DealershipException("Error starting app "+ex);
        }
    }
}
