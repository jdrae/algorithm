#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define MAX 10000001

bool not_prime[MAX]; // false 면 소수
int prime_num[3500]; // 소수 저장
int prime_num_length = 0;

void init() {
	for (int i = 2; i*i < MAX; i++) {
		if (not_prime[i]) continue; // 소수가 아니면 건너뜀
		else
			prime_num[prime_num_length++] = i;
		for (int j = i * 2; j < MAX; j += i)
			not_prime[j] = true;
	}
}

int main(int argc, char** argv)
{
	cin.tie(NULL); ios::sync_with_stdio(false);

	// freopen("input.txt", "r", stdin);

	int T; cin >> T;

	init();

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int n; cin >> n;

		// 소수
		if (!not_prime[n]) {
			printf("#%d %d\n", test_case, n);
			continue;
		}

		// 소수 아닌 경우. 소수로만 나눠줌
		int answer = 1;
		int pos = 0, cnt = 0;
		while (n >= 1) {
			if (n % prime_num[pos] == 0) {
				cnt++;
				n /= prime_num[pos];
			}
			else {
				if (cnt % 2) 
					answer *= prime_num[pos];
				if (!not_prime[n]) { // n 이 소수일 경우
					answer *= n;
					break;
				}

				pos++;
				if (pos == prime_num_length) { // 더 이상 n 을 분해할 소수가 없을 경우
					answer *= n;
					break;
				}

				cnt = 0;
			}
		}

		printf("#%d %d\n", test_case, answer);


	}
	return 0;
}