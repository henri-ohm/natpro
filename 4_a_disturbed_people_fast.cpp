#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<bool> a(n);
    vector<bool> b(n, false);

    for(int i = 0; i < n; i++){
        bool ai;
        cin >> ai;
        a[i] = ai;
    }

    bool prev = false;
    int k = 0;
    for(int i = 0; i < n; i++){
        if(!a[i] && prev) b[i] = true;
        
        if (i - 1 > 0 && a[i] && b[i - 1]){
            k++;
            prev = false;
        } else prev = a[i];
    }  

    cout << k << '\n';

}