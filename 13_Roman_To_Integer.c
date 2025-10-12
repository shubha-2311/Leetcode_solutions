#include<string.h>
#include<stdio.h>

int romanToInt(char* s) {
    int arr[strlen(s)];
    // printf("%d",strlen(s));
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='I')
            arr[i]=1;
        else if(s[i]=='V')
            arr[i]=5;
        else if(s[i]=='X')
            arr[i]=10;
        else if(s[i]=='L')
            arr[i]=50;
        else if(s[i]=='C')
            arr[i]=100;
        else if(s[i]=='D')
            arr[i]=500;
        else if(s[i]=='M')
            arr[i]=1000;
        // printf("%d ",arr[i]);
    }
    int res=arr[strlen(s)-1];
    for(int j=strlen(s)-1;j>0;j--){
        if(arr[j]>arr[j-1])
            res = res - arr[j-1];
        else
            res = res + arr[j-1];
        // printf("%d - %d \n",j,res);
    }
    return res;
}

int main(){
    char s[100];
    scanf("%s",s);
    int i = romanToInt(s);
    printf("%d",i);
    return 0;
}