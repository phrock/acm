#include <iostream>
#include <vector>
#include <gmpxx.h>

using namespace std;

long long gcd(long long a, long long b)
{
    while (b != 0) {
	long long r = a%b;
	a = b;
	b = r;
    }

    return a;
}

vector<mpz_class> getNumerator(const vector<mpz_class>& sequence)
{
    long long n = sequence.size();
    
    vector<mpz_class> numerator(n);

    numerator[0] = 2;

    for (long long i=1; i<n; i++) {
	mpz_class a = 1;
	mpz_class b = sequence[i];
	for (long long j=i; j>0; j--) {
	    mpz_class t = sequence[j-1]*b + a;
	    mpz_class g;
	    mpz_gcd(g.get_mpz_t(), t.get_mpz_t(), b.get_mpz_t());
	    t /= g;
	    b /= g;

	    a = b;
	    b = t;
	}
	numerator[i] = b;
    }

    return numerator;
}
	    

mpz_class numeratorSum(long long n)
{
    vector<mpz_class> sequence(n);

    sequence[0] = 2;

    for (int i=1; i<n; i++) {
	if (i%3 == 2) {
	    sequence[i] = 2*(i/3+1);
	} else {
	    sequence[i] = 1;
	}
    }

    // for (int i=0; i<sequence.size(); i++) {
    // 	cout << sequence[i] << " ";
    // }
    // cout << endl;

    vector<mpz_class> numerator = getNumerator(sequence);

    // for (int i=0; i<numerator.size(); i++) {
    // 	cout << numerator[i] << " ";
    // }
    // cout << endl;

    mpz_class result = 0;
    mpz_class tmp = numerator[n-1];
    while (tmp != 0) {
	result = result + tmp % 10;
	tmp /= 10;
    }
    return result;
}

int main()
{
    long long n = 100;

    cout <<"***"<<endl;
    cout << numeratorSum(n) << endl;
}
