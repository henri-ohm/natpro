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

int q;
int a, b, k;


#define N 100001
int num[N];

void napuni_djelitelje()
{
    for(int i = 1; i < N; i++)
    {
        for(int j = i; j < N; j += i)
        {
            num[j - 1]++;
        }
    }
}

int main()
{
    INIT();
    cin >> q;
    napuni_djelitelje();
    while(q--)
    {
        cin >> a >> b >> k;
        // koliko brojeva u [a, b] ima tocno k pozitivnih dijelitelja
        if(k == 1 && a == 1)
        {
            cout << 1 << '\n';
            continue;
        }
        
        int c = 0;
        for(int it = a; it <= b; it++)
            if(num[it - 1] == k) c++;
        
        cout << c << '\n';
    }
}