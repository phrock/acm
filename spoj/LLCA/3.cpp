#include<iostream>
#include<sstream>
#include<string>
using namespace std;int main(){string s;int T,k,a,b,ti,n,u,y,i,j,v[200],x,w;stringstream is;while(true){getline(cin,s);if(s=="")cout<<endl;else{is.str(s);is>>T;break;}}for(ti=0;ti<T;++ti){getline(cin,s);is.clear();is.str(s);is>>k>>a>>b;n=i=j=0;x=w=1;v[n++]=x;if(a<b)swap(a,b);while(x<a)x+=w,v[n++]=x,w*=k;u=y=n;while(a<v[--u]);while(b<v[--y]);while(u!=y)a=(a-v[u])/k+v[u---1];while(a!=b)a=(a-v[u])/k+v[u-1],b=(b-v[u])/k+v[u---1];cout<<a<<endl;}}
