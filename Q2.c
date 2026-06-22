#include<stdio.h>

int main()
{

int dice,sum;
int dp[50][500]={0};


printf("Enter number of dice: ");
scanf("%d",&dice);


printf("Enter target sum: ");
scanf("%d",&sum);



for(int i=1;i<=6;i++)
dp[1][i]=1;



for(int d=2;d<=dice;d++)
{

for(int s=1;s<=sum;s++)
{

for(int face=1;face<=6;face++)
{

if(s-face>=0)

dp[d][s]+=dp[d-1][s-face];

}

}

}


printf("Number of ways = %d",dp[dice][sum]);


return 0;

}
Input
Enter number of dice: 2

Enter target sum: 7
Output
Number of ways = 6
