#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector< vector<int> > combine(const vector<int>& v)
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

bool concatenate(const vector<int>& v)
{
    for (int i=1; i<=v.size()/2; i++) {
	int x = 0;
	for (int j=0; j<i; j++) {
	    x = x*10 + v[j];
	}

	int m = 2;
	int k = i;
	while (k <= v.size()) {
	    if (k == v.size()) {
		// cout << "xxxxxxxxx: " << x << endl;
		return true;
	    }

	    int y = x*m;
	    int d = 1;
	    int p = 10;
	    while (y/p > 0) {
		d++;
		p *= 10;
	    }

	    if (k+d > v.size()) {
		break;
	    }

	    int z = 0;
	    for (int j=k; j<k+d; j++) {
		z = z*10 + v[j];
	    }
	    // cout << "xxxxxxxxx: " << x << endl;
	    // cout << "yyyyyy: " << y << endl;
	    // cout << "zzzzzzzz: " << z << endl;
	    if (y != z) {
		break;
	    }

	    k += d;
	    m++;
	}
    }

    return false;
}

int main()
{
    vector<int> v;
    for (int i=1; i<=9; i++) {
	v.push_back(i);
    }

    vector< vector<int> > r = combine(v);

    for (int i=r.size()-1; i>=0; i--) {
 	if (concatenate(r[i]) == true) {
 	    for (int j=0; j<r[i].size(); j++) {
 		cout <<r[i][j];
 	    }
 	    cout << endl;
 	    break;
 	}
    }

    // int a[] = {1,9,2,3,8,4,5,7,6};
    // vector<int> test(a, a+sizeof(a)/sizeof(int));
    // // for (int i=0; i<test.size(); i++) cout <<test[i];
    // concatenate(test);
}
