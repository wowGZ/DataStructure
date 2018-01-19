#pragma once
#include"dataStruct1.h"
#include"graphFunc2.h"
#define FINITY 5000
#define M 20


//���������ѷ���·�ߣ�����;��������������·��


typedef int dist[M];
typedef int path[M];
int help (GraphMatrix g, path p, dist d, int i){
	int pre;
	int top = -1;
	i--;
	beauty st[M];
	printf ("\n·�̳���Ϊ:%7d, ·��Ϊ:", d[i]);
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
label:printf("�밴��������Ҫ�����Ĵ������뾰���ţ�\n");
	printf("ע�����롰-1������ֹͣѡ��\n");
	for(i = 0; i < M; i++){
		menu();
		printf("����������Ҫ�����ĵ� %d �����㣺", i + 1);
		scanf("%d", &num[i]);
		system("cls");
		if(num[i] == -1){
			break;
		}
		if(num[i] < 1 || num[i] > g.nodenum){
			printf("��������ݴ���"); 
			i--;
			to_menu();
		}
	}
//	printf("%d", i);
	j = i;
	i = 0;
	menu();
	printf ("����������ľ����ſ��Եó�������Ҫ�����ľ�������Ϊ��\n");
	printf ("%s ", g.beauties[num[i] - 1].name);
	for (i = 1; i < j; i++){
		printf("---> %s ", g.beauties[num[i] - 1].name);
	}
	printf("\n");
	printf("-----------------------------------------------------------------------\n");
	printf("�������Ƿ���Ҫ����ѡ�����ľ���·�ߣ����롰Yes���������ã����롰No���򲻽������á�\n");
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
		printf("\n������ã������������·��Ϊ:");
		for (count = 0; count < j; count++){
			
			dijkstra(g, num[count] , p, d); 
			m = count + 1;
			if (num[m] == -1){
				break;
			}
			printf("\n�� %d ����", count + 1);
			total_distance += help(g, p, d, num[m] );
		}
		printf("\n-----------------------------------------------------------------------");
		printf("\n�����������·�ߵ���·�̳���Ϊ: %7d\n", total_distance);
	}
} 
