#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int mat[n][n];
    int a,b;
    while(m--){
        cin >> a >> b;
        a--; b--;
        mat[a][b]=1;
        mat[b][a]=1;
    }
 

    auto stog = stack<int>();
    stog.push(0);
    vector<int> boje(n,2);

    b = 0;
    int tb;

    while(!stog.empty()){
        tb = b;
        int node = stog.top();
        stog.pop();
  
        if(boje[node] != 2) continue;
        boje[node] = tb;
        for(int i = 0; i < n; i++){
            if(mat[node][i] == 1){
                if(boje[i] == 2){
                    stog.push(i);
                } else if(boje[i] == tb){
                    cout << "NE" << '\n';
                    return 0;
                }
            }
        }
        b = 1 - b;
    }

    cout << "DA" << '\n';
}