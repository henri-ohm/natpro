#include <iostream>
#include <set>
#define FORI(n) for(int i = 0; i < (n); i++)
#define FORJ(n) for(int j = 0; j < (n); j++)
using namespace std;

typedef set<int> si;
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> m;
	int res[n] = {0};
	si not_defeated;
	FORI(n) not_defeated.insert(i);
	
	int l, r, won;
	FORI(m)
	{
		cin >> l >> r >> won;
		l--;
		r--;
		won--;
		si defeated;
		for(auto it = not_defeated.lower_bound(l); it != not_defeated.end(); it++)
		{
			int knight = *it;
			if(knight > r) break;
			if(knight != won)
			{
				defeated.insert(knight);
			}
		}
		
		for(auto it = defeated.begin(); it != defeated.end(); it++) 
		{
			auto defeated_knight = *it;
			not_defeated.erase(defeated_knight);
			res[defeated_knight] = won + 1;
		}
		
	} 
	
	FORI(n) cout << res[i] << " ";
	cout << '\n';
}
