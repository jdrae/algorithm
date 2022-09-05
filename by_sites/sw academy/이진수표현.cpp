#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	cin.tie(NULL); ios::sync_with_stdio(false);

	// freopen("input.txt", "r", stdin);

	int T; cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int n, m; cin >> n >> m;

		bool on = true;
		while (m > 1 && n > 0) {
			if (m % 2 != 1) {
				on = false;
				break;
			}
			m /= 2;
			n--;
		}
		if (n > 1 || m == 0)
			on = false;

		if (on)
			printf("#%d ON\n", test_case);
		else
			printf("#%d OFF\n", test_case);
			
	}
	return 0;
}