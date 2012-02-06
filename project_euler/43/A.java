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
    int[] p = new int[10];
    for (int i = 0; i < 10; ++i) {
      p[i] = i;
    }
    p[0] = 1;
    p[1] = 0;
    long res = 0;
    do {
      if (check(p)) {
        res += arrayToInt(p, 0, p.length);
      }
    } while (Permutation.next(p));
    System.out.println(res);
  }

  public static boolean check(int[] p) {
    for (int i = 0; i < a.length; ++i) {
      if (arrayToInt(p, i + 1, i + 4) % a[i] != 0) {
        return false;
      }
    }
    return true;
  }

  public static long arrayToInt(int[] a, int fromIndex, int toIndex) {
    long res = 0;
    for (int i = fromIndex; i < toIndex; ++i) {
      res = res * 10 + a[i];
    }
    return res;
  }

  public static int[] a = {2, 3, 5, 7, 11, 13, 17};
}

class Permutation {
  public static <T extends Comparable<? super T>> boolean next(T[] a) {
    for (int idx1 = a.length - 2; idx1 >= 0; --idx1) {
      if (a[idx1].compareTo(a[idx1 + 1]) < 0) {
        int idx2 = upperBound(a, idx1 + 1, a.length, a[idx1]);
        swap(a, idx1, idx2);
        int left = idx1 + 1, right = a.length - 1;
        while (left < right) {
          swap(a, left, right);
          ++left;
          --right;
        }
        return true;
      }
    }
    return false;
  }

  public static boolean next(int[] a) {
    for (int idx1 = a.length - 2; idx1 >= 0; --idx1) {
      if (a[idx1] < a[idx1 + 1]) {
        int idx2 = upperBound(a, idx1 + 1, a.length, a[idx1]);
        swap(a, idx1, idx2);
        int left = idx1 + 1, right = a.length - 1;
        while (left < right) {
          swap(a, left, right);
          ++left;
          --right;
        }
        return true;
      }
    }
    return false;
  }

  private static <T extends Comparable<? super T>> int upperBound(T[] a, int fromIndex, int toIndex, T key) {
    while (fromIndex + 1 < toIndex) {
      int mid = fromIndex + (toIndex - fromIndex) / 2;
      if (a[mid].compareTo(key) <= 0) {
        toIndex = mid;
      } else {
        fromIndex = mid;
      }
    }
    return fromIndex;
  }

  private static int upperBound(int[] a, int fromIndex, int toIndex, int key) {
    while (fromIndex + 1 < toIndex) {
      int mid = fromIndex + (toIndex - fromIndex) / 2;
      if (a[mid] <= key) {
        toIndex = mid;
      } else {
        fromIndex = mid;
      }
    }
    return fromIndex;
  }

  private static <T extends Comparable<? super T>> void swap(T[] a, int idx1, int idx2) {
    T tmp = a[idx1];
    a[idx1] = a[idx2];
    a[idx2] = tmp;
  }

  private static void swap(int[] a, int idx1, int idx2) {
    int tmp = a[idx1];
    a[idx1] = a[idx2];
    a[idx2] = tmp;
  }
}
