import scala.io.StdIn.readLine
import scala.util.control.Breaks
@main
def main(): Unit =
  //  Бинарное Дерево Поиска
  val tree = Node(5, End, End)
  //val updatedTree = tree.addValue(3).addValue(2).addValue(1).addValue(4).addValue(6)
  val loop = new Breaks;

  // 1 - Проверить на наличие узел
  // 2 - Добавить
  // 3 - удалить
  // 4 - Проверка на симметричность
  println("------Меню------")
  println("1 - Проверить на наличие узел")
  println("2 - Добавить элемент")
  println("3 - Удалить элемент")
  println("4 - Проверка на симметричность")
  println("5 - Нахождение минимального узла")
  println("ALL - Завершить работу")
  var updatedTree = tree
  loop.breakable({
    while(true) {

      val x = readLine().toInt
      val a = ""
      x match {
        case 1 =>
          println("Введи элемент для проверки -> ")
          val y = readLine(a).toInt
          println(updatedTree.find(y))
          println("Выбери действие")
        case 2 => {
          println("Введи элемент для добавления -> ")
          val y = readLine(a).toInt;
          updatedTree = updatedTree.addValue(y)
          println("Выбери действие")
        }
        case 3 =>
          println("Введи элемент для удаления -> ")
          val y = readLine(a).toInt
          updatedTree = updatedTree.remove(y)
          println("Выбери действие")
        case 4 =>
          println("Симметричность = ")
          print(updatedTree.isSymmetric)
          println("Выбери действие")
        case 5 =>
          println(updatedTree.min)
          println("Выбери действие")
        case _ => loop.break;
      }
    }
  })
  // println(updatedTree)
  // println(updatedTree.find(5).get)
  // println(updatedTree.find(3).get)
  // println(updatedTree.find(4).get)
  // println(updatedTree.find(6).get)

  // assert(updatedTree.find(6).isDefined, "Tree should contain 6")
  // assert(updatedTree.find(10).isEmpty, "Tree should not contain 10")

  // val treeWithRemovedElement = updatedTree.remove(6)
  // println(updatedTree)
  // assert(treeWithRemovedElement.find(6).isEmpty, "Tree should not contain 6 after removal")

  //val symmetricTree = Node(5, Node(3, End, End), Node(7, End, End))

  val symmetricTree1 = Node(
    5,
    Node(
      3,
      Node(2, End, End),
      Node(4, End, End)
    ),
    Node(
      3,
      Node(4, End, End),
      Node(2, End, End))
  )

  val symmetricTree2 = Node(
    5,
    Node(
      3,
      Node(4, End, End),
      Node(2, End, End)
    ),
    Node(
      3,
      Node(4, End, End),
      Node(2, End, End))
  )

  val symmetricTree3 = Node(
    5,
    Node(
      3,
      Node(5, End, End),
      Node(4, End, End)
    ),
    Node(
      7,
      Node(4, End, End),
      Node(5, End, End))
  )
  // assert(symmetricTree.isSymmetric, "Tree should be symmetric")
  println(symmetricTree1.isSymmetric)
  // assert(symmetricTree1.isSymmetric, "Tree should be symmetric")
  println(symmetricTree2.isSymmetric)
  println(symmetricTree3.isSymmetric)
//val updatedTree2 = tree.remove(2)
//println(updatedTree2)

