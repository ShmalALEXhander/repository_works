object IntHelper {
  implicit class IsPrimeMethod(val x: Int) extends AnyVal {
    def isPrime: Boolean = {
      if (x <= 1) false
      else if (x == 2) true
      else !(2 to Math.sqrt(x).toInt).exists(x % _ == 0)
    }
  }

  def gcd(a: Int, b: Int): Int = if (b == 0) a.abs else gcd(b, a % b)

  def isCoprime(a: Int, b: Int): Boolean = gcd(a, b) == 1

  def FuncYiler(x: Int): Int = (1 to x).count(isCoprime(x, _))

  def primeFact(x: Int): List[Int] = {
    def factors(n: Int, divisor: Int = 2): List[Int] = n match {
      case 1 => Nil
      case x if x % divisor == 0 => divisor :: factors(x / divisor, divisor)
      case x => factors(x, divisor + 1)
    }
    factors(x)
  }

  def PrimesInRange(r: Range): List[Int] = r.filter(_.isPrime).toList

  def goldhub(x: Int): (Int,Int) = {
    val primes = 2 to x-1 filter (_.isPrime)
    primes.find(p => (x - p).isPrime) match {
      case Some(p) => (p, x - p)
      case None    => throw new IllegalArgumentException("No such pair found")
    }
  }
}
object Main extends App {
  import IntHelper._

  val num5 = 126
  println(s"Простые множители числа $num5: ${primeFact(num5)}")

  val range = 7 to 31
  println(s"Простые числа в диапазоне $range: ${PrimesInRange(range)}")

  val num6 = 28
  println(s"Простые числа, дающие в сумме число $num6: ${goldhub(num6)}")

  val num1 = 7
  println(s"$num1 - Простое число? ${num1.isPrime}")

  val num2a = 56
  val num2b = 16
  println(s"НОД чисел $num2a и $num2b : ${gcd(num2a, num2b)}")

  val num3a = 35
  val num3b = 64
  println(s"$num3a и $num3b - взаимно просты? ${isCoprime(num3a, num3b)}")

  val num4 = 10
  println(s"Функция Эйлера числа $num4: ${FuncYiler(num4)}")

}