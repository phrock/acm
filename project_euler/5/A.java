import java.math.BigInteger;

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/

public class A {
  public static void main(String[] args) {
    BigInteger res = BigInteger.ONE;
    BigInteger x = BigInteger.ZERO;
    for (int i = 1; i <= 20; ++i) {
      x = x.add(BigInteger.ONE);
      res = res.multiply(x).divide(res.gcd(x));
      System.out.print(i + ": ");
      System.out.println(res);
    }
  }
}
