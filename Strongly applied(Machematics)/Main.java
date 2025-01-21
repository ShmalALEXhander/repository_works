package main;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import java.util.Random;

public class App extends Application {
    private enum PrimitiveType { LINE, CIRCLE, ELLIPSE, RECTANGLE }

    private PrimitiveType currentPrimitiveType;
    private double x, y, width, height;
    private boolean isDragging = false;

    @Override
    public void start(Stage primaryStage) {
        Random random = new Random();
        int randomType = random.nextInt(4);
        currentPrimitiveType = PrimitiveType.values()[randomType];

        x = 100;
        y = 100;
        width = 100;
        height = 100;

        Canvas canvas = new Canvas(800, 600);
        GraphicsContext gc = canvas.getGraphicsContext2D();

        primaryStage.widthProperty().addListener((obs, oldVal, newVal) -> draw(gc));
        primaryStage.heightProperty().addListener((obs, oldVal, newVal) -> draw(gc));

        canvas.setOnKeyPressed(e -> {
            if (e.getCode() == KeyCode.RIGHT) {
                x += 10;
                draw(gc);
            } else if (e.getCode() == KeyCode.LEFT) {
                x -= 10;
                draw(gc);
            } else if (e.getCode() == KeyCode.UP) {
                y -= 10;
                draw(gc);
            } else if (e.getCode() == KeyCode.DOWN) {
                y += 10;
                draw(gc);
            } else if (e.getCode() == KeyCode.NUMPAD8) {
                height += 10;
                draw(gc);
            } else if (e.getCode() == KeyCode.NUMPAD2) {
                height -= 10;
                draw(gc);
            } else if (e.getCode() == KeyCode.NUMPAD4) {
                width -= 10;
                draw(gc);
            } else if (e.getCode() == KeyCode.NUMPAD6) {
                width += 10;
                draw(gc);
            }
        });

        canvas.setOnMousePressed(e -> {
            if (e.getX() >= x && e.getX() <= x + width && e.getY() >= y && e.getY() <= y + height) {
                isDragging = true;
            }
        });

        canvas.setOnMouseReleased(e -> isDragging = false);

        canvas.setOnMouseDragged(e -> {
            if (isDragging) {
                x = e.getX() - width / 2;
                y = e.getY() - height / 2;
                draw(gc);
            }
        });

        Pane root = new Pane(canvas);
        Scene scene = new Scene(root, 800, 600);
        primaryStage.setScene(scene);

 
        canvas.requestFocus();

        primaryStage.setTitle("Resizable Primitive App");
        primaryStage.show();

        draw(gc);
    }

    private void draw(GraphicsContext gc) {
        gc.clearRect(0, 0, gc.getCanvas().getWidth(), gc.getCanvas().getHeight());

        switch (currentPrimitiveType) {
            case LINE:
                gc.setStroke(Color.BLACK);
                gc.strokeLine(x, y, x + width, y + height);
                break;
            case CIRCLE:
                gc.setFill(Color.LIGHTBLUE);
                gc.fillOval(x, y, width, height);
                break;
            case ELLIPSE:
                gc.setFill(Color.LIGHTGREEN);
                gc.fillOval(x, y, width, height);
                break;
            case RECTANGLE:
                gc.setFill(Color.LIGHTCORAL);
                gc.fillRect(x, y, width, height);
                break;
        }

        // Рисуем рамку
        gc.setStroke(Color.BLACK);
        gc.setLineDashes(5);
        gc.strokeRect(x, y, width, height);
    }

    public static void main(String[] args) {
        launch(args);
    }
}