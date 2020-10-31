#include<bits/stdc++.h>
#define FORI(n) for(int i = 0; i < n; i++)
using namespace std;

int n, m, k = 0;
int max_sum = 0;


int sum(int a, int b){return (a%m+b%m)%m;}

int sum_mod_m(vector<int>& a)
{
    int ret = 0;
    for(int i = 0; i < a.size(); i++){
        ret = sum(ret, a[i]);
    }
    return ret;
}

vector<int> arr, a;
vector<int> s1, s2;

void solve()
{
    for(int i = 0; i < s1.size(); i++)
    {
        for(int j = 0; j < s2.size(); j++)
        {
            if(sum(s1[i], s2[j]) > k) k = sum(s1[i], s2[j]);
        }
    }
}

void solve1(int k)
{
    if(k >= n/2){
        int sum = sum_mod_m(arr);
        s1.push_back(sum);
        return;
    }

    solve1(k + 1);
    arr.push_back(a[k]);
    solve1(k + 1);
    arr.pop_back();

}

void solve2(int k)
{
    if(k >= n){
        int sum = sum_mod_m(arr);
        s2.push_back(sum);
        return;
    }

    solve2(k + 1);
    arr.push_back(a[k]);
    solve2(k + 1);
    arr.pop_back();

}

// poboljsanje nad baseline rjesenjem = meet in the middle
// za svaku polovicu stvoriti polja suma i u tom polju naci max
int main()
{
    cin >> n >> m;

    a = vector<int>(n);

    FORI(n) cin >> a[i];

    arr = vector<int>();
    solve1(0);
    arr = vector<int>();
    solve2(n - n/2);

    solve();
    cout << k << '\n';
}