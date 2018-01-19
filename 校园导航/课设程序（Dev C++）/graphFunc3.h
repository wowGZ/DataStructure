#pragma once
#include"dataStruct1.h"
#include"graphFunc2.h"
#define FINITY 5000
#define M 20


//问路查询，即求任意两点之间的所有路径


int visited[M];
int pre[M];
void dfspath(GraphMatrix *g,int m,int n,int k)
{

	int s;                                          
	if(pre[k]==n&&k<10)
	{
		for(s=0;s<k;s++)
			printf("%s--->",g->beauties[pre[s]].name);
		printf("%s",g->beauties[pre[s]].name);
		putchar(10);
	}
	else
	{
		s=0;
		while(s<g->nodenum)
		{
			if((g->edges[pre[k]][s].length<FINITY)&&(visited[s]==0))
			{
                 visited[s]=1;
				 pre[k+1]=s;
				 dfspath(g,m,n,k+1);
				 visited[s]=0;
			}
            s++;
		}
	}
}
void printAllPath(GraphMatrix *g)
{
    int i,m,n;
	printf("请输入你要查询的两个景点的编号:");
	scanf("%d%d",&m,&n);
	m--;n--;
	pre[0]=m;
	for(i=0;i<g->nodenum;i++)
		visited[i]=0;
	visited[m]=1;
	dfspath(g,m,n,0);
}
