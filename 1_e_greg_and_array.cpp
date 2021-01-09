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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> m >> k;
	int64_t a[n];
	int64_t diff[n];
	
	
	FORI(n) {
		cin >> a[i];
		diff[i] = i == 0 ? a[i] : a[i] - a[i - 1];
	}
	
	op ops[m];
	int l, r, d;
	FORI(m) {
		cin >> l >> r >> d;
		l--; r--;
		ops[i] = {l, r, d};
	}
	

	int inner_diff[m] = {0};
	int x, y;
	FORI(k){
		cin >> x >> y;
		x--; y--;
		inner_diff[x]++;
		inner_diff[y+1]--;
	}
	
	
	
	int ops_todo[m] = {0};
	FORI(m){
		ops_todo[i] = i == 0 ? inner_diff[i] : inner_diff[i] + ops_todo[i - 1];
		
		op curr = ops[i];
		diff[curr.l] += ops_todo[i] * 1LL * curr.d;
		diff[curr.r + 1] -= ops_todo[i] * 1LL * curr.d;

	}	
	
	FORI(n) {
		a[i] = i == 0 ? diff[0] : diff[i] + a[i - 1];
		cout << a[i] << " ";
	}
	cout << '\n';
}

