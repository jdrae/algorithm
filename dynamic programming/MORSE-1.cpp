#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


const int M = 1000000000 + 100; // K�� �ִ� +100. �����÷� ���
int bino[201][201]; //bino[n+m][n]
// n&m �� �������� �����Ǵ� ���� ����
void calcBino() {
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++)
			bino[i][j] = min(M, bino[i-1][j-1]+bino[i-1][j]); //���װ�� ����
	}
}

/*
int skip;
void generate(int n, int m, string s) {
	if (skip < 0) return;
	if (n == 0 && m == 0) {
		if (skip == 0) cout << s << endl;
		--skip; //�ٸ� ���μ������� ����� ��� ���
		return;
	}
	if (bino[n + m][n] <= skip) {
		skip -= bino[n + m][n];
		return;
	}
	if (n > 0) generate(n - 1, m, s + "-");
	if (m > 0) generate(n, m - 1, s + "o");
}
*/

string kth(int n, int m, int skip) {
	if (n == 0) return string(m, 'o'); //�������: - �ٽ����� ������ o
	if (skip < bino[n + m - 1][n - 1]) // ù���ڰ� ������ ���(������ �� ���� ������ skip)
		return "-" + kth(n - 1, m, skip);
	return "o" + kth(n, m - 1, skip - bino[n + m - 1][n - 1]); // ù���ڰ� ������ ���
}

int main() {
	int C; cin >> C;
	while (C--) {
		int n, m, k; cin >> n >> m >> k;
		calcBino();
		cout << kth(n, m, k-1) << endl;
	}
}
