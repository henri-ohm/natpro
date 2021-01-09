#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	uint16_t t;
	cin >> t;
	int n;
	for(auto i = 0; i < t; i++)
	{
		cin >> n;
		ll a[n];
		for(int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		
		
		sort(a, a + n);
		
		int lo = 0, hi = n - 1, ind = n - 1;
		ll sorted[n];
		
		while(lo <= hi)
		{
			sorted[ind--] = (ind % 2 == 0) ? a[hi--] : a[lo++];
		}
		
		for(int j = 0; j < n; j++)
		{
			cout << sorted[j] << ' ';
		}
		cout << '\n';
	}
}
