#include<stdio.h>
int power(int a,int b,int mod){
    int t;
    if(b==1)
        return a;
    t=power(a,b/2,mod);
    if(b%2==0)
        return (t*t)%mod;
    else
        return (((t*t)%mod)*a)%mod;
 }
 int calculateKey(int a,int x,int p){
    return power(a,x,p);
 }
 int main()
 {
  int p,g,x1,a,x2,b;  
  printf("Enter the value of p and g : "); 
  scanf("%d%d",&p,&g);    
  printf("Enter the value of x1 for the first person : ");
  scanf("%d",&x1);  
  a=power(g,x1,p);    
  printf("Enter the value of X2 for the second person : ");
  scanf("%d",&x2);  
  b=power(g,x2,p);
  printf("key for the first person is : %d\n",power(b,x1,p));
  printf("key for the second person is : %d\n",power(a,x2,p));
  return 0;
 }
