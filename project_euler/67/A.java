import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

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
    List<List<Integer>> a = new ArrayList<List<Integer>>();
    while (in.hasNextLine()) {
      String s = in.nextLine();
      if (s.isEmpty()) {
        break;
      }
      Scanner in2 = new Scanner(s);
      List<Integer> tmp = new ArrayList<Integer>();
      while (in2.hasNextInt()) {
        tmp.add(in2.nextInt());
      }
      a.add(tmp);
    }
    // System.out.println(a);
    int n = a.size();
    int[][] dp = new int[n][n];
    dp[0][0] = a.get(0).get(0);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (j == 0) {
          dp[i][j] = dp[i - 1][j] + a.get(i).get(j);
        } else if (j == i) {
          dp[i][j] = dp[i - 1][j - 1] + a.get(i).get(j);
        } else {
          dp[i][j] = Math.max(dp[i - 1][j - 1], dp[i - 1][j]) + a.get(i).get(j);
        }
      }
    }
    int res = 0;
    for (int x : dp[n - 1]) {
      res = Math.max(res, x);
    }
    System.out.println(res);
  }
}
