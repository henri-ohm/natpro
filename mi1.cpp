#include<bits/stdc++.h>
using namespace std;
#define LOG(x) cout << #x << x << '\n'
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

constexpr ull M = 1e7 + 9;
int n,k;
auto a = vector<ull>(1e5 +2);
auto svjetiljka = vector<ull>(1e5 + 2);

ull br_svjet(int i)
{
	ull ret = 0;
	int lo = i - k > 0 ? i - k : 0;
	int hi = i + k < n ? i + k: n;

	for(; lo <= hi; lo++){
		ret += svjetiljka[lo];
	}

	return ret;
}


void osvjezi(int i, int svj)
{
	int hi = i + k < n ? i + k: n-1;
	svjetiljka[hi] += svj;
}

int main()
{
	init();
	cin >> n;
	cin >> k;
	FORI(n) cin >> a[i];

	FORI(n)
	{
		int zelim = a[i];
		ull imam = br_svjet(i);
		if(imam >= zelim) continue;
		osvjezi(i, zelim - imam);
	}

	ull sum = 0;
	FORI(n) {
		//cout << svjetiljka[i] << ' ';
		sum += svjetiljka[i];
	} //cout << endl;

	cout << sum << endl;
}
