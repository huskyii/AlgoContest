/*
ID: mail.ji1
PROG: ride
LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char group[8];
char comet[8];

int main(void){
  freopen("ride.in", "r", stdin);
  freopen("ride.out", "w", stdout);
  while(scanf("%s", comet) != EOF) {
    scanf("%s", group);
    int comet_product = 1, group_product = 1;
    for(size_t i = 0; i < strlen(comet); ++i) comet_product = (comet_product%47) * (comet[i]-'A'+1);
    for(size_t i = 0; i < strlen(group); ++i) group_product = (group_product%47) * (group[i]-'A'+1);

    if(comet_product%47 == group_product%47) printf("GO\n");
    else printf("STAY\n");
  }
  return 0;
}
