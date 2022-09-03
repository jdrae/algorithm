/*
�з���� �ν��� ���� R�� �־��� �� ���Ǻ� Ȯ�� P(Q|R)�� �ִ�ȭ�ϴ� Q�� ã�ƾ�
P(Q|R) = (P(R|Q)P(Q))/P(R)
*/


#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>//log
using namespace std;

int m,q, n; // m<501, q<21, n<101
string word[501];
map<string, int> wton;
int R[100], choice[102][502];
double B[501], T[501][501], M[501][501]; //Ȯ����
double cache[102][502];

// cache �ʱ�ȭ
void init() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			cache[i][j] = 1.0;
		}
	}
}

//���� �ܾ� ��ȣ�� p�϶�, ������ s��° �ܾ� ������ �ִ�ġ
double recognize(int segment, int previousMatch) { 
	if (segment == n) return 0;
	double& ret = cache[segment][previousMatch];
	if (ret != 1.0) return ret;
	ret = -1e200; //log(0): ���� ���Ѵ�
	int& choose = choice[segment][previousMatch]; 

	for (int thisMatch = 1; thisMatch <= m; ++thisMatch) { //[1,m]
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
	string ret = word[choose];
	if (segment < n - 1)
		ret = ret + " " + reconstruct(segment + 1, choose);
	return ret;
}

int main() {
	cin >> m >> q;
	//�ܾ�
	for (int i = 1; i <= m; i++) {
		cin >> word[i];
		wton.insert(make_pair(word[i], i));
	}
	//ó���� ������ Ȯ��
	for (int i = 1; i <= m; i++) { 
		cin >> B[i];
		B[i] = log(B[i]); //�α������� Ȯ���� ��ȯ�Ѵ�
	}
	// i�� ���� �ܾ j �� Ȯ��
	for (int i = 0; i <= m; i++) { 
		for (int j = 1; j <= m; j++) {
			if (i == 0)
				T[i][j] = B[j]; // T[0][j] �� j�� ó���� ������ Ȯ��
			else {
				cin >> T[i][j];
				T[i][j] = log(T[i][j]);
			}
		}
	}
	// i�� j�� �з��� Ȯ��
	for (int i = 1; i <= m; i++) { 
		for (int j = 1; j <= m; j++) {
			cin >> M[i][j];
			M[i][j] = log(M[i][j]);
		}
	}
	// �׽�Ʈ���̽�
	for (int i = 0; i < q; i++) { 
		cin >> n;
		// �з���� �ν��� ����
		for (int j = 0; j < n; j++) {
			string tmp; cin >> tmp;
			R[j] = wton[tmp];
		}


		// ���
		init();
		recognize(0, 0);
		cout << reconstruct(0, 0) << endl;
	}
}
