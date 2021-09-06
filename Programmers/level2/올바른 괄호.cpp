#include<string>
#include <iostream>
#include <stack>
using namespace std;

//#define STACK
bool solution(string str)
{
    bool answer = true;
    
    #ifdef STACK // 스택을 이용한 풀이
    stack<char> s;

    for(auto& ch : str)
    {
        if(ch == '(')
            s.push(ch);
        else
        {
            if(s.empty())
            {
                answer = false;
                break;
            }
            else
                s.pop();
        }
    }
    
    if(!s.empty())
        answer = false;

    return answer;
    #endif

    int n = 0;
    for (int i = 0; i < str.length(); i++) {
        if (n < 0)
            return false;
        if (str[i] == '(')
            n++;
        else if (str[i] == ')')
            n--;
    }
    
    return n == 0;
}