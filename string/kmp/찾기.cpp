#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1000001;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    char T[MAX], P[MAX];
    int n, m;
    // tip: 공백포함 문자열
    cin.getline(T, MAX); cin.getline(P,MAX);
    // tip: char 배열 길이
    n = strlen(T); m = strlen(P); 
    
    int fail[MAX] = {0};
    for(int i = 1, j=0; i<m; i++){
        while(j > 0 && P[i] != P[j]) j = fail[j-1];
        if(P[i] == P[j]) fail[i] = ++j;
    }

    vector<int> result;
    for(int i=0, j=0; i<n; i++){
        while(j > 0 && T[i] != P[j])
            j = fail[j-1];
        if(T[i] == P[j]){
            if(j == m-1){ // P 를 T[i-m+1:i] 에서 찾음
                result.push_back(i-m+2);
                j = fail[j]; // T: ababa P: aba 의 경우
            }
            else
                j++;
        }
    }

    printf("%d\n", (int)result.size());
    for(int i: result)
        printf("%d ",i);
}
