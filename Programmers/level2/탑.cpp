#include <stack>
#include <vector>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<pair<int, int>> s;
    
    for(int i = 0; i < heights.size(); i++)
    {
        if(s.empty())
        {
            s.push(make_pair(heights[i], i + 1));
            answer.push_back(0);
        }
        else
        {
            //스택이 비어있지 않을때 현재 조사하는 높이 이하의 탑은 스택에서 제거
            while(!s.empty() && s.top().first <= heights[i])
                s.pop();
            
            if(s.empty())
                answer.push_back(0);
            else
                answer.push_back(s.top().second);//발견한 더 높은 탑의 인덱스를 저장
            
            s.push(make_pair(heights[i], i + 1));//현재 조사한 탑을 스택에 푸시
        }
    }   
    
    return answer;
}