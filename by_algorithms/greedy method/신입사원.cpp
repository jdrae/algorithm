#include <iostream>
#include <cstring>
using namespace std;
#include <vector>
#include <algorithm>

int main(){
    int T; cin >> T;
    
    while(T--){
        int N; cin >> N;
        vector<pair<int, int>> score;
        int s1, s2;
        for(int i = 0; i<N; i++){
            cin >> s1 >> s2;
            score.push_back(make_pair(s1,s2));
        }
        sort(score.begin(), score.end());
        
        int cnt = 1;
        int interview = score[0].second;
        for(int i = 1; i<N; i++){
            if(score[i].second < interview){
                cnt++;
                interview = score[i].second;
            }
        }
        cout << cnt << endl;
    }
}