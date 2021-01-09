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

int n;
ull sigma = 0;

vector<pair<ull, ull>> tasks;
vector<bool> picker;
int main()
{
    INIT();
    cin >> n;
    tasks = vector<pair<ull, ull>>(n);
    picker = vector<bool>(n);
    ull a,b;

    FORI(n){
        cin >> a;
        tasks[i] = {a, 0};
        sigma += a;
    }
    FORI(n){
        cin >> b;
        tasks[i].second = b;
    }

    ull lo = 0, hi = sigma;
    ull best = 0;
    while(lo < hi)
    {
        ull mid = (lo + hi) / 2;
        if(possible(mid)){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
}