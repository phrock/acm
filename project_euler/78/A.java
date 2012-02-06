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

public class A {
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
    func(55375);
  }

  public static BigInteger func(int n) {
    BigInteger m = BigInteger.valueOf(1000000);
    BigInteger[] dp = new BigInteger[n + 1];
    Arrays.fill(dp, BigInteger.ZERO);
    dp[0] = BigInteger.ONE;
    System.out.println(n);
    for (int i = 1; i <= n; ++i) {
      System.out.println(i);
      for (int j = 1; j <= n; ++j) {
        dp[j] = dp[j].add(j >= i ? dp[j - i] : BigInteger.ZERO);
      }
    }
    return dp[n];
  }
}
