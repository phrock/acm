#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

const long MAX = 2000000;
bitset<MAX> bs(0);

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

bool isPrime(int n)
{
    if ((n > 0) && (bs[n] == 1)) {
	return true;
    } else {
	return false;
    }
}

int createConsecutivePrime(int a, int b)
{
    int i = 0;

    while (isPrime(i*i+a*i+b)) {
	i++;
    }

    return i+1;
}

int main()
{
    findPrime(bs);

    int result = 0;
    int ra = 0;
    int rb = 0;

    for (int a=-999; a<1000; a++) {
	for (int b=-999; b<1000; b++) {
	    int tmp = createConsecutivePrime(a, b);
	    if (tmp > result) {
		result = tmp;
		ra = a;
		rb = b;
	    }
	}
    }

    cout << result << " *** " << ra*rb << endl;
}
