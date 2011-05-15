#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

bool isPrime(long long x)
{
    long long sq = sqrt(x);
    for (long long i=2; i<=sq; i++) {
	if (x%i == 0) {
	    return false;
	}
    }
    return true;
}

long long findMaxPrime(long long x)
{
    long long max = 1;
    
    long long sq = sqrt(x);
    for (long long i=1; i<=sq; i++) {
	if (x%i == 0) {
	    if ((i > max) && isPrime(i)) {
		max = i;
	    }
	    if ((x/i > max) && isPrime(x/i)) {
		max = x/i;
	    }
	}
    }

    return max;
}

int main()
{
    long long a = 600851475143LL;
    cout << a << endl;

    // long long s = sqrt(a);
    // cout << s << endl;
    // cout << s*s << endl;

    long long test = 13195;
    long long test2 = 2000000000LL;
    cout << findMaxPrime(test) << endl;
    cout << findMaxPrime(test2) << endl;
    cout << findMaxPrime(a) << endl;
}
