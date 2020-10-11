#include <iostream>
#define FORI(n) for(int i = 0; i < (n); i++)
using namespace std;

int n, k;

int main()
{
	cin >> n >> k;
	int a[n];
	bool t[n];
	int prefix[n + 1];
	
	prefix[0] = 0;
	FORI(n) cin >> a[i];
	FORI(n) cin >> t[i];
	FORI(n) prefix[i + 1] = prefix[i] + (1 - t[i]) * a[i];
	
	
	int diff;
	int max_diff = 0;
	for(int i = k; i <= n; i++)
	{
		diff = prefix[i] - prefix[i - k];
		if(diff > max_diff) max_diff = diff;
	}
	
	int sum = 0; 
	FORI(n) sum += a[i] * t[i];
	
	sum += max_diff;
	cout << sum;
}
