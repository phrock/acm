#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

const long MAX = 2000000;

// if bit is 1, then this bit is prime.
void findPrime(bitset<MAX>& bs)
{
    bs.reset();
    bs.flip();
    bs[0] = 0;
    bs[1] = 0;

    for (int i=2; i<=sqrt(MAX-1); i++) {
     	if (bs[i] == 1) {
     	    for (int j=i*i; j<MAX; j+=i) {
     		bs[j] = 0;
     	    }
     	}
    }
}

bool truncatablePrime(int n, const bitset<MAX>& bs)
{
    int tmp = n;
    while (n != 0) {
	if (bs[n] == 0) {
	    return false;
	}
	n /= 10;
    }

    n = tmp;
    int m = 10;
    while (n/m > 0) {
	if (bs[n%m] == 0) {
	    return false;
	}
	m *= 10;
    }

    return true;
}

int main()
{
    bitset<MAX> bs(0);
    findPrime(bs);

    long long sum = 0LL;
    for (int i=11; i<MAX; i++) {
	if ((bs[i] == 1) && (truncatablePrime(i, bs) == true)) {
	    sum += i;
	    cout << i << endl;
	}
    }

    cout << "*************" << endl;
    cout << sum << endl;
}
