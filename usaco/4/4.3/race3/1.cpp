/*
  ID:   aphrodi1
  LANG: C++
  PROG: race3
*/

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
#include "/Users/Aphrodite/program/acm/lib/debug.cpp"
#endif

ifstream fin("race3.in");
ofstream fout("race3.out");
streambuf *cin_buf = cin.rdbuf();
streambuf *cout_buf = cout.rdbuf();

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/

vector< vector<int> > g;
int finish;

vector<int> accessable(int x)
{
    vector<int> visited((int)(g).size());
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while (!q.empty()) {
        int ft = q.front();
        q.pop();
        visited[ft] = 1;
        for (int i = 0; i < (int)(g[ft]).size(); ++i) {
            int node = g[ft][i];
            if (node == x || visited[node])
                continue;
            q.push(node);
        }
    }
    return visited;
}

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    /////////////////////////////////////////////////////////////////////////

    int tmp;
    while (cin >> tmp && tmp != -1) {
        vector<int> v;
        if (tmp == -2) {
            g.push_back(v);
            continue;
        }
        v.push_back(tmp);
        while (cin >> tmp && tmp != -2)
            v.push_back(tmp);
        // #ifdef DEBUG
        // print(v);
        // #endif
        g.push_back(v);
    }
    finish = (int)(g).size() - 1;

    vector< vector<int> > access((int)(g).size());
    vector<int> unavoidable;
    for (int i = 1; i < finish; ++i) {
        access[i] = accessable(i);
        if (!access[i][finish])
            unavoidable.push_back(i);
    }
    cout << (int)(unavoidable).size();
    for (int i = 0; i < (int)(unavoidable).size(); ++i)
        cout << " " << unavoidable[i];
    cout << endl;
    #ifdef DEBUG
    print2(access);
    #endif

    vector<int> split_point;
    for (int i = 0; i < (int)(unavoidable).size(); ++i) {
        int node = unavoidable[i];
        bool ok = true;
        vector<int> visited((int)(g).size());
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int ft = q.front();
            q.pop();
            if (access[node][ft] == 1) {
                ok = false;
                break;
            }
            visited[ft] = 1;
            for (int i = 0; i < (int)(g[ft]).size(); ++i) {
                int aux = g[ft][i];
                if (!visited[aux])
                    q.push(aux);
            }
        }
        if (ok)
            split_point.push_back(node);
    }
    cout << (int)(split_point).size();
    for (int i = 0; i < (int)(split_point).size(); ++i)
        cout << " " << split_point[i];
    cout << endl;
}
