#include <string>
#include <vector>
#include <set>
using namespace std;


int solution(int m, int n, vector<vector<int>> puddles) {
    
    set<pair<int, int>> s;
    for(auto& puddle : puddles)
    {
        s.insert(make_pair(puddle[1] - 1, puddle[0] - 1));
    }
    
    //n X m 2차원 배열 모든 원소를 0으로 초기화
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    //0번째 행 초기화
    for(int x = 1; x < m; x++)
    {
        if(s.find(make_pair(0, x)) != s.end())
            break;
        dp[0][x] = 1;
    }
    //0번째 열 초기화
    for(int y = 1; y < n; y++)
    {
        if(s.find(make_pair(y, 0)) != s.end())
            break;
        dp[y][0] = 1;
    }   
    
    //dp
    for(int x = 1; x < m; x++)
    {
        for(int y = 1; y < n; y++)
        {
            if(s.find(make_pair(y, x)) != s.end())
                continue;
            dp[y][x] = (dp[y-1][x] + dp[y][x-1]) % 1000000007;
        }
    }
    
    return dp[n - 1][m - 1];
}