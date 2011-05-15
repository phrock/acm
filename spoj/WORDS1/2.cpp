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
int g[26][26], v[26], pos1[26], pos2[26];

void dfs(int cur, int v[])
{
    v[cur] = 1;
    for (int i = 0; i < 26; ++i)
        if (!v[i] && g[cur][i]) dfs(i, v);
}

bool is_euler_connected()
{
    int start = 0;
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            if (g[i][j]) v[i] -= g[i][j], v[j] += g[i][j], pos1[i] = pos1[j] = 1, start = i;
    int a = 0, b = 0;
    bool ok = true;
    for (int i = 0; i < 26; ++i)
        if (v[i] && v[i] != 1 && v[i] != -1) { ok = false; break; }
        else if (v[i] == 1) { if (a) { ok = false; break; } else ++a; }
        else if (v[i] == -1) { if (b) { ok = false; break; } else ++b, start = i; }
    if (ok) {
        dfs(start, pos2);
        if (!memcmp(pos1, pos2, sizeof(pos1))) return true;
        else return false;
    } else {
        return false;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int ti = 0; ti < T; ++ti) {
        memset(g, 0, sizeof(g)); memset(v, 0, sizeof(v));
        memset(pos1, 0, sizeof(pos1)); memset(pos2, 0, sizeof(pos2));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%s", s), ++g[s[0]-'a'][s[strlen(s)-1]-'a'];
        printf("%s\n", is_euler_connected() ? "Ordering is possible." : "The door cannot be opened.");
    }
}
