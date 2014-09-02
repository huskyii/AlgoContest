// #define LOCAL
#include <cstdio>
#include <vector>
using namespace std;

char grid[10][11];

bool is_eligible(int row, int col){
    if(grid[row][col] != '*'){
        if(row - 1 < 0 || col - 1 < 0)
            return true;
        if(grid[row-1][col] == '*' || grid[row][col-1] == '*')
            return true;
    }
    return false;
}

int main(void){
#ifdef LOCAL
    freopen("uva232.in", "r", stdin);
    freopen("uva232.out", "w", stdout);
#endif
    int r,c;
    int row,col;
    int kase = 0;
    vector< pair<int, int> > eligible;
    for(; ;){
        scanf("%d", &r);
        if(r == 0)
            break;
        scanf("%d", &c);
        for(int i = 0; i < r; ++i)
            scanf("%s", grid[i]);
        eligible.clear();
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                if(is_eligible(i, j))
                    eligible.push_back(make_pair(i,j));
        if(kase)
            printf("\n");
        printf("puzzle #%d:\n", ++kase);
        printf("Across\n");
        for(int i = 0; i < eligible.size(); ++i){
            row = eligible[i].first;
            col = eligible[i].second;
            if(col - 1 < 0 || grid[row][col-1] == '*'){
                printf("%3d.", i+1);
                for(; col < c; ++col)
                    if(grid[row][col] != '*')
                        printf("%c", grid[row][col]);
                    else
                        break;
                printf("\n");
            }
        }
        printf("Down\n");
        for(int i = 0; i < eligible.size(); ++i){
            row = eligible[i].first;
            col = eligible[i].second;
            if(row - 1 < 0 || grid[row-1][col] == '*'){
                printf("%3d.", i+1);
                for(; row < r; row++)
                    if(grid[row][col] != '*')
                        printf("%c", grid[row][col]);
                    else
                        break;
                printf("\n");
            }
        }
    }
    return 0;
}
