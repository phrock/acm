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
    BigInteger x = factorial(100);
    int res = 0;
    while (!x.equals(BigInteger.ZERO)) {
      res += x.mod(BigInteger.TEN).intValue();
      x = x.divide(BigInteger.TEN);
    }
    System.out.println(res);
  }
  public static BigInteger factorial(int n) {
    BigInteger res = BigInteger.ONE;
    for (int i = 1; i <= n; ++i) {
      res = res.multiply(BigInteger.valueOf(i));
    }
    return res;
  }
}
