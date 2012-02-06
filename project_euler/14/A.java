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
    Long res = 1L, max = 1L;
    m.put(res, max);
    for (Long i = 1L; i < 1e6; ++i) {
      Long path = findPath(i);
      if (path > max) {
        max = path;
        res = i;
      }
    }
    System.out.println(res + " : " + max);
  }

  private static Map<Long, Long> m = new HashMap<Long, Long>();

  public static Long findPath(Long n) {
    if (m.containsKey(n)) {
      return m.get(n);
    }
    Long res;
    if (n % 2 == 0) {
      res = 1 + findPath(n / 2);
    } else {
      res = 1 + findPath(3 * n + 1);
    }
    if (n < 1e5) {
      m.put(n, res);
    }
    return res;
  }
}
