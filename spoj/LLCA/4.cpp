#include<iostream>
#define z while
using namespace std;main(){int T,k,a,b,t=0,n,u,y,v[200],x,w;cin>>T;z(t++<T){cin>>k>>a>>b;n=0;x=w=1;v[n++]=x;if(a<b)swap(a,b);z(x<a)x+=w,v[n++]=x,w*=k;u=y=n;z(a<v[--u]);z(b<v[--y]);z(a!=b){a=(a-v[u])/k+v[u-1];if(u==y)b=(b-v[u])/k+v[u-1];--u;}cout<<a<<endl;}}
