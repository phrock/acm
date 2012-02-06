import java.util.List;
import java.util.ArrayList;
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
    int p = 1, q = 1;
    for (int i = 10; i <= 99; ++i) {
      if (i % 10 == 0) {
        continue;
      }
      for (int j = 10; j < i; ++j) {
        if (j % 10 == 0) {
          continue;
        }
        int a = j / 10, b = j % 10, c = i / 10, d =i % 10;
        if (a == c && check(j, i, b, d) ||
            a == d && check(j, i, b, c) ||
            b == c && check(j, i, a, d) ||
            b == d && check(j, i, a, c)) {
          p *= j;
          q *= i;
        }
      }
    }

    int g = BigInteger.valueOf(p).gcd(BigInteger.valueOf(q)).intValue();
    System.out.println(q / g);
  }

  public static boolean check(int x, int y, int p, int q) {
    return x * q == y * p;
  }
}
