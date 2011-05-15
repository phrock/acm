#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    long long n, m;
    double res = 0;
    cout << setiosflags(ios::fixed) << setprecision(6);
    while (cin >> n >> m && (n || m)) {
        if (n > m) res = 0;
        else res = (m - n + 1.) / (m + 1.);
        cout << res << endl;
    }
}
