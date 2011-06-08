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

struct node {
    int data;
    node *left, *right;
};

void dfs(node *root, int x, int &res)
{
    ++res;
    if (x < root->data) {
        if (!root->left) {
            root->left = (node *)calloc(1, sizeof(node));
            root->left->data = x;
        } else {
            dfs(root->left, x, res);
        }
    } else {
        if (!root->right) {
            root->right = (node *)calloc(1, sizeof(node));
            root->right->data = x;
        } else {
            dfs(root->right, x, res);
        }
    }
}

int main()
{
    int n, x, res = 0;
    scanf("%d", &n);
    node *root = (node *)calloc(1, sizeof(node));
    scanf("%d", &x);
    root->data = x;
    cout << res << endl;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &x);
        dfs(root, x, res);
        printf("%d\n", res);
    }
}
