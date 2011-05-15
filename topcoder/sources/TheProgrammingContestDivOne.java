// BEGIN CUT HERE
PROBLEM STATEMENT
Farmer John and Fox Brus are participating in a programming contest as a team.


The duration of the contest is T minutes and they are given N tasks. Solutions can be submitted at any time during the contest, including exactly T minutes after the start of the contest. If they solve the i-th task immediately after the start of the contest, they get maxPoints[i] points and it decreases by pointsPerMinute[i] points per minute. In other words, if they solve the i-th task t minutes after the start of the contest, they will get maxPoints[i] - t * pointsPerMinute[i] points. It takes them requiredTime[i] minutes to solve the i-th task.


Return the maximal points they can get.

DEFINITION
Class:TheProgrammingContestDivOne
Method:find
Parameters:int, int[], int[], int[]
Returns:int
Method signature:int find(int T, int[] maxPoints, int[] pointsPerMinute, int[] requiredTime)


CONSTRAINTS
-T will be between 1 and 100,000, inclusive.
-maxPoints will contain between 1 and 50 elements, inclusive.
-maxPoints, pointsPerMinute and requiredTime will contain the same number of elements.
-Each element of maxPoints will be between 1 and 100,000, inclusive.
-Each element of pointsPerMinute will be between 1 and 100,000, inclusive.
-Each element of requiredTime will be between 1 and 100,000, inclusive.


EXAMPLES

0)
74
{502}
{2}
{47}

Returns: 408

They can solve the task 47 minutes after the start of the contest. They will get 502 - 2 * 47 = 408 points.

1)
40000
{100000, 100000}
{1, 100000}
{50000, 30000}

Returns: 0

They don't have time to solve the first task. If they solve the second task, they will get negative points (100000 - 100000 * 30000 = -2999900000 points), so they shouldn't solve it.

2)
75
{250, 500, 1000}
{2, 4, 8}
{25, 25, 25}

Returns: 1200


First, they can solve the third task 25 minutes after the start of the contest. They get 1000 - 8 * 25 = 800 points.
Second, they can solve the second task 50 minutes after the start of the contest. They get 500 - 4 * 50 = 300 points.
Third, they can solve the first task 75 minutes after the start of the contest. They get 250 - 2 * 75 = 100 points.

In total, they can get 800 + 300 + 100 = 1200 points.

3)
30
{100, 100, 100000}
{1, 1, 100}
{15, 15, 30}

Returns: 97000

The best strategy is solving only the third task.

// END CUT HERE
import java.util.*;
public class TheProgrammingContestDivOne {
	public int find(int T, int[] maxPoints, int[] pointsPerMinute, int[] requiredTime) {
		
	}
	public static void main(String[] args) {
		TheProgrammingContestDivOne temp = new TheProgrammingContestDivOne();
		System.out.println(temp.find(int T, int[] maxPoints, int[] pointsPerMinute, int[] requiredTime));
	}
}
