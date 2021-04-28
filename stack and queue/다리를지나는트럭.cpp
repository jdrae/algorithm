#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, curr_weight = 0, dists;
    queue<int> bridge_cars, left_dist;
    while(!truck_weights.empty() || !left_dist.empty()){
        int dists = left_dist.size();
        for(int i = 0; i <dists; i++){
            int d = left_dist.front(); 
            left_dist.pop();
            if(d<=1){
                curr_weight -= bridge_cars.front();
                bridge_cars.pop();continue;
            }
            left_dist.push(d-1);
        }
        if(!truck_weights.empty() && (bridge_cars.size() < bridge_length )&& (truck_weights.at(0) + curr_weight <= weight)){
            bridge_cars.push(truck_weights.at(0)); curr_weight += truck_weights.at(0);
            left_dist.push(bridge_length);
            truck_weights.erase(truck_weights.begin());
        }
        answer++;
    }
    return answer;
}