import java.util.Scanner;

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
    long n = in.nextLong(), d = in.nextLong(), m = in.nextLong(), l = in.nextLong(), cur = 0;
    while (cur < n * m) {
      cur += d;
      if (cur % m > l) {
        break;
      }
    }
    System.out.println(cur);
    
  }
}
