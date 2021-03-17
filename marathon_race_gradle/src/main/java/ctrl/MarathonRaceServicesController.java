package ctrl;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.text.Text;
import javafx.util.StringConverter;
import model.Registration;
import model.MarathonRace;
import services.ServicesException;
import services.MarathonRaceServices;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;

public class MarathonRaceServicesController {
    @FXML
    private TextField raceName, raceType, raceDate, raceDistance;
    @FXML
    private Text gameID;

    @FXML
    private TextField rezModel;
    @FXML
    private TextField repName,repAge1,repAge2;
    @FXML
    private TextField cName;
    @FXML
    private TextField personName, phoneNumber, address,personAge;
    @FXML
    private TableView<Registration> registrationResults;
    @FXML
    private TableView<Registration> registrationResults1;

    @FXML
    private DatePicker rentDate;

    @FXML
    private TableView<MarathonRace> raceResults;
    @FXML
    private TableView<MarathonRace> winterGameNameResults;


    @FXML
    private TableView<MarathonRace> reportResults;
    @FXML
    private TableView<MarathonRace> dateResults;
//price report
    @FXML
    private TableView<MarathonRace> priceResults;
    @FXML
    private TextField priceField;
//adress report
    @FXML
    private TableView<Registration> adressResults;
    @FXML
    private TextField adressField;

    @FXML
    private TableView<Registration> reportResults2;

    //connection to services
    private MarathonRaceServices marathonRaceServices;

    public MarathonRaceServicesController(){}

    public void setDealership(MarathonRaceServices dealership){
        this.marathonRaceServices =dealership;
    }

    private final DateTimeFormatter dateFormatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");
    @FXML
    public void initialize(){
        StringConverter<LocalDate> converter=new StringConverter<>() {
            @Override
            public String toString(LocalDate date) {
                return (date != null) ? dateFormatter.format(date) : "";
            }

            @Override
            public LocalDate fromString(String string) {
                return (string != null && !string.isEmpty())
                        ? LocalDate.parse(string, dateFormatter)
                        : null;
            }
        };

/*        rentDate.setConverter(converter);
        rentDate.setValue(LocalDate.now());
        rentDate.setEditable(false);

        reportDate.setConverter(converter);
        reportDate.setValue(LocalDate.now());
        reportDate.setEditable(false);*/
    }

    private boolean checkString(String s){
        return s==null || s.isEmpty()? false:true;
    }

    private void showNotification(String message, Alert.AlertType type){
        Alert alert=new Alert(type);
        alert.setTitle("Notification");
        alert.setContentText(message);
        alert.showAndWait();
    }
    @FXML
    public void addRaceHandler(ActionEvent actionEvent) {
        String name = raceName.getText();
        String type = raceType.getText();
        String date = raceDate.getText();
        String distance = raceDistance.getText();
        if (type.equals("kids") || type.equals("Kids") || type.equals("teens") || type.equals("Teens") || type.equals("adults") || type.equals("Adults") || type.equals("seniors") || type.equals("Seniors"))
        {
            if (checkString(name) && checkString(type) && checkString(date) && checkString(distance)) {
                try {
                    int id = marathonRaceServices.addRace(name, type, date, Integer.parseInt(distance));
                    gameID.setText("Marathon Race identification number is " + id);
                    showNotification("Marathon Race successfully added! ", Alert.AlertType.INFORMATION);
                } catch (ServicesException ex) {
                    showNotification(ex.getMessage(), Alert.AlertType.ERROR);
                }
            } else
                showNotification("You have to fill in all the fields! ", Alert.AlertType.ERROR);
        }
        else
        {
            showNotification("Type must be either 'kids' 'teens' 'adults' or 'seniors'", Alert.AlertType.ERROR);
            return;
        }
    }


    @FXML
    public void addRegistrationHandler(ActionEvent actionEvent) {
        //System.out.println("Add repaired button pressed ..."+repairDate.getValue().format(dateFormatter));
        int selectedRace= raceResults.getSelectionModel().getSelectedIndex();
        if (selectedRace<0){
            showNotification("You must select a Marathon Race first! ", Alert.AlertType.ERROR);
            return;
        }
        String name= personName.getText();
        String phone= phoneNumber.getText();
        String adress= address.getText();
        String age = personAge.getText();
        if (checkString(name)&&checkString(phone)&&checkString(adress)&&checkString(age)){
            try{
                //double price=Double.parseDouble(priceVal);
                MarathonRace marathonRace = raceResults.getItems().get(selectedRace);
                if(Integer.parseInt(age)<6)
                {
                    showNotification("There are no races for ages < 6!", Alert.AlertType.ERROR);
                    return;
                }
                if(marathonRace.getType().equals("kids")||marathonRace.getType().equals("Kids"))
                {
                    if(Integer.parseInt(age)<=11 && Integer.parseInt(age)>=6)
                    {
                        marathonRaceServices.addRegistration(name,phone, adress,marathonRace,Integer.parseInt(age));
                        clearRegistrationsFields();
                        showNotification("Registration successfully added! ", Alert.AlertType.INFORMATION);
                    }
                    else
                    {
                        showNotification("Age must be between 6 and 11 to register!", Alert.AlertType.ERROR);
                        return;
                    }
                }
                if(marathonRace.getType().equals("teens")||marathonRace.getType().equals("Teens"))
                {
                    if(Integer.parseInt(age)<=17 && Integer.parseInt(age)>=12)
                    {
                        marathonRaceServices.addRegistration(name,phone, adress,marathonRace,Integer.parseInt(age));
                        clearRegistrationsFields();
                        showNotification("Registration successfully added! ", Alert.AlertType.INFORMATION);
                    }
                    else
                    {
                        showNotification("Age must be between 12 and 17 to register!", Alert.AlertType.ERROR);
                        return;
                    }
                }
                if(marathonRace.getType().equals("adults")||marathonRace.getType().equals("Adults"))
                {
                    if(Integer.parseInt(age)<=60 && Integer.parseInt(age)>=18)
                    {
                        marathonRaceServices.addRegistration(name,phone, adress,marathonRace,Integer.parseInt(age));
                        clearRegistrationsFields();
                        showNotification("Registration successfully added! ", Alert.AlertType.INFORMATION);
                    }
                    else
                    {
                        showNotification("Age must be between 18 and 60 to register!", Alert.AlertType.ERROR);
                        return;
                    }

                }
                if(marathonRace.getType().equals("seniors")||marathonRace.getType().equals("Seniors"))
                {
                    if(Integer.parseInt(age)>=61)
                    {
                        marathonRaceServices.addRegistration(name,phone, adress,marathonRace,Integer.parseInt(age));
                        clearRegistrationsFields();
                        showNotification("Registration successfully added! ", Alert.AlertType.INFORMATION);
                    }
                    else
                    {
                        showNotification("Age must be between > 60 to register!", Alert.AlertType.ERROR);
                        return;
                    }
                }

                //chestieResults.getItems().remove(selectedChestie); ca e posibil sa se inscrie mai multi

            }catch (NumberFormatException ex){
                showNotification("The age must be a number! ", Alert.AlertType.ERROR);
                return;
            }catch (ServicesException ex){
                showNotification(ex.getMessage(), Alert.AlertType.ERROR);
            }
        }

    }
    private void clearRegistrationsFields() {
        personName.setText("");
        phoneNumber.setText("");
        address.setText("");
        personAge.setText("");
    }

    @FXML
    public void searchRaceHandler_cutot(ActionEvent actionEvent) {
        //era asa ca sa cauti chestiile in functie de ceva
        /*String searchModel=rezModel.getText();
        if (!checkString(searchModel)) {
            showNotification("You must introduce a brand! ", Alert.AlertType.ERROR);
            return;
        }
        List<Car> results=carDealership.getNotReservedCarsByBrand(searchModel);*/

        List<MarathonRace> results= marathonRaceServices.getAllRaces();
        raceResults.getItems().clear();
        raceResults.getItems().addAll(results);
    }
    @FXML
    public void searchRegistrationByRaceNameHandler(ActionEvent actionEvent)
    {
        String searchName = repName.getText();
        if(!checkString(searchName)){
            showNotification("You must introduce a name!", Alert.AlertType.ERROR);
            return;
        }
        List<Registration> allRegistrations = marathonRaceServices.getAllRegistrations();
        List<Registration> registrations = new ArrayList<>();
        for(Registration e: allRegistrations){
            if(e.getRace().getName().equals(searchName))
                registrations.add(e);
        }
        registrationResults.getItems().clear();
        registrationResults.getItems().addAll(registrations);

    }
    @FXML
    public void refreshRaceHandler(ActionEvent actionEvent) {
        List<MarathonRace> results= marathonRaceServices.getAllRaces();
        reportResults.getItems().clear();
        reportResults.getItems().addAll(results);
    }
    public void refreshRegistrationHandler(ActionEvent actionEvent) {
        List<Registration> results= marathonRaceServices.getAllRegistrations();
        reportResults2.getItems().clear();
        reportResults2.getItems().addAll(results);
    }
    @FXML
    public void clearFieldsHandler(ActionEvent actionEvent) {
        raceDistance.setText("");
        address.setText("");
        raceDate.setText("");
        raceType.setText("");
        raceName.setText("");
        gameID.setText("");
    }
    @FXML
    public void searchRegistrationByAgeHandler(ActionEvent actionEvent){
        String beginAge=repAge1.getText();
        String endAge=repAge2.getText();
        if(!checkString(beginAge)){
            showNotification("You must introduce an age!", Alert.AlertType.ERROR);
            return;
        }
        List<Registration> allRegistrations = marathonRaceServices.getAllRegistrations();
        List<Registration> registrations = new ArrayList<>();
        for(Registration e: allRegistrations){
            if(e.getAge()>=Integer.parseInt(beginAge)&&e.getAge()<=Integer.parseInt(endAge))
                registrations.add(e);
        }
        registrationResults1.getItems().clear();
        registrationResults1.getItems().addAll(registrations);

    }
    //comeback
    @FXML
    public void searchRacesByRegistrationNameHandler(ActionEvent actionEvent) {
        String childName=cName.getText();
        //List<WinterGame> allgames=winterGamesServices.getAllGames();
        List<Registration> allenrollments= marathonRaceServices.getAllRegistrations();
        List<MarathonRace> games = new ArrayList<>();
        for(Registration e: allenrollments)
        {
            if(e.getPersonName().equals(childName))
            {
                games.add(e.getRace());
            }
        }
        winterGameNameResults.getItems().clear();
        winterGameNameResults.getItems().addAll(games);



        /*String searchName = repName.getText();
        if(!checkString(searchName)){
            showNotification("You must introduce a name!", Alert.AlertType.ERROR);
            return;
        }
        List<Enrollment> allEnrollments = winterGamesServices.getAllEnrollments();
        //List<Carpet> results = carpetServices.getReservedCarpetsByName(searchName);
        List<Enrollment> enrollments = new ArrayList<>();
        for(Enrollment e:allEnrollments){
            if(e.getGame().getName().equals(searchName))
                enrollments.add(e);
        }
        enrollmentResults.getItems().clear();
        enrollmentResults.getItems().addAll(enrollments);*/

        /*List<Enrollment> reportResultList= winterGamesServices.getCarpetsDate(dateValue);
        List<WinterGame> winterGames =new ArrayList<>();
        for(Enrollment e:reportResultList)
        {
            winterGames.add(e.getGame());
            System.out.println(e.getGame());
        }
        dateResults.getItems().clear();
        dateResults.getItems().addAll(winterGames);*/
    }
    //pentru dateHandler
    /*@FXML
    public void reportHandler(ActionEvent actionEvent) {
        String dateValue=reportDate.getValue().format(dateFormatter);
        System.out.println(dateValue+" date");
        //System.out.println(Integer.parseInt(dateValue));
        List<Enrollment> reportResultList= winterGamesServices.getCarpetsDate(dateValue);
        List<WinterGame> winterGames =new ArrayList<>();
        for(Enrollment e:reportResultList)
        {
            winterGames.add(e.getGame());
            System.out.println(e.getGame());
        }
        dateResults.getItems().clear();
        dateResults.getItems().addAll(winterGames);
    }*/
    /*@FXML
    public void priceHandler(ActionEvent actionEvent){
        String priceValue=priceField.getText();
        if (!checkString(priceValue)) {
            showNotification("You must introduce a price! ", Alert.AlertType.ERROR);
            return;
        }
        List<Carpet> carpets = carpetServices.getCarsPrice(Integer.parseInt(priceValue));
        priceResults.getItems().clear();
        priceResults.getItems().addAll(carpets);
    }*/
    /*@FXML
    public void adressHandler(ActionEvent actionEvent){
        String adressValue=adressField.getText();
        if (!checkString(adressValue)) {
            showNotification("You must introduce an adress! ", Alert.AlertType.ERROR);
            return;
        }
        List<CarpetOrder> cars = carpetServices.getReservationAdress(adressValue);
        adressResults.getItems().clear();
        adressResults.getItems().addAll(cars);
    }*/

}
