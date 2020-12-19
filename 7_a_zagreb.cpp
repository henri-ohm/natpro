#include<bits/stdc++.h>
using namespace std;

#define DBG

#ifdef DBG
#define DEBUG(x) cout << #x << ' ' << x << '\n'
#elif
#define DEBUG(x)
#endif
int n, m;
int n_artikulacijskih = 0;
int t = 0;
bool first = true;
void dfs(int x, vector<int>& dt, vector<int>& min_dt, vector<bool>& visited, int graf[], int depth)
{
    if(visited[x]) return;

    dt[x] = t; t++;
    visited[x] = true;
    int dfs_children = 0;

    for(int i = 0; i < n; i++)
    {
        if(graf[x + i*n] == 1)
        {
            if(visited[i]){
                min_dt[x] = min(i, min_dt[x]);
            } else {
                dfs_children++;
                dfs(i, dt, min_dt, visited, graf, depth+1);
                min_dt[x] = min(min_dt[x], min_dt[i]);
                if(depth != 0 && dt[x] <= min_dt[i]) n_artikulacijskih++;
            }
        }
    }
    // DEBUG(x);
    // DEBUG(dt[x]);
    // DEBUG(min_dt[x]);
    // cout << '\n';
    if(depth == 0 && dfs_children > 1) n_artikulacijskih++;
}

int main()
{
    cin >> n >> m;
    
    auto dt = vector<int>(n, 0);
    int val = n+1;
    auto min_dt = vector<int>(n, val);
    auto visited = vector<bool>(n, false);
    int graf[n*n];

    

    int x,y;
    while(m--){
        cin >> x >> y;
        x--; y--;
        graf[x + y*n] = 1;
        graf[y + x*n] = 1;
    }

    
    dfs(0, dt, min_dt, visited, graf, 0);

    cout << n_artikulacijskih << '\n';
}