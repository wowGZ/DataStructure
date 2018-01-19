#pragma once
#include"dataStruct1.h"
#define FINITY 5000
#define M 20


/**
	������������֮������·��(dijkstra)
*/

typedef enum{FALSE,TRUE} boolean;
typedef int dist[M];
typedef int path[M];

void dijkstra(GraphMatrix g, int v0, path p, dist d) {
	boolean final[M];
	v0--;
	int i, j, k, v, min, x;
	//��һ����ʼ������S���������d
	for (v = 0; v < g.nodenum; v++) {
		final[v] = FALSE;
		d[v] = g.edges[v0][v].length;
		if (d[v] < FINITY && d[v] != 0) {
			p[v] = v0;
		}
		else {
			p[v] = -1;
		}
	}
	final[v0] = TRUE;
	d[v0] = 0;
	//�ڶ��������ҳ�n-1��������S��
	for (i = 0; i < g.nodenum; i++) {
		min = FINITY;
		for (k = 0; k < g.nodenum; ++k) {
			if (!final[k] && d[k] < min) {
				v = k;
				min = d[k];
			}
		}
		if (min == FINITY) {
			return;
		}
//		printf("\n%d---%d\n", g.beauties[v].num, min);
		
		final[v] = TRUE;
		//�������޸�S��V-S�и����ľ���
		for (k = 0; k < g.nodenum; k++) {
			if (!final[k] && (min + g.edges[v][k].length < d[k])) {
				d[k] = min + g.edges[v][k].length;
				p[k] = v;
			}
		}
	}
}
void print_g(GraphMatrix g, path p, dist d) {
	int i, pre, top = -1;
	beauty st[M];
	for (i = 0; i < g.nodenum; i++) {
		printf("\nDistance:%7d, path:", d[i]);
		st[++top] = g.beauties[i];
		pre = p[i];
		while (pre != -1) {
			st[++top] = g.beauties[pre];
			pre = p[pre];
		}
		printf("%s", st[top--].name);
		while (top >= 0) {
			printf(" ---> %s ", st[top--].name);
		}
	}
}
void shortPath(GraphMatrix g, path p, dist d){
	int v0;
	int i;
	printf("�����������:\n");
	scanf("%d", &v0);
	printf("�������յ���:\n");
	scanf("%d", &i);
	dijkstra(g, v0, p, d);
	help(g, p, d, i);
}

