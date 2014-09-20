#include <stdio.h>
#include <string.h>

#define MAX_N 1005

int main(void){
    int kase = 1;
    int n,a[MAX_N],b;
    int A,B;
    int count_a[10], count_b[10];
    while(1){
        scanf("%d", &n);
        if(n == 0)
            break;
        memset(count_a, 0, sizeof(count_a));
        printf("Game %d:\n", kase++);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            count_a[a[i]]++;
        }
        for(;;){
            A = 0;
            B = 0;
            memset(count_b, 0, sizeof(count_b));
            for(int i = 0; i < n; i++){
                scanf("%d", &b);
                if(a[i] == b)
                    A++;
                count_b[b]++;
            }
            if(b == 0)
                break;
            for(int i = 1; i < 10; i++)
                if(count_a[i] >= count_b[i])
                    B += count_b[i];
                else
                    B += count_a[i];
            printf("    (%d,%d)\n", A, B-A);
        }
    }
    return 0;
}
