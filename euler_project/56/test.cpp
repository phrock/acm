#include <iostream>
#include <gmpxx.h>

using namespace std;

int main()
{
    mpz_class a = 0;
    cout << a << endl;

    // mpz_t x = a.get_mpz_t();

    mpz_ui_pow_ui(a.get_mpz_t(), 200, 30);

    // mpz_class b(x);
    // cout << b << endl;

    cout << a << endl;

    cout << a+ 2<<endl;
}
