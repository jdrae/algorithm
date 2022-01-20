#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

int n, m;
deque<pair<int,int>> q;

int main(){
    int t; cin >> t;
    int tmp;
    while(t--){
        q.clear();
        cin >> n >> m;
        for(int i = 0; i<n; i++){
            cin >> tmp;
            q.push_back(make_pair(i,tmp));
        }
        int ans = 0;
        while(!q.empty()){
            pair<int,int> curr = q.front();
            bool pop = true;
            for(int i = 0; i<q.size(); i++){
                if(curr.second >= q[i].second) continue;
                q.pop_front(); q.push_back(curr); pop = false; break;
            }
            if(pop){
                // printf("pop: %d %d\n", q.front().first, q.front().second);
                q.pop_front();
                ans++;
                if(curr.first == m){
                    cout << ans << endl;
                    break;
                }
            }
        }
    }
}