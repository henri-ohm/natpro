#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	uint16_t t;
	cin >> t;
	int n;
	for(auto i = 0; i < t; i++)
	{
		cin >> n;
		int64_t a[n];
		for(int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		
		sort(a, a + n, [](int64_t first, int64_t second){
			return abs(first) < abs(second);
		});
		
		for(int j = 0; j < n; j++)
		{
			cout << a[j] << " ";
		}
		cout << '\n';
	}
}
