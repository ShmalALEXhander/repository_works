package main.views;

import javafx.scene.Scene;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import main.controllers.MainController;
import main.utils.DObserver;

public abstract class BaseView extends DObserver {
    protected Scene scene;
    public Scene getScene() {
        return this.scene;
    }
}
