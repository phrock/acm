#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <cmath>

using namespace std;

const long MAX = 10000000;


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
    if (n == 2) {
	return true;
    }
    for (int i=2; i*i<n; i++) {
	if (n%i == 0) {
	    return false;
	}
    }

    return true;
}

int main()
{
    bitset<MAX> bs(0);
    // findPrime(bs);
    cout <<"haha"<< endl;
    for (int d=9; d>=1; d--) {

	vector<int> v;
	for (int i=d; i>=1; i--) {
	    v.push_back(i);
	}

	while (prev_permutation(v.begin(), v.end())) {
	    int x = 0;
	    for (int j=0; j<v.size(); j++) {
		x = x*10 + v[j];
	    }
	    if (isPrime(x) == true) {
		cout << x << endl;
		return 0;
	    }
	}

    }
}
