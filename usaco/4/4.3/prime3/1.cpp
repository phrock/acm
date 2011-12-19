/*
  ID:   aphrodi1
  LANG: C++
  PROG: prime3
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

ifstream fin("prime3.in");
ofstream fout("prime3.out");
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

const int MAX = 100005;
bitset<MAX> is_prime;
int prime[MAX];
int prime_cnt;

void create_prime()
{
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (long long i = 2; i * i < MAX; ++i)
        if (is_prime[i])
            for (long long j = i * i; j < MAX; j += i)
                is_prime[j] = 0;
    prime_cnt = 0;
    for (int i = 0; i < MAX; ++i)
        if (is_prime[i])
            prime[prime_cnt++] = i;
}

int sum, left_top;
int g[5][5], row_sum[5][5], column_sum[5][5];
bool found;

void dfs(int row, int column)
{
    #ifdef DEBUG
    // cout << row << " " << column <<endl;
// if (g[0][0] == 1 && g[0][1] == 1 && g[0][2] == 3 && g[0][3] == 5 && g[0][4] == 1 && g[1][0] == 1 && g[1][1] == 4 && g[1][2] == 0 && g[1][3] == 3 && row == 1 && column == 4) {
//     cout << row << " *** " << column <<endl;
//     print2(g, 5, 5);
 // }
    #endif
    if (row == 5) {
        if (found) cout << endl;
        found = true;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j)
                cout << g[i][j];
            cout << endl;
        }
        return;
    }

    // if (g[0][0] == 1 && g[0][1] == 1 && g[0][2] == 3 && g[0][3] == 5 && g[0][4] == 1 && g[1][0] == 1 && g[1][1] == 4 && g[1][2] == 0 && g[1][3] == 3 && row == 1 && column == 4)
    //     cout << "---------------------" << endl;
    int backup = g[row][column], row_backup = row_sum[row][column], column_backup = column_sum[row][column];
    for (int i = 0; i <= 9; ++i) {
        if (i == 0 && (row == 0 || column == 0))
            continue;
        if (i % 2 == 0 && (row == 4 || column == 4))
            continue;
        g[row][column] = i;
        // if (g[0][0] == 1 && g[0][1] == 1 && g[0][2] == 3 && g[0][3] == 5 && g[0][4] == 1 && g[1][0] == 1 && g[1][1] == 4 && g[1][2] == 0 && g[1][3] == 3 && row == 1 && column == 4)
        //     cout << "+++++++++++++++ " << i << endl;
        // if (g[0][0] == 1 && g[0][1] == 1 && g[0][2] == 3 && g[0][3] == 5 && g[0][4] == 1 && g[1][0] == 1 && g[1][1] == 4 && g[1][2] == 0 && g[1][3] == 3 && row == 1 && column == 4 && g[row][column] == 3)
        // if (g[0][0] == 1 && g[0][1] == 1 && g[0][2] == 3 && g[0][3] == 5 && g[0][4] == 1 && g[1][0] == 1 && g[1][1] == 4 && g[1][2] == 0 && g[1][3] == 3 && i == 3 && g[row][column] == 3) {
        //     cout << row << " " << column << endl;
        //     #ifdef DEBUG
        //     print2(g, 5, 5);
        //     #endif
    // cout << "hhh" << i << endl;
        // }
    row_sum[row][column] = column == 0 ? g[row][column] : row_sum[row][column - 1] + g[row][column];
    column_sum[row][column] = row == 0 ? g[row][column] : column_sum[row - 1][column] + g[row][column];
    if (row_sum[row][column] > sum || column_sum[row][column] > sum) {
        g[row][column] = backup;
        row_sum[row][column] = row_backup;
        column_sum[row][column] = column_backup;
        return;
    }
    int cross_left = 0, cross_right = 0;
    if (row == column) {
        for (int i = 0; i <= row; ++i)
            cross_left += g[i][i];
        if (cross_left > sum) {
            g[row][column] = backup;
            row_sum[row][column] = row_backup;
            column_sum[row][column] = column_backup;
            return;
        }
    }
    if (row + column == 4) {
        for (int i = 0; i <= row; ++i)
            cross_right += g[row][4 - row];
        if (cross_right > sum) {
            g[row][column] = backup;
            row_sum[row][column] = row_backup;
            column_sum[row][column] = column_backup;
            return;
        }
    }

    if ((row == 4 && column == 0) && (cross_right != sum || !is_prime[cross_right]))
        continue;
    if ((row == 4 && column == 4) && (cross_left != sum || !is_prime[cross_left]))
        continue;
    if (column == 4) {
        int aux = g[row][0] * 10000 + g[row][1] * 1000 + g[row][2] * 100 +
            g[row][3] * 10 + g[row][4];
        if (!is_prime[aux] || row_sum[row][column] != sum) {
            g[row][column] = backup;
            row_sum[row][column] = row_backup;
            column_sum[row][column] = column_backup;
            continue;
        }
    }
    // if (g[0][0] == 1 && g[0][1] == 1 && g[0][2] == 3 && g[0][3] == 5 && g[0][4] == 1 && g[1][0] == 1 && g[1][1] == 4 && g[1][2] == 0 && g[1][3] == 3 && i == 3)
    //     cout << "kkkkkkkkkkkkk"<<endl;
    if (row == 4) {
        int aux = g[0][column] * 10000 + g[1][column] * 1000 +
            g[2][column] * 100 + g[3][column] * 10 + g[4][column];
        if (!is_prime[aux] || column_sum[row][column] != sum) {
            g[row][column] = backup;
            row_sum[row][column] = row_backup;
            column_sum[row][column] = column_backup;
            continue;
        }
    }
    // if (g[0][0] == 1 && g[0][1] == 1 && g[0][2] == 3 && g[0][3] == 5 && g[0][4] == 1 && g[1][0] == 1 && g[1][1] == 4 && g[1][2] == 0 && g[1][3] == 3 && i == 3) {
        // #ifdef DEBUG
        // print2(g, 5, 5);
        // #endif
        // cout << row << " " << column << endl;
        // cout << "kkkkkkkxxxxxxxxxxxxxxxkkkkkk"<<endl;}

    if (column < 4)
        dfs(row, column + 1);
    else
        dfs(row + 1, 0);
    g[row][column] = backup;
    row_sum[row][column] = row_backup;
    column_sum[row][column] = column_backup;
    }
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

    cin >> sum >> left_top;
    create_prime();
    g[0][0] = row_sum[0][0] = column_sum[0][0] = left_top;
    found = false;
    dfs(0, 1);
    if (!found)
        cout << "NONE" << endl;
}
