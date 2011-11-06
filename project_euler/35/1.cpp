#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

const long MAX = 1000000;

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

bool allPrime(int n, const bitset<MAX>& bs)
{
    int d = 0;
    int m = n;
    while (m != 0) {
	m /= 10;
	d++;
    }

    for (int i=1; i<d; i++) {
	m = n;

	int t = 1;
	for (int j=0; j<d-i; j++) {
	    t *= 10;
	}
	int x = 1;
	for (int j=0; j<i; j++) {
	    x *= 10;
	}

	m = n%t*x+n/t;

	if (bs[m] == 0) {
	    return false;
	}
    }

    return true;
}

int main()
{
    bitset<MAX> bs(0);
    findPrime(bs);

    int n = 1000000;

    int count = 0;
    for (int i=2; i<n; i++) {
	if ((bs[i] == 1) && (allPrime(i, bs) == true)) {
	    count++;
	}
    }

    cout << count << endl;
}
