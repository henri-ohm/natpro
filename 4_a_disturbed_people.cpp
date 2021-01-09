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


int n, k, smallest;
vector<bool> a, original;

void printvec(vector<bool>& vec){
    for_each(vec.begin(), vec.end(), [](bool val){ cout << val << " ";});
    cout << '\n';
}

bool is_valid(){
    for(int i = 1; i < n - 1; i++){
        if(a[i]) continue;

        if(a[i - 1] && a[i + 1] && !a[i]) return false;
    }

    return true;
}

int diff()
{
    int ret = 0;
    FORI(n) if(a[i] ^ original[i]) ret++;
    return ret;
}

void search(int k){
    if(k == n){
        //printvec(a);
        if(!is_valid()) return;

        int curr = diff();
        if(curr < smallest) smallest = curr;
        return;
    } 

    bool changed = false;
    search(k + 1);
    if(a[k]) {
        a[k] = false;
        changed = true;
    }
    search(k + 1);
    if(!a[k] && changed) a[k] = true;
}

int main()
{
    INIT();

    cin >> n;
    a = vector<bool>(n);
    smallest = n;

    FORI(n){
        bool ai;
        cin >> ai;
        a[i] = ai;
    }

    original = a;
    search(0);
    cout << smallest << '\n';
}