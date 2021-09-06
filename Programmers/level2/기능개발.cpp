#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;

    for(int i = 0; i < progresses.size(); i++)
    {
        int day = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0)
        {
            day++;
        }
        days.push(day);
    }
    
    int before_day = days.front();
    days.pop();
    int cnt = 1;
    while(!days.empty())
    {
        if(days.front() <= before_day)
        {
            cnt++;
            days.pop();    
        }
        else
        {
            before_day = days.front();
            answer.push_back(cnt);
            cnt = 1;
            days.pop();
        }
    }
    answer.push_back(cnt);
        
    
    return answer;
}