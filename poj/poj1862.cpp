#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
  int n, tmp;
  while(scanf("%d", &n) != EOF) {
    priority_queue<float> pq;
    for(int i = 0; i < n; ++i) {
      scanf("%d", &tmp);
      pq.push(tmp);
    }
    while(pq.size() > 1) {
      float a = pq.top();
      pq.pop();
      float b = pq.top();
      pq.pop();
      pq.push(2*sqrt(a*b));
    }
    printf("%.3f\n", pq.top());
  }
  return 0;
}
