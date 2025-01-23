
<!DOCTYPE html>
<html>
<head>
    <title>Добавить книгу</title>
</head>
<body>
<h2>Добавить книгу</h2>

<form action="BookServlet" method="post">
    <input type="hidden" name="action" value="add">
    <label for="title">Title:</label>
    <input type="text" name="title" required>
    <br>
    <label for="genre">Genre:</label>
    <input type="text" name="genre" required>
    <br>
    <label for="author">Category:</label>
    <input type="text" name="category" required>
    <br>
    <input type="submit" value="Add Book">
</form>

<br>
<a href="displayBook.jsp">Посмотреть все книги</a>
</body>
</html>
