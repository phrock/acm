#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

const long MAX = 100000000;
bitset<MAX> prime(0);

// if bit is 1, then this bit is prime.
void findPrime(bitset<MAX>& prime)
{
    prime.reset();
    prime.flip();
    prime[0] = 0;
    prime[1] = 0;

    for (int i=2; i<=sqrt(MAX-1); i++) {
     	if (prime[i] == 1) {
     	    for (int j=i*i; j<MAX; j+=i) {
     		prime[j] = 0;
     	    }
     	}
    }
}
bool isPrime(int x)
{
    if (x == 1) {
	return false;
    }
    for (int i=2; i*i<=x; i++) {
	if (x%i == 0) {
	    return false;
	}
    }
    return true;
}

int numDigits(int n)
{
    int result = 0;
    while (n != 0) {
	result++;
	n /= 10;
    }
    return result;
}

bool checkConcatenation(int x, int y)
{
    int xd = numDigits(x);
    int yd = numDigits(y);

    int tx = 1;
    for (int i=0; i<xd; i++) {
	tx *= 10;
    }
    int ty = 1;
    for (int i=0; i<yd; i++) {
	ty *= 10;
    }

    bool t1 = false;
    bool t2 = false;
    if (prime[x*ty+y] == true) {
	t1 = true;
    }
    if (prime[y*tx+x] == true) {
	t2 = true;
    }

    if ((t1==true) && (t2 == true)) {
	return true;
    } else {
	return false;
    }
}

set< set<int> > split(int n)
{
    set< set<int> > s;

    int m = numDigits(n);
    for (int i=1; i<m; i++) {
	int t = 1;;
	for (int j=0; j<i; j++) {
	    t *= 10;
	}

	int x = n % t;
	int y = n / t;

	if (prime[x] && prime[y] && (checkConcatenation(x, y) == true)) {
	    set<int> v2;
	    v2.insert(x);
	    v2.insert(y);

	    s.insert(v2);
	}
    }

    return s;
}

set< set<int> > increase_set(const set<int>& s)
{
    set< set<int> > result;

    for (int i = 2; i<MAX; i++) {
	if (prime[i] == 1) {
	    bool flag = true;
	    for (set<int>::const_iterator sci=s.begin(); sci!=s.end(); sci++) {
		if (checkConcatenation(*sci, i) == false) {
		    flag = false;
		    break;
		}
	    }

	    if (flag == true) {
		set<int> tmp = s;
		tmp.insert(i);
		result.insert(tmp);
	    }
	}
    }

    return result;
}

set< set<int> > increase(const set< set<int> >& s)
{
    set< set<int> > result;
    for (set< set<int> >::const_iterator sci=s.begin(); sci!=s.end(); sci++) {
	set< set<int> > tmp = increase_set(*sci);
	// cout << "*****  "<<tmp.size() << endl;
	for (set< set<int> >::const_iterator sci2=tmp.begin(); sci2!=tmp.end(); sci2++) {
	    result.insert(*sci2);
	}
    }

    return result;
}

bool check(int i, int j, const set< set<int> >& s)
{
    set<int> st;
    st.insert(i);
    st.insert(j);

    if (s.find(st) == s.end()) {
	return false;
    } else {
	return true;
    }
}

int main()
{
    findPrime(prime);
    cout <<"haha"<<endl;
    set< set<int> > s;

    for (int i=2; i<MAX; i++) {
	if (prime[i] == false) {
	    continue;
	}
	set< set<int> > tmp = split(i);
	for (set< set<int> >::const_iterator sci=tmp.begin(); sci!=tmp.end(); sci++) {
	    s.insert(*sci);
	}
    }
    
    // for (set< set<int> >::const_iterator sci=s.begin(); sci!=s.end(); sci++) {
    // 	for (set<int>::const_iterator sci2=(*sci).begin(); sci2!=(*sci).end(); sci2++) {
    // 	    cout << *sci2 << " ";
    // 	}
    // 	cout << endl;
    // }
    // cout << s.size() << endl;
    // cout << "////////////////"<<endl;

    cout << "kao" << endl;

    int n = 10000;
    for (int i=2; i<n; i++) {
	if (prime[i] == 1) {
	    for (int j=i; j<n; j++) {
		if (prime[j] == 1) {
		    if (check(i, j, s)) {
			//cout << i << " " << j << endl;
			for (int k=j; k<n; k++) {
			    if (prime[k] == 1) {
				if (check(k, i, s) && check(k, j, s)) {
				    //cout << i << " " << j << " " << k << endl;
				    for (int l=k; l<n; l++) {
					if (prime[l] == 1) {
					    if (check(l, i, s) && check(l, j, s) && check(l, k, s)) {
						//cout << i << " " << j << " " << k << " " << l << endl;
						for (int m=l; m<n; m++) {
						    if (prime[m] == 1) {
							if (check(m,i,s) && check(m,j,s)&&check(m,k,s) && check(m,l,s)) {
							    cout << i << " " << j << " " << k << " " << l<<" "<<m<< endl;
							    cout << i+j+k+l+m << endl;
							    return 0;
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
    }
}
