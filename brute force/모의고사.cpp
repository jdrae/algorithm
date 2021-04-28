#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Student{
    int id;
    int score;
}Student;

bool cmp(const Student &a, const Student &b){
    if(a.score == b.score) return a.id < b.id;
    return a.score > b.score;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int n = answers.size();
    vector<vector<int>> st_in; st_in.resize(4);
    st_in[0] = {1,2,3,4,5};
    st_in[1] = {2,1,2,3,2,4,2,5};
    st_in[2] = {3,3,1,1,2,2,4,4,5,5};
    Student st_out[3] = {{1,0},{2,0},{3,0}};
    
    for(int id = 0; id<3; id++){
        int size = st_in[id].size();
        for(int i = 0; i<n; i++){
            if(st_in[id][i%size] == answers[i])
                st_out[id].score++;
        }
    }
    
    sort(st_out, st_out + 3, cmp);
    int mx = st_out[0].score;
    for(int i = 0; i<3; i++){
        if(mx != st_out[i].score) break;
        answer.push_back(st_out[i].id);
    }
    return answer;
}