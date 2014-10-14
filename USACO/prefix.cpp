/*
ID: mail.ji1
PROG: prefix
LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXP = 200, MAXL = 12;
const int MAXN = 200015;
char p[MAXP][MAXL];
char seq[MAXN];
bool start[MAXN];

int main(void) {
  freopen("prefix.in", "r", stdin);
  freopen("prefix.out", "w", stdout);

  int pcnt = 0;
  while(scanf("%s", p[pcnt]) && p[pcnt++][0] != '.') {}
  int seqlen = 0;
  while(scanf("%s", seq + seqlen) != EOF) {
    seqlen += strlen(seq+seqlen);
  }

  int best;
  start[0] = true;
  for(int i = 0; i <= seqlen; ++i)
    if(start[i]) {
      best = i;
      for(int j = 0; j < pcnt; ++j) {
        if(memcmp(seq+i, p[j], strlen(p[j])) == 0)
          start[i+strlen(p[j])] = true;
      }
    }

  printf("%d\n", best);

  return 0;
}
