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
    int n = 20;
    int[][] a = new int[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        a[i][j] = in.nextInt();
      }
    }
    // System.out.println(Arrays.deepToString(a));
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j >= 3) {
          int aux = 1;
          for (int k = 0; k < 4; ++k) {
            aux *= a[i][j - k];
          }
          res = Math.max(res, aux);
        }
        if (i >= 3) {
          int aux = 1;
          for (int k = 0; k < 4; ++k) {
            aux *= a[i - k][j];
            res = Math.max(res, aux);
          }
        }
        if (i >= 3 && j >= 3) {
          int aux = 1;
          for (int k = 0; k < 4; ++k) {
            aux *= a[i - k][j - k];
          }
          res = Math.max(res, aux);
        }
        if (i + 4 <= n && j >= 3) {
          int aux = 1;
          for (int k = 0; k < 4; ++k) {
            aux *= a[i + k][j - k];
          }
          res = Math.max(res, aux);
        }
      }
    }
    System.out.println(res);
  }
}
