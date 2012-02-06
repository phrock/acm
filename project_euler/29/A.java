import java.util.HashSet;
import java.math.BigInteger;
import java.util.Set;

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
    Set<BigInteger> set = new HashSet<BigInteger>();
    for (int a = 2; a <= 100; ++a) {
      for (int b = 2; b <= 100; ++b) {
        set.add(BigInteger.valueOf(a).pow(b));
      }
    }
    System.out.println(set.size());
  }
}
