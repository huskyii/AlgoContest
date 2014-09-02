#include <stdio.h>
#include <string.h>
char state[5][6];

void swap(int x1, int y1, int x2, int y2){
    char tmp = state[x1][y1];
    state[x1][y1] = state[x2][y2];
    state[x2][y2] = tmp;
}

void print(){
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 4; ++j)
            printf("%c ", state[i][j]);
        printf("%c\n", state[i][4]);
    }
}

int main(void){
    char action[100];
    int kase = 0, len, flag, pos[2];
    int dir[256][2];
    memset(dir, 0, sizeof(dir));
    dir['A'][0] = -1;
    dir['A'][1] = 0;
    dir['B'][0] = 1;
    dir['B'][1] = 0;
    dir['L'][0] = 0;
    dir['L'][1] = -1;
    dir['R'][0] = 0;
    dir['R'][1] = 1;
    for(; ; ){
        gets(state[0]);
        if(strcmp(state[0],"Z") == 0)
            return 0;
        for(int i = 1; i < 5; i++){
            gets(state[i]);
        }
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)
                if(state[i][j] == ' '){
                    pos[0] = i;
                    pos[1] = j;
                    break;
                }
        flag = 0;
        for( ; ; ){
            gets(action);
            len = strlen(action);
            for(int i = 0; i < len; ++i){
                if(action[i] == '0')
                    break;
                if(dir[action[i]][0] == dir[action[i]][1]){
                    flag = 1;
                    break;
                }
                if(pos[0]+dir[action[i]][0] >= 0 && pos[0]+dir[action[i]][0] < 5 &&
                   pos[1]+dir[action[i]][1] >= 0 && pos[1]+dir[action[i]][1] < 5){
                    swap(pos[0], pos[1], 
                            pos[0]+dir[action[i]][0], pos[1]+dir[action[i]][1]);
                    pos[0] += dir[action[i]][0];
                    pos[1] += dir[action[i]][1];
                }else{
                    flag = 1;
                    break;
                }
            }
            if(action[len-1] == '0')
                break;
            if(flag)
                break;
        }
        if(kase)
            printf("\n");
        printf("Puzzle #%d:\n", ++kase);
        if(flag)
            printf("This puzzle has no final configuration.\n");
        else{
            print();
        }
    }
    return 0;
}
