/*
  ID:   aphrodi1
  LANG: C++
  PROG: cowcycle
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

ifstream fin("cowcycle.in");
ofstream fout("cowcycle.out");
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

int NF, NR, F1, F2, R1, R2;
double variance;
double front_gear[10], rear_gear[10];
double res_front_gear[10], res_rear_gear[10];

double calculate_variance()
{
    double res = 0;
    vector<double> v;
    for (int i = 0; i < NF; ++i)
        for (int j = 0; j < NR; ++j)
            v.push_back(fabs(front_gear[i] - rear_gear[j]));
    sort((v).begin(), (v).end());
    double mean = accumulate((v).begin(), (v).end(), 0.0) / (int)(v).size();
    for (int i = 0; i < (int)(v).size(); ++i)
        res += (v[i] - mean) * (v[i] - mean);
    return res;
}

void dfs(int front_cnt, int rear_cnt, int front_start, int rear_start)
{
    cout << front_cnt << " " << rear_cnt << " " << front_start << " " << rear_start << " " << front_gear[0] << endl;
    if (rear_cnt == NR) {
        cout <<"haha"<<endl;;
        double aux = calculate_variance();
        if (aux < variance) {
            variance = aux;
            for (int i = 0; i < NF; ++i)
                res_front_gear[i] = front_gear[i];
            for (int i = 0; i < NR; ++i)
                res_rear_gear[i] = rear_gear[i];
        }
        return;
    }
    if (front_cnt < NF) {
        for (int i = front_start; i <= F2; ++i) {
            if (F2 - i + 1 < NF - front_cnt)
                return;
            int backup = front_gear[front_cnt];
            front_gear[front_cnt] = i;
            dfs(front_cnt + 1, rear_cnt, i + 1, rear_start);
            front_gear[front_cnt] = backup;
        }
    } else {
        if (front_gear[NF - 1] * R2 < 3 * front_gear[0] * rear_start)
            return;
        for (int i = rear_start; i <= R2; ++i) {
            if (R2 - i + 1 < NR - rear_cnt)
                return;
            int backup = rear_gear[rear_cnt];
            rear_gear[rear_cnt] = i;
            dfs(front_cnt, rear_cnt + 1, front_start, i + 1);
            rear_gear[rear_cnt] = backup;
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

    cin >> NF >> NR >> F1 >> F2 >> R1 >> R2;
    variance = INT_MAX;
    dfs(0, 0, F1, R1);
    for (int i = 0; i < NF; ++i) {
        if (i) cout << " ";
        cout << res_front_gear[i];
    }
    cout << endl;
    for (int i = 0; i < NR; ++i) {
        if (i) cout << " ";
        cout << res_rear_gear[i];
    }
    cout << endl;
}
