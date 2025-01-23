<%@ page import="main.java.homebook.Bookstore" %>
<%@ page import="java.util.List" %>
<%@ page import="homebook.Bookstore" %>

<!DOCTYPE html>
<html>
<head>
    <title>Список книг</title>
</head>
<body>
<h2>Список книг</h2>

<% List<Bookstore> bookstores = (List<Bookstore>) request.getAttribute("getBooks").getBooks(); %>

<% if (Bookstore.isEmpty()) { %>
<p>Книг нет.</p>
<% } else { %>
<table border="1">
    <tr>
        <th>Title</th>
        <th>Genre</th>
        <th>Author</th>
    </tr>

    <% for (Bookstore bookstore : book) { %>
    <tr>
        <td><%= book.getTitle() %></td>
        <td><%= book.getGenre() %></td>
        <td><%= book.getAuthor() %></td>
    </tr>
    <% } %>
</table>
<% } %>

<br>
<a href="addBookForm.jsp">Добавить книгу</a>
<br>
<a href="editBookForm.jsp">Редактировать книгу</a>
<br>
<a href="deleteBookForm.jsp">Удалить книгу</a>
</body>
</html>
