#include <iostream>
#include <string>
#include <map>
using namespace std;

map<int, string> mm;
string func(int n)
{
    string res;
    if (n>=1000) {
        res=func(n/1000)+" thousand";
        if (n%1000) res+=" "+func(n%1000);
        return res;
    }
    if (n>=100) {
        res=func(n/100)+" hundred";
        if (n%100) res+=" "+func(n%100);
        return res;
    }
    if (((mm).find(n) != (mm).end())) return mm[n];
    return mm[n/10*10]+" "+mm[n%10];
}

int main()
{
mm[0]="zero";
mm[1]="one";
mm[2]="two";
mm[3]="three";
mm[4]="four";
mm[5]="five";
mm[6]="six";
mm[7]="seven";
mm[8]="eight";
mm[9]="nine";
mm[10]="ten";
mm[11]="eleven";
mm[12]="twelve";
mm[13]="thirteen";
mm[14]="fourteen";
mm[15]="fifteen";
mm[16]="sixteen";
mm[17]="seventeen";
mm[18]="eighteen";
mm[19]="nineteen";
mm[20]="twenty";
mm[30]="thirty";
mm[40]="forty";
mm[50]="fifty";
mm[60]="sixty";
mm[70]="seventy";
mm[80]="eighty";
mm[90]="ninety";

int n;
cin>>n;
cout << func(n) << endl;
}
