#include<stdio.h>
#include<stdbool.h>

bool isBeautifulNumber(int n){
    int count[10]={0};
    while(n>0){
        int r=n%10;
        count[r]++;
        n/=10;
    }
    for(int i=0;i<10;i++){
        if(count[i]!=0 && count[i]!=i) return false;
    }
    return true;
}

int nextBeautifulNumber(int n) {
    int i;
    for(i=n+1;i<=1224444;i++)
        if(isBeautifulNumber(i)) break;
    return i;
}

int main(){
    int n;
    printf("\nEnter the number: ");
    scanf("%d",&n);
    int res=nextBeautifulNumber(n);
    printf("\n%d",res);
    return 0;
}