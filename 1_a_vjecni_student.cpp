#include <std/bitsc++>
using namespace std;

int n, q;

int main()
{
	cin >> n >> q;
	int k[n];
	
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
		}
		else if(query == 2) 
		{
			cin >> x >> y;
			k[x - 1] = y;
		}
	}
	
	
}
