package homebook;

import homebook.Book;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import javax.xml.bind.Unmarshaller;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

@WebServlet("/bookServlet")
public class BookServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");

        try {
            String xmlFilePath = getServletContext().getRealPath("/WEB-INF/classes/books.xml");
            // Используем JAXB для демаршалинга (чтения из XML) данных из файла
            JAXBContext context = JAXBContext.newInstance(Bookstore.class, Book.class);

            Unmarshaller unmarshaller = context.createUnmarshaller();
            Bookstore bookstore = (Bookstore) unmarshaller.unmarshal(new File(xmlFilePath));

            // Получаем список книг
            List<Book> books = bookstore.getBooks();

            // Отправляем данные клиенту
            PrintWriter out = response.getWriter();
            out.println("<html><body>");
            out.println("<h1>Book List</h1>");

            for (Book book : books) {
                System.out.println("Title: " + book.getTitle());
                out.println("<p>Title: " + book.getTitle() + "</p>");
                out.println("<p>Author: " + book.getAuthor() + "</p>");
                out.println("<p>Genre: " + book.getGenre() + "</p>");
                out.println("<p>Price: $" + book.getPrice() + "</p>");
                out.println("<hr>");
            }

            out.println("</body></html>");

        } catch (JAXBException e) {
            e.printStackTrace();
            response.getWriter().println("Error reading XML file");
        }
    }
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String action = request.getParameter("action");

        try {
            if ("add".equals(action)) {
                addBook(request);
            } else if ("edit".equals(action)) {
                editBook(request);
            } else if ("delete".equals(action)) {
                deleteBook(request);
            }

            // Перенаправляем пользователя на страницу с книгами после операции
            response.sendRedirect("/bookServlet");

        } catch (JAXBException e) {
            e.printStackTrace();
            response.getWriter().println("Error processing request");
        }
    }
    private void addBook(HttpServletRequest request) throws JAXBException {
        String title = request.getParameter("title");
        String author = request.getParameter("author");
        String genre = request.getParameter("genre");
        double price = Double.parseDouble(request.getParameter("price"));

        // Создаем новую книгу
        Book newBook = new Book();
        newBook.setTitle(title);
        newBook.setAuthor(author);
        newBook.setGenre(genre);
        newBook.setPrice(price);


        Bookstore bookstore = getBookstore();
        List<Book> books = bookstore.getBooks();
        books.add(newBook);

        updateXmlFile(bookstore);
    }

    private void editBook(HttpServletRequest request) throws JAXBException {
        int id = Integer.parseInt(request.getParameter("id"));
        String title = request.getParameter("title");
        String author = request.getParameter("author");
        String genre = request.getParameter("genre");
        double price = Double.parseDouble(request.getParameter("price"));

        Bookstore bookstore = getBookstore();
        List<Book> books = bookstore.getBooks();

        // Находим книгу по ID
        for (Book book : books) {
            if (book.getTitle() == title) {
                // Обновляем данные книги
                book.setTitle(title);
                book.setAuthor(author);
                book.setGenre(genre);
                book.setPrice(price);
                break;
            }
        }

        // Сохраняем обновленный список в XML
        updateXmlFile(bookstore);
    }

    private void deleteBook(HttpServletRequest request) throws JAXBException {
        int title = Integer.parseInt(request.getParameter("title"));


        Bookstore bookstore = getBookstore();
        List<Book> books = bookstore.getBooks();


        books.removeIf(book -> book.getTitle() == title);


        updateXmlFile(bookstore);
    }

    private void updateXmlFile(Bookstore bookstore) throws JAXBException {

        String xmlFilePath = getServletContext().getRealPath("/WEB-INF/classes/books.xml");
        JAXBContext context = JAXBContext.newInstance(Bookstore.class, Book.class);
        Marshaller marshaller = context.createMarshaller();
        marshaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);


        marshaller.marshal(bookstore, new File(xmlFilePath));
    }


    private Bookstore getBookstore() throws JAXBException {
        String xmlFilePath = getServletContext().getRealPath("/WEB-INF/classes/books.xml");
        JAXBContext context = JAXBContext.newInstance(Bookstore.class, Book.class);
        Unmarshaller unmarshaller = context.createUnmarshaller();
        return (Bookstore) unmarshaller.unmarshal(new File(xmlFilePath));
    }

}
