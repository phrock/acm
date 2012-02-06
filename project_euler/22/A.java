import java.util.Scanner;
import java.util.Arrays;

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
    String[] a = in.next().split("[\",]");
    Arrays.sort(a);
    // System.out.println(Arrays.toString(a));
    int idx = 0;
    long res = 0;
    for (String s : a) {
      if (s.isEmpty()) {
        continue;
      }
      long sum = 0;
      for (int i = 0; i < s.length(); ++i) {
        sum += s.charAt(i) - 'A' + 1;
      }
      res += sum * ++idx;
    }
    System.out.println(res);
  }
}
