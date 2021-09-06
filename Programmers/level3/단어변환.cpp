#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//한글자만 다른지 체크
bool CheckWord(string str1, string str2)
{
    bool b = false;
    
    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] != str2[i])
        {
            if(b == true) // 두글자 이상이 다르다면 false
                return false;
            if(b == false)
                b = true;
        }
    }
    return b;
}

int solution(string begin, string target, vector<string> words) {
    
    //target이 없으면 return
    auto Iter = find(words.begin(), words.end(), target);
    if(Iter == words.end())
        return 0;

    vector<bool> visited(words.size(), false);
    
    
    queue<pair<string, int>> que;
    int ans = 0;
    que.push(make_pair(begin, ans));
    
    while(!que.empty())
    {
        string str = que.front().first;
        ans = que.front().second;
        if(str == target)
            return ans;
        
        que.pop();

        for(int i = 0; i < words.size(); i++)
        {
            if(!visited[i] && CheckWord(str, words[i])) // 방문한 적이 없고 한글자만 다르다면 queue에 넣는다.
            {
                visited[i] = true;
                que.push(make_pair(words[i], ans + 1));
            }
        }
        
        if(que.empty()) //target까지 변환할 방법이 없다면 return
            return 1;
    }
    
    return ans;
}