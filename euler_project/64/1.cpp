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
    cout <<d<<" "<< a<< " " <<b<<" "<<c<<endl;
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

int main()
{
    int n = 10000;

    int result = 0;
    for (int i=2; i<=n; i++) {
	cout << "*iiiiii: "<<i<<endl;
	if (sqrtNum(i) == true) {
	    continue;
	}
 	int x = getRepeatBlock(i);
 	if (x%2 == 1) {
	    // cout << " haha "<<endl;
 	    result++;
 	}
    }

    cout << result;

    // getRepeatBlock(23);
}
