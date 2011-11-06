#include <stdio.h>
 
 
int main()  {
 
    int i,j,sum,S[8],T[8],all[31];
 
    all[0]=1;
    all[1]=2;
    all[2]=4;
    all[3]=7;
    for(i=1;i<8;i++) S[i]=1;
    S[0]=0;
 
    for(i=4;i<=30;i++) {
        T[0]=0;
        T[1]=S[4];
        for(j=2;j<8;j++) T[j]=S[j/2]+S[j/2+4];
        for(j=0;j<8;j++) S[j]=T[j];
        sum=0;
        for(j=0;j<8;j++) sum+=S[j];
        all[i]=sum;
    }
    sum=0;
    for(i=0;i<8;i++) sum+=S[i];
    for(i=1;i<=30;i++) sum+=all[i-1]*all[30-i];
    printf("%d\n",sum);
 
    return 0;
}
