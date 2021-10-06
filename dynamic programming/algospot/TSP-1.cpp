#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define MAX = 10;
int n;
double dist[MAX][MAX];

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
	if (path.size == n)
		return currentLength + dist[path[0]][path.back()];

	double ret = INFINITY;
	for (int next = 0; next < n; ++next) {
		if (visited[next]) continue;
		
		int here = path.back();
		path.push_back(next);
		visited[next] = true;

		double cand = shortestPath(path, visited, currentLength + dist[here][next]);

		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back();
	}

	return ret;
}

int main() {
	n = 5;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", dist[i][j]);
			if (i == j) continue;
			dist[i][j] = rand() % 10 + 1;
		}
		printf("\n");
	}


	vector<int> path; path.push_back(0);
	vector<bool> visited; visited.push_back(0);
	double currentLength = 0;
	//cout << shortestPath(path, visited, currentLength) << endl;



}