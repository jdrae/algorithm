// 44ms / 6004kb
#include <iostream>
#include <cstring>
using namespace std;
const int GO_MAX = 10;
const int CHAR_MAX = 100001;

struct Trie{
    int cnt;
    int go[CHAR_MAX][GO_MAX];
    bool output[CHAR_MAX];
    bool goexist[CHAR_MAX];

    Trie(){
        cnt = 1;
        memset(go, 0, sizeof(go));
        memset(output, 0, sizeof(output));
        memset(goexist, 0, sizeof(goexist));
    }

    bool insert(const char* key, int node = 0){
        if(*key == '\0'){
            output[node] = true;
            return !goexist[node];
        }
        int nxt = *key - '0';
        if(!go[node][nxt]) go[node][nxt] = cnt++;
        goexist[node] = true;
        return !output[node] && insert(key+1, go[node][nxt]);
    }
};

int main(){
    int tc; scanf("%d",&tc);
    while(tc--){
        int n; scanf("%d",&n);
        Trie trie;
        bool result = true;
        for(int i = 0; i<n; i++){
            char tel[11];
            scanf("%s", tel);
            if(result && !trie.insert(tel)) result = false;
        }
        puts(result ? "YES" : "NO");
    }
}
