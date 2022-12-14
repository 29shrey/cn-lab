#include<stdio.h>
#include<string.h>
#include<time.h>

#include<stdlib.h>

char str[100];
int generateChecksum(int mode,int checksum){
    int n,temp,sum=0;
    if(strlen(str)%2 != 0){
        n = (strlen(str)+1)/2;
    }
    else{
        n = strlen(str)/2;
    }
    for(int i=0;i<n;i++){
        temp = str[i*2];
        temp = (temp*256) + str[(i*2)+1];
        printf("\n%x",temp);
        sum = sum+temp;
    }
     if(mode == 1){
        printf("\n%x",checksum);
        sum += checksum;
    }
    if(sum%65536 != 0){
        n = sum%65536;
        sum = (sum/65536) + n;
    }
    printf("\nThe Sum generated is %x",sum);
    sum = 65535 - sum; 
    printf("\nThe checksum generated is %x",sum); 

    return sum;
}

void main(){

    int sum1 = 0; 
    int sum2 = 0; 

    printf("\n-------------------Senders Side------------------------------\n");
    printf("\nEnter the String data you wanna send:\t");
    scanf("%s",str);
    sum1 = generateChecksum(0,0);
    printf("\n----------------------------------------------------------------------\n");
    int ch;
    printf("\nEnter 1 if you wanna intoduce an error otherwise press 0:\t");
    scanf("%d",&ch);    
    srand(time(NULL));
    printf("\n-------------------------------Receiver's side-------------------------\n");
    if(ch == 1){
        int num = (rand() % (strlen(str)));   
        printf("\nRandom number: %d, so we will change the this indexed character.",num);
        str[num]++; 
        sum2 = generateChecksum(1,sum1); 
        if(sum2 == 0){
            printf("\n No error detected");
        }
        else{
            printf("\n Error detected");
        }
    }
     else{
        sum2 = generateChecksum(1,sum1);
        if(sum2 == 0){
            printf("\n No error detected");
        }
        else{
            printf("\n Error detected");
        }
    }

    printf("\n----------------------------------------------------------------------\n");
}