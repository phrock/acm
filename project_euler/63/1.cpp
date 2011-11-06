#include <gmpxx.h>
#include <cmath>
#include <iostream>

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
    long long n = 100;
    int result = 0;
    for (long long i=1; i<n; i++) {
	for (long long j=1; j<n; j++) {
	    mpz_class x;
	    mpz_ui_pow_ui(x.get_mpz_t(), j, i);
	    int d =  digitsOfNum(x);
	    if (d > i) break;
	    if (d == i) {
		result++;
		cout << d << " : " << i<<endl;
		cout <<  x << endl;
	    }
	}
    }

    cout << result << endl;
}
