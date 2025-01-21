import java.util.*;

public class LZW {
    public static List compress(String input) {
        Map dictionary = new HashMap<>();
        for (int i = 0; i < 256; i++) {
            dictionary.put("" + (char) i, i);
        }

        String current = "";
        List compressed = new ArrayList<>();
        for (char c : input.toCharArray()) {
            String currentPlusC = current + c;
            if (dictionary.containsKey(currentPlusC)) {
                current = currentPlusC;
            } else {
                compressed.add(dictionary.get(current));
                dictionary.put(currentPlusC, dictionary.size());
                current = "" + c;
            }
        }

        if (!current.equals("")) {
            compressed.add(dictionary.get(current));
        }

        return compressed;
    }

    public static String decompress(List compressed) {
        Map dictionary = new HashMap<>();
        for (int i = 0; i < 256; i++) {
            dictionary.put(i, "" + (char) i);
        }

        int dictSize = 256;
        String result = "" + (char)(int)compressed.remove(0);
        for (Object code : compressed) {
            String entry;
            if (dictionary.containsKey(code)) {
                entry = (String) dictionary.get(code);
            } else if (code == dictSize) {
                entry = result + result.charAt(0);
            } else {
                throw new IllegalArgumentException("Invalid compressed code: " + code);
            }

            result += entry;
            dictionary.put(dictSize++, result.charAt(0) + entry);
        }

        return result;
    }

    public static void main(String[] args) {
        String input = "ABABABABA";

// Сжатие
        List compressed = compress(input);
        System.out.println("Сжатый поток: " + compressed);

// Декомпрессия
        String decompressed = decompress(compressed);
        System.out.println("Декодированный текст: " + decompressed);
    }
}