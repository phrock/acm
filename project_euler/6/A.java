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
    int a = 0, b = 0;
    for (int i = 1; i <= 100; ++i) {
      a += i * i;
      b += i;
    }
    b *= b;
    System.out.println(b - a);
  }
}
