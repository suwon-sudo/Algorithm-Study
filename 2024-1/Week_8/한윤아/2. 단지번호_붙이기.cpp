#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAP_SIZE 25
#define swap(a,b){int t=a;a=b;b=t;}
int N;
int apt[MAP_SIZE][MAP_SIZE];
int visited[MAP_SIZE][MAP_SIZE] = { 0, };
int cnt[MAP_SIZE*MAP_SIZE] = { 0, };
int dx[4] = { 0,0,-1,1 }; //상하좌우
int dy[4] = { -1,1,0,0 };
void dfs(int x, int y, int gp) {
        visited[x][y] = 1;
        cnt[gp]++;
        for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                        if (visited[nx][ny] == 0 && apt[nx][ny] == 1)
                                dfs(nx, ny, gp);
                }
        }
}
int main()
{
        int group = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) scanf("%1d", &apt[i][j]);
        }
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        if (visited[i][j] == 0 && apt[i][j] == 1) {
                                dfs(i, j, group);
                                group++; //dfs가 끝남 => 단지 하나 완성
                        }
                }
        }
        for (int i = 0; i < group - 1; i++) {
                for (int j = i + 1; j < group; j++) {
                        if (cnt[i] > cnt[j]) swap(cnt[i], cnt[j]);
                }
        }
        printf("%d\n", group);
        for (int i = 0; i < group; i++) printf("%d\n", cnt[i]);
}