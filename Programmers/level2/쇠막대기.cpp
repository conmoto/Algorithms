#include <string>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int ans = 0;
    stack<char> s;
    
    for(int i = 0; i < arrangement.length(); i++)
    {
        if(arrangement[i] == '(')
        {
            s.push('(');
        }
        else
        {
            s.pop();
            if(arrangement[i-1] == '(')
            {
                //이전에 '('인 경우 광선으로 막대기를 자른다.
                ans += s.size();
            }
            else
            {
                //이전에 '('가 아닌 경우 막대의 오른쪽 끝.
                ans++;
            }
        }
    }
    
    return ans;
}