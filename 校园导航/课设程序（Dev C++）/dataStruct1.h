#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 200
//定义景点结构体
typedef struct {
	int num;								//编号
	char name[Max];							//名称
	char introduction[Max];					//简介
} beauty;
//定义边结点结构体
typedef struct {
	int length;								//路程长度
} edgeNode;
//定义图的邻接矩阵结构体
typedef struct {
	int nodenum;								//结点个数
	int edgenum;								//边数 
	beauty beauties[Max];					//存储每个结点的信息
	edgeNode edges[Max][Max];				//存储结点之间的路径长度
} GraphMatrix;
