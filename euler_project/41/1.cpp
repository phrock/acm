#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <cmath>

using namespace std;

const long MAX = 10000000;

vector< vector<int> > permutation(const vector<int>& v)
{
    vector<int> a = v;
    sort(a.begin(), a.end());

    vector< vector<int> > result;

    while (true) {
	// for (int i=0; i<a.size(); i++) {
	//     cout << a[i] << " ";
	// }
	// cout << "********" << endl;

	// int element = 0;
	// for (int i=0; i<a.size(); i++) {
	//     element = element*10 + a[i];
	// }

	// result.push_back(element);

	result.push_back(a);

	int k = a.size() - 1;
	while ((k > 0) && (a[k] <= a[k-1])) {
	    k--;
	}
	if (k == 0) {
	    break;
	}

	int lessBig = k;
	for (int i=k; i<a.size(); i++) {
	    if ((a[i] > a[k-1]) && (a[i] < a[lessBig])) {
		lessBig = i;
	    }
	}
	swap(a[k-1], a[lessBig]);
	sort(a.begin()+k, a.end());
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

int main()
{
    bitset<MAX> bs(0);
    findPrime(bs);
    cout <<"haha"<< endl;
    for (int d=7; d>=1; d--) {

	vector<int> v;
	for (int i=1; i<=d; i++) {
	    v.push_back(i);
	}

	vector< vector<int> > p = permutation(v);

	for (int i=p.size()-1; i>=0; i--) {
	    int x = 0;
	    for (int j=0; j<p[i].size(); j++) {
		x = x*10 + p[i][j];
	    }
	    if (bs[x] == 1) {
		cout << x << endl;
		return 0;
	    }
	}

    }
}
