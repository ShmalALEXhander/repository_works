package main.controllers;

import main.models.FunctionGraph;
import main.models.MainModel;
import main.views.main.MainView;

import java.util.ArrayList;

public class MainController {
    private final MainModel model;
    public final MainView view;



    public MainController(MainModel model) {
        this.model = model;
        this.view = new MainView(this);

        this.model.addObserver(this.view);

        this.view.loaded();
    }

    public ArrayList<FunctionGraph> getGraphs() {
        return model.getGraphs();
    }



    public void setGraphVisible(int id, boolean isVisible) {
        model.setGraphVisible(id, isVisible);
    }

    public FunctionGraph getGraphic(int id) {
        return model.getGraphic(id);
    }

    public void setGraphWidth(int id, int width) {
        model.setGraphWidth(id, width);
    }

    public void setGraphToX(int id, double x) {
        model.setGraphToX(id, x);
    }

    public void setGraphFromX(int id, double x) {
        model.setGraphFromX(id, x);
    }
}
