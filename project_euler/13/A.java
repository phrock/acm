import java.util.Scanner;
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
    Scanner in = new Scanner(System.in);
    BigInteger sum = BigInteger.ZERO;
    while (in.hasNext()) {
      String s = in.next();
      sum = sum.add(new BigInteger(s));
    }
    System.out.println(sum);
    String res = sum.toString().substring(0, 10);
    System.out.println(res);
  }
}
