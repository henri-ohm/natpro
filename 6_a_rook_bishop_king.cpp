#include<bits/stdc++.h>

using namespace std;

int color(int i, int j)
{
    return (i + j) % 2; //0 bijela 1 crna
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ploca[8][8];
    int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int rook = 0;
    if(r1 != r2) rook++;
    if(c1 != c2) rook++;

    int bishop = 0;
    int bc = color(r1, c1);
    int t = color(r2, c2);
    if(bc == t){
        if(r1 - c1 == r2 - c2 || r1 + c1 == r2 + c2) bishop = 1;
        else bishop = 2;
    }

    int king = max(abs(r1 - r2), abs(c1 - c2));


    cout << rook << ' ' << bishop << ' ' << king << '\n';
}