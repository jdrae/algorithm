/*
�з���� �ν��� ���� R�� �־��� �� ���Ǻ� Ȯ�� P(Q|R)�� �ִ�ȭ�ϴ� Q�� ã�ƾ�
P(Q|R) = (P(R|Q)P(Q))/P(R)
*/


#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int m,q, n; // m<501, q<21, n<101
map<string, int> wton;
map<int,string> ntow;
int R[100], choice[102][502];
double B[500], T[501][501], M[501][501]; //Ȯ����
double cache[102][502];

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cache[i][j] = 1.0;
		}
	}
}

double recognize(int segment, int previousMatch) { //���� �ܾ� ��ȣ�� p�϶�, ������ s��° �ܾ� ������ �ִ�ġ
	if (segment == n) return 0;
	double& ret = cache[segment][previousMatch];
	if (ret != 1.0) return ret;
	ret = -1e200; //log(0): ���� ���Ѵ�
	int& choose = choice[segment][previousMatch]; 

	for (int thisMatch = 0; thisMatch < m; ++thisMatch) {
		double cand = T[previousMatch][thisMatch]
					+ M[thisMatch][R[segment]]
					+ recognize(segment + 1, thisMatch);
		if (ret < cand) {
			ret = cand;
			choose = thisMatch; // �ܾ� ��ȣ ����
		}
	}
	return ret; // Ȯ��[0,1]�� �α� ���� �׻� 0����. ��ȯ���� 0 �Ǵ� ����.
}

string reconstruct(int segment, int previousMatch) {
	int choose = choice[segment][previousMatch];
	string ret = ntow[choose];
	if (segment < n - 1)
		ret = ret + " " + reconstruct(segment + 1, choose);
	return ret;
}

int main() {
	cin >> m >> q;
	for (int i = 0; i < m; i++) { //�ܾ�
		string tmp; cin >> tmp;
		wton[tmp] = i;
		ntow[i] = tmp;
	}
	for (int i = 0; i < m; i++) { //ó���� ������ Ȯ��
		cin >> B[i];
	}
	for (int i = 1; i <= m; i++) { // i�� ���� �ܾ j �� Ȯ��
		for (int j = 1; j <= m; j++) {
			cin >> T[i][j];
		}
	}
	for (int i = 1; i <= m; i++) { // i�� j�� �з��� Ȯ��
		for (int j = 1; j <= m; j++) {
			cin >> M[i][j];
		}
	}
	for (int i = 0; i < q; i++) { // �׽�Ʈ���̽�
		cin >> n;
		for (int j = 0; j < n; j++) {// �з���� �ν��� ����
			string tmp; cin >> tmp;
			R[j] = wton[tmp];
		}
		// ���
		init();
		recognize(0,)
	}
}
