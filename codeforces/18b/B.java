import java.util.Scanner;

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/

public class B {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    long n = in.nextLong(), d = in.nextLong(), m = in.nextLong(), l = in.nextLong(), cur = 0;
    int i;
    for (i = 0; i < m; ++i) {
      cur += d;
      if (cur % m > l || cur >= n * m) {
        break;
      }
    }
    if (i < m) {
      System.out.println(cur);      
    } else {
      System.out.println((n * m / d + 1) * d);
    }
  }
}
