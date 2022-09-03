#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 501;

struct Trie{
    Trie* go[26];
    bool output;
    
    Trie(): output(false){fill(go, go+26, nullptr);}
    ~Trie(){
        for(int i = 0; i<26; i++)
            if(go[i]) delete go[i];
    }

    void insert(const char* key){
        if(*key == '\0') output = true;
        else{
            int nxt = *key - 'a';
            if(!go[nxt]) go[nxt] = new Trie;
            go[nxt]->insert(key+1);
        }
    }

    int check(const char* key){
        if(*key == '\0') return output; // 트라이도 끝나면 1, 안끝나면 0
        int nxt = *key - 'a';
        if(!go[nxt]) return false; // 체크해야할 글자가 트라이에 없음
        return go[nxt]->check(key+1);
    }
};

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n, m; cin >> n>>m;
    Trie *root = new Trie;
    int cnt = 0;
    for(int i= 0; i<n;i++){
        char w[MAX]; cin >> w;
        root->insert(w);
    }
    for(int i = 0; i<m; i++){
        char w[MAX]; cin >> w;
        if(root->check(w)) cnt++;
    }
    printf("%d\n", cnt);
    delete root;
}
