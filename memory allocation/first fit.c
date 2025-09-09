#include<stdio.h>
void main(){
int bsize[10],psize[10],bno,pno,alloc[10],i,j;
for(i=0;i<10;i++){
alloc[i]=-1;
}
printf("FIRSTFIT\n");
printf("Enter the number of blocks:");
scanf("%d",&bno);
printf("Enter the size of each blocks:");
for(i=0;i<bno;i++)
scanf("%d",&bsize[i]);
printf("Enter the number of process:");
scanf("%d",&pno);
printf("Enter the size of each process:");
for(i=0;i<pno;i++)
scanf("%d",&psize[i]);
for(i=0;i<pno;i++){
for(j=0;j<bno;j++){
if(bsize[j]>=psize[i]){
alloc[i]=j;
bsize[j]-=psize[i];
break;
}
}
}
printf("\nProcess No.\tProcess size\tBlock No\n");
for(i=0;i<pno;i++){
printf("%d\t\t%d\t\t",i+1,psize[i]);
if (alloc[i]!=-1)
printf("%d\n",alloc[i]+1);
else
printf("Not allocated\n");
}
}

