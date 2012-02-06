import java.util.Comparator;
import java.util.Arrays;

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/

 
public class Cut {
  public int getMaximum(int[] eelLengths, int maxCuts) {
    Integer[] a = new Integer[eelLengths.length];
    for (int i = 0; i < eelLengths.length; ++i)
      a[i] = eelLengths[i];
    // Arrays.sort(eelLengths, new Cmp());
    Arrays.sort(a, new Comparator<Integer>() {
        public int compare(Integer x, Integer y) {
          if (x % 10 == 0 && y % 10 != 0)
            return -1;
          if (x % 10 != 0 && y % 10 == 0)
            return 1;
          return x - y;
        }
      });
    for (Integer x : a)
      System.out.println(x);
    int res = 0;
    int idx = 0;
    while (idx < a.length) {
      if (a[idx] < 10) {
        ++idx;
      } else if (a[idx] == 10) {
        ++idx;
        ++res;
      } else {
        --maxCuts;
        a[idx] -= 10;
        ++res;
        if (maxCuts == 0)
          break;
      }
    }
    return res;
  }

  class Cmp implements Comparator<Integer> {
    public int compare(Integer x, Integer y) {
      if (x % 10 == 0 && y % 10 != 0)
        return -1;
      if (x % 10 != 0 && y % 10 == 0)
        return 1;
      return x < y ? -1 : x == y ? 0 : 1;
    }
  }


// BEGIN CUT HERE
  public static void main(String[] args) {
		if (args.length == 0) {
			CutHarness.run_test(-1);
		} else {
			for (int i=0; i<args.length; ++i)
				CutHarness.run_test(Integer.valueOf(args[i]));
		}
	}
// END CUT HERE
}

// BEGIN CUT HERE
class CutHarness {
	public static void run_test(int casenum) {
		if (casenum != -1) {
			if (runTestCase(casenum) == -1)
				System.err.println("Illegal input! Test case " + casenum + " does not exist.");
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = runTestCase(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			System.err.println("No test cases run.");
		} else if (correct < total) {
			System.err.println("Some cases FAILED (passed " + correct + " of " + total + ").");
		} else {
			System.err.println("All " + total + " tests passed!");
		}
	}
	
	static boolean compareOutput(int expected, int result) { return expected == result; }
	static String formatResult(int res) {
		return String.format("%d", res);
	}
	
	static int verifyCase(int casenum, int expected, int received) { 
		System.err.print("Example " + casenum + "... ");
		if (compareOutput(expected, received)) {
			System.err.println("PASSED");
			return 1;
		} else {
			System.err.println("FAILED");
			System.err.println("    Expected: " + formatResult(expected)); 
			System.err.println("    Received: " + formatResult(received)); 
			return 0;
		}
	}

	static int runTestCase(int casenum__) {
		switch(casenum__) {
		case 0: {
			int[] eelLengths          = {13, 20, 13};
			int maxCuts               = 2;
			int expected__            = 3;

			return verifyCase(casenum__, expected__, new Cut().getMaximum(eelLengths, maxCuts));
		}
		case 1: {
			int[] eelLengths          = {5, 5, 5, 5};
			int maxCuts               = 2;
			int expected__            = 0;

			return verifyCase(casenum__, expected__, new Cut().getMaximum(eelLengths, maxCuts));
		}
		case 2: {
			int[] eelLengths          = {34, 10, 48};
			int maxCuts               = 4;
			int expected__            = 5;

			return verifyCase(casenum__, expected__, new Cut().getMaximum(eelLengths, maxCuts));
		}
		case 3: {
			int[] eelLengths          = {30, 50, 30, 50};
			int maxCuts               = 350;
			int expected__            = 16;

			return verifyCase(casenum__, expected__, new Cut().getMaximum(eelLengths, maxCuts));
		}

		// custom cases

/*      case 4: {
			int[] eelLengths          = ;
			int maxCuts               = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new Cut().getMaximum(eelLengths, maxCuts));
		}*/
/*      case 5: {
			int[] eelLengths          = ;
			int maxCuts               = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new Cut().getMaximum(eelLengths, maxCuts));
		}*/
/*      case 6: {
			int[] eelLengths          = ;
			int maxCuts               = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new Cut().getMaximum(eelLengths, maxCuts));
		}*/
		default:
			return -1;
		}
	}
}

// END CUT HERE
