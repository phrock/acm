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
    Scanner sc = new Scanner(System.in);
    Long n = sc.nextLong();
    Long m = sc.nextLong();
    Long a = sc.nextLong();
    Long res = ((n + a - 1) / a) * ((m + a - 1) / a);
    System.out.println(res);
  }
}
