<%@ page import="homebook.Bookstore" %>
<!DOCTYPE html>
<html>
<head>
    <title>Удалить книгу</title>
</head>
<body>
<h2>Удалить книгу</h2>

<% List<Bookstore> books = (List<Bookstore>) request.getAttribute("getBooks").getBooks(); %>

<% if (Bookstore.isEmpty()) { %>
<p>Книг нет.</p>
<% } else { %>
<form action="BookServlet" method="post">
    <input type="hidden" name="action" value="delete">
    <label for="bookToDelete">Выбрать видео для удаления:</label>
    <select name="bookToDelete" id="bookToDelete" required>
        <% for (Bookstore bookstore : book) { %>
        <option value="<%= book.getTitle() %>"><%= book.getTitle() %></option>
        <% } %>
    </select>
    <br>
    <input type="submit" value="далить видео">
</form>
<% } %>

<br>
<a href="displayBook.jsp">Вернуться в раздел книг</a>
</body>
</html>
