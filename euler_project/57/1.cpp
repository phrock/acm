#include <iostream>

using namespace std;

int digitsOfNum(long long x)
{
    int result = 0;
    while (x != 0) {
	result++;
	x /= 10;
    }

    return result;
}

long long gcd(long long a, long long b)
{
    while (b != 0) {
	long long r = a%b;
	a = b;
	b = r;
    }

    return a;
}

int main()
{
    long long a = 1LL;
    long long b = 2LL;

    int count = 0;
    for (int i=1; i<1000; i++) {
	a = 2*b+a;
	long long tmp = gcd(a, b);
	a /= tmp;
	b /= tmp;

	// swap x and b
	a ^= b;
	b ^= a;
	a ^= b;

	long long numerator = a + b;
	long long denominator = b;

	tmp = gcd(numerator, denominator);
	numerator /= tmp;
	denominator /= tmp;

	if (digitsOfNum(numerator) > digitsOfNum(denominator)) {
	    cout << numerator << "  " << denominator << endl;
	    count++;
	}
    }

    cout << count << endl;
}
