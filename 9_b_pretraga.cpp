#include<bits/stdc++.h>

#define LOG(x) cout << #x << "::" << x << '\n'
#define INIT() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FORI(n) for(int i = 0; i < n; i++)
#define FORJ(n) for(int j = 0; j < n; j++)
#define FORK(n) for(int k = 0; k < n; k++)
using namespace std;
using ll = uint64_t;
constexpr int P = 31177;
constexpr int N = 4 * 1e5 + 1;
constexpr ll M = 1e9 + 7;
ll B[N];



ll add(ll a, ll b){
    return ((a % M) + (b % M)) % M;
}

ll mul(ll a, ll b){
    return ((a % M) * (b % M)) % M;
}

ll sub(ll a, ll b){
    b = b % M;
    b = M - b;
    return add(a, b);
}

int main()
{
    INIT();
    
    B[0] = 1;
    for(int i = 1; i < N; i++) B[i] = mul(P, B[i - 1]);

    string p;
    getline(cin, p);

    ll h = 0;
    FORI(p.size()) h = add(h, mul(p[i], B[i]));

    //cout << "pattern hash :: " << h << '\n';


    int n;
    cin >> n;
    cin.ignore();

    FORI(n)
    {
        int pos = -1;

        string s;
        getline(cin, s);

        if(s.size() < p.size()) {
            cout << pos << '\n';
            continue;
        }

        ll H[s.size()];
        H[0] = s[0];

        //cout << "HASH\n";
        //cout << H[0] << ' ';
        for(int j = 1; j < s.size(); j++) {
            H[j] = add(H[j - 1], mul(s[j], B[j]));
            //cout << H[j] << ' ';
        }
        //cout << '\n';
        

        for(int j = 0; j < s.size() - p.size() + 1; j++)
        {
            int l = j;
            int r = j + p.size();


            ll currh;
            if(l == 0){
                currh = H[r - 1];
            } else {
                currh = sub(H[r - 1], H[l - 1]);

            }
            //cout << currh << ' ';
            if(currh == mul(h, B[l])) {
                bool eq = true;
                for(int k = 0; k < p.size(); k++){
                    if(p[k] != s[j + k]) {
                        eq = false;
                        break;
                    }
                }
                if(!eq) continue;
                pos = j;
                break;
            }
        }
        //cout << '\n';

        cout << pos << '\n';
    }
}