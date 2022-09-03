#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string s, t;
int n, m, cache[1000][1000];

int func(int i, int j){
    if(i >= n || j >= m) return 0;
    int& ret = cache[i][j];
    if(ret != -1) return ret;
    
    ret = func(i, j+1);
    ret = max(ret, func(i+1, j));
    if(s[i] == t[j]) ret = max(ret, func(i+1, j+1) + 1);

    return ret;
}

int main(){
    cin >> s >> t;
    n = s.length();
    m = t.length();
    memset(cache, -1, sizeof(cache));
    cout << func(0,0) << endl;
}