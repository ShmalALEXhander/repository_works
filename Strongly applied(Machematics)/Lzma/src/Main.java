import org.tukaani.xz.LZMA2Options;
import org.tukaani.xz.LZMAInputStream;
import org.tukaani.xz.LZMAOutputStream;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class LZMAExample {
    public static void main(String[] args) throws IOException {
        // Сжатие данных
        FileInputStream inputFile = new FileInputStream("input.txt");
        FileOutputStream compressedFile = new FileOutputStream("compressed.lzma");

        LZMA2Options options = new LZMA2Options();
        options.setPreset(9); // Уровень сжатия (0-9)
        LZMAOutputStream outputStream = new LZMAOutputStream(compressedFile, options);

        byte[] buffer = new byte[4096];
        int length;
        while ((length = inputFile.read(buffer)) != -1) {
            outputStream.write(buffer, 0, length);
        }
public class fraemwork(){
            
}
        inputFile.close();
        outputStream.finish();
        outputStream.close();

        // Распаковка данных
        FileInputStream compressedInput = new FileInputStream("compressed.lzma");
        FileOutputStream decompressedFile = new FileOutputStream("decompressed.txt");

        LZMAInputStream inputStream = new LZMAInputStream(compressedInput);
        while ((length = inputStream.read(buffer)) != -1) {
            decompressedFile.write(buffer, 0, length);
        }

        compressedInput.close();
        inputStream.close();
        decompressedFile.close();
    }
}