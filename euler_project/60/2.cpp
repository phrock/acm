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
bool isPrime(long long x)
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

set< vector<int> > split(int n)
{
    set< vector<int> > s;

    int m = numDigits(n);
    for (int i=1; i<m; i++) {
	int t = 1;;
	for (int j=0; j<i; j++) {
	    t *= 10;
	}

	int x = n % t;
	int y = n / t;

	if (prime[x] && prime[y] && (checkConcatenation(x, y) == true)) {
	    vector<int> v2(2);
	    v2[0] = x;
	    v2[1] = y;

	    s.insert(v2);
	}
    }

    return s;
}

set< set<int> > increase_set(const set<int>& s)
{
    set< set<int> > result;

    for (set<int>::const_iterator sci=s.begin(); sci!=s.end(); sci++) {
	set<int> tmp = s;
	tmp.erase(*sci);
	set< vector<int> > sv = split(*sci);

	for (set< vector<int> >::const_iterator svi=sv.begin(); svi!=sv.end(); svi++) {
	    bool flag = true;

	    for (int i=0; i<2; i++) {
		if (!flag) break;
		for (set<int>::const_iterator sci2=tmp.begin(); sci2!=tmp.end(); sci2++) {
		    if (checkConcatenation((*svi)[i], (*sci2)) == false) {
			flag = false;
			break;
		    }
		}
	    }

	    if (flag == true) {
		set<int> tmp2 = tmp;
		tmp2.insert((*svi)[0]);
		tmp2.insert((*svi)[1]);
		result.insert(tmp2);
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

int main()
{
    findPrime(prime);
    cout <<"haha"<<endl;
    set< set<int> > s;

    for (int i=2; i<MAX; i++) {
	if (prime[i] == true) {
	    set< vector<int> > ts = split(i);
	    if (ts.size() == 0) {
		continue;
	    }
	    for (set< vector<int> >::const_iterator svi=ts.begin(); svi!=ts.end(); svi++) {
		set<int> ss((*svi).begin(), (*svi).end());
		s.insert(ss);
	    }
	}
    }

    for (set< set<int> >::const_iterator sci=s.begin(); sci!=s.end(); sci++) {
 	for (set<int>::const_iterator sci2=(*sci).begin(); sci2!=(*sci).end(); sci2++) {
 	    cout << *sci2 << " ";
 	}
	cout << endl;
    }
    cout << "////////////////"<<endl;

    set< set<int> > s2 = increase(s);
    cout << s2.size() << endl;
    for (set< set<int> >::const_iterator sci=s2.begin(); sci!=s2.end(); sci++) {
 	for (set<int>::const_iterator sci2=(*sci).begin(); sci2!=(*sci).end(); sci2++) {
 	    cout << *sci2 << " ";
 	}
	cout << endl;
    }
    cout << "////////////////"<<endl;

    set< set<int> > s3 = increase(s2);
    cout << s2.size() << endl;
    for (set< set<int> >::const_iterator sci=s3.begin(); sci!=s3.end(); sci++) {
 	for (set<int>::const_iterator sci2=(*sci).begin(); sci2!=(*sci).end(); sci2++) {
 	    cout << *sci2 << " ";
 	}
	cout << endl;
    }
    cout << "////////////////"<<endl;

}
