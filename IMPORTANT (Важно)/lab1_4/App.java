package main;

import main.controllers.MainController;
import javafx.application.Application;
import javafx.stage.Stage;
import main.models.MainModel;

public class App extends Application {

    @Override
    public void start(Stage stage) {

        MainController main = new MainController(new MainModel());

        stage.setTitle("SupaApp");
        stage.setScene(main.view.getScene());
        stage.show();
    }

    public static void main(String[] args) {
        Application.launch(args);
    }
}