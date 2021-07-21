// https://www.acmicpc.net/board/view/53965
#include <iostream>
#include <cstring>
using namespace std;

struct Trie{
    Trie* go[26];
    bool output;
    int branch, word;
    Trie(): output(false), branch(0), word(0){fill(go, go+26, nullptr);}
    ~Trie(){
        for(int i = 0; i<26; i++)
            if(go[i]) delete go[i];
    }

    void insert(const char* key){
        if(*key == '\0'){
            branch++;
            output = true;
        }
        else{
            if(!go[*key - 'a']){
                branch++;
                go[*key -'a'] = new Trie;
            }
            word++;
            go[*key-'a']->insert(key+1);
        }
    }

    long long count(bool isRoot=false){
        long long result = 0;
        if(isRoot || branch > 1){
            result = word;
        }
        for(int i = 0; i<26; i++){
            if(!go[i]) continue;
            result += go[i]->count();
        }
        return result;
    }
};

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n; 
    while(cin >> n){ // tip: 테스트케이스 개수를 모를때 입력
        if(cin.eof()) return 0;
        Trie *root = new Trie();
        for(int i = 0; i<n; i++){
            char word[81]; cin >>word;
            root->insert(word);
        }
        printf("%.2lf\n", 1.0*root->count(true)/n);
        delete root;
    }
}
