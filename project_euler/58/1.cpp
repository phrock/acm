#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

const long MAX = 20000000;
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

bool isPrime(long long x)
{
    if (x == 1) {
	return false;
    }
    for (int i=2; i*i<=x; i++) {
	if (x%i == 0) {
	    return false;
	}
    }
    return true;
}

long long countPrime(long long length)
{
    long long result = 0;
    for (long long i=1; i<=length; i+=2) {
	for (long long j=0; j<4; j++) {
	    long long x = i*i - (i-1)*j;
	    if (isPrime(x) == true) {
		result++;
	    }
	}
    }

    return result;
}

int main()
{
    // findPrime(prime);

    long long length = 3L;
    while (true) {
	long long total = 1 + 4*(length/2);
	long long primeAmount = countPrime(length);

	cout << total << "  :  " << primeAmount << endl;

	if (primeAmount*10 < total) {
	    break;
	}

	length += 2;
    }

    cout << isPrime(11) << endl;
    cout << length << endl;
}
