#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    unordered_set<char> skill_set;
    queue<string> skill_tree;
    
    //순서가 있는 스킬을 set에 추가한다.
    for(auto& s : skill)
    {
        skill_set.insert(s);
    }
    
    for(auto& skill_tree : skill_trees)
    {
        int check = 0;
        int idx = 0;
        for(auto& s : skill_tree)
        {
            //순서가 있는 스킬일 경우
            auto iter = skill_set.find(s);
            if(iter != skill_set.end())
            {
                //순서가 틀릴 경우 빠져나간다.
                if(skill[check] != s)
                    break;
                //순서가 맞을 경우 다음으로.
                else
                    check++;
            }
            
            idx++;
            if(idx == skill_tree.length())
                answer++;
        }
    }
    
    return answer;
}