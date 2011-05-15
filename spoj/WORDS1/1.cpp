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

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

char s[1005];
int n;
int g[26][26];

bool is_connect()
{
    vector<int> v(26);
    int start = 0;
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            if (g[i][j]) v[i] = v[j] = 1, start = i;
    for (int i = 0; i < 26; ++i) {
        if (!v[i]) continue;
        bool ok = false;
        for (int j = 0; j < 26; ++j)
            if (g[j][i]) { ok = true; break; }
        if (!ok) { start = i; break; }
    }
    vector<int> v2(26);
    queue<int> q;
    q.push(start);
    v2[start] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i) {
            if (v2[i]) continue;
            if (g[x][i]) q.push(i), v2[i] = 1;
        }
    }
    return v == v2;
}

bool is_euler_loop()
{
    if (!is_connect()) return false;
    vector<int> v(26);
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            if (g[i][j]) v[i] -= g[i][j], v[j] += g[i][j];
    #ifdef DEBUG
    print(v);    
    #endif
    int a = 0, b = 0;
    bool ok = true;
    for (int i = 0; i < 26; ++i)
        if (v[i] && v[i] != 1 && v[i] != -1) { ok = false; break; }
        else if (v[i] == 1) { if (a) { ok = false; break; } else ++a; }
        else if (v[i] == -1) { if (b) { ok = false; break; } else ++b; }
    if (ok && ((!a && !b) || (a == 1 && b == 1))) ok = true;
    else ok = false;
    return ok;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int ti = 0; ti < T; ++ti) {
        memset(g, 0, sizeof(g));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%s", s), ++g[s[0]-'a'][s[strlen(s)-1]-'a'];
        printf("%s\n", is_euler_loop() ? "Ordering is possible." : "The door cannot be opened.");
    }
}
