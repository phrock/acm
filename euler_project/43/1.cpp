#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isInteresting(const vector<int> v)
{
    int n = 7;
    vector<int> x(n);

    for (int i=0; i<n; i++) {
	x[i] = v[i+1]*100 + v[i+2]*10 + v[i+3];
    }

    if ((x[0]%2 == 0) && (x[1]%3 == 0) && (x[2]%5 == 0) &&
	(x[3]%7 == 0) && (x[4]%11 == 0) && (x[5]%13 == 0) && (x[6]%17 == 0)) {
	return true;
    } else {
	return false;
    }
}

int main()
{
    long long result = 0LL;

    vector<int> v;

    v.push_back(1);
    v.push_back(0);

    for (int i=2; i<=9; i++) {
	v.push_back(i);
    }

    long long tmp = 0LL;
    if (isInteresting(v) == true) {
	tmp = 0LL;
	for (int i=0; i<v.size(); i++) {
	    tmp = tmp*10 + v[i];
	}

	result += tmp;
    }

    while (next_permutation(v.begin(), v.end())) {
	if (isInteresting(v) == true) {
	    tmp = 0LL;
	    for (int i=0; i<v.size(); i++) {
		tmp = tmp*10 + v[i];
	    }

	    result += tmp;
	}
    }
    
    cout << result << endl;

    // vector<int> test;
    // test.push_back(1);
    // test.push_back(4);
    // test.push_back(0);
    // test.push_back(6);
    // test.push_back(3);
    // test.push_back(5);
    // test.push_back(7);
    // test.push_back(2);
    // test.push_back(8);
    // test.push_back(9);
    // cout << isInteresting(test) << endl;
}
