#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *msg[] = {"not a palindrome.", 
                     "a regular palindrome.",
                     "a mirrored string.", 
                     "a mirrored palindrome."};

const char *code = "A...3..HIL.JM.O...2TUVWXY51SE.Z..8.";

char s[123456];

char reverse(char ch){
    if(isalpha(ch))
        return code[ch - 'A'];
    return code[ch - '0' + 25];
}

int main(void){
    int front,back;
    int state;
    while(scanf("%s", s) != EOF){
        state = 3;
        back = strlen(s) - 1;
        front = 0;
        while(front < back){
            if(s[front] != s[back]){
                state &= 2;
            }
            if(s[front++] != reverse(s[back--])){
                state &= 1;
            }
        }
        printf("%s  -- is %s\n\n", s, msg[state]);
    }
    return 0;
}
