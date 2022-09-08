#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int n;
string words[16];
int answer;
int alph[26];
bool visited[16];

void init() {
	answer = 0;
	for (int i = 0; i < 26; i++)
		alph[i] = 0;
	for (int i = 0; i < 16; i++) {
		visited[i] = false;
	}
}

// 부분집합
void dfs(int pos, int cnt) { 
	if (pos == n) {
		if(cnt == 26) answer++;
		return;
	}

	for (char c : words[pos]) {
		if (alph[c - 'a'] == 0) cnt++;
		alph[c - 'a']++;
	}
	visited[pos] = true;
	dfs(pos + 1, cnt);

	for (char c : words[pos]) {
		alph[c - 'a']--;
		if (alph[c - 'a'] == 0) cnt--;
	}
	visited[pos] = false;
	dfs(pos + 1, cnt);

}


int main(int argc, char** argv)
{
	cin.tie(NULL); ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	int test_case;
	int T; cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> words[i];

		dfs(0, 0);

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}