/*문제 조건
1~9까지의 서로 다른 숫자 세 자리 => 0과 같은 숫자가 존재하면 안됨
123~987까지 수로 브루트포스
정답의 경우의 수 계산
예상되는 정답 수와 입력 값의 위치와 값이 같으면 S, 위치는 다른데 값이 같으면 B 
number[1000] 배열 1로 초기화 => 조건에 안맞으면 0으로 바꿈 => 마지막까지 1인 경우 확인*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int number[1000]; //123부터 사용
int N, in_s, in_b, cnt_s, cnt_b, ans=0;
string question; //물어본 수
int main()
{
        memset(number, 1, sizeof(number));
        cin >> N;
        //0(48)이 있는 경우, 같은 숫자가 있는 경우 제외
        for (int i = 123; i <= 987; i++) {
                string tmp = to_string(i);
                if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2])
                        number[i] = 0;
                if (tmp[0] == 48 || tmp[1] == 48 || tmp[2] == 48) 
                        number[i] = 0;
        }
        for (int i = 1; i <= N; i++) {
                cin >> question >> in_s >> in_b;
                for (int j = 123; j <= 987; j++) {
                        cnt_s = cnt_b = 0; //예상할 수 있는 세자리 수의 스트라이크, 볼
                        string predict = to_string(j);
                        //물어본 수(와 예상할 수 있는 수 비교
                        for (int x = 0; x < 3; x++) {
                                for (int y = 0; y < 3; y++) {
                                        //위치가 같고 값도 같으면 스트라이크
                                        if (x == y && question[x] == predict[y]) cnt_s++;
                                        //위치는 다른데 값이 같으면 볼
                                        if (x != y && question[x] == predict[y]) cnt_b++;
                                }
                        }
                        //입력한 스트라이크, 볼과 다르면 0으로 바꿈
                        if (in_s != cnt_s || in_b != cnt_b) number[j] = 0;
                }
        }
        for (int i = 123; i <= 987; i++) {
                if (number[i])ans++;
        }
        cout << ans << endl;
}