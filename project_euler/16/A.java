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
    BigInteger x = BigInteger.ONE, two = new BigInteger("2");
    for (int i = 1; i <= 1000; ++i) {
      x = x.multiply(two);
    }
    System.out.println(x);
    int res = 0;
    while (!x.equals(BigInteger.ZERO)) {
      res += x.mod(BigInteger.TEN).intValue();
      x = x.divide(BigInteger.TEN);
    }
    System.out.println(res);
  }
}
