#include <iostream>
#include <vector>
using namespace std;

char open[3] = {'(','{','['};
char close[3] = {')','}',']'};

bool isOpen(char o){
    for(int i = 0; i<3; i++)
        if(open[i] == o) return true;
    return false;
}

bool isPair(char o, char c){
    int op, cl;
    for(int i = 0; i<3; i++){
        if(open[i] == o) op = i;
    }
    for(int j = 0; j<3; j++){
        if(close[j] == c) cl = j;
    }
    return (op == cl);
}

int solution(string s) {
    int answer = 0;
    if(s.size() % 2) return 0;
    for(int i = 0; i<s.size(); i++){
        if(!isOpen(s[i])) continue;
        int check = 0;
        for(int st = i; st< s.size() + i; st++){
            int idx1 = st % s.size();
            if(!isOpen(s[idx1])) continue;
            for(int j = st+1; j<s.size() + i; j+=2){
                int idx2 = j % s.size();
                if(isPair(s[idx1], s[idx2])){
                    check += 1; break;
                }
            }
        }
        if(check == s.size()/2) answer++;
    }
    return answer;
}

int main(){
    cout << solution("[{}]{}()") << endl;

}