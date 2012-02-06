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
    for (int i = 100; i < 1000; ++i) {
      for (int j = i; j < 1000; ++j) {
        if (isPalindromic(Integer.toString(i * j))) {
          res = Math.max(res, i * j);
        }
      }
    }
    System.out.println(res);
  }

  public static boolean isPalindromic(String s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
      if (s.charAt(i) != s.charAt(j)) {
        return false;
      }
      ++i;
      --j;
    }
    return true;
  }
}
