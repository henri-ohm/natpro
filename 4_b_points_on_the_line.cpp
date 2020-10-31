#include<bits/stdc++.h>
#define FORI(n) for(int i = 0; i < n; i++)
using namespace std;

constexpr uint16_t MAXN = 100;
uint16_t n, d;
uint16_t a[MAXN];
int main()
{
    cin >> n >> d;
    FORI(n){
        cin >> a[i];
    }
    
    sort(a, a+n);
    if(a[n-1] - a[0] <= d){
        cout << 0 << '\n';
        return 0;
    }

    int k = n + 1;
    for(int i = 0; i < n - 1; i++){
        for(int j = i; j < n; j++){
            int mink = n - (j - i + 1);
            if(a[j] - a[i] <= d && mink <= k){
                k = mink;
            }
        }
    }

    cout << k << '\n';
}