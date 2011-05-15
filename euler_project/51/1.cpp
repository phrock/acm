#include <vector>
#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <algorithm>

using namespace std;

const long MAX = 1000000;
bitset<MAX> prime(0);
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

int digit(int n)
{
    int result = 0;
    while (n != 0) {
	result++;
	n /= 10;
    }
    return result;
}

bool testMatrix(int d, int amount)
{
    int matrix = 1;
    for (int i=1; i<d; i++) {
	matrix *= 10;
    }
	
    vector< vector<int> > v(d, vector<int>(10, 0));
    for (int i=matrix; i<matrix*10; i++) {
	if (prime[i] == 1) {
	cout << i << endl;

	    int m = i;
	    int base = 0;
	    while (m != 0) {
		int k = m%10;
		v[base][k]++;

		m /= 10;
		base++;
	    }
	}
    }

        for (int i=0; i<d; i++) {
	for (int j=0; j<10; j++) {
	    cout <<"bit: "<<i<<" >> "<<j<<" : "<<v[i][j];
	    cout << endl;
	}
	cout << endl;
	}

    bool flag = false;
    vector<int> vnum(d, -1);
    for (int i=0; i<d; i++) {
	for (int j=0; j<10; j++) {
	    if (v[i][j] >= amount) {
		flag = true;
		vnum[i] = j;
		break;
	    }
	}
    }
	
    if (flag == true) {
	cout << "haha " << d << endl;
    }

    for (int i=0; i<d; i++) {
	cout << vnum[i] <<endl;
    }

    return flag;
}

int main()
{
    findPrime(prime);

    int amount = 7;

    int d = 2;

    // while (testMatrix(d, amount) == false) {
    // 	d++;
    // }

    testMatrix(5, 7);
}
