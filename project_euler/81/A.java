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
    int n = 80;
    int[][] a = new int[100][100], dp = new int[100][100];
    for (int i = 2; i <= n; ++i) {
      dp[0][i] = dp[i][0] = Integer.MAX_VALUE;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        a[i][j] = in.nextInt();
        dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
      }
    }
    System.out.println(dp[n][n]);
  }
}
