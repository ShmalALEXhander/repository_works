<%@ page import="main.java.homebook.Bookstore" %>
<%@ page import="java.util.List" %>
<%@ page import="homebook.Bookstore" %>

<!DOCTYPE html>
<html>
<head>
    <title>Редактировать книгу</title>
</head>
<body>
<h2>Редактировать книгу</h2>

<% List<Bookstore> books = (List<Bookstore>) request.getAttribute("getBooks").getBooks(); %>

<% if (Bookstore.isEmpty()) { %>
<p>Книг нет.</p>
<% } else { %>
<form action="BookServlet" method="post">
    <input type="hidden" name="action" value="edit">

    <label for="bookToEdit">Выбрать книгу для редактирования:</label>
    <select name="bookToEdit" id="bookToEdit" required>
        <% for (Bookstore bookstore : book) { %>
        <option value="<%= book.getTitle() %>"><%= book.getTitle() %></option>
        <% } %>
    </select>
    <br>

    <%
        String bookToEditTitle = (String) request.getAttribute("bookToEditTitle");
        if (bookToEditTitle != null) {
            Bookstore bookToEdit = null;
            for (Bookstore bookstore : book) {
                if (book.getTitle().equals(bookToEditTitle)) {
                    bookToEdit = book;
                    break;
                }
            }

            if (bookToEdit != null) {
    %>
    <label for="title">Title:</label>
    <input type="text" name="title" value="<%= bookToEdit.getTitle() %>" required>
    <br>
    <label for="genre">Genre:</label>
    <input type="text" name="genre" value="<%= bookToEdit.getGenre() %>" required>
    <br>
    <label for="author">Author:</label>
    <input type="text" name="author" value="<%= bookToEdit.getAuthor() %>" required>
    <br>
    <%
            }
        }
    %>

    <input type="submit" value="Редактировать книгу">
</form>
<% } %>

<br>
<a href="displayBook.jsp">Вернуться в просмотр книг</a>
</body>
</html>
