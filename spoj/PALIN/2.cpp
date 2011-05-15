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
////////////////////////////////////////////////////////////////////////////////

void addString (char s[])
{
    int n=strlen(s);
    int i=0, j=n-1;
    while (i<j) swap(s[i], s[j]), i++, j--;
    for (i=0; i<n; i++)
        if (s[i]=='9') s[i]='0';
        else { s[i]++; break; }
    if (i==n) s[i]='1';
    i=0, j=strlen(s)-1;
    while (i<j) swap(s[i], s[j]), i++, j--;
}

int main()
{
    int t;
    cin>>t;
    char s[1000005], aux[1000005], res[1000005];
    for (int ti=0; ti<t; ++ti) {
        memset(s, 0, sizeof(s));
        memset(aux, 0, sizeof(aux));
        memset(res, 0, sizeof(res));
        scanf("%s", s);
        int n=strlen(s);
        strncpy(aux, s, (n+1)/2);
        // bool ok=true;
        // int a=(n-1)/2, b=n/2;
        // while (a>=0) if (s[a]>s[b]) { ok=false; break; } else if (s[a]<s[b]) break; else a++, b--;
        // if (ok) addString(aux);
        if (n%2==0) {
            strcpy(res, aux);
            int p=strlen(res), q=strlen(aux)-1;
            if (strlen(aux)!=(n+1)/2) q--;
            for (int i=q; i>=0; --i) res[p++]=aux[i];
            res[p]=0;
        } else {
            if (strlen(aux)==(n+1)/2) {
                strcpy(res, aux);
                int p=strlen(res), q=strlen(aux)-2;
                for (int i=q; i>=0; --i) res[p++]=aux[i];
                res[p]=0;
            } else {
                aux[strlen(aux)-1]=0;
                strcpy(res, aux);
                int p=strlen(res), q=strlen(aux)-1;
                for (int i=q; i>=0; --i) res[p++]=aux[i];
                res[p]=0;
            }                
        }
        if (strlen(res)>strlen(s) || strcmp(res, s)>0) { printf("%s\n", res); continue; }

        addString(aux);
        if (n%2==0) {
            strcpy(res, aux);
            int p=strlen(res), q=strlen(aux)-1;
            if (strlen(aux)!=(n+1)/2) q--;
            for (int i=q; i>=0; --i) res[p++]=aux[i];
            res[p]=0;
        } else {
            if (strlen(aux)==(n+1)/2) {
                strcpy(res, aux);
                int p=strlen(res), q=strlen(aux)-2;
                for (int i=q; i>=0; --i) res[p++]=aux[i];
                res[p]=0;
            } else {
                aux[strlen(aux)-1]=0;
                strcpy(res, aux);
                int p=strlen(res), q=strlen(aux)-1;
                for (int i=q; i>=0; --i) res[p++]=aux[i];
                res[p]=0;
            }                
        }
        printf("%s\n", res);
    }
}
