#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> stoi_dict = {
	{"ZRO", 0},
	{"ONE", 1},
	{"TWO", 2},
	{"THR", 3},
	{"FOR", 4},
	{"FIV", 5},
	{"SIX", 6},
	{"SVN", 7},
	{"EGT", 8},
	{"NIN", 9}
};

string itos_dict[10] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		// input
		string tmp; cin >> tmp; cin >> tmp;
		int size = stoi(tmp);

		int arr[10] = {0, };
		for (int i = 0; i < size; i++) {
			cin >> tmp;
			arr[stoi_dict[tmp]] += 1;
		}

		// print
		printf("#%d\n", test_case);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < arr[i]; j++) {
				cout << itos_dict[i] << " ";
			}
		}
		printf("\n");
	}
	return 0;
}