#pragma once
#include"dataStruct1.h"
#define FINITY 5000
#define M 20
//���ļ��ж�ȡͼ����Ϣ�������ͼ���ڽӾ���ĳ�ʼ��
void create_graph(GraphMatrix *g, char *s, int c){			//c = 0��ʾ��������ͼ�������ʾ��������ͼ
	int i;
	int j;
	int k;
	int w;
	FILE *graph;
	graph = fopen(s, "r");						//���ļ��ж�ȡͼ����Ϣ
	if(graph){
		fscanf(graph, "%d%d",&g->nodenum, &g->edgenum);		//����ͼ�еĶ���ֵ
		for(i = 0;i < g->nodenum; i++){
			fscanf(graph, "%d", &g->beauties[i].num);
			fscanf(graph, "%s", &g->beauties[i].name);
			fscanf(graph, "%s", &g->beauties[i].introduction); 
		}
		for(i = 0; i < g->nodenum; i++){				//��ʼ���ڽӾ���
			for(j = 0; j< g->nodenum; j++){
				if(i == j){
					g->edges[i][j].length = 0;
				}
				else{
					g->edges[i][j].length = FINITY;
				}
			}
		}
		for(k = 0; k < g->edgenum; k++){				//���������еı�
			fscanf(graph, "%d%d%d", &i, &j, &w);
			g->edges[i][j].length = w;
			if(c == 0){						//��������ͼ�ڽӾ���
				g->edges[j][i].length = w;
			}
		}
		fclose(graph);							//�ر��ļ�
	}
	else{
		g->nodenum = 0;
	}
}

//����ͼ�ж�Ӧ��㣬��������������Ϣ
void search_graph(GraphMatrix* g) {
	int i;
	printf("������������Ҫ��ѯ�Ľ��ı�ţ�\n");
	scanf("%d", &i);
	getchar();
	while (i < 1 || i > g.nodenum) {
		printf("�����������Ϣ�������������룡\n");
		scanf("%d", &i);
		getchar();
	}
	printf("========================================================\n");
	printf("�����Ϊ��\n\n%d\n\n", g->beauties[i - 1].num);
	printf("========================================================\n");
	printf("�������Ϊ��\n\n%s\n\n", g->beauties[i - 1].name);
	printf("========================================================\n");
	printf("��������£�\n\n%s\n\n", g->beauties[i - 1].introduction);
}


















