#include <map>
#include <set>
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

const long MAX = 20000;
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

void init_set(set< set<int> >& s, map< set<int>, set<int> >& m)
{
    for (int i=2; i<MAX; i++) {
	if (prime[i] == 1) {
	    set<int> s1;
	    s1.insert(i);
	    s.insert(s1);

	    for (int j=2; j<MAX; j++) {
		if ((prime[j] == 1) && (checkConcatenation(i, j) == true)) {
		    m[s1].insert(j);
		}
	    }
	}
    }
}

set< set<int> > increase_set(set< set<int> >& s, map< set<int>, set<int> >& m)
{
    set< set<int> > s2;

    for (set< set<int> >::const_iterator sci=s.begin(); sci!=s.end(); sci++) {
	if (m[*sci].size() == 0) {
	    continue;
	}
	for (set<int>::const_iterator sci2=m[(*sci)].begin(); sci2!=m[(*sci)].end(); sci2++) {
	    set<int> bigger = *sci;
	    bigger.insert(*sci2);

	    if (s2.find(bigger) != s2.end()) {
		continue;
	    }

	    bool flag = true;
	    for (set<int>::const_iterator sci3=(*sci).begin(); sci3!=(*sci).end(); sci3++) {
		if (checkConcatenation(*sci2, *sci3) == false) {
		    flag = false;
		    break;
		}
	    }
	    if (flag == true) {
		s2.insert(bigger);

		for (set<int>::const_iterator sci3=m[(*sci)].begin(); sci3!=m[(*sci)].end(); sci3++) {
		    if (checkConcatenation(*sci2, *sci3) == true) {
			m[bigger].insert(*sci3);
		    }
		}
	    }
	}
    }
    return s2;
}

int main()
{
    findPrime(prime);
    cout <<"haha"<<endl;
    set< set<int> > s;
    map< set<int>, set<int> > m;

    init_set(s, m);

    cout << s.size()<<endl;

    // for (set< set<int> >::const_iterator sci=s.begin(); sci!=s.end(); sci++) {
    // 	for (set<int>::const_iterator sci2=(*sci).begin(); sci2!=(*sci).end(); sci2++) {
    // 	    cout << *sci2 << " ";
    // 	}
    // 	cout << "  :  ";

    // 	for (set<int>::const_iterator sci2=m[(*sci)].begin(); sci2!=m[(*sci)].end(); sci2++) {
    // 	    cout << *sci2 << " ";
    // 	}
    // 	cout << endl;
    // }

    cout << "////////////////////////" << endl;
    
    set< set<int> > s2 = increase_set(s, m);

    // for (set< set<int> >::const_iterator sci=s2.begin(); sci!=s2.end(); sci++) {
    // 	for (set<int>::const_iterator sci2=(*sci).begin(); sci2!=(*sci).end(); sci2++) {
    // 	    cout << *sci2 << " ";
    // 	}
    // 	cout << "  :  ";

    // 	for (set<int>::const_iterator sci2=m[(*sci)].begin(); sci2!=m[(*sci)].end(); sci2++) {
    // 	    cout << *sci2 << " ";
    // 	}
    // 	cout << endl;
    // }
    cout << "////////////////////////" << endl;
    
    set< set<int> > s3 = increase_set(s2, m);
    set< set<int> > s4 = increase_set(s3, m);
    // for (set< set<int> >::const_iterator sci=s4.begin(); sci!=s4.end(); sci++) {
    // 	for (set<int>::const_iterator sci2=(*sci).begin(); sci2!=(*sci).end(); sci2++) {
    // 	    cout << *sci2 << " ";
    // 	}
    // 	cout << "  :  ";

    // 	for (set<int>::const_iterator sci2=m[(*sci)].begin(); sci2!=m[(*sci)].end(); sci2++) {
    // 	    cout << *sci2 << " ";
    // 	}
    // 	cout << endl;
    // }

    cout << "////////////////////////" << endl;
    set< set<int> > s5 = increase_set(s5, m);

    for (set< set<int> >::const_iterator sci=s5.begin(); sci!=s5.end(); sci++) {
 	for (set<int>::const_iterator sci2=(*sci).begin(); sci2!=(*sci).end(); sci2++) {
 	    cout << *sci2 << " ";
 	}
 	cout << "  :  ";

 	for (set<int>::const_iterator sci2=m[(*sci)].begin(); sci2!=m[(*sci)].end(); sci2++) {
 	    cout << *sci2 << " ";
 	}
 	cout << endl;
    }
}
