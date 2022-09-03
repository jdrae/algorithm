// https://syogeng.wordpress.com/2017/09/29/%EB%B0%B1%EC%A4%80-10360-the-mountain-of-gold/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
 
#define INF 1e9
 
typedef struct {
    int from, to, weight;
}Edge;
 
int main() {
    int T;
    cin >> T;
 
    for (int testCase = 1; testCase <= T; testCase++) {
        int N, M;
        cin >> N >> M;
 
        vector<vector<int>> rev(N);
        vector<Edge> edges;
        for (int i = 0; i < M; i++) {
            int from, to, weight;
            cin >> from >> to >> weight;
            rev[to].push_back(from);
            edges.push_back({ from, to, weight });
        }
 
        bool canGoBack[1000];
        fill(canGoBack + 1, canGoBack + N, false);
        canGoBack[0] = true;
        stack<int> st;
        st.push(0);
        while (!st.empty()) {
            const int cur = st.top(); st.pop();
            for (int next : rev[cur]) if (canGoBack[next] == false) {
                canGoBack[next] = true;
                st.push(next);
            }
        }
 
        int dist[1000];
        fill(dist + 1, dist + N, INF);
        dist[0] = 0;
        for (int i = 0; i < N - 1; i++) {
            for (const Edge cur : edges) {
                const int newDist = dist[cur.from] + cur.weight;
                dist[cur.to] = min(dist[cur.to], newDist);
            }
        }
 
        bool found = false;
        for (const Edge cur : edges) if (dist[cur.to] > dist[cur.from] + cur.weight && canGoBack[cur.to]) {
            found = true;
            break;
        }
 
        printf("Case #%d: %spossible\n", testCase, found ? "" : "not ");
    }
    return 0;
}