package Task4;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Task4 {
    private final JLabel coordinatesLabel;
    private Color color = Color.BLACK;

    public Task4() {
        JFrame frame = new JFrame("Координаты мыши");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel() {
            @Override
            public boolean isFocusable() {
                return true;
            }
        };

        coordinatesLabel = new JLabel("Нажмите на по области окна");
        coordinatesLabel.setFont(new Font("Arial", Font.BOLD, 16));
        coordinatesLabel.setForeground(color);
        panel.add(coordinatesLabel);

        frame.add(panel);
        frame.pack();
        frame.setSize(300, 300);
        frame.setVisible(true);
        panel.requestFocus();

        panel.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent event) {
                int x = event.getX();
                int y = event.getY();
                String coordinates = String.format("Координаты: (%d, %d)", x, y);
                coordinatesLabel.setText(coordinates);
                coordinatesLabel.setForeground(color);
            }
        });

        panel.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                switch (e.getKeyChar()) {
                    case 'b' -> color = Color.BLACK;
                    case 'w' -> color = Color.WHITE;
                    case 'r' -> color = Color.RED;
                    case 'g' -> color = Color.GREEN;
                    case 'o' -> color = Color.ORANGE;
                }
                coordinatesLabel.setForeground(color);
            }
        });
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Task4::new);
    }
}