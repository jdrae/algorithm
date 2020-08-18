#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool isBitSet(unsigned long long a, int b) {
	return (a & (1ull << b)) > 0;
}

int main() {
	
}