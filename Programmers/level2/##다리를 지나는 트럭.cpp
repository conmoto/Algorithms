#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    int departure_time = 0;
    queue<pair<int, int>> que;
    
    int weight_sum = 0;
    int idx = 0;
    
    while(idx < truck_weights.size())
    {
        if(weight_sum + truck_weights[idx] <= weight)
        {
            ++departure_time;
            
            weight_sum += truck_weights[idx];
            que.push(make_pair(truck_weights[idx], departure_time));
        }
        else
        {
            //다리가 견딜 수 있는 무게를 초과한 경우
            while(weight_sum + truck_weights[idx] > weight)
            {
                weight_sum -= que.front().first;
                //마지막으로 빠져나온 트럭의 출발 시간 + 다리의 길이 시간이 다음 트럭의 출발시간이 된다.
                departure_time = que.front().second + bridge_length;
                que.pop();
            }
            
            que.push(make_pair(truck_weights[idx], departure_time));
            weight_sum += truck_weights[idx];
        }
        
        // !!다리를 지나간 트럭들을 제거
        while(que.front().second <= departure_time - bridge_length)
        {
            weight_sum -= que.front().first;
            que.pop();
        }
        //cout << idx << ": " << departure_time << endl;
        ++idx;
    }
    
    int answer = departure_time + bridge_length;
    
    return answer;
}