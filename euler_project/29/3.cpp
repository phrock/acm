#include <iostream>
#include <set>
#include <gmpxx.h>

using namespace std;

int count(int a, int b)
{
    set<mpz_class> m;
    for (int i=2; i<=a; i++) {
	for (int j=2; j<=b; j++) {
	    mpz_class tmp = 1;
	    for (int k=0; k<j; k++) {
		tmp *= i;
	    }
	    m.insert(tmp);
	}
    }

    return m.size();
}

int main()
{
    int ta = 100;
    int tb = 100;

    cout << count(ta, tb) << endl;
}
