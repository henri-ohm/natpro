#include<bits/stdc++.h>

#define LOG(x) cout << #x << "::" << x << '\n'
#define INIT() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FORI(n) for(int i = 0; i < n; i++)
#define FORJ(n) for(int j = 0; j < n; j++)
#define FORK(n) for(int k = 0; k < n; k++)
using namespace std;

int n;

vector<vector<int>> tree;
vector<bool> visited;
vector<char> slova;

int best = 1; 
int prev_best;
bool best_exists = false;
int best_node = -1;

void reset()
{
    FORI(n) visited[i] = false;
}

void dfs(char c, int node, int d)
{
    
    visited[node] = true;
    if(slova[node] == c && d >= best){
        best = d;
        best_node = node;
        best_exists = true;
    }

    for(auto child: tree[node]){
        if(!visited[child]){
            dfs(c, child, d + 1);
        }
    }
}

void longest_path(char c, int node)
{
    best_node = -1;
    prev_best = max(best, prev_best);
    best = 1;

    reset();
    dfs(c, node, 0);
    reset();

    if(best_node == -1) return;

    dfs(c, best_node, 0);

}

int main()
{
    INIT();

    cin >> n;
    slova = vector<char>(n);
    visited = vector<bool>(n, false);
    auto first = vector<int>(3, -1);

    FORI(n) {
        cin >> slova[i];
        int x = slova[i] - 'A';
        if(first[x] < 0) first[x] = i;
    }

    tree = vector<vector<int>>(n);
    FORI(n) tree[i] = vector<int>();
    
    int x, y;
    
    FORI(n - 1)
    {
        cin >> x >> y;
        x--; y--;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    
    for(char c: {'A', 'B', 'C'})
    {
        int idx = c - 'A';
        int node = first[idx];
        if(node == -1) continue;
        longest_path(c, node);
    }

    cout << (best_exists ? max(best, prev_best) + 1 : 1) << '\n';
}