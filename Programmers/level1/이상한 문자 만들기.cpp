#include <string>

using namespace std;

string solution(string s) {
    
    //단어의 짝/홀수 인덱스를 판단하기 위한 변수
    int idx = 0;
    
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' ')
        {
            idx = 0;
        }
        else
        {
            //홀수번째는 소문자로, 짝수번째는 대문자로
            (idx & 1) ? (s[i] = tolower(s[i])) : (s[i] = toupper(s[i]));
            idx++;
        }   
    }
    
    return s;
}