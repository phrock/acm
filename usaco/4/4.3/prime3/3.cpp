/*
  ID:   aphrodi1
  LANG: C++
  PROG: prime3
*/
 
#include <fstream>
#include <cstring>
using namespace std;
 
struct 
{
    long num[6],next;		
} node[100000];
struct matrix
{
    long rec[6][6];
} ans[10000];
long tmp[6][6],head[11][11][11][11][11];
long need_sum_dig,tot_ans = 0,tot_node = 0;
bool f[11][11][11][11][11],pp[100000];
 
void initdata()
{
    ifstream infile ("prime3.in");
    infile >> need_sum_dig >> tmp[1][1];
 
    memset(head,-1,sizeof(head));
    memset(f,0,sizeof(f));
    memset(pp,1,sizeof(pp));
 
    infile.close();		
    return;
}
 
void get_sum_dig(long x)
{
    long tmp_sum = 0,dig[6],i;
 
    for(int i = 5; i >= 1; i--)
    {
        dig[i] = x % 10;
        tmp_sum += dig[i];
        x /= 10;
    }
 
    if (tmp_sum != need_sum_dig)
        return;
 
    f[dig[1]][dig[2]][dig[3]][dig[4]][dig[5]] = true;
 
    if (dig[1] == tmp[1][1])
    {
        tot_node++;
        node[tot_node].next = head[dig[1]][10][10][10][10];
        head[dig[1]][10][10][10][10] = tot_node;
        for (i = 1; i <= 5; i++)
            node[tot_node].num[i] = dig[i];		
    }	
 
    tot_node++;
    node[tot_node].next = head[10][10][dig[3]][10][10];
    head[10][10][dig[3]][10][10] = tot_node;
    for (i = 1; i <= 5; i++)
        node[tot_node].num[i] = dig[i];		
 
    tot_node++;
    node[tot_node].next = head[dig[1]][10][10][10][dig[5]];
    head[dig[1]][10][10][10][dig[5]] = tot_node;
    for (i = 1; i <= 5; i++)
        node[tot_node].num[i] = dig[i];		
 
    tot_node++;
    node[tot_node].next = head[10][dig[2]][10][dig[4]][10];
    head[10][dig[2]][10][dig[4]][10] = tot_node;
    for (i = 1; i <= 5; i++)
        node[tot_node].num[i] = dig[i];		
 
    tot_node++;
    node[tot_node].next = head[dig[1]][dig[2]][10][dig[4]][10];
    head[dig[1]][dig[2]][10][dig[4]][10] = tot_node;
    for (i = 1; i <= 5; i++)
        node[tot_node].num[i] = dig[i];		
 
    tot_node++;
    node[tot_node].next = head[dig[1]][10][dig[3]][10][10];
    head[dig[1]][10][dig[3]][10][10] = tot_node;
    for (i = 1; i <= 5; i++)
        node[tot_node].num[i] = dig[i];		
 
    tot_node++;
    node[tot_node].next = head[10][dig[2]][dig[3]][10][10];
    head[10][dig[2]][dig[3]][10][10] = tot_node;
    for (i = 1; i <= 5; i++)
        node[tot_node].num[i] = dig[i];		
 
    tot_node++;
    node[tot_node].next = head[dig[1]][dig[2]][10][10][dig[5]];
    head[dig[1]][dig[2]][10][10][dig[5]] = tot_node;
    for (i = 1; i <= 5; i++)
        node[tot_node].num[i] = dig[i];		
 
    tot_node++;
    node[tot_node].next = head[10][dig[2]][dig[3]][dig[4]][10];
    head[10][dig[2]][dig[3]][dig[4]][10] = tot_node;
    for (i = 1; i <= 5; i++)
        node[tot_node].num[i] = dig[i];		
 
    tot_node++;
    node[tot_node].next = head[dig[1]][10][dig[3]][10][dig[5]];
    head[dig[1]][10][dig[3]][10][dig[5]] = tot_node;
    for (i = 1; i <= 5; i++)
        node[tot_node].num[i] = dig[i];		
 
    return;
}
 
void makeprime()
{
    long i,j;
 
    for (i = 2; i <= 317; i++)
        if (pp[i])
        {
            j = i * i;
            while (j <= 99999)
            {
                pp[j] = false;
                j += i;
            } 
        }
 
    for (i = 10001; i <= 99997; i++)
        if (pp[i])
            get_sum_dig(i);
}
 
bool check_one()
{
    if (head[tmp[1][1]][10][10][10][tmp[5][1]] <= 0)
        return false;
 
    if (head[tmp[1][1]][10][10][10][tmp[1][5]] <= 0)
        return false;
 
    if (head[tmp[5][1]][10][10][10][tmp[5][5]] <= 0)
        return false;
 
    if (head[tmp[1][5]][10][10][10][tmp[5][5]] <= 0)
        return false;
 
    if (head[10][tmp[2][2]][10][tmp[4][2]][10] <= 0)
        return false;
 
    if (head[10][tmp[2][2]][10][tmp[2][4]][10] <= 0)
        return false;
 
    if (head[10][tmp[4][2]][10][tmp[4][4]][10] <= 0)
        return false;
 
    if (head[10][tmp[2][4]][10][tmp[4][4]][10] <= 0)
        return false;
 
    return true;
}
 
bool check_two()
{
    if (head[tmp[1][2]][tmp[2][2]][10][tmp[4][2]][10] <= 0)
        return false;
 
    if (head[tmp[1][4]][tmp[2][4]][10][tmp[4][4]][10] <= 0)
        return false;
 
    if (head[tmp[1][3]][10][tmp[3][3]][10][10] <= 0)
        return false;
 
    return true;
}
 
bool check_three()
{
    if (head[10][tmp[3][2]][tmp[3][3]][10][10] <= 0)
        return false;
 
    if (head[tmp[5][1]][tmp[5][2]][10][10][tmp[5][5]] <= 0)
        return false;
 
    return true;
}
 
bool check_four()
{
    if (! f[tmp[5][1]][tmp[5][2]][tmp[5][3]][tmp[5][4]][tmp[5][5]])
        return false;
 
    if (head[tmp[1][3]][10][tmp[3][3]][10][tmp[5][3]] <= 0)
        return false;
 
    if (head[10][tmp[3][2]][tmp[3][3]][tmp[3][4]][10] <= 0)
        return false;
 
    return true;
}
 
bool check_five()
{
    if (head[10][tmp[2][2]][tmp[2][3]][tmp[2][4]][10] <= 0)
        return false;
 
    if (head[10][tmp[3][2]][tmp[3][3]][tmp[3][4]][10] <= 0)
        return false;
 
    if (head[10][tmp[4][2]][tmp[4][3]][tmp[4][4]][10] <= 0)
        return false;
 
    return true;
}
 
bool check_six()
{
    if (head[tmp[1][1]][tmp[2][1]][10][10][tmp[5][1]] <= 0)
        return false;
 
    if (head[tmp[1][5]][tmp[2][5]][10][10][tmp[5][5]] <= 0)
        return false;		
 
    return true;	
}
 
bool check_seven()
{
    if (! f[tmp[1][1]][tmp[2][1]][tmp[3][1]][tmp[4][1]][tmp[5][1]])
        return false;
 
    if (! f[tmp[1][5]][tmp[2][5]][tmp[3][5]][tmp[4][5]][tmp[5][5]])
        return false;	
 
    if (! f[tmp[3][1]][tmp[3][2]][tmp[3][3]][tmp[3][4]][tmp[3][5]])
        return false;
 
    return true;
}
 
void rec_ans()
{
    tot_ans++;
 
    int i,j;
    for (i = 1; i <= 5; i++)
        for (j = 1; j <= 5; j++)
            ans[tot_ans].rec[i][j] = tmp[i][j];
 
    return;
}
 
void solve()
{	
    long p[10],i,j;
 
    p[1] = head[tmp[1][1]][10][10][10][10];	// main_d
    while (p[1] > 0)
    {
        for (i = 1; i <= 5; i++)
            tmp[i][i] = node[p[1]].num[i];
 
        p[2] = head[10][10][tmp[3][3]][10][10];	// sub_d
        while (p[2] > 0)
        {
            for (i = 5; i >= 1; i--)
                tmp[i][6 - i] = node[p[2]].num[6 - i];
 
            if (! check_one())
            {
                p[2] = node[p[2]].next;
                continue;
            }
 
            p[3] = head[tmp[1][1]][10][10][10][tmp[1][5]];	// 1st_row
            while (p[3] > 0)
            {
                for (j = 2; j <= 4; j++)
                    tmp[1][j] = node[p[3]].num[j];
 
                if (! check_two())
                {
                    p[3] = node[p[3]].next;
                    continue;
                }
 
                p[4] = head[tmp[1][2]][tmp[2][2]][10][tmp[4][2]][10];	// 2nd_col
                while (p[4] > 0)
                {
                    tmp[3][2] = node[p[4]].num[3];
                    tmp[5][2] = node[p[4]].num[5];
 
                    if (! check_three())
                    {
                        p[4] = node[p[4]].next;
                        continue;	
                    }
 
                    p[5] = head[tmp[1][4]][tmp[2][4]][10][tmp[4][4]][10];	// 4th_col
                    while (p[5] > 0)
                    {						
                        tmp[3][4] = node[p[5]].num[3];
                        tmp[5][4] = node[p[5]].num[5];	
                        tmp[5][3] = need_sum_dig - tmp[5][1] - tmp[5][2] - tmp[5][4] - tmp[5][5];
 
                        if (! check_four())
                        {
                            p[5] = node[p[5]].next;
                            continue;								
                        }
 
                        p[6] = head[tmp[1][3]][10][tmp[3][3]][10][tmp[5][3]];	// 3rd_col
                        while (p[6] > 0)
                        {
                            tmp[2][3] = node[p[6]].num[2];
                            tmp[4][3] = node[p[6]].num[4];
 
                            if (! check_five())
                            {
                                p[6] = node[p[6]].next;
                                continue;
                            }
 
                            p[7] = head[10][tmp[2][2]][tmp[2][3]][tmp[2][4]][10];	// 2nd_row
                            while (p[7] > 0)
                            {
                                tmp[2][1] = node[p[7]].num[1];
                                tmp[2][5] = node[p[7]].num[5];
 
                                if (! check_six())
                                {
                                    p[7] = node[p[7]].next;
                                    continue;
                                }
 
                                p[8] = head[10][tmp[4][2]][tmp[4][3]][tmp[4][4]][10];	// 4th_row
                                while (p[8] > 0)
                                {
                                    tmp[4][1] = node[p[8]].num[1];
                                    tmp[4][5] = node[p[8]].num[5];	
                                    tmp[3][1] = need_sum_dig - tmp[1][1] - tmp[2][1] - tmp[4][1] - tmp[5][1];
                                    tmp[3][5] = need_sum_dig - tmp[1][5] - tmp[2][5] - tmp[4][5] - tmp[5][5];
 
                                    if (! check_seven())
                                    {
                                        p[8] = node[p[8]].next;
                                        continue;	
                                    }
 
                                    rec_ans();
 
                                    p[8] = node[p[8]].next;
                                }
 
                                p[7] = node[p[7]].next;
                            }
 
                            p[6] = node[p[6]].next;
                        }
 
                        p[5] = node[p[5]].next;
                    }
 
                    p[4] = node[p[4]].next;
                }
 
                p[3] = node[p[3]].next;
            }
 
            p[2] = node[p[2]].next;				
        }
 
        p[1] = node[p[1]].next;
    }
 
    return;
}
 
bool comp(matrix a,matrix b)
{
    int i,j;
 
    for (i = 1; i <= 5; i++)
        for (j = 1; j <= 5; j++)
            if (a.rec[i][j] < b.rec[i][j])
                return true;
            else if (a.rec[i][j] > b.rec[i][j])
                return false;
 
    return false;	
}
 
void sort_ans(long s,long t)
{
    long l = s,r = t;
    matrix key = ans[(t + s) >> 1];
 
    while (l <= r)
    {
        while (comp(ans[l],key)) l++;
        while (comp(key,ans[r])) r--;
        if (l <= r)
        {
            swap(ans[l],ans[r]);
            l++;
            r--;
        }
    }
 
    if (s < r) sort_ans(s,r);
    if (l < t) sort_ans(l,t);
}
 
void outitdata()
{
    ofstream outfile ("prime3.out");
    int i,j;
    for (long k = 1; k < tot_ans; k++)
    {
        for (i = 1; i <= 5; i++)
        {
            for (j = 1; j <= 5; j++)
                outfile << ans[k].rec[i][j];
            outfile << endl;
        }
        outfile << endl;		
    }
 
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 5; j++)
            outfile << ans[tot_ans].rec[i][j];
        outfile << endl;
    }
 
    outfile.close();		
    return;
}
 
int main()
{
    initdata();
    makeprime();
    solve();
    sort_ans(1,tot_ans);
    outitdata();
 
    return 0;
}
