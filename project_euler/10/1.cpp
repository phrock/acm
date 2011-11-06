#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

const long MAX = 2000000;
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

int main()
{
    findPrime(prime);

    long long sum = 0LL;
    for (int i=1; i<MAX; i++) {
	if (prime[i] == 1) {
	    sum += i;
	}
    }

    cout << sum << endl;
}
