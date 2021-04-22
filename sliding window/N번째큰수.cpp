#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#include <queue>

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n, tmp;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> tmp;
            if(j==0){
                pq.push(tmp); continue;
            }
            if(pq.top() < tmp){
                pq.pop();
                pq.push(tmp);
            }
        }
    }
    printf("%d\n", pq.top());
}