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

  public static final int MAX = 1000000;
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
    int[] a = Prime.getPrime();
    int cnt = 0;
    for (int x : a) {
      if (check(x)) {
        ++cnt;
      }
    }
    System.out.println(cnt);
  }

  public static boolean check(int n) {
    int m = n;
    do {
      m = rotateRight(m);
      if (!Prime.isPrime(m)) {
        return false;
      }
    } while (m != n);
    return true;
  }

  public static int rotateRight(int n) {
    int k = Integer.toString(n).length() - 1;
    return n / 10 + n % 10 * (int)Math.pow(10, k);
  }
}
