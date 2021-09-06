#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> umap;
    
    for(auto& clothe : clothes)
        ++umap[clothe[1]];
    
    //각 종류에서 하나를 입는다 or 안 입는다
    for(auto& item : umap)
        answer *= item.second + 1;
    //아무것도 입지 않은 경우를 제외
    answer -= 1;
    
    return answer;
}