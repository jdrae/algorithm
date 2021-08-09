#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int arr[30];
    for(int i = 0; i<n; i++) arr[i] = 1;
    for(int i : reserve) arr[i-1] = 2;
    for(int i : lost) arr[i-1] -= 1;
    
    for(int i = 0; i<n; i++){
        if(arr[i] == 0){
            if(i-1 >= 0 && arr[i-1] == 2){
                arr[i-1] -= 1; arr[i] += 1;
            }
            else if(i+1 < n && arr[i+1] == 2){
                arr[i+1] -= 1; arr[i] += 1;
            }
        }
        if(arr[i] != 0) answer += 1;
    }
    
    
    return answer;
}