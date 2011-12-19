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
vector<int> candidate;
int g[5], column_sum[5];
bool found;

int sum_digits(int n)
{
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int reverse_q(int n)
{
    string s = *({stringstream ss; ss << (n); static string _; ss >> _; &_;});
    reverse((s).begin(), (s).end());
    return *({stringstream ss; ss << (s); static int _; ss >> _; &_;});
}

void dfs(int cur)
{
    cout << cur << endl;
    if (cur == 5) {
        if (found) cout << endl;
        found = true;
        for (int i = 0; i < 5; ++i)
            cout << g[i] << endl;
        return;
    }
    for (int k = 0; k < (int)(candidate).size(); ++k) {
        int backup = g[cur];
        g[cur] = candidate[k];
        column_sum[0] += g[cur] / 10000;
        column_sum[1] += g[cur] / 1000 % 10;
        column_sum[2] += g[cur] / 100 % 10;
        column_sum[3] += g[cur] / 10 % 10;
        column_sum[4] += g[cur] % 10;
        bool ok = true;
        if (k == 0) {
            if (column_sum[0] != left_top)
                ok = false;
            for (int i = 0; i < 5; ++i)
                if (column_sum[i] == 0) {
                    ok = false;
                    break;
                }
        }
        for (int i = 0; i < 5; ++i)
            if (column_sum[i] > sum) {
                ok = false;
                break;
            }
        int cross_left = 0, cross_right = 0, tmp = 10000, p = 0, q = 0;
        for (int i = 0; i <= cur; ++i) {
            cross_left += g[i] / tmp % 10;
            p = p * 10 + g[i] / tmp % 10;
            tmp /= 10;
        }
        tmp = 1;
        for (int i = 0; i <= cur; ++i) {
            cross_right += g[i] / tmp % 10;
            q = q * 10 + g[i] / tmp % 10;
            tmp *= 10;
        }
        if (cross_left > sum || cross_right > sum)
            ok = false;
        if (!ok) {
            column_sum[0] -= g[cur] / 10000;
            column_sum[1] -= g[cur] / 1000 % 10;
            column_sum[2] -= g[cur] / 100 % 10;
            column_sum[3] -= g[cur] / 10 % 10;
            column_sum[4] -= g[cur] % 10;
            g[cur] = backup;
            continue;
        }
        if (cur < 4) {
            dfs(cur + 1);
            column_sum[0] -= g[cur] / 10000;
            column_sum[1] -= g[cur] / 1000 % 10;
            column_sum[2] -= g[cur] / 100 % 10;
            column_sum[3] -= g[cur] / 10 % 10;
            column_sum[4] -= g[cur] % 10;
            g[cur] = backup;
        } else {
            for (int i = 0; i < 5; ++i)
                if (column_sum[i] != sum) {
                    ok = false;
                    break;
                }
            if (cross_left != sum || cross_right != sum)
                ok = false;
            int tmp = 10000;
            for (int i = 0; i < 5; ++i) {
                int aux = 0;
                for (int j = 0; j < 5; ++j)
                    aux = aux * 10 + g[j] / tmp % 10;
                tmp /= 10;
                if (!is_prime[aux]) {
                    ok = false;
                    break;
                }
            }
            q = reverse_q(q);
            if (p < 10000 || !is_prime[p] || q < 10000 || !is_prime[q])
                ok = false;
            if (ok)
                dfs(cur + 1);
            column_sum[0] -= g[cur] / 10000;
            column_sum[1] -= g[cur] / 1000 % 10;
            column_sum[2] -= g[cur] / 100 % 10;
            column_sum[3] -= g[cur] / 10 % 10;
            column_sum[4] -= g[cur] % 10;
            g[cur] = backup;
        }
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
    for (int i = 0; i < prime_cnt; ++i)
        if (prime[i] > 10000 && sum_digits(prime[i]) == sum)
            candidate.push_back(prime[i]);
    #ifdef DEBUG
    print(candidate);
    #endif
    found = false;
    dfs(0);
    if (!found)
        cout << "NONE" << endl;
}
