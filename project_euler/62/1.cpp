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
	
long long findNumber(int n)
{
    long long x = 2;
    while (testPermutation(x*x*x) != n) {
	x++;
	cout << x <<"***"<<endl;
    }

    return x*x*x;
}

int main()
{
    cout << findNumber(5) << endl;

}
