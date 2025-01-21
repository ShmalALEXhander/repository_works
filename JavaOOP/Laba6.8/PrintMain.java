import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class PrintMain extends JFrame implements Runnable {

    private int x = 20;
    private int y = 20;
    private int startX = x;
    private MyCanvas canvas;

    private class MyCanvas extends JPanel {

        public MyCanvas() {
            setDoubleBuffered(true);
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.drawString("Hello world", x, y);
        }
    }

    public PrintMain() {
        setSize(600, 200);
        setBackground(Color.gray);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        canvas = new MyCanvas();
        JButton b1 = new JButton("Старт");
        b1.setLayout(null);
        b1.setLocation(20, 10);
        b1.setSize(100, 50);
        b1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                start();
            }
        });
        add(b1, BorderLayout.SOUTH);
        add(canvas, BorderLayout.CENTER);
    }
    public void start() {
        Thread t = new Thread(this);
        t.start();
    }

    public void run() {
        while (true) {
            x = x + 1;
            try {
                Thread.sleep(8);
            } catch (Exception e) {
            }
            if (x >= canvas.getWidth() - 100) {
                x = startX;
            }
            canvas.repaint();
        }
    }
}