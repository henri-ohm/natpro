#include <bits/stdc++.h>
using namespace std;
#define FORI(n) for(auto i = 0; i < n; i++)
#define FORJ(n) for(auto j = 0; j < n; j++)
int d(int vx, int vy, int cx, int cy){
    return abs(vx - cx) + abs(vy - cy);
}

struct pos{
    int x;
    int y;
};

int n, m;
char mat[1000][1000];
bool visited[1000][1000];
queue<pos> q;
pos jaz;
pos vuk;
vector<pos> cikla;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    q = queue<pos>();
    cikla = vector<pos>();

    FORI(n) {
        FORJ(m) {
            cin >> mat[i][j];
            if(mat[i][j] == 'V') vuk = {i, j};
            else if(mat[i][j] == '+') cikla.push_back({i, j});
            else if(mat[i][j] == 'J') jaz = {i, j};
        }
    }

    q.push(vuk);
    
    while(!q.empty())
    {
        pos v = q.front();
        q.pop();
        visited[v.x][v.y] = true;

        
    }
}
