import ctrl.MarathonRaceServicesController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.stage.Stage;
import repository.RegistrationFileRepository;
import repository.MarathonRaceFileRepository;
import repository.MarathonRaceRepository;
import services.ServicesException;
import services.MarathonRaceServices;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

public class MainFX extends Application{
    @Override
    public void start(Stage primaryStage) throws Exception {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("MarathonRaceWindow.fxml"));
            Parent root = loader.load();
            MarathonRaceServicesController ctrl = loader.getController();
            ctrl.setDealership(getDealership());
            Scene scene = new Scene(root);
            primaryStage.setScene(scene);
            primaryStage.setTitle("Marathon Race");
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

    static MarathonRaceServices getDealership() throws ServicesException {
        try {
            Properties properties = new Properties();
            properties.load(new FileInputStream("MARATHONRACE.properties"));
            String requestFileName=properties.getProperty("RacesFile");
            if (requestFileName==null){
                requestFileName="RacesFile.txt";
                System.err.println("RacesFile file not found. Using default "+requestFileName);
            }
            String formsFileName=properties.getProperty("RegistrationsFile");
            if (formsFileName==null){
                formsFileName="RegistrationsFile.txt";
                System.err.println("RegistrationsFile file not found. Using default "+formsFileName);
            }
            MarathonRaceRepository carRepo = new MarathonRaceFileRepository(requestFileName);

            RegistrationFileRepository rezRepo = new RegistrationFileRepository(formsFileName, carRepo);
            return new MarathonRaceServices(carRepo, rezRepo);
        }catch (IOException ex){
            throw new ServicesException("Error starting app "+ex);
        }
    }
}
