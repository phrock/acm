import java.math.BigInteger;
import java.util.Arrays;

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/

public class B {
  public static void main(String[] args) {
    // int cur = 1;
    // while (true) {
    //   BigInteger res = func(cur++);
    //   System.out.println(cur + " : " + res);
    //   if (res.equals(BigInteger.ZERO)) {
    //     System.out.println(cur);
    //     break;
    //   }
    // }
    System.out.println(func(5));
    func(100000);
  }

  public static int func(int n) {
    int m = 1000000;
    int[] dp = new int[n + 1];
    dp[0] = 1;
    System.out.println(n);
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        dp[j] += dp[j - i];
        dp[j] %= m;
      }
      System.out.println(i + ": " + dp[n]);
    }
    return dp[n];
  }
}
