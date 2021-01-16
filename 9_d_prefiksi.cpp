#include<bits/stdc++.h>

#define LOG(x) cout << #x << "::" << x << '\n'
#define INIT() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FORI(n) for(int i = 0; i < n; i++)
#define FORJ(n) for(int j = 0; j < n; j++)
#define FORK(n) for(int k = 0; k < n; k++)
using namespace std;

constexpr int C = 27;

struct node{
    int sol;
    node* children[C];

    node(){
        sol = 0;
        FORI(C) children[i] = nullptr;
    }
};

struct trie{
    node* root;

    trie(){
        root = new node();
    }

    void add(string s){
        node* curr = root;

        FORI(s.size()){
            int letter = s[i] - 'a';
            node* next = curr->children[letter];

            if(next){
                curr = next;
            } else {
                node* newNode = new node();
                curr->children[letter] = newNode;
                curr = newNode;
            }

            curr->sol++;
        }
        return;
    }

    int get(string s){
        node* curr = root;
        int len = 0;

        FORI(s.size()){
            int letter = s[i] - 'a';
            
            node* next = curr->children[letter];

            if(next) curr = next;
            else break;
            len++;
        }

        return len;
    }
};
int main()
{
    INIT();

    int q;
    cin >> q;

    trie* t = new trie();

    FORI(q)
    {
        int tip;
        string s;
        cin >> tip >> s;

        if(tip == 1){
            t->add(s);
        } else {
            cout << t->get(s) << '\n';
        }
    }
}