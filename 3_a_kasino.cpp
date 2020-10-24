#include<bits/stdc++.h>

#define MOD 1000000007L
#define LOG(x) cout << #x << "::" << x << '\n'
using namespace std;
using ll = uint64_t;
using s = uint16_t;
using vll = vector<ll>;
using vvs = vector<vector<s>>;

void init();
void solve();
void print_sol();

s n, m;
ll t;
vll money_current;
vll money_future;
vvs who_likes_who;

int main()
{
	init();
	solve();
	print_sol();
}

void solve()
{
	while(t--)
	{
		for(s person = 0; person < n; person++)
		{
			s i_like = who_likes_who[person].size();
			ll my_money = money_current[person];

			for(auto liked_person: who_likes_who[person])
			{
				money_future[liked_person] += my_money % MOD;
			}
		}

		for(s it = 0; it < n; it++)
		{
			money_current[it] += money_future[it] % MOD;
			money_future[it] = 0;
			
		}
	}
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	money_current = vll(n);
	money_future = vll(n, 0);
	who_likes_who = vvs(n);
	s subjekt, objekt;

	while(m--)
	{
		cin >> subjekt >> objekt;
		who_likes_who[subjekt - 1].push_back(objekt - 1);
	}

	ll a;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		money_current[i] = a;
	}

	cin >> t;
}

void print_sol()
{
	for(auto money: money_current)
	{
		cout << money << ' ';
	}
	cout << '\n';
}