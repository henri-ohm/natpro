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

    node() {
        sol = 0;
        FORI(C) children[i] = nullptr;
    }
};

int index(char c)
{
    if(c == ' ') return 26;
    else return c - 'a';
}

struct trie{
    node* root;

    trie(node* root) : root(root){}

    void add(string s){
        node* curr = root;

        FORI(s.size()){
            int letter = index(s[i]);
            node* next = curr->children[letter];

            if(next){
                curr = next;
            } else {
                node* newNode = new node();
                curr->children[letter] = newNode;
                curr = newNode;
            }

            curr->sol = max(curr->sol, (int)s.size());
        }
        return;
    }

    int get(string s){
        node* curr = root;
        int len = 0;
        FORI(s.size()){
            int letter = index(s[i]);
            //LOG(letter);
            node* next = curr->children[letter];

            if(next) curr = next;
            else return 0;
        }

        return curr->sol;
    }
};

int main()
{
    INIT();
    int q;
    cin >> q;
    cin.ignore();
    node* root = new node();
    trie* t = new trie(root);

    FORI(q)
    {
        string line;
        getline(cin, line);
        
        string linija(line.begin(), line.end());
        char tip = linija[0];
        string s = linija.substr(2);
        
        t->add(s);
        if(tip == 's'){
            cout << t->get(s) << '\n';
        }
        
    }
}