import javax.swing.*;
import java.awt.*;

public class Example4 extends JFrame {
    private JPanel panel; //объявили как наследник
    public Example4() {
        super("Example4");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 300);
        panel = new JPanel() {
            public void paintComponent(Graphics g) {
                int w = getWidth(), h = getHeight();
                g.setColor(Color.WHITE);
                g.fillRect(0, 0, w - 1, h - 1);
                Graphics2D g2 = (Graphics2D) g;
                g2.setStroke(new BasicStroke(3)); // толщина линий - 3 пикселя
                int step = 15;
                g.setColor(Color.RED);
                for (int i = 3; i < w - step - 20; i += step) {
                    g.drawLine(i, i, i + step, i);
                    g.drawLine(i + step, i, i + step, i + step);
                }
                g.setColor(Color.ORANGE);
                for (int i = 3; i < w - step - 20; i += step) {
                    g.drawLine(i, i, i, i + step);
                    g.drawLine(i, i + step, i + step, i + step);
                }
            }
        };
        add(panel);
        setVisible(true);
    }

}
