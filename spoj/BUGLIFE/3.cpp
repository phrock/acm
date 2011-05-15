#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
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

#ifdef DEBUG
#include "/home/rock/program/topcoder/libs/debug.cpp"
#endif
////////////////////////////////////////////////////////////////////////////////

const int MAX=2005;
int matrix[MAX][MAX];
int gender[MAX];
int n, m;

bool set_gender(int cur, int x)
{
    gender[cur] = x;
    for (int i=1; i<=n; ++i)
        if (matrix[cur][i]) {
            if (!gender[i]) {
                if (!set_gender(i, x==1?2:1)) return false;
            } else if (gender[i] == x) return false;
        }
    return true;
}

bool check()
{
    for (int i=1; i<=n; ++i)
        if (!gender[i])
            if (!set_gender(i, 1)) return false;
    return true;
}

int main()
{
    int T, a, b;
    scanf("%d", &T);
    for (int i=0; i<T; ++i) {
        memset(matrix, 0, sizeof(matrix));
        memset(gender, 0, sizeof(gender));
        cout<<"Scenario #"<<i+1<<":"<<endl;
        scanf("%d%d", &n, &m);
        for (int i=0; i<m; ++i) {
            scanf("%d%d", &a, &b);
            matrix[a][b] = matrix[b][a] = 1;
        }
        cout<<(check() ? "No suspicious bugs found!" : "Suspicious bugs found!")<<endl;
    }
}
