// solve again
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 2*100000;

int n, s, e;
vector<int> arr;
// tip: 트리 배열로 나타내기
int leftchild[MAX], rightchild[MAX], parent[MAX];
char op[MAX];

// curr 번 째 노드가 피연산자인지 연산자인지 파악해 해당 노드의 연산 결과 반환
// 연산자일 경우(중간 노드): 연산자에 따라 왼쪽 트리와 오른쪽 트리의 결과 재귀적으로 계산
// 피연산자일 경우(리프 노드): - 의 오른쪽 자식을 홀수번째 거치면 작은 수부터, 이외는 큰 수부터 반환
int dfs(int curr, int cnt){ 
    int ret = 0;
    // 연산자
    if(curr >= n+1){
        if(op[curr] == '+'){
            ret += dfs(leftchild[curr], cnt);
            ret += dfs(rightchild[curr], cnt);
        }
        else{
            ret += dfs(leftchild[curr], cnt);
            ret -= dfs(rightchild[curr], cnt + 1);
        }
    }
    // 피연산자
    else{
        if(cnt % 2){ // 작은 수
            ret = arr[s++];
        }
        else{ // 큰 수
            ret = arr[e--];
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 1; i<=n; i++){
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    char o; int a, b;
    for(int i = n+1; i<=2*n-1; i++){
        cin >> o >> a >> b;
        op[i] = o;
        leftchild[i] = a; rightchild[i] = b;
        parent[a] = parent[b] = i;
    }
    
    sort(arr.begin(), arr.end());
    s = 0; e = n - 1;

    printf("%d\n", dfs(2*n-1, 0));
}
