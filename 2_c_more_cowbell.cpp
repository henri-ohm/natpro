#include <bits/stdc++.h>
#define FORI(n) for(int i = 0; i < n; i++)
#define FORJ(n) for(int j = 0; j < n; j++)
using namespace std;
using ll = uint64_t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// number of cowbells
	int n;
	// number of boxes
	int k;
	
	// n <= 2k because in each box there is a max of 2 cowbells
	cin >> n >> k;
	
	// sizes of cowbells
	int s[n];
	
	FORI(n)
	{
		cin >> s[i]; // given in non-decresing order
	}
	
	if(n == k){ cout << s[n - 1] << '\n'; return 0;}
	
	int smax = s[n - 1];
	
	for(int i = 0; i < n - k; i++)
	{
		smax = max(smax, s[i] + s[2 * (n - k) - i - 1]);
	}
	
	cout << smax << '\n';
}
