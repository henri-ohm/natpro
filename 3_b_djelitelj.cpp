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
using pii = pair<i,i>;

int q;
int a, b, k;


#define N 100001
int num[N];
auto pairs = vector<pair<int, int>>(N); // pair of a number n, and the number of his divisors
void napuni_djelitelje()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = i; j < N; j += i)
        {
            num[j - 1]++;
        }
    }

    for(int i = 1; i <= N; i++)
    {
        pairs[i - 1] = {i, num[i-1]};
    }

    sort(pairs.begin(), pairs.end(), [](pii& a, pii& b){ 
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });
}

int main()
{
    INIT();
    cin >> q;
    napuni_djelitelje();
    while(q--)
    {
        cin >> a >> b >> k;
        
        int c = 0;

        auto it = lower_bound(pairs.begin(), pairs.end(), make_pair(0, k), [](const pii& a, const pii& b){
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        
        for(; it != pairs.end(); it++)
        {
            auto curr = *it;
            if(curr.second != k) break;
            if(curr.first >= a && curr.first <= b) c++;
        }
        
        cout << c << '\n';
    }
}