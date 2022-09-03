#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, k;
int answer = 9;

void func(int made, int cnt){
    if(cnt > 8) return;
    if(made == n) answer = min(cnt, answer);
    
    int tmp = 0;
    for(int i = 0; i<9; i++){
        tmp = tmp + k * pow(10, i);
        func(made+tmp, cnt+1+i);
        func(made-tmp, cnt+1+i);
        func(made*tmp, cnt+1+i);
        func(made/tmp, cnt+1+i);
    }
    
}

int solution(int N, int number) {
    k = N; n = number;
    func(0, 0);
    answer = answer > 8 ? -1 : answer;
    return answer;
}