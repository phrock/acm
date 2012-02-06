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
