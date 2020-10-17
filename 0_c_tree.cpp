#include <iostream>
#include <stack>
#include <vector>
#define SIZE 100000000
using namespace std;

int n;

void solve_stack(vector<bool>& tree, vector<bool>& visited)
{
	stack<int> s;
	s.push(1);
	while(!s.empty())
	{
		int node = s.top(); s.pop();
		
		cout << node << '\n';
		if(visited[node - 1]) continue;
		
		visited[node - 1] = true;
		for(int i = n - 1; i >= 0; i--)
		{
			if(tree[(node - 1) * n + i])
			{
				s.push(node);
				s.push(i + 1);
				tree[(node - 1) * n + i] = false;
				tree[i * n + (node - 1)] = false;
			}
		}
	}
}

int main()
{
	cin >> n;
	vector<bool> visited(n, false);	
	vector<bool> tree(n * n, false);
	int a, b;
	for(int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		tree[(a - 1) * n + b - 1] = true;
		tree[(b - 1) * n + a - 1] = true;
	}
	solve_stack(tree, visited);
	return 0;
}

