#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int pivot;
bool comp(const string& s1, const string& s2)
{
    return (s1[pivot] == s2[pivot]) ? (s1 < s2) : (s1[pivot] < s2[pivot]);
}

vector<string> solution(vector<string> strings, int n) {
    
    pivot = n;
    
    sort(strings.begin(), strings.end(), comp);
    
    return strings;
}