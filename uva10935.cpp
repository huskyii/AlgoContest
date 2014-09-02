//#define debug
#include <cstdio>
#include <queue>
using namespace std;

int main(void){
#ifdef debug
    freopen("uva10935.in", "r", stdin);
#endif
    queue<int> deck;
    int T;
    while(true){
        scanf("%d", &T);
        if(T == 0)
            break;
        for(int i = 1; i <=T; i++)
            deck.push(i);
        printf("Discarded cards:");
        while(deck.size() >= 2){
            printf(" %d", deck.front());
            deck.pop();
            if(deck.size() > 1)
                printf(",");
            deck.push(deck.front());
            deck.pop();
        }
        printf("\nRemaining card: %d\n", deck.front());
        deck.pop();
    }
    return 0;
}
