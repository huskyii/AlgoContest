#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

void print(const vector<int> &v) {
  for(auto elem: v)
    cout << elem;
}

int main(void) {
  int m, s;
  while(scanf("%d %d", &m, &s) != EOF) {
    int mins, maxs;

    if(m == 1) mins = 0;
    else mins = 1;

    maxs = 9 * m;

    if(s < mins or s > maxs) {
      printf("-1 -1\n");
      continue;
    }

    vector<int> minseq(m), maxseq(m);
    int tmp;

    tmp = s;
    for(int i = 0; i < m; ++i) {
      if(tmp <= 0) break;
      tmp > 9? maxseq[i] = 9: maxseq[i] = tmp;
      tmp -= 9;
    }

    tmp = s-1;
    if(s != 0) {
      for(int i = m-1; i >= 0; --i) {
        if(tmp <= 0) break;
        tmp > 9? minseq[i] = 9: minseq[i] = tmp;
        tmp -= 9;
      }
      minseq[0] += 1;
    }

    print(minseq);
    cout << " ";
    print(maxseq);
    cout << endl;
  }
  return 0;
}
