/*
ID: aphrodi1
PROG: rect1
LANG: C++
*/
#include<cstdio>
#include<cstring>
using namespace std;
int limx,limy,limc;
int x1[1010],x2[1010],y1[1010],y2[1010],color[2510],area[2510];
void cover(int dx,int ux,int dy,int uy,int floor,int c)
{
    while((floor<=limc) && ((dx>=x2[floor]) || (ux<=x1[floor]) || (dy>=y2[floor]) || (uy<=y1[floor])))
        floor ++; //if the two rectangles are not overlap,come-up~
    if(floor>limc) {area[c] += (ux-dx) * (uy-dy);return;}//when it comes to the topside,add its acreage
    if(dx<x1[floor]) {cover(dx,x1[floor],dy,uy,floor+1,c); dx = x1[floor];}
    if(ux>x2[floor]) {cover(x2[floor],ux,dy,uy,floor+1,c); ux = x2[floor];}
    if(dy<y1[floor]) {cover(dx,ux,dy,y1[floor],floor+1,c); dy = y1[floor];}
    if(uy>y2[floor]) {cover(dx,ux,y2[floor],uy,floor+1,c); uy = y2[floor];}
}
int main(void)
{
    FILE *fin = fopen("rect1.in","r");
    FILE *fout = fopen("rect1.out","w");
    memset(color,0,sizeof(color));
    fscanf(fin,"%d %d %d",&x2[0],&y2[0],&limc);
    x1[0] = y1[0] = 0; color[0] = 1;
    for(int i=1 ; i<=limc ; i++)
        fscanf(fin,"%d %d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i],&color[i]);
    for(int i=limc ; i>=0 ; i--)
        cover(x1[i],x2[i],y1[i],y2[i],i+1,color[i]);
    for(int i=1 ; i<=2500 ; i++)
        if(area[i])
            fprintf(fout,"%d %d\n",i,area[i]);
    return 0;
}
