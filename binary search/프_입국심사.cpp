#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long l = 0; long long r = (long long)n * times[times.size()-1];
    while(l+1<r){
        printf("===%lld to %lld\n", l, r);
        long long mid = (l+r) / 2;
        long long cnt = 0;
        for(int i = 0; i< times.size(); i++){
            cnt += mid/times[i];
        }
        printf("%lld %lld\n", mid, cnt);
        if(cnt < n) l = mid;
        else r = mid;
    }
    answer = r;
    return answer;
}

int main(){
    int MAX = 1000000000;
    cout << solution(MAX, {MAX,2})<<endl;
}