package main.models;

import java.util.function.UnaryOperator;

public class FunctionGraph {
    private double[] x;
    private double[] y;

    public double fromX;
    public double toX;
    public double step;
    public String label;
    public int width;
    public UnaryOperator<Double> function;
    public int id;
    public boolean isVisible;
    public String color;

    public FunctionGraph(
        int id,
        double fromX,
        double toX,
        double step,
        UnaryOperator<Double> function,
        String label,
        int width,
        boolean isVisible,
        String color
    ) {
        this.id = id;
        this.fromX = fromX;
        this.toX = toX;
        this.step = step;
        this.function = function;
        this.label = label;
        this.width = width;
        this.isVisible = isVisible;
        this.color = color;

        this.calculate();
    }

    public void calculate() {
        int n = (int) ((this.toX - this.fromX) / this.step);
        this.x = new double[n];
        this.y = new double[n];
        for (int i = 0; i < n; i++) {
            this.x[i] = this.fromX + i * this.step;
            this.y[i] = this.function.apply(this.x[i]);
        }
    }

    public double[] getX() {
        return this.x;
    }

    public double[] getY() {
        return this.y;
    }
}
