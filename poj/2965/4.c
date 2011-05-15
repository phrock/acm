#include <stdio.h>

int main()
{
  char c;
  int start=0;
  for (int i=0; i<4; ++i) 
    for (int j=0; j<5; ++j) {
      c=getchar();
      if (j==4) continue;
      if (c=='+') {
	start^=1<<(i*4+j);
	for (int p=0; p<4; ++p) start^=1<<(i*4+p);
	for (int p=0; p<4; ++p) start^=1<<(p*4+j);
      }
    }
  printf("%d\n", __builtin_popcount(start));
  for (int i=0; i<16; ++i)
    if (start & (1<<i)) printf("%d %d\n", i/4+1, i%4+1);
}
