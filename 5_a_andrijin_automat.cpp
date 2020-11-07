#include<bits/stdc++.h>
using namespace std;


void solveall(int s);
int n, m;
vector<pair<int, char>> coins;
map<char, vector<int>> sol;
set<char> colors;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    coins = vector<pair<int, char>>(n);
    

    int v;
    char c;
    
    for(int i = 0; i < n; i++){
        cin >> v >> c;
        coins[i] = {v, c};
        colors.insert(c);
    }

    sol = map<char, vector<int>>();
    for(auto c: colors)
    {
        sol[c] = vector<int>(m+1, m+1);
        sol[c][0] = 0;
    }

    for(auto c : coins){
        sol[c.second][c.first] = 1;
    }
    solveall(m);

    int k = m+1;
    for(auto c: colors) k = min(k, sol[c][m]);

    cout << k << '\n';
}

void solveall(int s)
{
    for(int j = 1; j <= s; j++)
    {
        for(auto c : coins)
        {
            if(c.first > j) continue;
            for(auto col : colors)
            {    
                if(col == c.second) continue;
                sol[c.second][j] = min(sol[c.second][j], sol[col][j - c.first] + 1);
            }
 
        }
    }
}
