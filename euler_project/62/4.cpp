#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

long long cubeRoot(long long n)
{
    return pow(n, 1/3.0);
}

bool testCube(long long n)
{
    long long cc = cubeRoot(n);
    for (long long x=cc; x < cc+3; x++) {
	if (x*x*x == n) {
	    return true;
	}
    }
    return false;
}

int testPermutation(long long n)
{
    cout << n << endl;
    vector<int> v;
    while (n != 0) {
	v.push_back(n%10);
	n /= 10;
    };
    reverse(v.begin(), v.end());

    int result = 1;
    while (next_permutation(v.begin(), v.end()) == true) {
	long long x = 0;
	for (int i=0; i<v.size(); i++) {
	    x = x*10 + v[i];
	}
	// cout << x << endl;
	if (testCube(x) == true) {
	    result++;
	}
    }

    return result;
}

bool testNum(long long a, long long b)
{
    vector<int> va;
    while (a != 0) {
	va.push_back(a%10);
	a /= 10;
    };
    reverse(va.begin(), va.end());
    
    vector<int> vb;
    while (b != 0) {
	vb.push_back(b%10);
	b /= 10;
    };
    reverse(vb.begin(), vb.end());
    
    while (next_permutation(va.begin(), va.end()) == true) {
	if (va == vb) {
	    return true;
	}
    }

    return false;
}

long long findNumber(int n)
{
    int M = 10000;
    long long result = 0;

    vector< vector<int> > v(M, vector<int>(10));
    vector<long long> cube(M);
    for (long long i=0; i<M; i++) {
	long long tmp = i*i*i;
	cube[i] = tmp;
	while (tmp != 0) {
	    v[i][tmp%10]++;
	    tmp /= 10;
	}
    }

    vector<int> candidate(M);

    for (long long i=0; i<M; i++) {
	for (long long j=i+1; j<M; j++) {
	    if (v[i] == v[j]) {
		candidate[i]++;
	    }
	}
    }

    for (long long i=0; i<M; i++) {
	int m = n-1;
	if (candidate[i] < m) {
	    continue;
	}
	cout << cube[i] <<" : "<<endl;
	cout <<"****************"<<endl;
	return cube[i];
    }

    return result;
}

int main()
{
    //    cout << findNumber(3) << endl;
    cout << "///////////"<<endl;
    cout << findNumber(5) << endl;
}
