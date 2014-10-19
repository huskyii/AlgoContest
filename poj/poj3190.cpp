#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

struct N {
	int l,r,id,stall;
	bool operator <(const N &a) const {
		return a.r < r;
	}
}cow[50010];
inline bool cmp(const N &a, const N &b) {
	return a.l < b.l;
}

int main(void) {
  ios_base::sync_with_stdio(false);
	priority_queue<N> que;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)	{
		cin >> cow[i].l >> cow[i].r;
		cow[i].id = i;
	}
	sort(cow+1, cow+n+1, cmp);
	cow[0].stall = 1;
	cow[0].r = 0;
	que.push(cow[0]);
	int a[50010];
	int S = 2;
	for(int i = 1; i <= n; i++)	{
		N c = que.top();
		if(cow[i].l > c.r) {
			que.pop();
			cow[i].stall = c.stall;
			a[cow[i].id] = c.stall;
			que.push(cow[i]);
		}	else {
			cow[i].stall = S;
			a[cow[i].id] = S++;
			que.push(cow[i]);
		}
	}
	cout << S-1 << endl;
	for(int i = 1; i <= n; i++)
		cout << a[i] << endl;
	return 0;
}
