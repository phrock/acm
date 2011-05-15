#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

bool isPrime(long long x)
{
    if (x == 1) {
	return false;
    }
    for (long long i=2; i*i<=x; i++) {
	if (x%i == 0) {
	    return false;
	}
    }
    return true;
}

int main()
{
    long long x =99239887LL;
    cout << isPrime(x) << endl;
}
