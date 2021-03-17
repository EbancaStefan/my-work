package ctrl;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;

import static java.lang.String.valueOf;

public class MoneyController {
    @FXML
    private TextField leiField;

    @FXML
    private TextField euroField;

    @FXML
    private void convert(ActionEvent e)
    {
        try{
            double lei=Double.parseDouble(leiField.getText());
            double euro;
            euro = lei/4.8;
            euroField.setText(String.valueOf(euro));
        }catch (NumberFormatException ex){
            showErrorMessage("Eroare la introducerea datelor "+ex);
        }
        double lei = Double.parseDouble(leiField.getText());
        double euro;
        euro = lei/4.8;
        euroField.setText(String.valueOf(euro));
    }

    void showErrorMessage(String text){
        Alert message=new Alert(Alert.AlertType.ERROR);
        message.setTitle("ERROR");
        message.setContentText(text);
        message.showAndWait();
    }

}
