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

struct trie {
    trie *next[10];
    char data;
    bool is_leaf;
};

trie * init_trie()
{
    trie *node = (trie *)malloc(sizeof(trie));
    for (int i = 0; i < 10; ++i)
        node->next[i] = NULL;
    node->data = '\0';
    node->is_leaf = false;

    return node;
}

void add_trie(trie *root, const string &s, bool &ok)
{
    trie *cur = root;
    for (int i = 0; i < (int)(s).size(); ++i) {
        int idx = s[i] - '0';
        if (cur->next[idx] == NULL) {
            trie *node = init_trie();
            node->data = s[i];
            if (i == (int)(s).size() - 1)
                node->is_leaf = true;
            cur->next[idx] = node;
        } else {
            if (cur->next[idx]->is_leaf == true || i == (int)(s).size() - 1)
                ok = false;
        }
        cur = cur->next[idx];
    }
}

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int n;
        cin >> n;
        bool ok =true;
        trie *root = init_trie();
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            if (!ok) continue;
            add_trie(root, s, ok);
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}
