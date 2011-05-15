#include <vector>
#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <algorithm>

using namespace std;

const long MAX = 1000000;
//const long MAX = 1000;
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

int main()
{
    findPrime(prime);

    vector<int> v;
    long long sum = 0LL;
    for (int i=0; i<prime.size(); i++) {
	if (prime[i] == 1) {
	    v.push_back(i);
	    sum += i;
	}
    }

    long long result = sum;
    int n = v.size();
    for (int i=1; i<v.size(); i++) {
	cout << "*********  " << n-i << endl;
	for (int j=0; j<=i; j++) {
	    result = sum;
	    for (int a=0; a<j; a++) {
		result -= v[a];
	    }
	    for (int b=0; b<i-j; b++) {
		result -= v[n-1-b];
	    }

	    if (result<MAX) cout <<"&&&&&&&& "<<result<<endl;

	    if ((result < MAX) && (prime[result] == 1)) {
		cout << "**********///////// " << i<<endl;
		    cout << result << endl;
		    break;
	    }
	}
    }
}
