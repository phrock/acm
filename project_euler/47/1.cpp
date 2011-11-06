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

bool has4Prime(int n, const bitset<MAX>& bs)
{
    int m = n;
    int result = 0;
    for (int i=2; i<n; i++) {
	if ((bs[i] == 1) && (m%i == 0)) {
	    result++;
	    if (result > 5) {
		return false;
	    }
	}
    }

    if (result == 4) {
	return true;
    } else {
	return false;
    }
}

int main()
{
    bitset<MAX> bs(0);
    findPrime(bs);

    for (int i=10; i<MAX; i++) {

	int j = 0;
	for (j=0; j<4; j++) {
	    if (!has4Prime(i+j,bs)) {
		break;
	    }
	}
	if (j == 2) {
	cout << i << endl;
	cout << "j: "<< j<<endl;
	}
	if (j == 4) {
	    cout << i<< endl;
	    break;
	}
	i += j;
    }
}
