#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 100;

int uf[MAX];
int find(int a){
    if(uf[a] <0) return a;
    return uf[a] = find(a);
}

bool merge(int a, int b){
    a = find(a); b = find(b);
    if(a==b) return false;
    uf[b] = a;
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pair<double, double> arr[MAX];
    int n; cin >> n;
    double x, y;
    for(int i = 0; i<n; i++){
        cin >> x>> y;
        arr[i] = {x,y};
    }
    // printf("%.2f, %.2f", arr[0].first, arr[0].second);

    priority_queue<pair<double, pair<int,int>>> pq;
    for(int i = 0; i<n ;i++){
        for(int j = i+1; j<n; j++){
            double cost = hypot(arr[i].first - arr[j].first, arr[i].second - arr[j].second);
            pq.push({-cost, {i,j}});
        }
    }

    fill(uf, uf+n, -1);
    double mst = 0; int cnt = 0;
    while(!pq.empty()){
        if(merge(pq.top().second.first, pq.top().second.second)){
            mst += pq.top().first;
            if(cnt++ == n-1) break;
        }
        pq.pop();
    }
    printf("%.2f", mst);
}