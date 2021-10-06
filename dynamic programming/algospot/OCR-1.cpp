/*
분류기로 인식한 문장 R이 주어질 때 조건부 확률 P(Q|R)을 최대화하는 Q를 찾아야
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
double B[501], T[501][501], M[501][501]; //확률값
double cache[102][502];

// cache 초기화
void init() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			cache[i][j] = 1.0;
		}
	}
}

//이전 단어 번호가 p일때, 문장의 s번째 단어 이후의 최대치
double recognize(int segment, int previousMatch) { 
	if (segment == n) return 0;
	double& ret = cache[segment][previousMatch];
	if (ret != 1.0) return ret;
	ret = -1e200; //log(0): 음의 무한대
	int& choose = choice[segment][previousMatch]; 

	for (int thisMatch = 1; thisMatch <= m; ++thisMatch) { //[1,m]
		double cand = T[previousMatch][thisMatch]
					+ M[thisMatch][R[segment]]
					+ recognize(segment + 1, thisMatch);
		if (ret < cand) {
			ret = cand;
			choose = thisMatch; // 단어 번호 저장
		}
	}
	return ret; // 확률[0,1]의 로그 값은 항상 0이하. 반환값은 0 또는 음수.
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
	//단어
	for (int i = 1; i <= m; i++) {
		cin >> word[i];
		wton.insert(make_pair(word[i], i));
	}
	//처음에 출현할 확률
	for (int i = 1; i <= m; i++) { 
		cin >> B[i];
		B[i] = log(B[i]); //로그형으로 확률을 변환한다
	}
	// i의 다음 단어가 j 일 확률
	for (int i = 0; i <= m; i++) { 
		for (int j = 1; j <= m; j++) {
			if (i == 0)
				T[i][j] = B[j]; // T[0][j] 는 j가 처음에 출현할 확률
			else {
				cin >> T[i][j];
				T[i][j] = log(T[i][j]);
			}
		}
	}
	// i를 j로 분류할 확률
	for (int i = 1; i <= m; i++) { 
		for (int j = 1; j <= m; j++) {
			cin >> M[i][j];
			M[i][j] = log(M[i][j]);
		}
	}
	// 테스트케이스
	for (int i = 0; i < q; i++) { 
		cin >> n;
		// 분류기로 인식한 문장
		for (int j = 0; j < n; j++) {
			string tmp; cin >> tmp;
			R[j] = wton[tmp];
		}


		// 결과
		init();
		recognize(0, 0);
		cout << reconstruct(0, 0) << endl;
	}
}
