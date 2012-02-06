import java.util.List;
import java.util.ArrayList;

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
    List<Integer> tmp = new ArrayList<Integer>();
    for (int i = 1; i < a.length; ++i) {
      for (int j = 1; j <= i / 2; ++j) {
        if (i % j == 0) {
          a[i] += j;
        }
      }
      if (a[i] > i) {
        tmp.add(i);
      }
    }
    // System.out.println(tmp);
    for (int x : tmp) {
      for (int y : tmp) {
        int z = x + y;
        if (z < b.length) {
          b[z] = 1;
        }
      }
    }
    int sum = 0;
    for (int i = 0; i < b.length; ++i) {
      if (b[i] == 0) {
        sum += i;
      }
    }
    System.out.println(sum);
  }
  public static int[] a = new int[30000];
  public static int[] b = new int[30000];
}
