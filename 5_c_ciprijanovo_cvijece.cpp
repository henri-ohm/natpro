#include<bits/stdc++.h>

#define LOG(x) cout << #x << "::" << x << '\n'
#define INIT() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FORI(n) for(int i = 0; i < n; i++)
#define FORJ(n) for(int j = 0; j < n; j++)
#define FORK(n) for(int k = 0; k < n; k++)
using namespace std;
using ull = uint64_t;
using ll  = int64_t;
using i   = int32_t;
using ss  = int16_t;
using us  = uint16_t;

using vi   = vector<i>;
using vll  = vector<ll>;
using vull = vector<ull>;

int n, m;
const char cvijet = 'X';


int je_cvijet(char c) {return c == cvijet ? 1 : 0;}
bool is_legal(int i, int j){
    i = i+1;
    j = j+1;
    return i <= 2*j && j <= 2*i;
}
int main()
{
    INIT();
    cin >> n >> m;
    char polje[n][m];

    FORI(n) {
        FORJ(m) 
            cin >> polje[i][j];
    }

    int mc[3][n][m];
    FORI(3) FORJ(n) FORK(m) mc[i][j][k] = 0;
    mc[0][0][0] = mc[1][0][0] = mc[1][0][0] = je_cvijet(polje[0][0]);

    // 0 - dolje
    // 1 - desno
    // 2 - doljedesno
    FORI(n){
        FORJ(m){
            if(!is_legal(i, j)) continue;
            if(j > 0)          mc[0][i][j] = max( mc[0][i][j] ,  mc[1][i][j-1]   + je_cvijet(polje[i][j]));
            if(j > 0 && i > 0) mc[0][i][j] = max( mc[0][i][j] ,  mc[2][i-1][j-1] + je_cvijet(polje[i][j]));

            if(i > 0)          mc[1][i][j] = max( mc[1][i][j] ,  mc[0][i-1][j]   + je_cvijet(polje[i][j]));
            if(i > 0 && j > 0) mc[1][i][j] = max( mc[1][i][j] ,  mc[2][i-1][j-1] + je_cvijet(polje[i][j]));

            if(i > 0)          mc[2][i][j] = max( mc[2][i][j] ,  mc[0][i-1][j]   + je_cvijet(polje[i][j]));
            if(j > 0)          mc[2][i][j] = max( mc[2][i][j] ,  mc[1][i][j-1]   + je_cvijet(polje[i][j]));
        }
    }

    int best = je_cvijet(polje[0][0]);
    FORK(3) FORI(n) FORJ(m) best = max(best, mc[k][i][j]);
    cout << best << '\n';

    // FORK(3){
    //     cout << "k = " << k << '\n';
    //     FORI(n) FORJ(m) cout << mc[k][i][j] << " \n"[j == m - 1 ? 1 : 0];
    // }
}