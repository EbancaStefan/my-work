package ctrl;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.text.Text;
import javafx.util.StringConverter;
import model.Car;
import dealership.CarDealership;
import dealership.DealershipException;
import model.CarReservation;
import model.ReservationStatus;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;

public class CarDealershipController {
    //for Car
    @FXML
    private TextField carBrand, carModel,carPrice, carYear;
    @FXML
    private Text carID;

    //for CarReservation
    @FXML
    private TextField rezModel;
    @FXML
    private TextField ownerName, ownerAdress;

    @FXML
    private DatePicker rentDate;

    @FXML
    private TableView<Car> carResults;


//cars
    @FXML
    private TextField carsBrand, carsModel,carsPrice, carsYear;
    @FXML
    private DatePicker reportDate;

    @FXML
    private TableView<Car> reportResults;
    @FXML
    private TableView<Car> dateResults;
//price report
    @FXML
    private TableView<Car> priceResults;
    @FXML
    private TextField priceField;
//adress report
    @FXML
    private TableView<CarReservation> adressResults;
    @FXML
    private TextField adressField;

    @FXML
    private TableView<CarReservation> reportResults2;

    //connection to services
    private CarDealership carDealership;

    public CarDealershipController(){}

    public void setDealership(CarDealership dealership){
        this.carDealership=dealership;
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
    public void delCarHandler(ActionEvent actionEvent) {
        String brand=carBrand.getText();
        String model=carModel.getText();
        String price=carPrice.getText();
        String year=carYear.getText();
        if (checkString(brand)&&checkString(model)&&checkString(price)&&checkString(year)){
            try {
                if(carDealership.delCar(brand,model,Integer.parseInt(price),Integer.parseInt(year))==1)
                    showNotification("Car successfully deleted! ", Alert.AlertType.INFORMATION);
                else
                    showNotification("Car was not deleted! ", Alert.AlertType.INFORMATION);
            }catch(DealershipException ex){
                showNotification(ex.getMessage(), Alert.AlertType.ERROR);
            }
        }
        else
            showNotification("You have to fill in all the fields! ", Alert.AlertType.ERROR);
    }
    @FXML
    public void addCarHandler(ActionEvent actionEvent) {
        String brand=carBrand.getText();
        String model=carModel.getText();
        String price=carPrice.getText();
        String year=carYear.getText();
        if (checkString(brand)&&checkString(model)&&checkString(price)&&checkString(year)){
            try {
                int id = carDealership.addCar(brand,model,Integer.parseInt(price),Integer.parseInt(year));
                carID.setText("Request identification number is " + id);
                showNotification("Car successfully added! ", Alert.AlertType.INFORMATION);
            }catch(DealershipException ex){
                showNotification(ex.getMessage(), Alert.AlertType.ERROR);
            }
        }
        else
            showNotification("You have to fill in all the fields! ", Alert.AlertType.ERROR);
    }

    @FXML
    public void updateCarHandler(ActionEvent actionEvent) {
        int selectedCar=reportResults.getSelectionModel().getSelectedIndex();
        if (selectedCar<0){
            showNotification("You must select a car first! ", Alert.AlertType.ERROR);
            return;
        }
        String brand=carsBrand.getText();
        String model=carsModel.getText();
        String price=carsPrice.getText();
        String year=carsYear.getText();
        if (checkString(brand)&&checkString(model)&&checkString(price)&&checkString(year)){
            try {
                Car car = reportResults.getItems().get(selectedCar);
                //System.out.println(reportResults.getItems().get(selectedCar).getID());
                car.setID(reportResults.getItems().get(selectedCar).getID());
                if(car.getStatus()== ReservationStatus.NotReserved)
                    carDealership.updateCar(brand,model,Integer.parseInt(price),Integer.parseInt(year),car.getID(),1);
                else
                {
                    carDealership.updateCar(brand,model,Integer.parseInt(price),Integer.parseInt(year),car.getID(),0);
                }
                showNotification("Car successfully updated! ", Alert.AlertType.INFORMATION);
                List<Car> results=carDealership.getAllCars();
                reportResults.getItems().clear();
                reportResults.getItems().addAll(results);
            }catch(DealershipException ex){
                showNotification(ex.getMessage(), Alert.AlertType.ERROR);
            }
        }
        else
            showNotification("You have to fill in all the fields! ", Alert.AlertType.ERROR);
    }
    @FXML
    public void delCarHandler2(ActionEvent actionEvent) {
        int selectedCar=reportResults.getSelectionModel().getSelectedIndex();
        if (selectedCar<0){
            showNotification("You must select a car first! ", Alert.AlertType.ERROR);
            return;
        }
        try {
            Car car = reportResults.getItems().get(selectedCar);
            car.setID(reportResults.getItems().get(selectedCar).getID());
            if(carDealership.delCar(car.getBrand(),car.getModel(),car.getPrice(),car.getYear())==1)
                showNotification("Car successfully deleted! ", Alert.AlertType.INFORMATION);
            else
                showNotification("Car was not deleted! ", Alert.AlertType.INFORMATION);
            reportResults.getItems().remove(selectedCar);
        }catch(DealershipException ex){
            showNotification(ex.getMessage(), Alert.AlertType.ERROR);
        }
    }

    @FXML
    public void addCarReservationHandler(ActionEvent actionEvent) {
        //System.out.println("Add repaired button pressed ..."+repairDate.getValue().format(dateFormatter));
        int selectedCar=carResults.getSelectionModel().getSelectedIndex();
        if (selectedCar<0){
            showNotification("You must select a car first! ", Alert.AlertType.ERROR);
            return;
        }
        String name=ownerName.getText();
        String adress=ownerAdress.getText();
        String rentDay=rentDate.getValue().format(dateFormatter);
        if (checkString(name)&&checkString(adress)&&checkString(rentDay)){
            try{
                //double price=Double.parseDouble(priceVal);
                Car car=carResults.getItems().get(selectedCar);
                carDealership.addCarReservation(name,adress,car,rentDay);
                carResults.getItems().remove(selectedCar);
                clearRepairedFormFields();
                showNotification("Car Reservation successfully added! ", Alert.AlertType.INFORMATION);
            }catch (NumberFormatException ex){
                showNotification("The price must be a number! ", Alert.AlertType.ERROR);
                return;
            }catch (DealershipException ex){
                showNotification(ex.getMessage(), Alert.AlertType.ERROR);
            }
        }

    }
    @FXML
    public void delResHandler(ActionEvent actionEvent) {
        int selectedRes=reportResults2.getSelectionModel().getSelectedIndex();
        if (selectedRes<0){
            showNotification("You must select a car first! ", Alert.AlertType.ERROR);
            return;
        }
        try {
            CarReservation res = reportResults2.getItems().get(selectedRes);
            res.setID(reportResults2.getItems().get(selectedRes).getID());
            if(carDealership.delRes(res.getOwnerName(), res.getAdress(),res.getDate(),res.getCar().getID())==1)
                showNotification("Reservation successfully deleted! ", Alert.AlertType.INFORMATION);
            else
                showNotification("Reservation was not deleted! ", Alert.AlertType.INFORMATION);
            reportResults2.getItems().remove(selectedRes);
        }catch(DealershipException ex){
            showNotification(ex.getMessage(), Alert.AlertType.ERROR);
        }
    }
    private void clearRepairedFormFields() {
        ownerName.setText("");
        ownerAdress.setText("");
    }

    @FXML
    public void searchCarHandler(ActionEvent actionEvent) {
        String searchModel=rezModel.getText();
        if (!checkString(searchModel)) {
            showNotification("You must introduce a brand! ", Alert.AlertType.ERROR);
            return;
        }
        List<Car> results=carDealership.getNotReservedCarsByBrand(searchModel);
        carResults.getItems().clear();
        carResults.getItems().addAll(results);
    }
    @FXML
    public void refreshCarHandler(ActionEvent actionEvent) {
        List<Car> results=carDealership.getAllCars();
        reportResults.getItems().clear();
        reportResults.getItems().addAll(results);
    }
    public void refreshCarReservationHandler(ActionEvent actionEvent) {
        List<CarReservation> results=carDealership.getAllReservations();
        reportResults2.getItems().clear();
        reportResults2.getItems().addAll(results);
    }
    @FXML
    public void clearFieldsHandler(ActionEvent actionEvent) {
        carYear.setText("");
        carPrice.setText("");
        carModel.setText("");
        carBrand.setText("");
        carID.setText("");
    }
    @FXML
    public void reportHandler(ActionEvent actionEvent) {
        String dateValue=reportDate.getValue().format(dateFormatter);
        System.out.println(dateValue+" date");
        //System.out.println(Integer.parseInt(dateValue));
        List<CarReservation> reportResultList=carDealership.getCarsDate(dateValue);
        List<Car> cars=new ArrayList<>();
        for(CarReservation e:reportResultList)
        {
            cars.add(e.getCar());
            System.out.println(e.getCar());
        }
        dateResults.getItems().clear();
        dateResults.getItems().addAll(cars);
    }
    @FXML
    public void priceHandler(ActionEvent actionEvent){
        String priceValue=priceField.getText();
        if (!checkString(priceValue)) {
            showNotification("You must introduce a price! ", Alert.AlertType.ERROR);
            return;
        }
        List<Car> cars = carDealership.getCarsPrice(Integer.parseInt(priceValue));
        priceResults.getItems().clear();
        priceResults.getItems().addAll(cars);
    }
    @FXML
    public void adressHandler(ActionEvent actionEvent){
        String adressValue=adressField.getText();
        if (!checkString(adressValue)) {
            showNotification("You must introduce an adress! ", Alert.AlertType.ERROR);
            return;
        }
        List<CarReservation> cars = carDealership.getReservationAdress(adressValue);
        adressResults.getItems().clear();
        adressResults.getItems().addAll(cars);
    }

}
