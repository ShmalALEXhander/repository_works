object Logic {

  def main(args: Array[String]): Unit = {
    val logicMenu = Map(
      1 -> "Логическое отрицание",
      2 -> "Логическое И",
      3 -> "Логическое ИЛИ",
      4 -> "Логическое НЕ И",
      5 -> "Логическое исключающее ИЛИ",
      6 -> "Операция импликации",
      7 -> "Логическая эквивалентность"
    )
    println("Выберите функцию для применения:")
    logicMenu.foreach { case (key, value) =>
      println(s"$key. $value")
    }

    val choice = scala.io.StdIn.readInt()
    val logicFunction: PartialFunction[(Boolean, Boolean), Boolean] = choice match {
      case 1 => { case (a, _) => not(a) }
      case 2 => { case (a, b) => and(a, b) }
      case 3 => { case (a, b) => or(a, b) }
      case 4 => { case (a, b) => nand(a, b) }
      case 5 => { case (a, b) => xor(a, b) }
      case 6 => { case (a, b) => impl(a, b) }
      case 7 => { case (a, b) => equ(a, b) }
      case _ => throw new IllegalArgumentException("Неверный выбор.")
    }

    println("Введите значения A и B (true/false):")
    val a = scala.io.StdIn.readBoolean()
    val b = scala.io.StdIn.readBoolean()

    val result = logicFunction(a, b)
    println(s"Результат: $result")
  }

  def not(a: Boolean): Boolean = !a

  def and(a: Boolean, b: Boolean): Boolean = a && b

  def or(a: Boolean, b: Boolean): Boolean = a || b

  def nand(a: Boolean, b: Boolean): Boolean = !(a && b)

  def xor(a: Boolean, b: Boolean): Boolean = a ^ b

  def impl(a: Boolean, b: Boolean): Boolean = !a || b

  def equ(a: Boolean, b: Boolean): Boolean = a == b

}