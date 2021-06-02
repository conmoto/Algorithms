#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    
    vector<int> answer;
    vector<int> temp;
    
    for(int i = 0; i < commands.size(); i++)
    {
        temp = array;
        
        int start = commands[i][0] - 1;
        int end = commands[i][1];
        int target = start + commands[i][2] - 1;
        
        sort(temp.begin() + start, temp.begin() + end);

        answer.push_back(temp[target]);
    }
   
    return answer;
}