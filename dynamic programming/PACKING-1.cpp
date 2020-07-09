#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, capacity;
string name[100];
int volume[100], need[100];
int cache[1001][100];

int pack(int capacity, int item) {
	if (item == n) return 0;
	int& ret = cache[capacity][item];
	if (ret != -1) return ret;

	ret = pack(capacity, item + 1);
	if (capacity >= volume[item]) {
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	}
	return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked) {
	if (item == n) return;
	if (pack(capacity, item) == pack(capacity, item + 1)) {
		reconstruct(capacity, item + 1, picked);
	}
	else {
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}


int main() {
	int testCase; cin >> testCase;
	while (testCase--) {
		cin >> n >> capacity;
		for (int i = 0; i < n; i++) {
			cin >> name[i] >> volume[i] >> need[i];
		}
		memset(cache, -1, sizeof(cache));
		printf("%d ", pack(capacity, 0));
		vector<string> picked;
		reconstruct(capacity, 0, picked);
		printf(" %d\n", picked.size());
		for (int i = 0; i < picked.size(); i++)
			cout << picked[i] <<endl;
	}

}