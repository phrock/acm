#include <iostream>
#include <gmpxx.h>

using namespace std;

int getDigitSum(mpz_class x)
{
    mpz_class digitSum = 0;
    while (x != 0) {
	digitSum += x%10;
	x /= 10;
    }

    return digitSum.get_si();
}

int main()
{
    mpz_class x;

    int result = 0;
    for (int i=1; i<100; i++) {
	for (int j=1; j<100; j++) {
	    mpz_ui_pow_ui(x.get_mpz_t(), i, j);
	    int digitSum = getDigitSum(x);
	    result = digitSum > result ? digitSum : result;
	}
    }

    cout << result << endl;
}
