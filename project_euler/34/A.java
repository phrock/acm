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
    int[] factorial = new int[10];
    factorial[0] = 1;
    for (int i = 1; i < factorial.length; ++i) {
      factorial[i] = i * factorial[i - 1];
    }
    int sum = 0;
    for (int i = 10; i < 2000000; ++i) {
      int tmp = 0;
      for (int x : array(i)) {
        tmp += factorial[x];
      }
      if (tmp == i) {
        sum += i;
      }
    }
    System.out.println(sum);
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
