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
    int sum = 1;
    for (int i = 3; i <= 1001; ++i, ++i) {
      int k = i * i;
      for (int j = 0; j < 4; ++j) {
        sum += k;
        k -= i - 1;
      }
    }
    System.out.println(sum);
  }
}
