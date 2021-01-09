#include<bits/stdc++.h>
using namespace std;
#define LOG(x) cout << ##x << x << '\n'
#define endl '\n'
#define FORI(n) for(int i = 0; i < n; i++)
#define FORJ(n) for(int j = 0; j < n; j++)
#define FORK(n) for(int k = 0; k < n; k++)
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}

using ll = int64_t;
using ull = uint64_t;
using i = int32_t;
using ui = uint32_t;
using s = int16_t;
using us = uint16_t;
using vi = vector<i>;
using vvi = vector<vector<i>>;
using pi = pair<i, i>;
struct veza {
	int g, r, p;
};

vector<veza> veze;
constexpr ull M = 1e7 + 9;
int g,r,n,m,q;

bool is_valid(int p)
{
	int grad[g];
	int repetitor[r];
	FORI(g) grad[i] = 0;
	FORI(r) repetitor[i] = 0;
	for(auto& veza: veze){
		if(p >= veza.p) {
			grad[veza.g - 1]++;
			repetitor[veza.r - 1]++;
		}
	}
	FORI(g) if(grad[i] < n) return false;
	FORI(r) if(repetitor[i] < m) return false;
	return true;
}

int main()
{
	init();
	cin >> g >> r >> n >> m >> q;
	int max_p = 0;

	veze = vector<veza>(q);
	FORI(q){
		int a,b,c;
		cin >> a >> b >> c;
		veze[i] = {a,b,c};
		if(c > max_p) max_p = c;
	}
	max_p++;
	int lo = 0;
	int hi = max_p;
	int mid;
	int val;
	while(lo <= hi){
		mid = (lo + hi) / 2;
		if(is_valid(mid)){
			hi = mid - 1;
			val = mid;
		} else {
			lo = mid + 1;
		}
	}
	cout << (lo >= max_p ? -1 : val) << endl;
}
