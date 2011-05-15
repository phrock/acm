#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fractionRecurringCircle(int n, int d)
{
    int x = d;
    while (x%2 == 0) {
	x /= 2;
    }
    while (x%5 == 0) {
	x /= 5;
    }
    if (x == 1) {
	return 0;
    }

    vector<int> v;

    int remainder = n;
    v.push_back(remainder);
    int index = 0;
    while (true) {
	int zero = -1;
	while (remainder < d) {
	    remainder *= 10;
	    zero++;
	}

	remainder = remainder % d;

	if ((index = v.end()-find(v.begin(), v.end(), remainder)) != 0) {
	    return index + zero;
	}
	
	v.push_back(remainder);
    }

    cout << "error here" << endl;
}

int main()
{
    int n = 1;
    int d = 3;
    cout << fractionRecurringCircle(n, d) << endl;
    cout << fractionRecurringCircle(n, 7) << endl;
    cout << fractionRecurringCircle(n, 111) << endl;

    int result_recur = 0;
    int result_d = 0;
    for (int i=2; i<1000; i++) {
	int tmp = fractionRecurringCircle(n, i);
	if (tmp > result_recur) {
	    result_recur = tmp;
	    result_d = i;
	}
    }

    cout << result_d << " : " << result_recur<< endl;
}
