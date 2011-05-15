#include <vector>
#include <map>
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

const long MAX = 1000001;
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

vector<int> getPhi(int n)
{
    vector<int> phi(n, 1);
    for (int i=1; i<n; i++) {
	// cout << "*** " << i<<endl;
	if (prime[i] == 1) {
	    long long x = i;

	    while (x < n) {
		// cout << i <<" xxx: "<<x<< " "<<t<<endl;
		long long y = x;
		while (y < n) {
		    if (x == i) {
			phi[y] *= x-1;
		    } else {
			phi[y] *= i;
		    }
		    // cout << i <<" xxx: "<<x<< " "<<y << " "<<phi[y]<<endl;
		    y += x;
		}

		x *= i;
	    }
	}
    }

    return phi;
}

// long double getRatio(int n)
// {
//     long long phi = getPhi(n);

//     long double t = 1.0*n;
//     long double result = t/phi;

//     return result;
// }

int main()
{
    findPrime(prime);

    int n = MAX;

    vector<int> phi = getPhi(n);

    int result = 0;
    double resultRatio = 0.0;

    for (int i=1; i<n; i++) {
	double tmp = 1.0;
	tmp = tmp*i/phi[i];
 	cout << i << " : " << tmp <<endl;
 	if (tmp > resultRatio) {
 	    resultRatio = tmp;
 	    result = i;
 	}
    }

    cout << result << endl;

    // for (int i=0; i<n; i++) {
    // 	cout << i << " : "<<phi[i] << endl;
    // }
}
