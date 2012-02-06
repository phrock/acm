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
    BigInteger m = BigInteger.TEN.pow(10);
    BigInteger res = BigInteger.ZERO;
    for (int i = 1; i <= 1000; ++i) {
      res = res.add(BigInteger.valueOf(i).modPow(BigInteger.valueOf(i), m)).mod(m);
    }
    System.out.println(res);
  }
}
