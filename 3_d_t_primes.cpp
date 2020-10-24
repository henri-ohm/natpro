#include<bits/stdc++.h>

#define LOG(x) cout << #x << "::" << x << '\n'
#define INIT() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr) 
#define FORI(n) for(int i = 0; i < n; i++)

using namespace std;
using ull = uint64_t;
using ll  = int64_t;
using i   = int32_t;
using ss  = int16_t;
using us  = uint16_t;

using vi   = vector<i>;
using vll  = vector<ll>;
using vull = vector<ull>;

auto yes = "YES";
auto no  = "NO";

i n;
vull x;

bool is_prime(ull n)
{
    if(n < 2) return false;
    for(ull x = 2; x * x <= n; x++)
    {
        if(n % x == 0) return false;
    }
    return true;
}

bool is_t_prime(ull n)
{
    ull root = sqrt(n);
    if(root * root != n) return false;
    return is_prime(root);
}
int main()
{
    INIT();

    cin >> n;
    ull xi;
    while(n--)
    {
        cin >> xi;
        cout << (is_t_prime(xi) ? yes : no) << '\n';
    }
}