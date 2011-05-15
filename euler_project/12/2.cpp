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

int main()
{
    bitset<MAX> bs(0);
    findPrime(bs);
    cout << countDivisor(76576500,bs) << endl;
    int max = 500;
    long long m = 0;
    long long n = 1;
    for (long long i=2; (m=countDivisor(n, bs)) <= 500; i++) {
	cout <<m <<": "<<n<<endl;
	n += i;
    }

    cout << n << endl;
}
