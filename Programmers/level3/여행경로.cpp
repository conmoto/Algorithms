#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<string>> answer;

void dfs(string now, int remain_ticket, vector<bool>& ticket_used, vector<vector<string>>& tickets, vector<string>& rout)
{
    if(remain_ticket == 0)
    {
        rout.push_back(now);
        answer.push_back(rout);
        for(auto& a : rout)
            cout << a << " ";
        rout.pop_back();
        return;
    }
    
    for(int i = 0; i < tickets.size(); i++)
    {
        if(tickets[i][0] == now && !ticket_used[i]) //현재 도시에서 출발하는 티켓이 있고 아직 사용하지 않았다면
        {
            rout.push_back(tickets[i][0]);
            ticket_used[i] = true;
            now = tickets[i][1];
            remain_ticket--;
            
            dfs(now, remain_ticket, ticket_used, tickets, rout);
                        
            rout.pop_back();
            ticket_used[i] = false;                
            remain_ticket++;
        }
            
    }
}


vector<string> solution(vector<vector<string>> tickets) {
    
    string now;
    vector<bool> ticket_used(tickets.size(), false);
    int remain_ticket = tickets.size();
    vector<string> rout;
    
    for(int i = 0; i < tickets.size(); i++)
    {
        //모든 티켓의 출발 도시로 부터 출발을 해본다.
        rout.push_back(tickets[i][0]);
        ticket_used[i] = true;
        now = tickets[i][1];
        remain_ticket--;
                
        dfs(now, remain_ticket, ticket_used, tickets, rout);
        
        rout.pop_back();
        ticket_used[i] = false;
        remain_ticket++;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer[0];
}