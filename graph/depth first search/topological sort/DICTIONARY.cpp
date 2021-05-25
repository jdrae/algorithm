#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int SIZE = 26;
vector<string> words;
vector<vector<int>> adj;
vector<int> visited, order;

void makeGraph(){
    for(int j = 1; j<n; j++){
        int i = j-1, len = min(words[i].size(), words[j].size());
        //word[i] 가 word[j] 보다 앞에 오는 이유
        for(int k = 0; k < len; k++){
            if(words[i][k] != words[j][k]){
                int a = words[i][k] - 'a';
                int b = words[j][k] - 'a';
                adj[a][b] = 1;
                break;
            }
        }
    }
}

void dfs(int curr){
    visited[curr] = 1;
    for(int nxt = 0; nxt < SIZE; nxt++){
        if(adj[curr][nxt] && !visited[nxt]){
            dfs(nxt);
        }
    }
    order.push_back(curr);
}

vector<int> topologicalSort(){
    // dfsAll
    for(int i=0; i<SIZE; i++)
        if(!visited[i]) dfs(i);
    
    reverse(order.begin(), order.end());

    // 정렬 결과에 역방향 간선이 있는지
    for(int i=0; i<SIZE; i++){
        for(int j=i+1; j<SIZE; j++){
            if(adj[order[j]][order[i]])
                return vector<int>();
        }
    }

    return order;
}


int main(){
    int tc; cin >> tc;
    while(tc--){
        adj = vector<vector<int>>(SIZE, vector<int>(SIZE,0));
        visited = vector<int>(SIZE, 0);
        order.clear();

        cin >> n;
        words.resize(n);
        for(int i=0; i<n; i++){
            cin >> words[i];
        }

        makeGraph();

        vector<int> ans = topologicalSort();
        if(ans.empty()){
            printf("INVALID HYPOTHESIS\n");
            continue;
        }
        for(int i : ans){
            printf("%c", i +'a');
        }
        cout<<endl;
    }
}