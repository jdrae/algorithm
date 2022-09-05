#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int n;
char to_char[101];
pair<int, int> tree[101];
char answer[101];
int pos;

void inorder(int root) {
	if (root == -1) return;
	inorder(tree[root].first);
	answer[pos++] = to_char[root];
	inorder(tree[root].second);
}

int main(int argc, char** argv)
{
	cin.tie(NULL); ios::sync_with_stdio(false);

	// freopen("input.txt", "r", stdin);

	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		// input
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int root; char c;
			int l = -1, r = -1;
			cin >> root >> c;
            if(cin.get() != '\n') {
                cin >> l;
                if(cin.get() != '\n') 
                    cin >> r;
            }
			tree[root] = {l, r};
			to_char[root] = c;
		}
        
		// solution
        pos = 0;
		inorder(1);

		// output
        cout << '#' << test_case << ' ';
        for(int i = 0; i < pos; i++) cout << answer[i];
        cout << '\n';
	}
	return 0;
}