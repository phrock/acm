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
    int res = 0;
    for (int i = 1; i < 100; ++i) {
      for (int j = 1; j < 100; ++j) {
        BigInteger a = BigInteger.valueOf(i);
        BigInteger x = a.pow(j);
        int sum = calculateSum(x);
        res = Math.max(res, sum);
        // System.out.println(x + " " + sum);
      }
    }
    System.out.println(res);
  }

  public static int calculateSum(BigInteger n) {
    int res = 0;
    while (!n.equals(BigInteger.ZERO)) {
      res += n.mod(BigInteger.TEN).intValue();
      n = n.divide(BigInteger.TEN);
    }
    return res;
  }
}
