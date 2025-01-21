import java.awt.*;
import javax.swing.*;
public class Example1 {
    private JFrame frame;
    private JPanel panel;
    public Example1 () {
        frame = new JFrame("Func sin (x)");
        frame.setSize(314, 337);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        panel = new JPanel() { // внутренний класс-наследник JPanel
            @Override
            public void paintComponent(Graphics g) {
                int w = getWidth(), h = getHeight();
                int h1=h-10;
                g.setColor(Color.WHITE);
                Graphics2D g2 = (Graphics2D)g;
                g2.setStroke(new BasicStroke(2)); // толщина линий - 3 пикселя
                int size=300;
                double[] x=new double[size];
                double[] y=new double[size];
                double p = 3.141592;
                double step=(2*p)/(size-1);
                for(int i=0; i<size;i++) {
                    x[i]=-p+i*step;
                    y[i]=Math.sin(x[i]);
                }
                g.setColor(Color.BLACK);
                g.drawLine(0,h/2,w,h/2);
                g.drawLine(w/2,0,w/2, h);
                g.setColor(Color.ORANGE);
                for(int i=1;i<size;i++){
                    g.drawLine(i,(int)(h1/2-y[i-1]*(h1/2)+5), i, (int)(h1/2-y[i]*(h1/2)+5));
                }
            }
        };
        frame.add(panel);
        frame.setVisible(true);
    }
}
