#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

priority_queue<int, deque<int>, less<int>> pque;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    
    int answer = 0;
    int i = 0;

    for(int day = 0; day < k; day++)
    {
        //공급을 할 수 있는 날이면 공급량을 힙에 오름차순으로 저장한다.
        if(dates[i] == day)
        {
            pque.push(supplies[i]);
            i++;
        }

        if(stock == 0)
        {
            stock += pque.top();
            pque.pop();
            answer++;
        }

        stock--;
    }

    return answer;
}