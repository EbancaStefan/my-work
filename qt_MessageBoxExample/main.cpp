#include <QDebug>
#include <QMessageBox>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);

    int ret = msgBox.exec(); //  exec() slot returns the StandardButtons value of the button that was clicked

    // checking which button was pressed
    switch (ret) {
    case QMessageBox::Save:
        qDebug()<<"Save was pressed.";
        break;
    case QMessageBox::Discard:
        qDebug()<<"Don't save (discard) was pressed.";
        break;
    case QMessageBox::Cancel:
        qDebug()<<"Cancel was pressed.";
        break;
    default:
        // should never be reached
        break;
    }


    // QMessageBox severity levels
    // for all the STATIC methods below the parameters are the following:
    //      - the parent of the messagebox
    //      - the title of the message box
    //      - the text of the message box
    //      - the buttons to be displayed on the message box
    //      - the default selected button
    // QMessageBox::information: for reporting information about normal operations.
    QMessageBox::information(nullptr, "Success", "The item was succesfully added in the shopping chart!", QMessageBox::Ok);
    // QMessageBox::warning: For reporting non-critical errors.
    QMessageBox::warning(nullptr, "Warning!", "Three consecutive unsuccessful logins. You can try again 3 minutes.", QMessageBox::NoButton);
    // QMessageBox::question For asking a question during normal operations.
    QMessageBox::question(nullptr, "", "Are you sure you want to delete the selected item? ", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    // QMessageBox::critical: For reporting critical errors.
    QMessageBox::critical(nullptr, "Critical error!", "A critical error occured!", QMessageBox::Ok );

    return a.exec();
}
