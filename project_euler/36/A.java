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
    int sum = 0;
    for (int i = 1; i < 1000000; ++i) {
      if (isPalindromic(Integer.toString(i)) &&
          isPalindromic(Integer.toBinaryString(i))) {
        sum += i;
      }
    }
    System.out.println(sum);
  }

  public static boolean isPalindromic(String s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
      if (s.charAt(left) != s.charAt(right)) {
        return false;
      }
      ++left;
      --right;
    }
    return true;
  }
}
