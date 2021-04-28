#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int n = priorities.size();
    queue<pair<int,int>> q;
    for(int i = 0; i<n; i++){
        q.push(make_pair(i, priorities[i]));
    }
    sort(priorities.begin(), priorities.end());
    int i = n-1;
    while(i > -1 || !q.empty()){
        if(q.front().second < priorities[i]){
            q.push(q.front()); q.pop();
        }
        else{
            answer++;
            i--;
            if(q.front().first == location) break;
            q.pop();
        }
    }
    
    return answer;
}