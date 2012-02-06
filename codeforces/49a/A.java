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
    String s = in.nextLine().toUpperCase();
    String t = "AEIOUY";
    for (int i = s.length() - 1; i >= 0; --i) {
      char c = s.charAt(i);
      if (Character.isUpperCase(c)) {
        // String res = (t.indexOf(c) == -1 ? "NO" : "YES");
        if (t.indexOf(c) == -1)
          System.out.println("NO");
        else
          System.out.println("YES");
        System.exit(0);
      }
    }
  }
}
