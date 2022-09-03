// 152ms / 7172kb
#include <iostream>
using namespace std;
const int MAX = 10;

struct Trie{
    Trie* go[10]; // 다음 노드를 가리키는 포인터 배열
    bool output;
    bool goexist;

    Trie(){
        fill(go, go+MAX, nullptr);
        output = goexist = false;
    }
    ~Trie(){
        for(int i = 0; i<MAX; i++)
            if(go[i]) delete go[i];
    }

    bool insert(const char* key){
        if(*key == '\0'){
            output = true;
            return !goexist; // 자식이 있다면 false
        }
        int nxt = *key - '0';
        if(!go[nxt]) go[nxt] = new Trie;
        goexist = true;
        return !output && go[nxt]->insert(key+1); // 끝나지 않았고, 이후 자식이 없으면 true
    }

    // bool consistent(){
    //     if(goexist && output) return false;
    //     for(int i = 0; i<MAX; i++)
    //         if(go[i] && !go[i]->consistent()) return false;
    //     return true;
    // }
};

int main(){
    int tc; scanf("%d",&tc);
    while(tc--){
        int n; scanf("%d",&n);
        Trie *root = new Trie;
        bool result = true;
        for(int i = 0; i<n; i++){
            char tel[11];
            scanf("%s", tel);
            if(result && !root->insert(tel)) result = false;
        }
        puts(result ? "YES" : "NO");
        delete root;
    }
}
