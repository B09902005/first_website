#include <stdio.h>
int n, m;
char maze[30][30];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool out_of_maze(int x, int y){
    return x < 0 || y < 0 || x >= n || y >= m;
}
int main(){
    int d = 1, x, y;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%s", maze[i]);
        for(int j=0; maze[i][j]; j++){
            if(maze[i][j] == 'I'){
                x = i, y = j;
                if(i == 0) d = 0;
                if(j == 0) d = 1;
                if(i == n-1) d = 2;
                if(j == m-1) d = 3; 
            }
        }
    }
    x += dx[d], y += dy[d];
    while(maze[x][y] != 'O'){
        maze[x][y] = '*';
        for(int nd = (d + 1) % 4;; nd = (nd + 3) % 4){
            if(maze[x+dx[nd]][y+dy[nd]] != 'X'){
                x += dx[nd];
                y += dy[nd];
                d = nd;
                break;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        printf("%s\n", maze[i]);
    }
    return 0;
}