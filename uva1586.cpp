#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){
    float dict[256];
    dict['C'] = 12.01;
    dict['H'] = 1.008;
    dict['O'] = 16.00;
    dict['N'] = 14.01;
    char seq[85],symbol,tmp[85];
    int T,n,len,j;
    float ans;
    scanf("%d", &T);
    while(T--){
        ans = 0;
        scanf("%s", seq);
        len = strlen(seq);
        for(int i = 0; i <= len; i++){
            if(i==len || isalpha(seq[i])){
                tmp[j] = '\0';
                j = 0;
                if(strlen(tmp))
                    ans += dict[symbol] * atoi(tmp);
                symbol = seq[i];
                if(i+1 >= len || isalpha(seq[i+1]))
                    ans += dict[symbol];
            }else{
                tmp[j++] = seq[i];
            }
        }
        printf("%.3f\n", ans);
    }
    return 0;
}
