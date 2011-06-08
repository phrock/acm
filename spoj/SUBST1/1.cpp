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
#include "/home/rock/program/acm/topcoder/libs/debug.cpp"
#endif

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

struct trie {
    trie *next[52];
};

trie * init_trie()
{
    trie *node = (trie *)malloc(sizeof(trie));
    for (int i = 0; i < 52; ++i)
        node->next[i] = NULL;

    return node;
}

long long res

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        string s;
        cin >> s;
        cout << func(s) << endl;
    }
}
