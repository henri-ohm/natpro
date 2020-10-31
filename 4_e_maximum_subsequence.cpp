#include<bits/stdc++.h>
#define FORI(n) for(int i = 0; i < n; i++)
using namespace std;

int n, m;
int max_sum = 0;

int sum_mod_m(vector<int>& a)
{
    int ret = 0;
    for(int i = 0; i < a.size(); i++){
        ret = (ret % m + a[i] % m) % m;
    }
    return ret;
}

vector<int> arr, a;

void solve(int k)
{
    if(k == n){
        int sum = sum_mod_m(arr);
        if(sum > max_sum){
            max_sum = sum;
        }
        return;
    }

    solve(k + 1);
    arr.push_back(a[k]);
    solve(k + 1);
    arr.pop_back();

}
int main()
{
    cin >> n >> m;

    a = vector<int>(n);

    FORI(n) cin >> a[i];

    solve(0);
    cout << max_sum << '\n';
}