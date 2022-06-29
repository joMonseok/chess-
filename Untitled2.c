
#include<stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

void main() {
    int leng=0;
    scanf("%d", &leng);

    int map[500][500]={0,};
    int dap = 0;
    int a=0;
    int i,j,k;
    int chk=0,tr;
    for(i=0;i<leng;i++)
    	for(j=0;j<i+1;j++)
    		scanf("%d",&map[i][j]);
    for (i = 1; i < leng; i++) {
    	map[i][0]+=map[i-1][0];
        for (j = 1; j < i; j++) {
        	map[i][j]=MAX(map[i][j]+map[i-1][j-1],map[i][j]+map[i-1][j]);
        }
    	map[i][j]+=map[i-1][j-1];
    }
    map[i][0]+=map[i-1][0];
    for(k=1;k<leng;k++){
        	map[i][k]=MAX(map[i][k]+map[i-1][k-1],map[i][k]+map[i-1][k]);
        	map[i][0]=MAX(map[i][0],map[i][k]);
	}
    	map[i][k]+=map[i-1][k-1];
        map[i][0]=MAX(map[i][0],map[i][k]);
    if(leng==1)
    	printf("%d",map[0][0]);
    else
    	printf("%d", map[i][0]);
}

