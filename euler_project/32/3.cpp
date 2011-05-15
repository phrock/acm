#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> combine(const vector<int>& v)
{
    vector<int> a = v;
    sort(a.begin(), a.end());

    vector<int> result;

    while (true) {
	// for (int i=0; i<a.size(); i++) {
	//     cout << a[i] << " ";
	// }
	// cout << "********" << endl;

	int element = 0;
	for (int i=0; i<a.size(); i++) {
	    element = element*10 + a[i];
	}

	result.push_back(element);

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

bool nonDup(int n)
{
    set<int> s;
    int tmp = 0;
    while (n != 0) {
	tmp = n%10;
	if (s.count(tmp) > 0) {
	    return false;
	}
	s.insert(tmp);
    }
    return true;
}

vector<int> createMultiplier(int n)
{
    vector<int> v;
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    while (n != 0) {
	if (n%10 == 0) {
	    return v;
	}
	array[n%10] = 0;
	n /= 10;
    }

    for (int i=1; i<=9; i++) {
	if (array[i] != 0) {
	    v.push_back(i);
	}
    }

    vector<int> result = combine(v);

    return result;
}

long long countSum(long long n)
{
    set<long long> s;
    vector<int> v;
    long long tmp = 0LL;

    for (long long i=2; i<=n; i++) {
	v = createMultiplier(i);
	if (v.size() != 0) {
	    for (int j=0; j<v.size(); j++) {
		cout << "<<<<<<<<<  "<< v[j] << endl;
		tmp = i * v[j];
		s.insert(tmp);
	    }
	}
    }

    long long result = 0;
    for (set<long long>::const_iterator sci=s.begin(); sci!=s.end(); sci++) {
	result += *sci;
    }

    return result;
}

int main()
{
    int n = 2;

    cout << countSum(n) << endl;
}
