#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// v[row][col]
int v[10][10];

int main(void){
    int row1, row2;
    char col1, col2;
    while(scanf("%c%d %c%d", &col1, &row1, &col2, &row2) == 4){
        //printf("aa");
        getchar();
        memset(v, 0, sizeof(v));
        queue< pair<int, int> > w;
        w.push(make_pair(row1, col1-'a'+1));
        v[row1][col1 - 'a' + 1] = 1;
        while(!w.empty()){
            pair<int, char> f = w.front();
            int row = f.first;
            int col = f.second;
            if(row == row2 && col == col2 - 'a' + 1)
                break;
            w.pop();
            if(row - 1 > 0){
                if(col - 2 > 0 && !v[row-1][col-2]){
                    v[row-1][col-2] = v[row][col] + 1;
                    w.push(make_pair(row-1, col-2));
                }
                if(col + 2 < 9 && !v[row-1][col+2]){
                    v[row-1][col+2] = v[row][col] + 1;
                    w.push(make_pair(row-1, col+2));
                }
            }
            if(row + 1 < 9){
                if(col - 2 > 0 && !v[row+1][col-2]){
                    v[row+1][col-2] = v[row][col] + 1;
                    w.push(make_pair(row+1, col-2));
                }
                if(col + 2 < 9 && !v[row+1][col+2]){
                    v[row+1][col+2] = v[row][col] + 1;
                    w.push(make_pair(row+1, col+2));
                }
            }
            if(row - 2 > 0){
                if(col - 1 > 0 && !v[row-2][col-1]){
                    v[row-2][col-1] = v[row][col] + 1;
                    w.push(make_pair(row-2, col-1));
                }
                if(col + 1 < 9 && !v[row-2][col+1]){
                    v[row-2][col+1] = v[row][col] + 1;
                    w.push(make_pair(row-2, col+1));
                }
            }
            if(row + 2 < 9){
                if(col - 1 > 0 && !v[row+2][col-1]){
                    v[row+2][col-1] = v[row][col] + 1;
                    w.push(make_pair(row+2, col-1));
                }
                if(col + 1 < 9 && !v[row+2][col+1]){
                    v[row+2][col+1] = v[row][col] + 1;
                    w.push(make_pair(row+2, col+1));
                }
            }
        }
        printf("To get from %c%d to %c%d takes %d knight moves.\n",
                col1, row1, col2, row2, v[row2][col2 - 'a' + 1] - 1);
    }
    return 0;
}
