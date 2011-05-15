#include <cmath>
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

const long MAX = 3000000;

long long fac(long long x, int n)
{
    long long result = 1;
    for (int i=0; i<n; i++) {
	result *= x;
    }
    return result;
}

// if bit is 1, then this bit is prime.
void findPrime(bitset<MAX>& bs)
{
    bs.reset();
    bs.flip();
    bs[0] = 0;
    bs[1] = 0;

    for (int i=2; i<=sqrt(MAX-1); i++) {
     	if (bs[i] == 1) {
     	    for (int j=i*i; j<MAX; j+=i) {
     		bs[j] = 0;
     	    }
     	}
    }
}

bool has4Prime(int n, const bitset<MAX>& bs)
{
    int m = n;
    int result = 0;
    for (int i=2; i<n; i++) {
	if ((bs[i] == 1) && (m%i == 0)) {
	    result++;
	    if (result > 5) {
		return false;
	    }
	}
    }

    if (result == 4) {
	return true;
    } else {
	return false;
    }
}

int main()
{
    bitset<MAX> bs(0);
    findPrime(bs);

    bitset<MAX> p4(0);

    for (long long i=2; i<MAX; i++) {
	if (bs[i] == 1) {
	    for (long long j=i+1; j<MAX; j++) {
		if (i*j > MAX) {
		    break;
		}
		if (bs[j] == 1) {
		    for (long long k=j+1; k<MAX; k++) {
			if (i*j*k > MAX) {
			    break;
			}
			if (bs[k] == 1) {
			    for (long long l=k+1; l<MAX/(i*j*k); l++) {
				if (bs[l] == 1) {
				    if (i*j*k*l < MAX) {
					cout <<i<<" "<<j<<" "<<k<<" "<<l<<endl;
					cout << i*j*k*l<<endl;
					p4[i*j*k*l] = 1;
					long long x = i*j*k*l;
					for (int a=1;fac(i,a)*j*k*l<MAX ; a++) {
					    for (int b=1; fac(i,a)*fac(j,b)*k*l<MAX; b++) {
						for (int c=1; fac(i,a)*fac(j,b)*fac(k,c)*l<MAX; c++) {
						    for (int d=1; fac(i,a)*fac(j,b)*fac(k,c)*fac(l,d)<MAX; d++) {
							p4[fac(i,a)*fac(j,b)*fac(k,c)*fac(l,d)] = 1;
						    }
						}
					    }
					}
						
					
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    cout <<"************"<<endl;

    int count = 0;
    for (int i=0; i<p4.size(); i++) {
	if (p4[i] == 1) {
	    count++;
	}
    }
    cout << count << endl;

    cout <<"//////////////"<<endl;
    for (int i=0; i<p4.size(); i++) {
	if ((p4[i] == 1) && (p4[i+1] == 1) &&
	    (p4[i+2] == 1) && (p4[i+3] == 1)) {
	    cout << i << endl;
	    break;
	}
    }

	
}
