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
  public static boolean isPrime(int n) {
    return bitSet.get(n);
  }

  public static int[] getPrime(int n) {
    n = Math.min(n, primeCount);
    int[] primeNumber = new int[n];
    for (int idx = 0, i = 0; i <= MAX; ++i) {
      if (isPrime(i)) {
        primeNumber[idx++] = i;
        if (idx == n) {
          break;
        }
      }
    }
    return primeNumber;
  }

  public static int[] getPrime() {
    return getPrime(primeCount);
  }

  public static final int MAX = 10000000;
  public static final int primeCount;
  private static BitSet bitSet = new BitSet(MAX + 1);

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
    int a = 0, b = 0, max = 0;
    for (int i = -1000 + 1; i < 1000; ++i) {
      for (int j = -1000 + 1; j < 1000; ++j) {
        int tmp = func(i, j);
        if (tmp > max) {
          max = tmp;
          a = i;
          b = j;
        }
      }
    }
    System.out.println(a + " " + b + " : " + max + " : " + a * b);
  }

  public static int func(int a, int b) {
    int n = 0;
    while (true) {
      int k = n * n + a * n + b;
      if (k < 0 || !Prime.isPrime(k)) {
        break;
      }
      ++n;
    }
    return n;
  }
}
