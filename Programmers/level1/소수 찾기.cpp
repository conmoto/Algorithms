#include <iostream>
using namespace std;

bool prime[1000001];

void FindPrime(const int& n)
{
    for(int i = 2; i <= n; i++)
    {
        prime[i] = true;
    }
    
    // m=ab라면 a와 b중 적어도 하나는 sqrt(n) 이하이므로 i*i <= n 까지만 검사
    for(int i = 2; i*i <= n; i++)
    {
        //자신의 배수는 소수가 아니다.
        for(int j = i + i; j <= n; j += i)
        {
            prime[j] = false;
        }
    }
}

int solution(int n) {
    
    FindPrime(n);
    
    int ans = 0;
    for(int i = 2; i <= n; i++)
    {
        if(prime[i])
            ++ans;
    }
    
    return ans;
}