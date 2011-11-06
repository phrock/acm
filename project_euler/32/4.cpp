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

void countSum(const vector<int>& v, set<int>& s)
{
    for (int i=1; i<=v.size()-2; i++) {
	for (int j=1; (j <= i) && (v.size()-j-i <= i); j++) {
	    int product = 0;
	    int multiplicand = 0;
	    int multiplier = 0;

	    for (int k=0; k<i; k++) {
		product = product*10 + v[k];
	    }
	    for (int k=i; k<i+j; k++) {
		multiplicand = multiplicand*10 + v[k];
	    }
	    for (int k=i+j; k<v.size(); k++) {
		multiplier = multiplier*10 + v[k];
	    }

	    if (product == (multiplicand * multiplier)) {
		// sum += product; // + multiplicand + multiplier;
		s.insert(product);
		cout << product << " = " << multiplicand << " * " << multiplier << endl;
	    }
	}
    }

}

int main()
{
    vector<int> v;
    for (int i=1; i<=9; i++) {
	v.push_back(i);
    }

    vector< vector<int> > r = combine(v);

    int sum = 0;

    set<int> s;
    for (int i=0; i<r.size(); i++) {
	// for (int j=0; j<r[i].size(); j++) {
	//     cout <<r[i][j] << " ";
	// }
	// cout << endl;

	countSum(r[i], s);
    }

    for (set<int>::const_iterator sci=s.begin(); sci!=s.end(); sci++) {
	sum += *sci;
    }

    cout << sum << endl;
}
