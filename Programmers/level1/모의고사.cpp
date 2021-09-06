#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {2,1,2,3,2,4,2,5};
    vector<int> c = {3,3,1,1,2,2,4,4,5,5};

    vector<int> cnt(3, 0);
    for(int i = 0; i < answers.size(); i++)
    {
        //1
        if(a[i%a.size()] == answers[i]) cnt[0]++;
        //2
        if(b[i%b.size()] == answers[i]) cnt[1]++;
        //3
        if(c[i%c.size()] == answers[i]) cnt[2]++;
    }
    
    vector<int> ans;
    int max = *max_element(cnt.begin(),cnt.end());
    for(int i = 0; i< 3; i++) {
        if(cnt[i] == max) ans.push_back(i+1);
    }
    
    return ans;
}