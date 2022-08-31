#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
	cin.tie(NULL); ios::sync_with_stdio(false);

	// freopen("input.txt", "r", stdin);

	int test_case;
	int T; cin >> T;


	for (test_case = 1; test_case <= T; ++test_case)
	{
		// input
		long long k; cin >> k;

		// solution
        // 짝수를 계속 나눴을 때 마지막에 1이 나오는지 0이 나오는지 판별
        // (4의 배수인지, 4의 배수가 아닌 2의 배수인지)
		while ((k % 2) == 0)
			k /= 2;

		if ((k - 1) / 2 % 2 == 0) {
			printf("#%d 0\n", test_case);
		}
		else {
			printf("#%d 1\n", test_case);
		}

		
	}
	return 0;
}