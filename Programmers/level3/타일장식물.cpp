long long length[81];
long long round[81];

long long solution(int N) {

    //N번째 사각형 변 길이: N-1번째 사각형 변 길이 + N - 2번째 사각형 변 길이.
    length[0] = 1;
    length[1] = 1;
    for(int i = 2; i < N; i++)
        length[i] = length[i-1] + length[i-2];
    
    //N번째 둘레: N-1번째 둘레 + N번째 사각형 변 * 2
    round[0] = 4;
    for(int i = 1; i < N; i++)
        round[i] = round[i - 1] + length[i] * 2;

    return round[N-1];
}