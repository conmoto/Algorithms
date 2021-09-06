#include <string>
#include <algorithm>
using namespace std;

bool comp(const char& a, const char& b)
{
    return a > b;
}

string solution(string s) {
    sort(s.begin(), s.end(), comp);
    
    return s;
}