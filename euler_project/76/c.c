#include<stdio.h>
 
long a[102][102];
int i,j;
 
void main(){
    a[1][1]=1;
    a[2][1]=1;a[2][2]=2;
    for(i=3;i<101;i++){
	a[i][1]=1;
	for(j=2;j<i;j++){
	    if(j>i-j) a[i][j]=a[i][j-1]+a[i-j][i-j];
	    else a[i][j]=a[i][j-1]+a[i-j][j];
	}
	a[i][i]=1+a[i][i-1];
    }
    printf("%li\n",a[100][100]-1);
}


