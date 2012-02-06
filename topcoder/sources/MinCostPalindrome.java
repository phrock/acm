public class MinCostPalindrome {
  public int getMinimum(String s, int oCost, int xCost) {
    int n = s.length();
    int res = 0;
    for (int i = 0; i < n / 2; ++i) {
      int j = n - i - 1;
      char p = s.charAt(i), q = s.charAt(j);
      if (p == q) {
        if (p == '?')
          res += Math.min(oCost, xCost) * 2;
      } else {
        if (p != '?' && q != '?') {
          res = -1;
          break;
        } else if (p == 'o' || q == 'o') {
          res += oCost;
        } else {
          res += xCost;
        }
      }

    }
    return res;
  }

// BEGIN CUT HERE
  public static void main(String[] args) {
		if (args.length == 0) {
			MinCostPalindromeHarness.run_test(-1);
		} else {
			for (int i=0; i<args.length; ++i)
				MinCostPalindromeHarness.run_test(Integer.valueOf(args[i]));
		}
	}
// END CUT HERE
}

// BEGIN CUT HERE
class MinCostPalindromeHarness {
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
			String s                  = "oxo?xox?";
			int oCost                 = 3;
			int xCost                 = 5;
			int expected__            = 8;

			return verifyCase(casenum__, expected__, new MinCostPalindrome().getMinimum(s, oCost, xCost));
		}
		case 1: {
			String s                  = "x??x";
			int oCost                 = 9;
			int xCost                 = 4;
			int expected__            = 8;

			return verifyCase(casenum__, expected__, new MinCostPalindrome().getMinimum(s, oCost, xCost));
		}
		case 2: {
			String s                  = "ooooxxxx";
			int oCost                 = 12;
			int xCost                 = 34;
			int expected__            = -1;

			return verifyCase(casenum__, expected__, new MinCostPalindrome().getMinimum(s, oCost, xCost));
		}
		case 3: {
			String s                  = "oxoxooxxxxooxoxo";
			int oCost                 = 7;
			int xCost                 = 4;
			int expected__            = 0;

			return verifyCase(casenum__, expected__, new MinCostPalindrome().getMinimum(s, oCost, xCost));
		}
		case 4: {
			String s                  = "?o";
			int oCost                 = 6;
			int xCost                 = 2;
			int expected__            = 6;

			return verifyCase(casenum__, expected__, new MinCostPalindrome().getMinimum(s, oCost, xCost));
		}
		case 5: {
			String s                  = "????????????????????";
			int oCost                 = 50;
			int xCost                 = 49;
			int expected__            = 980;

			return verifyCase(casenum__, expected__, new MinCostPalindrome().getMinimum(s, oCost, xCost));
		}
		case 6: {
			String s                  = "o??oxxo?xoox?ox??x??" ;
			int oCost                 = 3;
			int xCost                 = 10;
			int expected__            = 38;

			return verifyCase(casenum__, expected__, new MinCostPalindrome().getMinimum(s, oCost, xCost));
		}

		// custom cases

     case 7: {
			String s                  = "o??oxxo?xoox?ox??x??";
			int oCost                 = 3;
			int xCost                 = 10;
			int expected__            = 38;

			return verifyCase(casenum__, expected__, new MinCostPalindrome().getMinimum(s, oCost, xCost));
		}
/*      case 8: {
			String s                  = ;
			int oCost                 = ;
			int xCost                 = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new MinCostPalindrome().getMinimum(s, oCost, xCost));
		}*/
/*      case 9: {
			String s                  = ;
			int oCost                 = ;
			int xCost                 = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new MinCostPalindrome().getMinimum(s, oCost, xCost));
		}*/
		default:
			return -1;
		}
	}
}

// END CUT HERE
