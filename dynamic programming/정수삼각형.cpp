#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
vector<vector<int>> arr;
int cache[500][500];

int func(int i, int j){
    if(i < 0 || j < 0 || i >= n || j > i ) return 0;
    if(i==n) return arr[i][j];
    int& ret = cache[i][j];
    if(ret != -1) return ret;
    ret = arr[i][j];
    ret += max(func( i+1, j), func( i+1, j+1));
    return ret;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    n = triangle.size();
    arr.assign(triangle.begin(), triangle.end());
    memset(cache, -1, sizeof(cache));
    answer = func(0, 0);
    return answer;
}