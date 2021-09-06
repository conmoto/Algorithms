#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    //내림차순으로 정렬
    sort(citations.begin(), citations.end(), greater<int>());
    
    for(int i = 0; i < citations.size(); i++)
    {
        //인용 횟수 >= 인용 논문 수
        if(citations[i] >= i + 1)
            answer = i + 1;
    }
    
    return answer;
}