#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 200
//���徰��ṹ��
typedef struct {
	int num;								//���
	char name[Max];							//����
	char introduction[Max];					//���
} beauty;
//����߽��ṹ��
typedef struct {
	int length;								//·�̳���
} edgeNode;
//����ͼ���ڽӾ���ṹ��
typedef struct {
	int nodenum;								//������
	int edgenum;								//���� 
	beauty beauties[Max];					//�洢ÿ��������Ϣ
	edgeNode edges[Max][Max];				//�洢���֮���·������
} GraphMatrix;
