#include <bits/stdc++.h>

using namespace std;
using ll = uint64_t;
vector<ll> c;
int t, n;
ll k;

bool possible_sols_in_row(ll per_row)
{
	if(per_row <= 0) return true;
	auto cc = vector<ll>(n);
	copy(c.begin(), c.end(), cc.begin());
	
	ll rows = 0;
	for(ll height = 0; height < n && rows < k; height++)
	{
		if(cc[height] >= per_row)
		{
			rows += cc[height] / per_row;
			cc[height] %= per_row;
		}
		
		if(height < n - 1 && cc[height] + cc[height + 1] >= per_row)
		{
			rows++;
			cc[height + 1] -= per_row - cc[height];
			cc[height] = 0;
		}
	}
	
	return rows >= k;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);	
	cin >> t;	
	while(t--)
	{
		cin >> n >> k;
		
		c = vector<ll>(n);
		ll sols = 0ULL, num;
		
		for(int i = 0; i < n; i++)
		{
			cin >> num;
			c[i] = num;
			sols += c[i];
		}

		ll ans, lo = 0, hi = 1 + sols / k;
		
		while(lo <= hi)
		{
			ll mid = (lo + hi) / 2;
			if(possible_sols_in_row(mid))
			{
				ans = mid;
				lo = mid + 1;
			}
			else 
				hi = mid - 1;
		}

		cout << ans * k << '\n';
	}
}
