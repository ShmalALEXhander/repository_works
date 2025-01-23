package main.views.main;

import javafx.geometry.Pos;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.chart.LineChart;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.Priority;
import javafx.scene.paint.Color;

import java.security.cert.PolicyNode;


public class UiMain {

    private final VBox root;
    HBox legendContainer;
    LineChart<Number, Number> lineChart;

    ComboBox<ComboBoxItem> comboBoxGraph;
    TextField width;
    TextField fromX;
    TextField toX;
    CheckBox isVisible;

    UiMain(VBox root) { this.root = root; }

    void setup_ui() {

        // LineChart
        lineChart = new LineChart<Number, Number>(
            new javafx.scene.chart.NumberAxis(),
            new javafx.scene.chart.NumberAxis()
        );
        lineChart.setTitle("Графики");
        lineChart.setLegendVisible(false);
        root.getChildren().add(lineChart);

        // Legend
        legendContainer = new HBox();
        legendContainer.setAlignment(Pos.CENTER);
        legendContainer.setSpacing(10);
        root.getChildren().add(legendContainer);

        // Control

        var control_layout = new HBox();
        control_layout.setAlignment(Pos.CENTER);
        control_layout.setSpacing(10);
        root.getChildren().add(control_layout);

        var control_layout_left = new HBox();
        control_layout_left.setAlignment(Pos.CENTER);
        control_layout_left.setSpacing(20);

        var control_layout_right = new HBox();
        control_layout_right.setAlignment(Pos.CENTER);
        control_layout_right.setSpacing(20);

        control_layout.getChildren().addAll(control_layout_left, control_layout_right);

        // Выбор графика
        comboBoxGraph = new ComboBox<>();
        comboBoxGraph.setMinHeight(40);
        comboBoxGraph.setMinWidth(100);
        control_layout_left.getChildren().add(comboBoxGraph);

        // Ширина графика
        var widthLayout = new HBox();
        widthLayout.setAlignment(Pos.CENTER);
        control_layout_left.getChildren().add(widthLayout);

        var widthLabel = new Label("Ширина:");
        widthLabel.setMinHeight(40);
        widthLabel.setMinWidth(100);
        widthLabel.setFont(new javafx.scene.text.Font(20));

        width = new TextField();
        width.setMinHeight(40);
        width.setMinWidth(100);
        width.textProperty().addListener((observable, oldValue, newValue) -> {
            if (!newValue.matches("\\d*")) {
                width.setText(newValue.replaceAll("[^\\d]", ""));
            }
        });
        widthLayout.getChildren().addAll(widthLabel, width);

        // Область определения
        var definitionLayout = new VBox();
        definitionLayout.setAlignment(Pos.CENTER);
        control_layout_left.getChildren().add(definitionLayout);

        var fromXLayout = new HBox();
        fromXLayout.setAlignment(Pos.CENTER);
        fromXLayout.setSpacing(10);

        var fromXLabel = new Label("От:");
        fromXLabel.setFont(new javafx.scene.text.Font(20));

        fromX = new TextField();
        fromX.setMinHeight(40);
        fromX.setMaxWidth(100);
        fromX.textProperty().addListener((observable, oldValue, newValue) -> {
            try {
                Double.parseDouble(newValue);
            } catch (NumberFormatException e) {
                if (!newValue.equals("-") && !newValue.isEmpty())
                    fromX.setText(oldValue);
            }
        });
        fromX.setFont(new javafx.scene.text.Font(20));
        fromXLayout.getChildren().addAll(fromXLabel, fromX);

        var toXLayout = new HBox();
        toXLayout.setAlignment(Pos.CENTER);
        toXLayout.setSpacing(10);

        var toXLabel = new Label("До:");
        toXLabel.setFont(new javafx.scene.text.Font(20));

        toX = new TextField();
        toX.setMinHeight(40);
        toX.setMaxWidth(100);
        toX.textProperty().addListener((observable, oldValue, newValue) -> {
            try {
                Double.parseDouble(newValue);
            } catch (NumberFormatException e) {
                if (!newValue.equals("-") && !newValue.isEmpty())
                    toX.setText(oldValue);
            }
        });
        toX.setFont(new javafx.scene.text.Font(20));
        toXLayout.getChildren().addAll(toXLabel, toX);

        definitionLayout.getChildren().addAll(fromXLayout, toXLayout);


        // Видимость графика
        isVisible = new CheckBox("Видимость");
        isVisible.setFont(new javafx.scene.text.Font(20));
        control_layout_left.getChildren().add(isVisible);


    }
}


