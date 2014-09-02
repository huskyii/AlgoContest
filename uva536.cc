#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

stack<char> post;

void solve(char *pre, char *in, int in_len){
    if(in_len == 0)
        return ;
    int i;
    char root = pre[0];
    post.push(root);
    for(i = 0; i < in_len; i++){
        if(in[i] == root){
            solve(pre+1+i, in+i+1, in_len - i - 1);
            break;
        }
    }
    solve(pre+1, in, i);
}

int main(void){
    char pre[30], in[30];
    while(scanf("%s %s", pre, in) == 2){
        solve(pre, in, strlen(in));
        while(!post.empty()){
            printf("%c", post.top());
            post.pop();
        }
        printf("\n");
    }
    return 0;
}
