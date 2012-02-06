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
    int n = 80;
    int[][] a = new int[n + 5][n + 5], dp = new int[n + 5][n + 5];
    for (int i = 1; i <= n; ++i) {
      dp[0][i] = dp[n + 1][i] = Integer.MAX_VALUE / 2;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        a[i][j] = in.nextInt();
      }
    }
    for (int j = 1; j <= n; ++j) {
      for (int i = 1; i <= n; ++i) {
        dp[i][j] = dp[i][j - 1] + a[i][j];
      }
      for (int i = 1; i <= n; ++i) {
        dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + a[i][j]);
      }
      for (int i = n; i >= 1; --i) {
        dp[i][j] = Math.min(dp[i][j], dp[i + 1][j] + a[i][j]);
      }
    }
    int res = Integer.MAX_VALUE;
    for (int i = 1; i <= n; ++i) {
      res = Math.min(res, dp[i][n]);
    }
    System.out.println(res);
  }
}
