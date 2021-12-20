#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cache[100][100];
int y, x;

int func(int i, int j){
    if(i == y-1 && j == x-1) return 1;
    if(i>=y || j >= x) return 0;
    
    int& ret =  cache[i][j];
    if(ret != -1) return ret;
    
    ret = 0;
    ret += func(i+1, j) % 1000000007;
    ret += func(i,j+1) % 1000000007;
    
    return ret % 1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    x = m; y = n;
    memset(cache, -1, sizeof(cache));
    
    for(int i = 0; i<puddles.size(); i++){
        cache[puddles[i][1]-1][puddles[i][0]-1] = 0;
    }
    
    answer = func(0,0);
    return answer;
}