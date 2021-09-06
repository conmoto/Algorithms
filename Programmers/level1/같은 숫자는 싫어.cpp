#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    int before = arr[0];
    
    for(int& i : arr)
    {
        if(before != i)
        {
            answer.push_back(i);
            before = i;   
        }
    }    
    
    return answer;
}