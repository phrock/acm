import java.util.Map;
import java.util.HashMap;

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
    int res = 0, max = 0;
    for (int i = 2; i < 1000; ++i) {
      int tmp = findCycle(i);
      if (tmp > max) {
        max = tmp;
        res = i;
      }
      System.out.println(i + " : " + tmp);
    }
    System.out.println(res + ": " + max);
  }
  public static int findCycle(int n) {
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    int x = 10, pos = 0;
    while (x > 0) {
      ++pos;
      x %= n;
      if (map.containsKey(x)) {
        return pos - map.get(x);
      } else {
        map.put(x, pos);
      }
      x *= 10;
    }
    return 0;
  }
}
