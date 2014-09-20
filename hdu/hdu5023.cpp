#include <cstdio>
#include <set>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 5;
int st[4*MAXN];
int m, n, ql, qr, c;
set<int> ans;

void paint(int node, int l, int r) {
  if(st[node] == c) return ;
  if(ql <= l && r <= qr) { st[node] = c; return ; }
  int mid = l + (r-l)/2;
  st[2*node] = st[node] != 0? st[node]: st[2*node];
  st[2*node+1] = st[node] != 0? st[node]: st[2*node+1];
  if(mid+1 <= ql) { paint(node*2+1, mid+1, r); }
  if(qr <= mid) { paint(node*2, l, mid); }
  if(ql <= mid && mid+1 <= qr) {paint(node*2, l, mid); paint(node*2+1, mid+1, r);}
  st[node] = 0;
}

void query(int node, int l, int r) {
  if(st[node] != 0) { ans.insert(st[node]); return ; }
  int mid = l + (r-l)/2;
  if(mid+1 <= qr) query(node*2+1, mid+1, r);
  if(ql <= mid) query(node*2, l, mid);
}

void print() {
  for(int i = 1; i < 2*n; i++)
    printf("%d ", st[i]);
  printf("\n");
}

int main(void){
  char op;
  while(scanf("%d %d", &n, &m) != EOF && n) {
    memset(st, 0, sizeof(st));
    st[1] = 2;
    while(m--) {
      cin >> op;
      if(op == 'P') { scanf("%d %d %d", &ql, &qr, &c); paint(1, 1, n); /*print(); */}
      else {
        scanf("%d %d\n", &ql, &qr);
        ans.clear();
        query(1, 1, n);

        int i = 0;
        for(set<int>::iterator it = ans.begin(); it != ans.end(); ++i, ++it) {
          if(i) printf(" ");
          printf("%d", *it);
        }
        printf("\n");
      }
    }
  }
  return 0;
}
