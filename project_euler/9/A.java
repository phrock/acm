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
    for (int i = 1; i < 1000; ++i) {
      for (int j = i; j < 1000; ++j) {
        int k = 1000 - i - j;
        if (k < j) {
          break;
        }
        if (i + j > k && i * i + j * j == k * k) {
          System.out.println(i + " " + j + " " + k);
          System.out.println(i * j * k);
        }
      }
    }
  }
}
