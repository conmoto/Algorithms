#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(char& ch : s)
    {
        if(ch != ' ')
        {
            ch >= 'a' ?
                ch = (ch - 'a' + n) % 26 + 'a' :
                ch = (ch - 'A' + n) % 26 + 'A'; 
        }
        answer.push_back(ch);
    }
    
    return answer;
}