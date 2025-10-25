#include<stdio.h>
int totalMoney(int n) {
    int total=0,week=28,monday=1;
    while(n>0){
        if(n<=7){
            total+=n*(2*monday+(n-1))/2;
            n=0;
        }
        else{
            total+=week;
            week+=7;
            monday++;
            n-=7;
        }
    }
    return total;
}
int main(){
    int n;
    printf("\nEnter number of days: ");
    scanf("%d",&n);
    printf("%d",totalMoney(n));
    return 0;
}