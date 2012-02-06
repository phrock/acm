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
    long n = 20;
    System.out.println(catlanNumber(n));
  }
  public static long catlanNumber(long n) {
    long res = 1;
    for (long i = 1; i <= n; ++i) {
      res *= 2 * n - i + 1;
      res /= i;
    }
    res /= n + 1;
    return res;
  }
}
