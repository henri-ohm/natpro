#include <bits/stdc++.h>

using namespace std;


struct node {
    short value;
    short num;
};

short n, m;
queue<node> q;
bool visited[20001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    q = queue<node>();
    q.push({n, 0});

    while(!q.empty()){
        node curr = q.front();
        q.pop();
        visited[curr.value] = true;
        
        if(curr.value == m){
            cout << curr.num << '\n';
            break;
        }

        if(curr.value < m && !visited[2*curr.value]) q.push({2 * curr.value, curr.num + 1});
        if(curr.value > 0 && !visited[curr.value - 1]) q.push({curr.value - 1, curr.num + 1});
    }
    
}