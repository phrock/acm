import java.util.Scanner;
import java.util.Arrays;

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
    String s = in.next();
    String[] a = s.split("\\W+");
    // System.out.println(Arrays.toString(a));
    int res = 0;
    for (String x : a) {
      if (x.isEmpty()) {
        continue;
      }
      if (isTriangleNumber(stringToInt(x))) {
        ++res;
      }
    }
    System.out.println(res);
  }

  public static int stringToInt(String s) {
    int res = 0;
    for (char c : s.toCharArray()) {
      res += c - 'A' + 1;
    }
    return res;
  }

  public static boolean isTriangleNumber(int n) {
    return p[n] == 1;
  }

  private static int[] p;
  static {
    p = new int[1000];
    int idx = 1, cur = 2;
    while (idx < p.length) {
      p[idx] = 1;
      idx += cur;
      ++cur;
    }
  }
}
