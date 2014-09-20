#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char mir[256]={0};
char str[123456];
int main(){
    int state;
    int i,j;
    mir['A'] = 'A';
    mir['E'] = '3';
    mir['H'] = 'H';
    mir['I'] = 'I';
    mir['J'] = 'L';
    mir['L'] = 'J';
    mir['M'] = 'M';
    mir['O'] = 'O';
    mir['S'] = '2';
    mir['T'] = 'T';
    mir['U'] = 'U';
    mir['V'] = 'V';
    mir['W'] = 'W';
    mir['X'] = 'X';
    mir['Y'] = 'Y';
    mir['Z'] = '5';
    mir['0'] = '0';
    mir['1'] = '1';
    mir['2'] = 'S';
    mir['3'] = 'E';
    mir['5'] = 'Z';
    mir['8'] = '8';
    while(gets(str)){
        state = 3;
        for(i=0,j=(strlen(str)-1);i<=j;++i,--j){
            if(str[i]!=str[j]) state &= 2;
            if(str[i]!=mir[str[j]]) state &= 1;
        }
        printf("%s",str);
        if(state==0)
            puts(" -- is not a palindrome.");
        else if(state==1)
            puts(" -- is a regular palindrome.");
        else if(state==2)
            puts(" -- is a mirrored string.");
        else if(state==3)
            puts(" -- is a mirrored palindrome.");
         puts("");
    }
    return 0;
}
