#include <iostream>
#include <gmpxx.h>
#include <stdlib.h>
 
using namespace std;
 
int isprime(int n)
{
        if (n < 2) { return 0; }
        if (n % 2 == 0) { return (n == 2); }
        if (n % 3 == 0) { return (n == 3); }
        for (int p = 5; ; ) {
                int q = n/p;
                if (q < p) { break; }
                if (q*p == n) { return 0; }
                p += 2;
                q = n/p;
                if (q < p) { break; }
                if (q*p == n) { return 0; }
                p += 4;
        }
        return 1;
}
 
const int nprimes = 100;
 
int primes[nprimes];
 
void fillprimes(void)
{
        primes[0] = 2;
        int n = 1;
        while (n < nprimes) {
                primes[n] = primes[n-1] + 1;
                while (!isprime(primes[n])) { ++primes[n]; }
                ++n;
        }
}
 
mpz_class hcs(
        int nf,         // At least nf factors
        int maxe,       // Primes exponents <= maxe
        int px          // Starting with the primes[px]
)
{
        if (px >= nprimes) { printf("Error: not enough primes\n"); exit(0); }
        if (nf <= 1) { return 1; }
        if (nf <= 3) { return primes[px]; }
        mpz_class ppow(primes[px]);
        mpz_class best = ppow * hcs((nf + 2)/3, 1, px+1);
        for (int exp = 2; exp <= maxe; ++exp) {
                ppow *= primes[px];
                if (ppow > best) { break; }
                mpz_class test = ppow * hcs((nf + 2*exp)/(2*exp + 1), exp, px+1);
                if (test < best) { best = test; }
        }
        return best;
}
 
uint64_t tau(mpz_class n)
{
        uint64_t result = 1;
        int p = 0;
        while (n > 1) {
                int f = 0;
                while ((n % primes[p]) == 0) {
                        n /= primes[p];
                        ++f;
                }
                result *= (f + 1);
                p++;
        }
        return result;
}
 
int main(void)
{
        fillprimes();
        mpz_class n;
 
        n = hcs(1999, 1000, 0);
        cout << n << "^2 has " << tau(n*n) << " factors\n";
 
        n = hcs(7999999, 1000, 0);
        cout << n << "^2 has " << tau(n*n) << " factors\n";
 
        n = hcs(1999999999, 1000, 0);
        cout << n << "^2 has " << tau(n*n) << " factors\n";
 
        return 0;
}


