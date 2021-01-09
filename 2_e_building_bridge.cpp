#include <bits/stdc++.h>
#define FORI(n) for(int i = 0; i < n; i++)
#define LOG(x) cout << "::" << #x << "::" << x << '\n'
using namespace std;
using ld = long double;

int a, b;

ld dist(int y_a, int y_b)
{
	return sqrt((pow(a, 2) + pow(y_a, 2))) + sqrt(pow(b - a, 2) + pow(y_b - y_a, 2));
}

int main()
{

	
	int n, m;
	
	cin >> n >> m >> a >> b;
	
	int A[n];
	FORI(n) cin >> A[i];
	
	int B[m], LB[m];
	FORI(m) cin >> B[i];
	FORI(m) cin >> LB[i];
	
	int Aans, Bans;
	ld min_dist = -1;
	
#ifdef MLOGN // MLOGN ends O(m*logn) solution	
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
	

#else
	
	int it_a = n - 1, it_b = m - 1;
	while(it_b >= 0 && it_a >= 0)
	{
		int y_a_top = A[it_a];
		int y_a_bot = A[it_a - 1];
		
		int y_b_top = B[it_b];
		
		ld b_to_a_top = dist(y_a_top, y_b_top);
		ld b_to_a_bot = dist(y_a_bot, y_b_top);
		
		if(b_to_a_top > b_to_a_bot)
		{
			it_a--;
		} 
		else 
		{
			if(min_dist == -1 || b_to_a_top + LB[it_b] < min_dist)
			{
				min_dist = b_to_a_top + LB[it_b];
				Aans = it_a + 1;
				Bans = it_b + 1;
			}
			it_b--;
		}
		
	}
	
#endif



	cout << Aans << " " << Bans << '\n';
}
