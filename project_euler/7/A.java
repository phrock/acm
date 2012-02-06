import java.util.BitSet;

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/

class Prime {
  public static final int MAX = 1000000;
  public static BitSet bitSet = new BitSet(MAX + 1);
  public static final int primeCount;
  public static boolean isPrime(int n) {
    return bitSet.get(n);
  }
  public static int[] getPrime(int n) {
    if (n > bitSet.cardinality()) {
      n = bitSet.cardinality();
    }
    int[] primeNumber = new int[n];
    int idx = 0;
    for (int i = 0; i <= MAX; ++i) {
      if (isPrime(i)) {
        primeNumber[idx++] = i;
        if (idx == n) {
          break;
        }
      }
    }
    return primeNumber;
  }
  static {
    bitSet.set(0, 2, false);
    bitSet.set(2, MAX, true);
    for (long i = 2; i * i <= MAX; ++i) {
      if (isPrime((int)i)) {
        for (long j = i * i; j <= MAX; j += i) {
          bitSet.set((int)j, false);
        }
      }
    }
    primeCount = bitSet.cardinality();
  }
}

public class A {
  public static void main(String[] args) {
    int[] a = Prime.getPrime(10001);
    System.out.println(a[10001 - 1]);
  }
}
