#include<bits/stdc++.h>
using namespace std;
#define LOG(x) cout << #x << ' ' << x << '\n'
int n, m, r;
/*
n - broj otoka
m - broj mostova
r - otok na kojem se na pocetku nalazimo
*/

void dfs(int x, vector<double>& prob, map<int, vector<int>>& graf, double probability)
{
    // LOG(x);
    if(graf[x].size() == 0){ // na ovome otoku smo zapeli
        prob[x - 1] += probability;
    } else {
        auto vec = graf[x];
        int velicina = vec.size();
        // LOG(velicina);
        for(int child: vec){
            dfs(child, prob, graf, probability / velicina);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> r;
    int a, b;
    
    auto bridovi = map<int, vector<int>>();

    while(m--)
    {
        cin >> a >> b;
        bridovi[a].push_back(b);
    }

    double startval = 0.0;
    vector<double> prob = vector<double>(n, startval);
    dfs(r, prob, bridovi, 1);

    vector<pair<double, int>> sol = vector<pair<double, int>>(n);

    for(int i = 0; i < n; i++){
        sol[i] = {prob[i], i+1};
    }

    sort(sol.begin(), sol.end(), [](auto& a, auto& b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });

    double starting = sol[0].first;
    for(int i = 0; i < n; i++){
        if(abs(sol[i].first - starting) > 1e-9) break;
        cout << sol[i].second << ' ';
    } cout << '\n';
}