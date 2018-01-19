#pragma once
#include"dataStruct1.h"
#define FINITY 5000
#define M 20
//从文件中读取图的信息，并完成图的邻接矩阵的初始化
void create_graph(GraphMatrix *g, char *s, int c){			//c = 0表示建立无向图，否则表示建立有向图
	int i;
	int j;
	int k;
	int w;
	FILE *graph;
	graph = fopen(s, "r");						//从文件中读取图的信息
	if(graph){
		fscanf(graph, "%d%d",&g->nodenum, &g->edgenum);		//读入图中的顶点值
		for(i = 0;i < g->nodenum; i++){
			fscanf(graph, "%d", &g->beauties[i].num);
			fscanf(graph, "%s", &g->beauties[i].name);
			fscanf(graph, "%s", &g->beauties[i].introduction); 
		}
		for(i = 0; i < g->nodenum; i++){				//初始化邻接矩阵
			for(j = 0; j< g->nodenum; j++){
				if(i == j){
					g->edges[i][j].length = 0;
				}
				else{
					g->edges[i][j].length = FINITY;
				}
			}
		}
		for(k = 0; k < g->edgenum; k++){				//读入网络中的边
			fscanf(graph, "%d%d%d", &i, &j, &w);
			g->edges[i][j].length = w;
			if(c == 0){						//建立无向图邻接矩阵
				g->edges[j][i].length = w;
			}
		}
		fclose(graph);							//关闭文件
	}
	else{
		g->nodenum = 0;
	}
}

//查找图中对应结点，并且输出其相关信息
void search_graph(GraphMatrix* g) {
	int i;
	printf("请输入您所需要查询的结点的编号：\n");
	scanf("%d", &i);
	getchar();
	while (i < 1 || i > g.nodenum) {
		printf("您所输入的信息有误，请重新输入！\n");
		scanf("%d", &i);
		getchar();
	}
	printf("========================================================\n");
	printf("结点编号为：\n\n%d\n\n", g->beauties[i - 1].num);
	printf("========================================================\n");
	printf("结点名称为：\n\n%s\n\n", g->beauties[i - 1].name);
	printf("========================================================\n");
	printf("结点简介如下：\n\n%s\n\n", g->beauties[i - 1].introduction);
}


















