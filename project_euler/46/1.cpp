#include <cmath>
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

int main()
{
    bitset<MAX> bs(0);
    findPrime(bs);

    for (int i=3; i<MAX; i+=2) {
	if (bs[i] == 0) {
	    int j = 3;
	    for (; j<i; j+=2) {
		if (bs[j] == 1) {
		    int t = i - j;
		    t /= 2;

		    int q = sqrt(t);
		    if (q*q == t) {
			break;
		    }
		}
	    }
	    if (j == i) {
		cout << i << endl;
		break;
	    }
	}
    }
}
