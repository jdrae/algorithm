#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int solution(string numbers) {
    int answer = 0;
    int n = numbers.size();
    unordered_set<int> set;
    sort(numbers.begin(), numbers.end());
	do {
		for (int i = 1; i < n+1; i++) {
			int a = stoi(numbers.substr(0,i));
            if(isPrime(a)) set.insert(a);
		}
	} while (next_permutation(numbers.begin(), numbers.end()));
    
    answer = set.size();
    
    return answer;
}