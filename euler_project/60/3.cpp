#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

const long MAX = 10000;
bitset<MAX> prime(0);

// if bit is 1, then this bit is prime.
void findPrime(bitset<MAX>& prime)
{
    prime.reset();
    prime.flip();
    prime[0] = 0;
    prime[1] = 0;

    for (long long i=2; i<=sqrt(MAX-1); i++) {
     	if (prime[i] == 1) {
     	    for (long long j=i*i; j<MAX; j+=i) {
     		prime[j] = 0;
     	    }
     	}
    }
}
bool isPrime(long long x)
{
    if (x == 1) {
	return false;
    }
    for (long long i=2; i*i<=x; i++) {
	if (x%i == 0) {
	    return false;
	}
    }
    return true;
}

long long numDigits(long long n)
{
    long long result = 0;
    while (n != 0) {
	result++;
	n /= 10;
    }
    return result;
}

bool checkConcatenation(long long x, long long y)
{
    long long xd = numDigits(x);
    long long yd = numDigits(y);

    long long tx = 1;
    for (long long i=0; i<xd; i++) {
	tx *= 10;
    }
    long long ty = 1;
    for (long long i=0; i<yd; i++) {
	ty *= 10;
    }

    bool t1 = false;
    bool t2 = false;
    if (isPrime(x*ty+y) == true) {
	t1 = true;
    }
    if (isPrime(y*tx+x) == true) {
	t2 = true;
    }

    if ((t1==true) && (t2 == true)) {
	return true;
    } else {
	return false;
    }
}

set< vector<long long> > split(long long n)
{
    set< vector<long long> > s;

    long long m = numDigits(n);
    for (long long i=1; i<m; i++) {
	long long t = 1;;
	for (long long j=0; j<i; j++) {
	    t *= 10;
	}

	long long x = n % t;
	long long y = n / t;

	if (prime[x] && prime[y] && (checkConcatenation(x, y) == true)) {
	    vector<long long> v2(2);
	    v2[0] = x;
	    v2[1] = y;

	    s.insert(v2);
	}
    }

    return s;
}

set< set<long long> > increase_set(const set<long long>& s)
{
    set< set<long long> > result;

    for (long long i = 2; i<MAX; i++) {
	if (prime[i] == 1) {
	    bool flag = true;
	    for (set<long long>::const_iterator sci=s.begin(); sci!=s.end(); sci++) {
		if (checkConcatenation(*sci, i) == false) {
		    flag = false;
		    break;
		}
	    }

	    if (flag == true) {
		set<long long> tmp = s;
		tmp.insert(i);
		result.insert(tmp);
	    }
	}
    }

    return result;
}

set< set<long long> > increase(const set< set<long long> >& s)
{
    set< set<long long> > result;
    for (set< set<long long> >::const_iterator sci=s.begin(); sci!=s.end(); sci++) {
	set< set<long long> > tmp = increase_set(*sci);
	// cout << "*****  "<<tmp.size() << endl;
	for (set< set<long long> >::const_iterator sci2=tmp.begin(); sci2!=tmp.end(); sci2++) {
	    result.insert(*sci2);
	}
    }

    return result;
}

int main()
{
    findPrime(prime);
    cout <<"haha"<<endl;
    set< set<long long> > s;

    for (long long i=2; i<MAX; i++) {
	if (prime[i] == true) {
	    set<long long> tmp;
	    tmp.insert(i);
	    s.insert(tmp);
	}
    }

    for (set< set<long long> >::const_iterator sci=s.begin(); sci!=s.end(); sci++) {
 	for (set<long long>::const_iterator sci2=(*sci).begin(); sci2!=(*sci).end(); sci2++) {
 	    cout << *sci2 << " ";
 	}
	cout << endl;
    }
    cout << s.size() << endl;
    cout << "////////////////"<<endl;

    set< set<long long> > s2 = increase(s);
    for (set< set<long long> >::const_iterator sci=s2.begin(); sci!=s2.end(); sci++) {
 	for (set<long long>::const_iterator sci2=(*sci).begin(); sci2!=(*sci).end(); sci2++) {
 	    cout << *sci2 << " ";
 	}
	cout << endl;
    }
    cout << s2.size() << endl;
    cout << "////////////////"<<endl;

    set< set<long long> > s3 = increase(s2);
    cout << s3.size() << endl;
    for (set< set<long long> >::const_iterator sci=s3.begin(); sci!=s3.end(); sci++) {
 	for (set<long long>::const_iterator sci2=(*sci).begin(); sci2!=(*sci).end(); sci2++) {
 	    cout << *sci2 << " ";
 	}
	cout << endl;
    }
    cout << s3.size() << endl;
    cout << "////////////////"<<endl;

    set< set<long long> > s4 = increase(s3);
    cout << s4.size() << endl;
    for (set< set<long long> >::const_iterator sci=s4.begin(); sci!=s4.end(); sci++) {
 	for (set<long long>::const_iterator sci2=(*sci).begin(); sci2!=(*sci).end(); sci2++) {
 	    cout << *sci2 << " ";
 	}
	cout << endl;
    }
    cout << s4.size() << endl;
    cout << "////////////////"<<endl;
    
    set< set<long long> > s5 = increase(s5);
    cout << s5.size() << endl;
    for (set< set<long long> >::const_iterator sci=s5.begin(); sci!=s5.end(); sci++) {
 	for (set<long long>::const_iterator sci2=(*sci).begin(); sci2!=(*sci).end(); sci2++) {
 	    cout << *sci2 << " ";
 	}
	cout << endl;
    }
    cout << s5.size() << endl;
    cout << "////////////////"<<endl;
    

}
