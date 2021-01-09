#include<bits/stdc++.h>
using namespace std;

int n, m, d, k, slomljenih; // d=2k
vector<vector<int>> sjedala;


void pobroji(int d, int m)
{

}


int main()
{
    cin >> n >> m >> d;
    // n - broj redaka
    // m - broj grupa
    // d - broj clanova po grupi

    slomljenih = 0;
    char c;
    for(int i = 0; i < 2; i++){
        sjedala[i] = vector<int>(n);
        for(int j = 0; j < n; j++){
            cin >> c;
            if(c == 'X') slomljenih++;
            sjedala[i][j] = c == '.' ? 0 : -1;
        }
    }

    k = 0;
    if(m*d > n-slomljenih){
        cout << k << '\n';
        return;
    }
    pobroji(d, m);
    cout << k << '\n';
}