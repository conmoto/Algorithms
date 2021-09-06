#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = -1;
    
    sort(scoville.begin(), scoville.end());
    
    if(scoville[0] >= K)
    {
        return 0;
    }
    for(int i = 1; i < scoville.size(); i++)
    {   
        if(scoville[i - 1] < scoville[i])
        {
            scoville[i] = scoville[i - 1] + scoville[i] * 2;
        }
        else
        {
            scoville[i] = scoville[i] + scoville[i - 1] * 2;
        }
        
        if(scoville[i] >= K)
        {
            answer = i;
            break;
        }
    }
    
    return answer;
}