#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(const string& str, char del){
    vector<string> ret;
    stringstream ss(str);
    string buff;
    while(getline(ss, buff, del)){
        ret.push_back(buff);
    }
    return ret;
}

int unix_time(const string& str){ //20:59:57.421
    vector<string> times = split(str, ':');
    int h = stoi(times[0]) * 60 * 60 * 1000;
    int m = stoi(times[1]) * 60 * 1000;
    vector<string> sec = split(times[2], '.');
    int s = stoi(sec[0]) * 1000 + stoi(sec[1]);
    return h+m+s;
}

typedef struct Log{
    int start, end;
}Log;

int solution(vector<string> lines) {
    int answer = 0;
    int n = lines.size();
    vector<Log> log;
    
    for(int i = 0; i < n ; i++){
        vector<string> spl = split(lines[i], ' ');
        string dur = spl[2];
        dur.pop_back();
        if(dur.find(".") != string::npos)
            dur.replace(dur.find("."),1,"");
        int end = unix_time(spl[1]);
        int start = unix_time(spl[1]) - (stoi(dur) * 1000);
        log.push_back({start, end});
    }
    
    for(int i =0;i<log.size(); i++){
        // printf("%d %d\n", log[i].start, log[i].end);
    }
    return answer;
}