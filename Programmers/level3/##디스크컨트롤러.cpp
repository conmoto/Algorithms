#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

//요청되는 시점을 내림차순으로 정렬
struct comp1
{
    bool operator()(const vector<int>& v1, const vector<int>& v2)
    {
        if(v1[0] == v2[0])// 요청 시간이 같을 경우엔 소요 시간을 내림차순으로 정렬
            return v1[1] > v2[1];
        return v1[0] > v2[0];
    }    
};
//소요 시간을 내림차순으로 정렬
struct comp2
{
    bool operator()(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] > v2[1];
    }    
};

priority_queue<vector<int>, vector<vector<int>>, comp1> pque1;
priority_queue<vector<int>, vector<vector<int>>, comp2> pque2;

int solution(vector<vector<int>> jobs) {   
    
    int job_time = 0;
    int end_time = 0;
    
    //모든 job을 pque1에 넣는다.
    for(auto& job : jobs)
    {
        pque1.push(job);
    }
    
    // 두개의 큐가 모두 비워질때까지 반복한다.
    while(!pque1.empty() || !pque2.empty()) 
    {
        //현재까지 요청받은 job들을 pque1에서 꺼내 pque2에 넣는다.    
        while(!pque1.empty() && pque1.top()[0] <= end_time)
        {
            pque2.push(pque1.top());
            pque1.pop();
        }
        //pque2에서 소요시간이 가장 짧은 job을 꺼내 실행한다.
        if(!pque2.empty())
        {
            //다음 요청까지 공백 시간이 있을 경우를 주의한다.
            end_time = max(end_time + pque2.top()[1], pque2.top()[0] + pque2.top()[1]);
            job_time += end_time - pque2.top()[0];
            pque2.pop();
        }
        else if(!pque1.empty()) //pque2가 비어있는데 pque1이 비어있지 않다면 job을 하나 꺼내 pque2에 넣는다.
        {
            pque2.push(pque1.top());
            pque1.pop();
        }
    }
    
    return job_time / jobs.size();
}