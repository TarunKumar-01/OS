#include<stdio.h>
int main()
{
int i,p,pr[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
int bt[10],temp,j,art[10],wat[10],tat[10],ta=0,sum=0;
float wag=0,tag=0,tsm=0,wsm=0;
printf(" Question 4 \n");
printf("\nEnter the No. of processes :");
scanf("%d",&p);

for(i=0;i<p;i++)
{
printf("\tEnter  burst time for %d process :",i+1);
scanf(" %d",&bt[i]);
printf("\tEnter arrival time for %d process :",i+1);
scanf(" %d",&art[i]);
}



for(i=0;i<p;i++)
{
for(j=0;j<p;j++)
{
if(art[i]<art[j])
{
temp=pr[j];
pr[j]=pr[i];
pr[i]=temp;
temp=art[j];
art[j]=art[i];
art[i]=temp;
temp=bt[j];
bt[j]=bt[i];
bt[i]=temp;
}
}
}

for(j=0;j<p;j++)
{
btime=btime+bt[j];
min=bt[k];
for(i=k;i<p;i++)
{
if (btime>=art[i] && bt[i]<min)
{
temp=pr[k];
pr[k]=pr[i];
pr[i]=temp;
temp=art[k];
art[k]=art[i];
art[i]=temp;
temp=bt[k];
bt[k]=bt[i];
bt[i]=temp;
}
}
k++;
}
wat[0]=0;
for(i=1;i<p;i++)
{
sum=sum+bt[i-1];
wat[i]=sum-art[i];
wsm=wsm+wat[i];
}

wag=(wsm/p);
for(i=0;i<p;i++)
{
ta=ta+bt[i];
tat[i]=ta-art[i];
tsm=tsm+tat[i];
}

tag=(tsm/p);

printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
printf("\n RESULT:-");
printf("\nProcess \t BurstTime\t ArrivalTime\t WaitingTime\t Turn-aroundTime" );
for(i=0;i<p;i++)
{
printf("\n p%d\t\t %d\t\t %d\t\t %d\t\t\t%d",pr[i],bt[i],art[i],wat[i],tat[i]);
}
printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
printf("\n\nAVERAGE(WAITING TIME) : %f",wag);
printf("\nAVERAGE(TURN AROUND TIME): %f",tag);
return 0;
}

