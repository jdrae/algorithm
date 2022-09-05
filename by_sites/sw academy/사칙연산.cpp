#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

struct Node {
	int num;
	char op;
	int left;
	int right;
	bool is_op;
};

const int MAX = 1001;
int n;
Node tree[MAX];

bool is_operator(string s){
	if (s == "+" || s == "-" || s == "*" || s == "/") return true;
	return false;
}


double postorder(int root) {
	if (tree[root].is_op == false)
		return tree[root].num;

	double a = postorder(tree[root].left);
	double b = postorder(tree[root].right);
	
	switch (tree[root].op)
	{
	case('+'):
		return a + b;
	case('-'):
		return a - b;
	case('*'):
		return a * b;
	case('/'):
		return a / b;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	cin.tie(NULL); ios::sync_with_stdio(false);

	// freopen("input.txt", "r", stdin);

	int T;

	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		// input
		cin >> n;
		for (int i = 0; i < n; i++) {
			int id; string value;
			int l = -1, r = -1;
			cin >> id >> value;
			bool is_op = is_operator(value);
			if (is_op) {
				cin >> l >> r;
				tree[id].op = value[0];
			}
			else {
				tree[id].num = stoi(value);
			}

			tree[id].is_op = is_op;
			tree[id].left = l;
			tree[id].right = r;
		}

		// solution
		int answer = (int)postorder(1);

		// output
		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}