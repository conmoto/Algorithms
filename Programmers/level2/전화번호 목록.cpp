#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {    
    
    //짧은 번호부터 집합에 포함시키기 위해 정렬한다
    sort(phone_book.begin(), phone_book.end());

    unordered_set<string> s;
    
    for(auto& phone : phone_book)
    {
        //집합에 있는 번호 중 접두어가 있는 경우를 찾는다.
        for(auto& prefix : s)
        {
            if(prefix == phone.substr(0, prefix.size()))
               return false;
        }
        //검사가 끝난 번호는 집합에 넣는다.
        s.insert(phone);
    }
    
    return true;
}