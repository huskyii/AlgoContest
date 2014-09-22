/*
ID: mail.ji1
PROG: transform
LANG: C++11
*/
#include <cstdio>
#include <cstring>
using namespace std;

char a[10][11], b[10][11], c[10][11];

inline bool Compare(char src[][11], char dst[][11], int n) {
	for (int i = 0; i < n; ++i)
		if (memcmp(src[i], dst[i], n)) return false;
	return true;
}

void Transform(char src[][11], char dst[][11], int n, int k) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			switch (k) {
			case 1: dst[i][j] = src[n-j-1][i]; break;
			case 2: dst[i][j] = src[n-i-1][n-j-1]; break;
			case 3: dst[i][j] = src[j][n-i-1]; break;
			case 4: dst[i][j] = src[i][n-j-1];
			}
}

int main(void) {
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	bool changed = false;
  int n;
	scanf("%d%*c", &n);
	for (int i = 0; i < n; ++i)
		gets(a[i]);
	for (int i = 0; i < n; ++i)	{
		gets(b[i]);
		if (memcmp(a[i], b[i], n)) changed = true;
	}
	for (int k = 1; k <= 4; ++k) {
		Transform(a, c, n, k);
		if (Compare(c, b, n)) return printf("%d\n", k), 0;
	}
	for (int k = 1; k <= 3; ++k) {
		Transform(c, a, n, k);
		if (Compare(a, b, n)) return printf("%d\n", 5), 0;
	}
	puts(changed ? "7" : "6");
}

