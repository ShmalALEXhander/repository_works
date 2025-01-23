package homebook;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class XmlExample {
    public static void main(String[] args) {
        try {
            // Создаем список книг
            List<Book> books = new ArrayList<>();
            Book book1 = new Book();
            book1.setTitle("The Catcher in the Rye");
            book1.setAuthor("J.D. Salinger");
            book1.setGenre("Fiction");
            book1.setPrice(19.99);
            books.add(book1);

            // Создаем объект Bookstore и устанавливаем список книг
            Bookstore bookstore = new Bookstore();
            bookstore.setBooks(books);

            // Используем JAXB для маршалинга в XML и сохранения в файл
            JAXBContext context = JAXBContext.newInstance(Bookstore.class);
            Marshaller marshaller = context.createMarshaller();
            marshaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);

            // Сохраняем в файл
            marshaller.marshal(bookstore, new File("books.xml"));

        } catch (JAXBException e) {
            e.printStackTrace();
        }
    }
}
