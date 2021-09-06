#include <string>
#include <vector>

using namespace std;

void dfs(int idx, int sum, int target, int size, int& answer, const vector<int>& numbers)
{
    if(idx == size)
    {
        if(sum == target)
            answer++;
        return;
    }
    
    dfs(idx + 1, sum + numbers[idx], target, size, answer, numbers);
    dfs(idx + 1, sum - numbers[idx], target, size, answer, numbers);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(0, 0, target, numbers.size(), answer, numbers);
    
    return answer;
}