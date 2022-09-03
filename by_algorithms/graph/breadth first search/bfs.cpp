// https://blog.naver.com/kks227/220785747864
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
class Graph{
public:
    int N;
    vector<vector<int>> adj;

    Graph(): N(0){}
    Graph(int n): N(n){adj.resize(N);}

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void sortList(){
        for(int i=0; i<N; i++)
            sort(adj[i].begin(), adj[i].end());
    }

    void bfs(){
        vector<bool> visited(N, false);
        queue<int> Q;
        Q.push(0);
        visited[0] = true;

        int level = 0;
        while(!Q.empty()){
            int qSize = Q.size();
            cout << "----- level " << level << " -----" << endl;
            for (int i = 0; i < qSize; i++){
                int curr = Q.front();
                Q.pop();
                cout << "node " << curr << " visited" << endl;
                for(int next: adj[curr]){
                    if(!visited[next]){
                        visited[next] = true;
                        Q.push(next);
                    }
                }
            }
            level++;
        }
    }
};

int main(){
    Graph G(9);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    G.addEdge(1, 5);
    G.addEdge(3, 4);
    G.addEdge(4, 5);
    G.addEdge(2, 6);
    G.addEdge(2, 8);
    G.addEdge(6, 7);
    G.addEdge(6, 8);
    G.sortList();
    G.bfs();
}