#include <iostream>

using namespace std;

const long long M = 10000000000LL;

long long xFacX(long long n)
{
    long long result = 1LL;
    for (long long i=0; i<n; i++) {
	result *= n;
	result %= M;
    }

    return result;
}

int main()
{
    long long result = 0LL;
    for (long long i=1; i<=1000; i++) {
	result += xFacX(i);
	result %= M;
    }

    cout << result;
}
