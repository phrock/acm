#include <iostream>
#include <gmpxx.h>

using namespace std;

int digitsOfNum(mpz_class x)
{
    int result = 0;
    while (x != 0) {
	result++;
	x /= 10;
    }

    return result;
}

int main()
{
    mpz_class a = 1;
    mpz_class b = 2;

    int count = 0;
    for (int i=1; i<1000; i++) {
	a = 2*b+a;
	mpz_class gcd;
	mpz_gcd(gcd.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t());
	a /= gcd;
	b /= gcd;

	// swap x and b
	mpz_swap(a.get_mpz_t(), b.get_mpz_t());

	mpz_class numerator = a + b;
	mpz_class denominator = b;

	mpz_gcd(gcd.get_mpz_t(), numerator.get_mpz_t(), denominator.get_mpz_t());
	numerator /= gcd;
	denominator /= gcd;

	if (digitsOfNum(numerator) > digitsOfNum(denominator)) {
	    cout << numerator << "  " << denominator << endl;
	    count++;
	}
    }

    cout << endl << "**************"<< endl;
    cout << count << endl;
}
