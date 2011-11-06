#include <cmath>
#include <iostream>
#include <vector>
#include <bitset>
#include <map>
#include <climits>

using namespace std;

long long f(long long n)
{
    return n*(3*n-1)/2;
}

bool test(long long n, map<long long, int>& st)
{
    if (st[n] == -1) {
	return false;
    } else if (st[n] == 1) {
	return true;
    } else {
	long long x = 24*n+1;
	long long y = (long long)sqrt(x);
	if (x != y*y) {
	    st[n] = -1;
	    return false;
	}
	if ((y+1) % 6 == 0) {
	    st[n] = 1;
	    return true;
	} else {
	    st[n] = -1;
	    return false;
	}
    }
}

bool check(long long n, map<long long, int>& st)
{
    long long m = n;
    long long x = f(n);
    cout << n << " *********:  " <<x<<endl;
    while (3*m+1 <= x) {
	m++;
    }

    for (long long i=n+1; i<=m; i++) {
	long long y = f(i);
	long long j = 0LL;
	if (test(x+y, st)) {
	    long long z = x+y;
	    if (test(y+z, st)) {
		return true;
	    }
	}

    }

    return false;
}

int main()
{
    map<long long, int> st;
    long long n = 1LL;
    // while (check(n, st) == false) {
    // 	n++;
    // }

    cout << test(23,st)<<endl;

    vector<int> v(2000, 0);
    int result = INT_MAX;

    for (int i=1; i<2000; i++) {
	v[i] = n*(3*n-1)/2;
    }

    for (int i=0; i<v.size(); i++) {
	for (int j=0; j<i; j++) {
	    // cout <<i << " " << j<<endl;
	    if (test(v[i]+v[j],st) && test(v[i]-v[j],st)) {
		cout << v[i]-v[j]<<endl;
	    }
	}
    }

    cout << result << endl;

	    
}
