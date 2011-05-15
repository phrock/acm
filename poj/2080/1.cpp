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

ifstream fin("in");
////////////////////////////////////////////////////////////////////////////////

int nmonth[2][13]={ {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
int nyear[2]={365, 366};
string nweek[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

bool isLeapYear(int year)
{
  if (year%400==0 || (year%4==0 && year%100!=0)) return true;
  else return false;
}

string func(int n)
{
  int week=(6+n%7)%7;
  int year=2000;
  int leap=isLeapYear(year);
  while (n>=nyear[leap]) { n-=nyear[leap]; year++; leap=isLeapYear(year); }
  int month=1;
  while (n>=nmonth[leap][month]) { n-=nmonth[leap][month]; month++; }
  int day=n+1;
  string res=*({stringstream ss; ss<<(year); static string _; ss>>_; &_;})+
    (month<10?"-0":"-")+*({stringstream ss; ss<<(month); static string _; ss>>_; &_;})+
    (day<10?"-0":"-")+*({stringstream ss; ss<<(day); static string _; ss>>_; &_;})+" "+nweek[week];
  return res;
}

int main()
{
#ifdef DEBUG
  cin.rdbuf(fin.rdbuf());  
#endif

  int n;
  while (cin>>n && n!=-1) {
    cout<<func(n)<<endl;
  }
}
