#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int main(void){
    int T;
    scanf("%d", &T);
    getchar();
    char str[130];
    while(T--){
        bool flag = true;
        stack<char> s;
        gets(str);
        //printf("%s\n", str);
        for(size_t i = 0; i < strlen(str); i++){
            if(str[i] == '(' || str[i] == '[')
                s.push(str[i]);
            else if(str[i] == ')'){
                if(!s.empty() && s.top() == '(')
                    s.pop();
                else{
                    flag = false;
                    break;
                }
            }else if(str[i] == ']'){
                if(!s.empty() && s.top() == '[')
                    s.pop();
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(flag && s.empty())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
