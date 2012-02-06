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
    StringBuilder sb = new StringBuilder();
    int cur = 1;
    while (cur < 200000) {
      sb.append(cur);
      ++cur;
    }
    int k = 1, res = 1;
    while (k <= 1000000) {
      res *= sb.charAt(k - 1) - '0';
      k *= 10;
    }
    System.out.println(res);
  }
}
