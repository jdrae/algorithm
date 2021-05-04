#include <string>
#include <vector>

using namespace std;

bool isSmall(char c){
    return ('a' <= c && 'z' >= c);
}
bool isBig(char c){
    return ('A'<=c && 'Z' >= c);
}

string solution(string s) {
    string answer = "";
    int dif = 'a' - 'A';
    bool first = true;
    for(char c : s){
        if(c == ' '){ first=true; answer += c; continue;};
        if(!isSmall(c) && !isBig(c)){answer += c; first = false; continue;};
        if(first){
            if(isSmall(c)) c -= dif;
            answer += c;
            first = false;
        }
        else{
            if(isBig(c)) c += dif;
            answer += c;
        }
    }
    return answer;
}