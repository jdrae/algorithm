#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 95;
float whole = 0;
char c[31];

struct Trie{
    Trie* go[MAX];
    float output;
    char word[31];
    Trie(): output(0){fill(go, go+MAX, nullptr); fill(word, word+31, '\0');}
    ~Trie(){
        for(int i = 0; i<MAX; i++)
            if(go[i]) delete go[i];
    }

    void insert(const char* key){
        if(*key == '\0'){
            output++;
            strcpy(word, c);
        }
        else{
            int nxt = *key - 32;
            if(!go[nxt]) go[nxt] = new Trie;
            go[nxt]->insert(key+1);
        }
    }

    void print(){
        if(output > 0){
            printf("%s %.4f\n", word, output/whole*100);
        }
        for(int i = 0; i<MAX; i++){
            if(!go[i]) continue;
            go[i]->print();
        }
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Trie* root = new Trie();
    while(true){ // tip: 입력 종료될때까지 받기
        cin.getline(c, 31);
        if (cin.eof()) break;
        whole++;
        root->insert(c);
    }

    // while(scanf("%[^\n]%*c", c)) { // tip: 입력 종료될때까지 받기
    //     whole++;
    //     root->insert(c);
    // }

    root->print();
    delete root;
}
