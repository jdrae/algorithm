#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int color[1000][3];
int cache[1000][4];

int cost(int start, int choose) {
	int& ret = cache[start][choose+1];
	if (ret != -1) return ret;
	ret = 1000000 + 1;
	if (start == n-1) {
		for (int i = 0; i < 3; i++) {
			if (i == choose) continue;
			ret = min(ret, color[start][i]);
		}
		return ret;
	}

	for (int i = 0; i < 3; i++) {
		if (i == choose) continue;
		ret = min(ret, color[start][i] + cost(start+1, i));
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> color[i][0] >> color[i][1] >> color[i][2]; 
	}
	memset(cache, -1, sizeof(cache));
	cout << cost(0, -1) << endl;

}
