#include <iostream>
#define FORI(n) for(int i = 0; i < (n); i++)
#define FORJ(n) for(int j = 0; j < (n); j++)
using namespace std;

int n, m;

int main()
{
	cin >> n >> m; //knights and fights
	int knights[n];
	bool in_game[n];
	FORI(n) knights[i] = 0;
	FORI(n) in_game[i] = true;
	
	int l, r, won;
	FORI(m)
	{
		cin >> l >> r >> won;
		l--;
		r--;
		for(int j = l; j <= r; j++)
		{
			if(in_game[j] && j + 1 != won)
			{
				knights[j] = won;
				in_game[j] = false;
			}
		}
	}
	
	FORI(n) cout << knights[i] << " ";
	cout << '\n';
}
