import java.math.BigInteger;

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
    BigInteger x = new BigInteger("600851475143");
    BigInteger res = BigInteger.ZERO;
    for (BigInteger i = BigInteger.ONE; i.pow(2).compareTo(x) <= 0; i = i.add(BigInteger.ONE)) {
      if (x.mod(i).equals(BigInteger.ZERO)) {
        BigInteger p = x.divide(i);
        if (res.compareTo(p) < 0 && p.isProbablePrime(3)) {
          res = p;
          break;
        }
        if (res.compareTo(i) < 0 && i.isProbablePrime(3)) {
          res = i;
        }
      }
    }
    System.out.println(res);
  }
}
