#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    
    //2차원 배열 초기화
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));

    //1행
    dp[0][0] = triangle[0][0];
    
    //N행의 M번째 숫자의 최대: max(N-1행의 M-1, N-1행의 M) + 자신의 숫자
    for(int row = 1; row < triangle.size(); row++)
    {
        for(int idx = 0; idx < triangle[row].size(); idx++)
        {
            if(idx == 0)//맨 왼쪽
            {
                dp[row][idx] = dp[row-1][idx] + triangle[row][idx];
            }
            else if(idx == triangle[row].size() - 1)//맨 오른쪽
            {
                dp[row][idx] = dp[row-1][idx - 1] + triangle[row][idx];
            }
            else
            {
                dp[row][idx] = max(dp[row-1][idx-1], dp[row-1][idx]) 
                                + triangle[row][idx];
            }
        }
    }
    
    //마지막 행에서 가장 큰 값 선택
    int ans = 0;
    for(int i = 0; i < triangle.size(); i++)
    {
        ans = max(ans, dp[triangle.size() - 1][i]);
    }
    
    return ans;
}