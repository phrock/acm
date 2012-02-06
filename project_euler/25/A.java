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
    BigInteger a = BigInteger.ZERO, b = BigInteger.ONE, c = a.add(b);
    int idx = 2;
    while (c.toString().length() < 1000) {
      a = b;
      b = c;
      c = a.add(b);
      ++idx;
    }
    System.out.println(c);
    System.out.println(idx);
  }
}
