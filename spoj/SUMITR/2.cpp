#include <iostream>
using namespace std;
#define F(i,n) for(i=0;i<n;++i)
int d[105][105]; int main(){int T,t,i,j,n,x,r;cin>>T;F(t,T){r=0;cin>>n;F(i,n)F(j,i+1){cin>>x;d[i+1][j+1]=max(d[i][j],d[i][j+1])+x;r=max(r,d[i+1][j+1]);};cout<<r<<endl;}}
