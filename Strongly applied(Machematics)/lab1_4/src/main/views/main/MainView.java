package main.views.main;

import javafx.event.ActionEvent;
import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.chart.XYChart;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Circle;
import main.controllers.MainController;
import main.models.FunctionGraph;
import main.views.BaseView;

import java.util.ArrayList;


public class MainView extends BaseView {
    private final UiMain ui;
    private final MainController controller;

    public MainView(MainController controller) {
        var root = new VBox();
        scene = new Scene(root, 800, 600);

        this.controller = controller;

        this.ui = new UiMain(root);
        this.ui.setup_ui();

        // Регистрация событий
        this.ui.comboBoxGraph.setOnAction(this::currentGraphChanged);
        this.ui.isVisible.setOnAction(this::graphVisibleChanged);
        this.ui.fromX.setOnAction(this::graphFromXChanged);
        this.ui.toX.setOnAction(this::graphToXChanged);
        this.ui.width.setOnAction(this::graphWidthChanged);

    }

    private void graphWidthChanged(ActionEvent actionEvent) {
        controller.setGraphWidth(
            (int) this.ui.comboBoxGraph.getSelectionModel().getSelectedItem().getPayload(),
            Integer.parseInt(this.ui.width.getText())
        );
    }

    private void graphToXChanged(ActionEvent actionEvent) {
        controller.setGraphToX(
            (int) this.ui.comboBoxGraph.getSelectionModel().getSelectedItem().getPayload(),
            Double.parseDouble(this.ui.toX.getText())
        );
    }

    private void graphFromXChanged(ActionEvent actionEvent) {
        controller.setGraphFromX(
            (int) this.ui.comboBoxGraph.getSelectionModel().getSelectedItem().getPayload(),
            Double.parseDouble(this.ui.fromX.getText())
        );
    }

    private void graphVisibleChanged(ActionEvent actionEvent) {
        controller.setGraphVisible(
            (int) this.ui.comboBoxGraph.getSelectionModel().getSelectedItem().getPayload(),
            ui.isVisible.isSelected()
        );
    }

    private void currentGraphChanged(ActionEvent actionEvent) {
        modelChanged();
    }

    private void drawGraphic(FunctionGraph graph) {

        var series = new XYChart.Series<Number, Number>();
        series.setName(graph.label);
        for (int i = 0; i < graph.getX().length; i++) {
            series.getData().add(new XYChart.Data<>(graph.getX()[i], graph.getY()[i]));
        }
        ui.lineChart.getData().add(series);

        // Краска и стили
        Node line = series.getNode().lookup(".chart-series-line");
        line.setStyle("-fx-stroke: " + graph.color + ";");
        for (XYChart.Data<Number, Number> data : series.getData()) {
            Node point = data.getNode();
            point.setStyle(
                    "-fx-background-color: " + graph.color +
                            "; -fx-scale-x: " + graph.width +
                            "px; -fx-scale-y: " + graph.width + "px;"
            );
        }

        // Кастомный элемент легенды
        var legendColorShape = new Circle(10);
        legendColorShape.setFill(Paint.valueOf(graph.color));

        var legendLabel = new Label(graph.label);

        var legendItem = new HBox(legendColorShape, legendLabel);
        HBox.setMargin(legendItem, new javafx.geometry.Insets(10, 10, 20, 10));
        legendItem.setAlignment(Pos.CENTER);
        legendItem.setSpacing(5);

        ui.legendContainer.getChildren().add(legendItem);
    }

    public void modelChanged() {
        ui.lineChart.getData().clear();
        ui.legendContainer.getChildren().clear();

        var current = controller.getGraphic((int) this.ui.comboBoxGraph.getSelectionModel().getSelectedItem().getPayload());

        controller.getGraphs().stream()
                .filter(graph -> graph.id != current.id && graph.isVisible)
                .forEach(this::drawGraphic);

        if (current.isVisible) {
            drawGraphic(current);
        }

        this.ui.width.setText(String.valueOf(current.width));
        this.ui.isVisible.setSelected(current.isVisible);
        this.ui.fromX.setText(String.valueOf(current.fromX));
        this.ui.toX.setText(String.valueOf(current.toX));
    }

    public void loaded() {
        this.ui.comboBoxGraph.getItems().clear();
        for (var graph : controller.getGraphs()) {
            this.ui.comboBoxGraph.getItems().add(new ComboBoxItem(graph.label, graph.id));
        }
        this.ui.comboBoxGraph.getSelectionModel().select(0);
        modelChanged();

    }
}
