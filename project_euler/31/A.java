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
    int[] a = {1, 2, 5, 10, 20, 50, 100,200};
    int[] dp = new int[205];
    dp[0] = 1;
    for (int x : a) {
      for (int i = 1; i <= 200; ++i) {
        if (i >= x) {
          dp[i] += dp[i - x];
        }
      }
    }
    System.out.println(dp[200]);
  }
}
