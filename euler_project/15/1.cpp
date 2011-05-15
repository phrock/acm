#include <iostream>

using namespace std;

long double choose_n_from_2n(long double n)
{
    long double result = 1;

    for (long long i=0; i<n; i++) {
	result *= 2*n-i;
    }

    for (long long i=0; i<n; i++) {
	result /= i+1;
    }

    return result;
}

int main()
{
    cout << choose_n_from_2n(2) << endl;
    cout << choose_n_from_2n(3) << endl;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << choose_n_from_2n(20) << endl;

}
