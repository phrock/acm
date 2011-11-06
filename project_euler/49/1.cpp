#include <vector>
#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <algorithm>

using namespace std;

const long MAX = 10000;
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

bool testPrime(const vector<int>& v)
{
    int x = 0;
    for (int i=0; i<v.size(); i++) {
	x = x*10 + v[i];
    }

    if (prime[x] == 1) {
	return true;
    } else {
	return false;
    }
}

int vectorToInt(const vector<int>& v)
{
    int x = 0;
    for (int i=0; i<v.size(); i++) {
	x = x*10 + v[i];
    }

    return x;
}

void output(const vector<int>& v)
{
    for (int i=0; i<v.size(); i++) {
	cout << v[i];
    }
    cout << endl;
}

void testPermutation(const vector<int> v)
{
    vector<int> t1 = v;

    if (testPrime(t1)) {
	int x = vectorToInt(t1);
	vector<int> t2 = t1;
	while (next_permutation(t2.begin(), t2.end()) == true) {
	    if (testPrime(t2) == true) {
		int y = vectorToInt(t2);
		int increase = y - x;
		vector<int> t3 = t2;
		while (next_permutation(t3.begin(), t3.end()) == true) {
		    if (testPrime(t3) && (vectorToInt(t3) == y+increase)) {
			output(t1);
			output(t2);
			output(t3);
			cout <<"**********"<<endl;
		    }
		}
	    }
	}
    }

    while (next_permutation(t1.begin(), t1.end()) == true) {
	if (testPrime(t1)) {
	    int x = vectorToInt(t1);
	    vector<int> t2 = t1;
	    while (next_permutation(t2.begin(), t2.end()) == true) {
		if (testPrime(t2) == true) {
		    int y = vectorToInt(t2);
		    int increase = y - x;
		    vector<int> t3 = t2;
		    while (next_permutation(t3.begin(), t3.end()) == true) {
			if (testPrime(t3) && (vectorToInt(t3) == y+increase)) {
			    output(t1);
			    output(t2);
			    output(t3);
			    cout <<"**********"<<endl;
			}
		    }
		}
	    }
	}
    }
}

int main()
{
    findPrime(prime);

    vector<int> v(4);

    for (int i=0; i<10; i++) {
	v[0] = i;
	for (int j=i; j<10; j++) {
	    v[1] = j;
	    for (int k=j; k<10; k++) {
		v[2] = k;
		for (int l=k; l<10; l++) {
		    v[3] = l;
		    testPermutation(v);
		}
	    }
	}
    }
}
