// https://programmers.co.kr/learn/courses/30/lessons/49189

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {    
    queue<pair<int, int>> que; // 방문 노드와 거리를 저장하는 큐
    vector<bool> visited(n + 1, false);
    vector<int> count(n + 1, 0); // 거리마다 노드 갯수를 저장
    
    int max_distance = 1;
    visited[1] = true;
    for(int i = 0; i < edge.size(); i++)
    {
        //1번노드와 연결된 노드들을 큐에 삽입
        if(edge[i][0] == 1) 
        {
            que.push(make_pair(edge[i][1], max_distance));
            visited[edge[i][1]] = true;
            count[max_distance]++;
        }
        else if(edge[i][1] == 1)
        {
            que.push(make_pair(edge[i][0], max_distance));
            visited[edge[i][0]] = true;
            count[max_distance]++;
        }
    }
    
    while(!que.empty())
    {
        int cur_node = que.front().first;
        max_distance = que.front().second + 1;
        que.pop();
        
        for(int i = 0; i < edge.size(); i++)
        {
            if(edge[i][0] == cur_node && !visited[edge[i][1]])
            {
                que.push(make_pair(edge[i][1], max_distance));
                visited[edge[i][1]] = true;
                count[max_distance]++;
            }
            else if(edge[i][1] == cur_node && !visited[edge[i][0]])
            {
                que.push(make_pair(edge[i][0], max_distance));
                visited[edge[i][0]] = true;
                count[max_distance]++;
            }
        }
    }
    
    int answer = 0;
    for(auto& n : count)
    {
        if(n != 0)
            answer = n;
    }
    
    return answer;
}