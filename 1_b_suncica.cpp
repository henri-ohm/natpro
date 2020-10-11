#include<iostream>
#include<vector>
using namespace std;

vector<long long> fen;
int n,q;
long long fen_sum(int index)
{
	long long sum = 0;
	index++;
	for(; index > 0; index -= index & (-index))
	{
		sum += fen[index];
	}
	return sum;
}

void fen_add(int index, long long val)
{
	index++;
	for(; index <= n; index += index & (-index))
	{
		fen[index] += val;
	}
}

int main()
{
	
	cin >> n >> q;
	long long x;
	long long diff[n];
	long long t[n];
	fen = vector<long long>(n + 1);
	
	
	for(int i = 0; i < n; i++)
	{
		cin >> t[i];

		diff[i] = i == 0 ? t[i] : t[i] - t[i - 1];
		fen_add(i, diff[i]);		
	}
	
	int num, a, b;
	for(int i = 0; i < q; i++)
	{
		cin >> num;
		if(num == 1)
		{
			cin >> a >> b >> x;
			diff[a - 1] += x;
			diff[b] -= x;
			fen_add(a - 1, x);
			fen_add(b, -x);
		}
		else 
		{
			int x;
			cin >> x;
			cout << fen_sum(x - 1) << '\n';
		}
	}
}
