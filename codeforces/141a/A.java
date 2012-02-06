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
    String a = in.next() + in.next(), b = in.next();
    char[] x = a.toCharArray(), y = b.toCharArray();
    Arrays.sort(x);
    Arrays.sort(y);
    System.out.println(Arrays.equals(x, y) ? "YES" : "NO");
  }
}
