#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj; // i 와 j 사이의 간선의 수
vector<string> graph[26][26]; // graph[i][j] : i로 시작해서 j 로 끝나는 단어들
vector<int> indegree, outdegree; // in/outdegree[i]: i 로 시작하는/끝나는 단어 수.
void makeGraph(const vector<string> &words){
    for(int i=0; i<26; i++){
        for(int j=0; j<26;j++){
            graph[i][j].clear();
        }
    }
    adj = vector<vector<int>>(26,vector<int>(26,0));
    indegree = outdegree = vector<int>(26,0);

    for(int i=0; i<words.size(); i++){
        int a = words[i][0] - 'a';
        int b = words[i][words[i].size()-1] - 'a';
        graph[a][b].push_back(words[i]);
        adj[a][b]++;
        outdegree[a]++;
        indegree[b]++;
    }
}

void getEulerCircuit(int curr, vector<int>& circuit){
    for(int nxt=0; nxt<adj.size(); nxt++){
        while(adj[curr][nxt] > 0){
            adj[curr][nxt]--;
            getEulerCircuit(nxt, circuit);
        }
    }
    circuit.push_back(curr);
}

vector<int> getEulerTrailOrCircuit(){
    vector<int> circuit;
    for(int i=0; i<26; i++){
        if(outdegree[i] == indegree[i]+1){
            getEulerCircuit(i,circuit);
            return circuit;
        }
    }

    for(int i=0; i<26; i++){
        if(outdegree[i]){
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    return circuit;
}

bool checkEuler(){
    int plus1 = 0, minus1 = 0;
    for(int i=0; i<26; i++){
        int delta = outdegree[i] - indegree[i];
        if(delta < -1 || 1 < delta) return false;
        if(delta == 1) plus1++;
        if(delta == -1) minus1++;
    }
    return (plus1 == 1 && minus1 == 1) || (plus1 ==0 && minus1 == 0);
}

string solve(const vector<string> &words){
    makeGraph(words);
    if(!checkEuler()) return "IMPOSSIBLE";
    vector<int> circuit = getEulerTrailOrCircuit();
    if(circuit.size() != words.size() + 1) return "IMPOSSIBLE";

    reverse(circuit.begin(), circuit.end());
    string ret;
    for(int i=1; i<circuit.size(); i++){
        int a = circuit[i-1], b = circuit[i];
        if(ret.size()) ret += " ";
        ret += graph[a][b].back();
        graph[a][b].pop_back();
    }
    return ret;
}

int main(){
    int tc; cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<string> arr;
        arr.resize(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        cout << solve(arr) << endl;
    }
}