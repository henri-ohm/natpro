#include <bits/stdc++.h>
#define FORI(n) for(int i = 0; i < n; i++)
#define LOG(x) cout << #x << "::" << x << '\n'
using namespace std;
using ld = long double;

int a, b;

ld dist(int y_a, int y_b)
{
	return sqrt((pow(a, 2) + pow(y_a, 2))) + sqrt(pow(b - a, 2) + pow(y_b - y_a, 2));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	
	cin >> n >> m >> a >> b;
	
	int A[n];
	FORI(n) cin >> A[i];
	
	int B[m], LB[m];
	FORI(m) cin >> B[i];
	FORI(m) cin >> LB[i];
	
	int Aans, Bans;
	ld min_dist = -1;
	
	FORI(m)
	{		
		double lo = 0, hi = n - 1;
		
		while(hi - lo > 1e-7)
		{
			double mid1 = lo + (hi - lo) / 3;
			double mid2 = hi - (hi - lo) / 3;

			if(dist(A[(int)mid1], B[i]) < dist(A[(int)mid2], B[i]))
			{
				hi = mid2;
			}
			else if(dist(A[(int)mid1], B[i]) > dist(A[(int)mid2], B[i]))
			{
				lo = mid1;
			}
			else
			{
				lo = mid1; 
				hi = mid2;
			}
		}
		
		ld leng = dist(A[(int)hi], B[i]) + LB[i];
		if(min_dist == -1 || leng < min_dist)
		{
			Aans = lo + 1;
			Bans = i + 1;
			min_dist = leng;
		}	
	}
	
	cout << Aans << " " << Bans << '\n';	
}
