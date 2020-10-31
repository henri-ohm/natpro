#include<bits/stdc++.h>
#define loop(n) for(int i = 0; i < n; i++)
using namespace std;

struct entry{
    int l, r, id;
};

constexpr int LIMIT = 1e7;
bool tagged_begin[LIMIT];

bool compare_ends(entry l, entry r) { return l.r < r.r;}

int n;

int main()
{
    cin >> n;
    entry entries[n];
    loop(n)
    {
        int l,r;
        cin >> l >> r;
        entries[i] = {l, r, i};
    }

    sort(entries, entries + n, compare_ends);

    int ans[n];

    for(int i = 0; i < n; i++)
    {
        int begin = entries[i].l;
        while(tagged_begin[begin])begin++;
        tagged_begin[begin] = true;
        ans[entries[i].id] = begin;
    }

    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
}