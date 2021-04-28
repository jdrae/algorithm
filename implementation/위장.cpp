#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int n = clothes.size();
    map<string, int> m;
    for(int i = 0; i<n; i++){
        string key = clothes[i][1];
        if(m.count(key) == 0)
            m[key] = 1;
        else
            m[key]++;
    }
    for(auto const& [key, val] : m){
        // printf("%s %d\n", key.c_str(), val);
        answer *= (val+1);
    }
    return answer - 1;
}