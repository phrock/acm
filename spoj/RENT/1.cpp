#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct node {
    int start;
    int stop;
    int price;
};

node a[10005];
int dp[10005];

bool cmp(const node &x, const node &y) { return x.stop < y.stop; }

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int n;
        cin >> n;
        node aux;
        aux.start = aux.stop = aux.price = 0;
        a[0] = aux;
        for (int i = 1; i <= n; ++i) {
            cin >> aux.start >> aux.stop >> aux.price;
            aux.stop += aux.start;
            a[i] = aux;
        }
        sort(a, a + n + 1, cmp);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            // int j = i;
            // while (a[--j].stop > a[i].start) ;
            node tmp;
            tmp.stop = a[i].start;
            int j = upper_bound(a, a + n + 1, tmp, cmp) - a - 1;
            dp[i] = max(dp[i - 1], dp[j] + a[i].price);
        }
        cout << dp[n] << endl;
    }
}
