#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{   
    int cnt_p = 0;
    int cnt_y = 0;
    
    for(auto ch : s)
    {
        if(ch == 'p' || ch == 'P')
            cnt_p++;
        if(ch == 'y' || ch == 'Y')
            cnt_y++;
    }
    
    return (cnt_p == cnt_y);
}