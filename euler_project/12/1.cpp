#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int countDivisor(long long n)
{
    int result = 1;
    for (long long i=1; i<=n/2; i++) {
	if (n%i == 0) {
	    result++;
	}
    }

    return result;
}

int main()
{
    int max = 500;
    long long m = 0;
    long long n = 1;
    for (long long i=2; (m=countDivisor(n)) <= 500; i++) {
	cout <<m <<": "<<n<<endl;
	n += i;
    }

    cout << n << endl;
}
