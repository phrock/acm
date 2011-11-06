#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int countChain(long long n, vector<int>& v)
{
    if (n >= v.size()) {
	if (n%2 == 0) {
	    return countChain(n/2, v) + 1;
	} else {
	    return countChain(3*n+1, v) + 1;
	}
    }

    if (v[n] > 0) {
	return v[n];
    }
    
    int count = 1;
    while (n != 1) {
	if (n%2 == 0) {
	    int t = countChain(n/2, v);
	    v[n] = t + 1;
	    return v[n];
	} else if ((3*n+1) < v.size()) {
	    int t = countChain(3*n+1, v);
	    v[n] = t + 1;
	    return v[n];
	} else {
	    return countChain(3*n+1, v) + 1;
	}
    }

    v[n] = count;
    return count;
}

int main()
{
    int n = 2000000;
    int result = 0;
    vector<int> v(n, 0);

    cout << countChain(13, v) << endl;

    int rrr = 0;
    int tmp;
    for (int i=1; i<1000000; i++) {
	tmp = countChain(i, v);
	if (tmp > result) {
	    result = tmp;
	    rrr = i;
	}
    }

    cout << rrr << ": " << result << endl;
}
