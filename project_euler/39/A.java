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
    int n = 1000;
    int[] array = new int[n + 5];
    for (int i = 1; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (i + j > n) {
          break;
        }
        for (int k = j; k < n; ++k) {
          if (i + j + k > n) {
            break;
          }
          if (i + j > k && i * i + j * j == k * k) {
            ++array[i + j + k];
          }
        }
      }
    }
    int res = 0, max = 0;
    for (int i = 1; i <= n; ++i) {
      if (array[i] > max) {
        max = array[i];
        res = i;
      }
    }
    System.out.println(res);
  }
}
