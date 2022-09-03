// https://blog.naver.com/kks227/220793360258
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000;
vector<int> prime;

void n2() {
	for (int i = 2; i <= MAX; i++) {
		bool isPrime = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) prime.push_back(i);
	}
}

void eratosthenes() {
	bool isPrime[MAX + 1];
	fill(isPrime + 2, isPrime + MAX + 1, true);
	for (int i = 2; i <= MAX; i++) {
		if(isPrime[i]) prime.push_back(i);
		for (int j = i * 2; j <= MAX; j += i)
			isPrime[j] = false;
	}
}

void eratosthenes2() {
	bool isPrime[MAX + 1];
	fill(isPrime + 2, isPrime + MAX + 1, true);
	// Â¦¼ö ºø±Ý
	for (int i = 4; i <= MAX; i += 2)
		isPrime[i] = false;
	for (int i = 3; i <= MAX; i += 2) {
		if (!isPrime[i]) continue;
		prime.push_back(i);
		for (int j = i * i; j <= MAX; j += i * 2)
			isPrime[j] = false;
	}
}

int main() {
	eratosthenes2();
	for (int i = 0; i < prime.size(); i++) {
		printf("%4d", prime[i]);
		if (i % 10 == 9 || i == prime.size() - 1) puts("");
	}
}