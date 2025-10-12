#include<stdio.h>
long long int func(long long int n){
if(n < 0)
return -1;
else{
    long long int result = 0;
    while(n >0){
        result =result * 10 + n % 10;
        n /= 10;
    }
    return result;
}
}
int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
long long int num,res;
scanf("%lld",&num);
res=func(num);
if(res==-1)
printf("NULL!");
else
printf("%lld",res);
return 0;
}