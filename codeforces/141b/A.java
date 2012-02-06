import java.util.*;

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/

public class A
{
  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    int a = in.nextInt(), x = in.nextInt(), y = in.nextInt();
    if (y <= 0 || y % a == 0) {
      System.out.println(-1);
      System.exit(0);
    }
    int res;
    if (y < a) {
      res = (x * 2 < a && x * 2 > -a) ? 1 : -1;
    } else {
      y -= a;
      int n = y / (2 * a), m = y % (2 * a);
      int k = n * 3 + 2;
      if (m < a) {
        res = (x * 2 < a && x * 2 > -a) ? k : -1;
      } else {
        if (x >= a || x <= -a || x == 0) {
          res = -1;
        } else {
          res =  (x < 0) ? k + 1 : k + 2;
        } 
      }
    }
    System.out.println(res);
  }
}
