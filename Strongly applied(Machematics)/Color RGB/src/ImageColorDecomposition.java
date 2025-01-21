import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

public class ImageColorDecomposition {
    public static void main(String[] args) {
        try {
            BufferedImage image = ImageIO.read(new File("C:\\Users\\Александр\\Desktop\\RGB_svg.bmp"));
            int width = image.getWidth();
            int height = image.getHeight();

            BufferedImage redChannel = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
            BufferedImage greenChannel = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
            BufferedImage blueChannel = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);


            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    int rgb = image.getRGB(x, y);
                    int red = (rgb >> 16) & 0xFF;
                    int green = (rgb >> 8) & 0xFF;
                    int blue = rgb & 0xFF;

                    int redRGB = (red << 16) | (0 << 8) | 0;
                    int greenRGB = (0 << 16) | (green << 8) | 0;
                    int blueRGB = (0 << 16) | (0 << 8) | blue;

                    redChannel.setRGB(x, y, redRGB);
                    greenChannel.setRGB(x, y, greenRGB);
                    blueChannel.setRGB(x, y, blueRGB);
                }
            }
            ImageIO.write(redChannel, "jpg", new File("C:\\Users\\Александр\\Desktop\\red_channel.jpg"));
            ImageIO.write(greenChannel, "jpg", new File("C:\\Users\\Александр\\Desktop\\green_channel.jpg"));
            ImageIO.write(blueChannel, "jpg", new File("C:\\Users\\Александр\\Desktop\\blue_channel.jpg"));

            System.out.println("Разложение цветного изображения выполнено успешно.");
        } catch (IOException e) {
            System.out.println("Ошибка при обработке изображения: " + e.getMessage());
        }
    }
}