#pragma once
#include"dataStruct1.h"
#include"graphFunc2.h"
#define FINITY 5000
#define M 20


//多个景点最佳访问路线，即求途径这多个景点的最佳路径


typedef int dist[M];
typedef int path[M];
int help (GraphMatrix g, path p, dist d, int i){
	int pre;
	int top = -1;
	i--;
	beauty st[M];
	printf ("\n路程长度为:%7d, 路线为:", d[i]);
	st[++top] = g.beauties[i];
	pre = p[i];
	while (pre != -1) {
		st[++top] = g.beauties[pre];
		pre = p[pre];
	}
	printf ("%s", st[top--].name);
	while (top >= 0) {
		printf(" ---> %s ", st[top--].name);
	}
	return d[i];
}
void travelBestPath(GraphMatrix g, path p, dist d){
	int num[M];
	int i;
	int j;
	int count = 0;
	int m = 0;
label:printf("请按照您所需要游览的次序，输入景点编号：\n");
	printf("注：输入“-1”即可停止选择。\n");
	for(i = 0; i < M; i++){
		menu();
		printf("请输入您所要游览的第 %d 个景点：", i + 1);
		scanf("%d", &num[i]);
		system("cls");
		if(num[i] == -1){
			break;
		}
		if(num[i] < 1 || num[i] > g.nodenum){
			printf("输入的数据错误！"); 
			i--;
			to_menu();
		}
	}
//	printf("%d", i);
	j = i;
	i = 0;
	menu();
	printf ("按照您输入的景点编号可以得出，您所要游览的景点依次为：\n");
	printf ("%s ", g.beauties[num[i] - 1].name);
	for (i = 1; i < j; i++){
		printf("---> %s ", g.beauties[num[i] - 1].name);
	}
	printf("\n");
	printf("-----------------------------------------------------------------------\n");
	printf("请问您是否想要重新选择您的景点路线？输入“Yes”进行重置；输入“No”则不进行重置。\n");
	char choice[M];
	scanf("%s", choice);
	if (strcmp(choice, "Yes") == 0){
		system("cls");
		menu();
		goto label;
	}
	else{
		system("cls");
		menu();
		int total_distance = 0;
		printf("\n-----------------------------------------------------------------------");
		printf("\n经计算得，您的最佳旅游路线为:");
		for (count = 0; count < j; count++){
			
			dijkstra(g, num[count] , p, d); 
			m = count + 1;
			if (num[m] == -1){
				break;
			}
			printf("\n第 %d 步：", count + 1);
			total_distance += help(g, p, d, num[m] );
		}
		printf("\n-----------------------------------------------------------------------");
		printf("\n您的旅游最佳路线的总路程长度为: %7d\n", total_distance);
	}
} 
