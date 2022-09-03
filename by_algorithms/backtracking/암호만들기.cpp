#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
char arr[15], res[15];
bool isVowel[26];

void backtrack(int pos, int prev, int consonant, int vowel){
    if(pos == l){
        if(consonant >= 2 && vowel >= 1) puts(res);
        return;
    }

    for(int i = prev+1; i<c; i++){
        res[pos] = arr[i];
        backtrack(pos+1, i, consonant + !isVowel[arr[i]-'a'], vowel + isVowel[arr[i]-'a']);
    }
}

int main(){
    cin >> l >> c;
    for(int i = 0; i<c; i++){
        cin >> arr[i];
    }

    sort(arr, arr+c);

    isVowel['a'-'a'] = isVowel['e'-'a'] = isVowel['i'-'a'] = isVowel['o'-'a'] = isVowel['u'-'a'] = true;
    backtrack(0,-1,0,0);
}