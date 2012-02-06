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
    int[] a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int res = 0;
    do {
      int n = 0;
      for (int x : a) {
        n = n * 10 + x;
      }
      if (n > res && check(n)) {
        res = n;
      }
    } while (Permutation.next(a));
    System.out.println(res);
  }

  public static boolean check(int n) {
    String s = Integer.toString(n);
    for (int i = 1; i < 8; ++i) {
      Integer x = Integer.valueOf(s.substring(0, i));
      int cur = i, multiple = 2;
      while (cur < 9) {
        String tmp = Integer.toString(x * multiple);
        if (s.startsWith(tmp, cur)) {
          cur += tmp.length();
          ++multiple;
        } else {
          break;
        }
      }
      if (cur == 9) {
        return true;
      }
    }
    return false;
  }
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
