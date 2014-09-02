/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-08-21			*/
/****************************************/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

char img[70][70];
vector<int> arr;

int check(int row, int col, int w){
    //if the rectangle are all 0 then return 0 
    //else if it are all 1 then return 1
    //otherwise return -1;
    int flag = img[row][col] - '0';
    for(int i = 0; i < w; i++){
        for(int j = 0; j < w; j++){
            if(img[row+i][col+j] != flag + '0'){
                return -1;
            }
        }
    }
    return flag;
}

void solve1(int row, int col, int w, int suffix, int deepth){
    if(check(row, col, w) == 1){
        arr.push_back(suffix);
    }else if(check(row, col, w) == -1){
        solve1(row, col, w/2, suffix+1*(pow(5,deepth+1)), deepth+1);
        solve1(row, col+w/2, w/2, suffix+2*(pow(5,deepth+1)), deepth+1);
        solve1(row+w/2, col, w/2, suffix+3*(pow(5,deepth+1)), deepth+1);
        solve1(row+w/2, col+w/2, w/2, suffix+4*(pow(5,deepth+1)), deepth+1);
    }
}

void solve2(int node, int n){
    int dir;
    int row = 0, col = 0, w = n;
    do{
        dir = node % 5;
        w /= 2;
        if(dir == 2){
            col += w;
        }else if(dir == 3){
            row += w;
        }else if(dir == 4){
            row += w;
            col += w;
        }
        node /= 5;
    }while(node);
    for(int i = row; i < row+w; i++){
        for(int j = col; j < col+w; j++){
            img[i][j] = '*';
        }
    }
}

int main(void){
    int kase = 0;
    int n;
    //int state = 0;
    while(scanf("%d", &n) == 1 && n){
        memset(img, 0, sizeof(img));
        arr.clear();
        if(kase){
            printf("\n");
        }
        printf("Image %d\n", ++kase);
        if(n > 0){
            for(int i = 0; i < n; i++){
                scanf("%s", img[i]);
            }
            if(check(0, 0, n) == 1){
                arr.push_back(0);
            }else if(check(0, 0, n) == -1){
                solve1(0, 0, n/2, 1, 0);
                solve1(0, n/2, n/2, 2, 0);
                solve1(n/2, 0, n/2, 3, 0);
                solve1(n/2, n/2, n/2, 4, 0);
            }
            sort(arr.begin(), arr.end());
            if(!arr.empty()){
                for(size_t i = 0; i < arr.size()-1; i++){
                    if(i % 12 == 11){
                        printf("%d\n", arr[i]);
                    }else{
                        printf("%d ", arr[i]);
                    }
                }
                printf("%d\n", arr[arr.size()-1]);
            }
            printf("Total number of black nodes = %d\n", (int)arr.size());
        }else if(n < 0){
            int node;
            n = -n;
            while(scanf("%d ", &node) == 1 && node != -1){
                arr.push_back(node);
            }
            if(arr.empty()){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n-1; j++)
                        printf(".");
                    printf(".\n");
                }
            }else if(arr[0] == 0){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n-1; j++)
                        printf("*");
                    printf("*\n");
                }
            }else{
                for(size_t i = 0; i < arr.size(); i++){
                    solve2(arr[i], n);
                }
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n-1; j++){
                        if(img[i][j] == '*')
                            printf("*");
                        else
                            printf(".");
                    }
                    if(img[i][n-1]){
                        printf("*\n");
                    }else{
                        printf(".\n");
                    }
                }
            }
        }
    }
    return 0;
}
