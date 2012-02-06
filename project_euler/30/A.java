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
    long res = 0;
    for (int i = 2; i <= 1e6; ++i) {
      if (check(i)) {
        res += i;
      }
    }
    System.out.println(res);
  }

  public static boolean check(int n) {
    List<Integer> a = array(n);
    int sum = 0;
    for (int x : a) {
      sum += Math.pow(x, 5);
    }
    return sum == n;
  }

  public static List<Integer> array(int n) {
    List<Integer> list = new ArrayList<Integer>();
    while (n > 0) {
      list.add(n % 10);
      n /= 10;
    }
    return list;
  }
}
