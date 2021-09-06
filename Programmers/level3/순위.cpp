#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

void FindWinner(vector<vector<int>>& results, unordered_set<int>& s, int index, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(results[i][index] == 1) //나에게 이긴사람 이라면.
        {
            auto Iter = s.find(i);
            if(Iter == s.end()) // 아직 집합에 포함된 적이 없다면.
            {
                s.insert(i);
                //cout << i << " ";
                FindWinner(results, s, i, n); // 나에게 이긴 사람에게 이긴 사람을 탐색.
            }
        }    
    }
}
void FindLoser(vector<vector<int>>& results, unordered_set<int>& s, int index, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(results[index][i] == 1) //나에게 진사람 이라면.
        {
            auto Iter = s.find(i);
            if(Iter == s.end()) // 아직 집합에 포함된 적이 없다면.
            {
                s.insert(i);
                //cout << i << " ";
                FindLoser(results, s, i, n); // 나에게 진 사람에게 진 사람을 탐색.
            }
        }    
    }
}

int solution(int n, vector<vector<int>> results) {

    int answer = 0;
    
    //자신에게 이긴사람을 찾기 위해서 방향그래프의 역방향 추적을 해야하므로 인접배열로 만든다.
    vector<vector<int>> graph(n + 1, vector<int>(n+1, 0)); //2차원 벡터 초기화.
        
    //이긴사람 -> 진사람 방향그래프를 만든다.
    for(int i = 0; i < results.size(); i++)
    {
        graph[results[i][0]][results[i][1]] = 1;
    }
    
    for(int i = 1; i <= n; i++)
    {
        unordered_set<int> s;
        //나에게 진 사람을 찾는다.(정방향 탐색)
        //cout << "Loser: ";
        FindLoser(graph, s, i, n);
        //나에게 이긴 사람을 찾는다.(역방향 탐색)
        //cout << "Winner: ";
        FindWinner(graph, s, i, n);
        
        if(s.size() == n - 1) // 나에게 이긴사람 + 진 사람의 수가 n - 1이라면
            answer++;
    }
    
    return answer;
}