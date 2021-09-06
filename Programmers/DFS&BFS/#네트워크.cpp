#include <string>
#include <vector>
#include <queue>
using namespace std;


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; i++)
    {
        queue<int> que;
        
        if(!visited[i]) //아직 방문하지 않은 노드에서 출발.
        {
            answer++;
            
            que.push(i);
            while(!que.empty()) //연결 된 모든 점을 방문처리 하도록 너비 우선 탐색을 합니다.
            {
                int cur = que.front();
                visited[cur] = true;
                que.pop();
                
                for(int i = 0; i < n; i++)
                {
                    if(!visited[i] && computers[cur][i]) //연결되어있고 방문하지 않았다면 queue에 push.
                        que.push(i);
                }
            }
        }
    }
    
    return answer;
}