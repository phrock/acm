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
    int x = 0, y = 1;
    long sum = 0;
    while (y <= 4e6) {
      if (y % 2 == 0) {
        sum += y;
      }
      int nextY = x + y;
      x = y;
      y = nextY;
    }
    System.out.println(sum);
  }
}
