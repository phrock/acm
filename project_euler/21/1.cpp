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

int countDivisor(long long n, const bitset<MAX>& bs)
{
    int result = 1;

    for (int i=1; i<=n; i++) {
	if (bs[i] == 1) {
	    int e = 0;
	    while (n%i == 0) {
		n /= i;
		e++;
	    }
	    if (e > 0) {
		result *= e+1;
	    }
	}
    }
    
    return result;
}

int d(int n)
{
    int sum = 0;
    for (int i=1; i<n; i++) {
	if (n%i == 0) {
	    sum += i;
	}
    }

    return sum;
}

int main()
{
    cout << d(220) << endl;
    cout << d(284) << endl;

    int a[10000];
    for (int i=1; i<10000; i++) {
	a[i] = d(i);
    }

    int result = 0;
    for (int i=1; i<10000; i++) {
	if (a[i] >= 10000) {
	    continue;
	}
	if ((i == a[a[i]]) && (i != a[i])) {
	    result += i+a[i];
	    a[i] = 10000;
	}
    }

    cout <<"*********\n" << result << endl;
}
