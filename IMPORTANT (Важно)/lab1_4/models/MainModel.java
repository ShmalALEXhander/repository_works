package main.models;


import main.utils.DObserver;

import java.util.ArrayList;
import java.util.function.UnaryOperator;

public class MainModel {

    private final ArrayList<Object> observers;

    private final ArrayList<FunctionGraph> graphs;

    public MainModel() {
        this.graphs = new ArrayList<>() {
            {
                add(new FunctionGraph(1, -3.14, 3.14, 0.1, Math::sin, "y(x) = sin(x)", 1, true, "red"));
                add(new FunctionGraph(2, -3.14, 3.14, 0.1, Math::cos, "y(x) = cos(x)", 1, true, "blue"));
                add(new FunctionGraph(3, -3.14, 3.14, 0.1, Math::exp, "y(x) = exp(x)", 1, true, "green"));
            }
        };
        this.observers = new ArrayList<>();
    }

    public ArrayList<FunctionGraph> getGraphs() {
        return this.graphs;
    }

    public FunctionGraph getGraphic(int id) {
        for (FunctionGraph graph : this.graphs) {
            if (graph.id == id) {
                return graph;
            }
        }
        return null;
    }


    public void setGraphFromX(int id, double fromX) {
        var graph = this.getGraphic(id);
        if (graph != null) {
            graph.fromX = fromX;
            graph.calculate();
        }
        this.notifyObservers();
    }

    public void setGraphToX(int id, double toX) {
        var graph = this.getGraphic(id);
        if (graph != null) {
            graph.toX = toX;
            graph.calculate();
        }
        this.notifyObservers();
    }

    public void setGraphStep(int id, double step) {
        var graph = this.getGraphic(id);
        if (graph != null) {
            graph.step = step;
            graph.calculate();
        }
        this.notifyObservers();
    }

    public void setGraphFunction(int id, UnaryOperator<Double> function) {
        var graph = this.getGraphic(id);
        if (graph != null) {
            graph.function = function;
            graph.calculate();
        }
        this.notifyObservers();
    }

    public void setGraphVisible(int id, boolean isVisible) {
        var graph = this.getGraphic(id);
        if (graph != null) {
            graph.isVisible = isVisible;
        }
        this.notifyObservers();
    }

    public void setGraphLabel(int id, String label) {
        var graph = this.getGraphic(id);
        if (graph != null) {
            graph.label = label;
        }
        this.notifyObservers();
    }

    public void setGraphWidth(int id, int width) {
        var graph = this.getGraphic(id);
        if (graph != null) {
            graph.width = width;
        }
        this.notifyObservers();
    }

    public void addObserver(DObserver observer) {
        this.observers.add(observer);
    }

    public void notifyObservers() {
        for (Object observer : this.observers) {
            ((DObserver) observer).modelChanged();
        }
    }

    public void removeObserver(DObserver observer) {
        this.observers.remove(observer);
    }

}
