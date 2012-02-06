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
    int res = 0;
    for (int i = 1; i < a.length; ++i) {
      for (int j = 1; j < i; ++j) {
        if (i % j == 0) {
          a[i] += j;
        }
      }
    }
    for (int i = 1; i < a.length; ++i) {
      if (a[i] < a.length && i != a[i] && i == a[a[i]]) {
        res += i;
      }
    }
    System.out.println(res);
  }
  public static int[] a = new int[10000];
}
