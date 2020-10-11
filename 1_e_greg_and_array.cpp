#include <bits/stdc++.h>
#define FORI(n) for (int i = 0; i < (n); i++)
#define FORJ(n) for (int j = 0; j < (n); j++)
using namespace std;
int n, m, k;

typedef struct {
	int l;
	int r;
	int d;
} op;

int main()
{
	cin >> n >> m >> k;
	int64_t a[n];
	int64_t diff[n];
	op ops[m];
	
	FORI(n) 
	{
		cin >> a[i];
		diff[i] = i == 0 ? a[i] : a[i] - a[i - 1];
	}
	
	int l, r, d;
	FORI(m) 
	{
		cin >> l >> r >> d; // add d to a_l, ..., a_r
		l--; r--;
		ops[i] = {l, r, d};
	}
	
	int x, y;
	FORI(k)
	{
		cin >> x >> y; // commit all ops_x, ..., ops_y
		x--; y--;
		for(; x <= y; x++)
		{
			op curr = ops[x];
			diff[curr.l] += curr.d;
			diff[curr.r + 1] -= curr.d;
		}
	}
	
	FORI(n) 
	{
		a[i] = i == 0 ? diff[0] : diff[i] + a[i - 1];
		cout << a[i] << " ";
	}
	cout << '\n';
}
