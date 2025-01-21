case class Pos(x: Int, y: Int)
object RSimulator {
  def walk(position: Pos, commands: String): Pos = {
    commands.foldLeft(position)((pos, command) => move(pos, command))
  }
  private def move(position: Pos, command: Char): Pos = {
    command match {
      case 'G' => Pos(position.x, position.y + 1)
      case 'L' => Pos(position.x - 1, position.y)
      case 'R' => Pos(position.x + 1, position.y)
      case 'D' => Pos(position.x, position.y - 1)
      case _ => position
    }
  }
}

object Main extends App {
  val initialPosition = Pos(0, 0)

  while (true) {
    println("Введите команды для перемещения робота (G - вверх, L - поворот налево, R - поворот направо, D - вниз):")
    val commandsString = scala.io.StdIn.readLine().toUpperCase()

    val finalPosition = RSimulator.walk(initialPosition, commandsString)
    println(s"Конечное положение: (${finalPosition.x}, ${finalPosition.y})")
  }
}