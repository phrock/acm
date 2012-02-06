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

public class B {
  public static boolean check(int x, int[] a) {
    int idx = 0, p = 1, orig = x;
    while (x != 1) {
      int aux = 0;
      while (x % a[idx] == 0) {
        x /= a[idx];
        ++aux;
      }
      if (aux > 0) {
        p *= aux + 1;
      }
      ++idx;
    }
    System.out.println(orig + ": " + p);
    if (p > 500) {
      return true;
    } else {
      return false;
    }
  }
  public static void main(String[] args) {
    int[] a = Prime.getPrime();
    int x = 0, plus = 1;
    while (true) {
      x += plus++;
      if (check(x, a)) {
        System.out.println(x);
        break;
      }
    }
  }
}
