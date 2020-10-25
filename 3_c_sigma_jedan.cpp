#include<bits/stdc++.h>
#define LOG(x) cout << #x << '=' << x << '\n'
using namespace std;
using ll = uint64_t;
using i = uint32_t;
void io_init();
void fill_divs();

constexpr int n = 1e6;
i a, b, c;
ll u,  v;

auto divs = vector<ll>(n);


int main()
{
    io_init();

    int q;
    cin >> q;
    while(q--)
    {
        cin >> a >> b >> u >> v;
        fill_divs(a, b);
        c = 0;
        for(int i = a; i <= b; i++)
        {
            if(divs[i - 1] <= v && divs[i - 1] >= u) c++;
        }

        cout << c << '\n';
    }
}

void fill_divs(i a, i b)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = a; j <= b; j += i)
        {
            divs[j - 1] += i;
        }
    }
}

/*

Dano je q upita oblika:

"Za koliko prirodnih brojeva n takvih da a⩽n⩽b vrijedi u⩽σ1(n)⩽v?

Ako znate da je σ1(n) zbroj pozitivnih djelitelja n, odgovorite na njih.

Input
U prvom retku ulaza je 1⩽q⩽105, broj upita.

U sljedećih q redaka, odvojeni razmakom, su redom prirodni brojevi a,b,u i v iz opisa. 
U svim upitima vrijedi 1⩽a⩽b⩽106 i 1⩽u⩽v⩽1012.

Output
Ispišite q redaka, u i-tom od kojih je odgovor na i-ti upit.

*/


void io_init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}