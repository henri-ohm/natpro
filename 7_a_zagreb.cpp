#include<bits/stdc++.h>
using namespace std;

int n, m;
int n_artikulacijskih = 0;
int t = 0;

vector<int> dt;
vector<int> min_dt;
vector<bool> visited;
vector<vector<int>> adj;
vector<bool> ap;

void dfs(int x, int p = -1)
{
    visited[x] = true;
    dt[x] = min_dt[x] = t++;

    int children = 0;

    for(auto i: adj[x])
    {
        if(i == p) continue;
        if(visited[i]){
            min_dt[x] = min(min_dt[x], dt[i]);
        } else {
            dfs(i, x);
            min_dt[x] = min(min_dt[x], min_dt[i]);
            if(min_dt[i] >= dt[x] && p != -1){
                //n_artikulacijskih++;
                ap[x] = true;
            }
            
            children++;
        }
    }

    if(p == -1 && children > 1) {
        ap[x] = true;
        //n_artikulacijskih++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    
    dt = vector<int>(n, -1);
    min_dt = vector<int>(n, -1);
    visited = vector<bool>(n, false);
    adj = vector<vector<int>>(n);
    ap = vector<bool>(n, false);
    int x,y;
    while(m--){
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 0; i < n; i++)
        if(!visited[i])
            dfs(i);

    // for(int i = 0; i < n; i++)
    //     if(ap[i]) n_artikulacijskih++;

    cout << n_artikulacijskih << '\n';
}