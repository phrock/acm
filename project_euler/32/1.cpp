#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

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
    cout <<"/////////"<<endl;
    while (n != 0) {
	if (n%10 == 0) {
	    return v;
	}
	array[n%10] = 0;
	n /= 10;
    }
    cout <<"/////////"<<endl;
    for (int i=1; i<=9; i++) {
	if (array[i] != 0) {
	    v.push_back(i);
	}
    }
    cout <<"/////////"<<endl;
    vector<int> result;
    sort(v.begin(), v.end());
    int a = 0;
    int b = 0;
    for (int i=0; i<v.size(); i++) {
	a = a*10 + v[i];
    }
    for (int j=v.size()-1; j>=0; j--) {
	b = b*10 + v[j];
    }
    cout <<"/////////*******"<<endl;
    for (int i=a; i<=b; i++) {
	cout  <<"***********  "<<i << endl;
	if (nonDup(i) == true) {
	    cout  <<"***********  "<<i << endl;
	    result.push_back(i);
	}
    }

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
