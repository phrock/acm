#include <map>
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

const long MAX = 1000001;
bitset<MAX> prime(0);

// if bit is 1, then this bit is prime.
void findPrime(bitset<MAX>& prime)
{
    prime.reset();
    prime.flip();
    prime[0] = 0;
    prime[1] = 0;

    for (int i=2; i<=sqrt(MAX-1); i++) {
     	if (prime[i] == 1) {
     	    for (int j=i*i; j<MAX; j+=i) {
     		prime[j] = 0;
     	    }
     	}
    }
}

long long getPhi(int n)
{
    map<int, int> mp;
    for (int i=0; i<=n; i++) {
	if (prime[i] == 0) {
	    continue;
	}
	while (n%i == 0) {
	    mp[i]++;
	    n /= i;
	}
	if (n == 1) {
	    break;
	}
    }

    long long result = 1LL;
    for (map<int,int>::const_iterator mci=mp.begin(); mci!=mp.end(); mci++) {
	result *= (long long)pow(mci->first, mci->second-1);
	result *= (long long)(mci->first-1);
    }
    cout << "***"<<result <<endl;
    return result;
}

long double getRatio(int n)
{
    long long phi = getPhi(n);

    long double t = 1.0*n;
    long double result = t/phi;

    return result;
}

int main()
{
    findPrime(prime);
    
    long long result = 0;
    double resultRatio = 0.0;

    for (int i=2; i<MAX; i++) {
	double tmp = getRatio(i);
	cout << i << " : " << tmp <<endl;
	if (tmp > resultRatio) {
	    resultRatio = tmp;
	    result = i;
	}
    }

    cout << result << endl;
}
