import java.util.Scanner;

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
    int n = in.nextInt();
    int[] a = new int[7];
    for (int i = 0; i < 7; ++i) {
      a[i] = in.nextInt();
    }
    int idx = 0;
    while (true) {
      n -= Math.min(a[idx], n);
      if (n == 0) {
        break;
      }
      idx = (idx + 1) % 7;
    }
    System.out.println(idx + 1);
    
  }
}
