#include <vector>
#include <iostream>

using namespace std;

int methods(int n, const vector<int>& v, int k)
{
    if (n == 0) {
	return 1;
    }
    if ((n < 0) || (k == 0)) {
	return 0;
    }

    return methods(n, v, k-1) + methods(n-v[k-1], v, k);
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(10);
    v.push_back(20);
    v.push_back(50);
    v.push_back(100);
    v.push_back(200);

    cout << methods(5, v, v.size()) << endl;
    cout << methods(200, v, v.size()) << endl;
    cout << methods(500, v, v.size()) << endl;
}
