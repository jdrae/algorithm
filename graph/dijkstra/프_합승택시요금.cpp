#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 201;
const int INF = 2000000000;
typedef pair<int, int> P;
vector<P> adj[MAX];

int dijkstra(int i, int s, int a, int b) {
    int dist[MAX]; fill(dist, dist + MAX, INF);
    priority_queue<P> pq;
    dist[i] = 0;
    pq.push({ 0,i });
    while (!pq.empty()) {
        int curr = pq.top().second;
        int cd = -pq.top().first;
        pq.pop();
        if (dist[curr] < cd) continue;

        for (auto& p : adj[curr]) {
            int nxt = p.second;
            int nd = p.first + cd;
            if (dist[nxt] > nd) {
                dist[nxt] = nd;
                pq.push({ -dist[nxt], nxt });
            }
        }
    }
    if (dist[s] == INF) return INF;
    return dist[s] + dist[a] + dist[b];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    for (auto& p : fares) { // {u,v, w}
        adj[p[0]].push_back(P(p[2], p[1])); // w, v
        adj[p[1]].push_back(P(p[2], p[0]));
    }

    for (int i = 1; i <= n; i++) {
        answer = min(answer, dijkstra(i, s, a, b));
    }

    return answer;
}

int main() {
    // cout << solution(6, 4, 6, 2, { {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} }) << endl;
    // cout << solution(7, 3, 4, 1, { {5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6} }) << endl;
    cout << solution(6, 4, 5, 6, { {2,6,6}, {6,3,7}, {4,6,7}, {6,5,11}, {2,5,12}, {5,3,20}, {2,4,8}, {4,3,9} }) << endl;
}