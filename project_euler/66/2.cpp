#include <gmpxx.h>
#include <map>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> initVector(int n)
{
    vector<int> v(4);
    int sq = sqrt(n);

    v[0] = sq;
    v[1] = 1;
    v[2] = n;
    v[3] = sq;

    return v;
}

vector<int> nextVector(const vector<int>& v)
{
    vector<int> result(4);

    int a = v[2] - v[3]*v[3];
    a /= v[1];
    int b = v[2];
    int c = v[3];

    int sq = sqrt(b);
    
    int d = 0;
    while ((d*a - c) <= sq) {
	d++;
    }
    d--;

    c = d*a - c;
    // cout <<d<<" "<< a<< " " <<b<<" "<<c<<endl;
    result[0] = d;
    result[1] = a;
    result[2] = b;
    result[3] = c;

    return result;
}
	
int getRepeatBlock(int n)
{
    vector<int> v = initVector(n);

    for (int i=0; i<v.size(); i++) {
	cout << v[i] << " ";
    }
    cout << endl;

    map< vector<int>, int > mp;
    mp[v]++;

    int result = 0;
    vector<int> next = nextVector(v);
    while (mp[next] == 0) {
	mp[next]++;
	next = nextVector(next);
	result++;
    }

    return result;
}

bool sqrtNum(int n)
{
    int x = sqrt(n);
    if (x*x == n) {
	return true;
    } else {
	return false;
    }
}

bool checkEquation(mpz_class h, mpz_class k, int d)
{
    // cout << h << " " << k << endl;
    if (h*h == d*k*k+1) {
	return true;
    } else {
	return false;
    }
}

mpz_class getX(int n)
{
    vector<int> v = initVector(n);

    mpz_class h0 = v[0];
    mpz_class k0 = 1;

    if (checkEquation(h0, k0, n) == true) {
	return h0;
    }

    vector<int> next = nextVector(v);
    mpz_class h1 = next[0]*h0 + 1;
    mpz_class k1 = next[0]*k0;

    while (checkEquation(h1, k1, n) == false) {
	next = nextVector(next);
	mpz_class h2 = next[0]*h1 + h0;
	mpz_class k2 = next[0]*k1 + k0;

	h0 = h1;
	k0 = k1;

	h1 = h2;
	k1 = k2;
    }

    return h1;
}

long long minValue(int n)
{
    long long result = 0;
    mpz_class x = 0;
    for (int i=1; i<=n; i++) {
	if (sqrtNum(i) == true) {
	    continue;
	}
	mpz_class tmp = getX(i);
	cout << i << " : " << tmp << endl;
	if (tmp > x) {
	    x = tmp;
	    result = i;
	    // cout << x << endl;
	}
    }
    return result;
}

int main()
{
    int n = 1000;
    cout << minValue(n) << endl;
    // cout <<    getX(5) << endl;
}
