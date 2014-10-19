#include <cstdio>
using namespace std;

int main(void) {
  int a[6];
  int b[4] = {0,5,3,1};
  int x2,x1;
  while(true) {
    for(int i = 0; i < 6; i++)
      scanf("%d",&a[i]);
    if(a[0]+a[1]+a[2]+a[3]+a[4]+a[5] == 0) break;
    int count = a[5]+a[4]+a[3]+(a[2]+3)/4;
    x2 = a[3]*5+b[a[2]%4];
    if(x2 < a[1])
    count += (a[1]-x2+8)/9;
    x1 = count*36-a[5]*36-a[4]*25-a[3]*16-a[2]*9-a[1]*4;
    if(a[0] > x1)
    count += (a[0]-x1+35)/36;
    printf("%d\n",count);
  }
}
