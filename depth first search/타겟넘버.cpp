#include <string>
#include <vector>

using namespace std;

vector<int> arr;
int n, m;

int dfs(int curr, int idx){
    if((idx == n)&&(curr == m)) return 1;
    if(idx == n) return 0;
    int ret = 0;
    ret += dfs(curr+arr[idx], idx+1);
    ret += dfs(curr-arr[idx], idx+1);
    
	return ret;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    n = numbers.size(); m = target;
    arr.assign(numbers.begin(), numbers.end());
    answer = dfs(0, 0) ;
    return answer;
}