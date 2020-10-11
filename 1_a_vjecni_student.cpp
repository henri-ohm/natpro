#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;
vector<int> k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> q;
	k = vector<int>(n);
	
	
	for(int i = 0; i < n; i++) 
	{
		cin >> k[i];
	}
	
	int query, l, r, x, y;
	for(int i = 0; i < q; i++)
	{
		cin >> query;
		if(query == 1)
		{
			cin >> l >> r;
			vector<int>::const_iterator first = k.begin() + l - 1;
			vector<int>::const_iterator last = k.begin() + r;
			vector<int> segment(first, last);
			sort(segment.begin(), segment.end());
			
			
			cout << segment[r - l - 1] << '\n';
		}
		else if(query == 2) 
		{
			cin >> x >> y;
			k[x - 1] = y;
		}
	}
	
	
}
