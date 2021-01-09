#include<bits/stdc++.h>

#define LOG(x) cout << #x << "::" << x << '\n'
#define INIT() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FORI(n) for(int i = 0; i < n; i++)
#define FORJ(n) for(int j = 0; j < n; j++)
#define FORK(n) for(int k = 0; k < n; k++)
using namespace std;

int n,q;
vector<vector<int>> tree;
vector<int> depth;
vector<vector<int>> ancestors;

int lca(int x, int y)
{
    if(x == y) return x;
    if(depth[x] < depth[y]) swap(x, y);

    int step = depth[x] - depth[y];
    int log2n = ceil(log2(n));

    for(int i = log2n - 1; i >= 0; i--)
    {
        int ii = 1 << i;
        if(ii > step) continue;

        x = ancestors[i][x];
        step -= ii;
        
    }

    for(int i = log2n - 1; i >= 0; i--)
    {
        if(ancestors[i][x] != ancestors[i][y]){
            x = ancestors[i][x];
            y = ancestors[i][y];
        }
    }
    if(x == y) return x;
    return ancestors[0][x];
}

void dfs(int node, int d)
{
    depth[node] = d;
    for(auto child: tree[node])
        dfs(child, d + 1);
}

void fill_ancestors()
{
    ancestors[0][0] = 0;
    FORI(n) for(auto& child: tree[i]) ancestors[0][child] = i;

    int log2n = ceil(log2(n));
    for(int k = 1; k < log2n; k++) // 2. predak, 4. predak
    {
        FORI(n)
        {
            int kk = (1 << k) - 1;
            int ancestor = ancestors[k - 1][i];
            ancestor = ancestors[k - 1][ancestor];
            ancestors[k][i] = ancestor;
        }
    }
    
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    tree = vector<vector<int>>(n);
    depth = vector<int>(n);

    int log2n = ceil(log2(n));
    ancestors = vector<vector<int>>(log2n);
    FORI(log2n) ancestors[i] = vector<int>(n);

    int m;
    FORI(n)
    {
        cin >> m;
        tree[i] = vector<int>(m);
        FORJ(m)
        {
            int x;
            cin >> x;
            x--;
            tree[i][j] = x;
        }
    }
    
    dfs(0, 0); // napuni dubine svih cvorova
    fill_ancestors();

    int x, y;
    FORI(q)
    {
        cin >> x >> y;
        x--; y--;
        cout << lca(x, y) + 1 << '\n';
    }
}