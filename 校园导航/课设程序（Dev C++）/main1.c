#include<conio.h> 
#include"menu.h" 
#include"graphFunc1.h"
#include"graphFunc2.h"
#include"graphFunc3.h"
#include"graphFunc4.h"
#include"graphFunc5.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int end()
{   
	int k = 1;
	int ch;
	printf("确认退出吗?(0.退出 1.不退出):");
    scanf("%d", &ch);
    while (1)
	{
		if (ch == 0||ch == 1)
			break;
		else
		{
			printf("输入的数据不合理，请重新输入:");
			scanf("%d",&ch);
		}			
	}  
	if (ch == 0)
	{
		k = 0;
		printf("谢谢使用本系统，欢迎下次光临!\n");
	}
	return k;
}

int main(int argc, char *argv[]) {
	GraphMatrix g;
	path p;
	dist d;
	int s;
	int k = 1;
	create_graph(&g, "G13.txt", 0);
	while(k)
	{
		menu();
		scanf("%d", &s);
		switch(s)
		{
			case 1: printMap();
					to_menu();
					system("cls");
					break;
            case 2: search_graph(&g);
					to_menu();
					system("cls");
                    break;
            case 3: printAllPath(&g);
					to_menu();
                    break;
            case 4: travelBestPath(g, p, d);
					to_menu();
					system("cls");
                    break;
            case 5: shortPath(g, p, d);
					to_menu();
					system("cls");
                    break;
		    case 0: k = end();
		}
	}
//	travelPath(g, p, d);
//	printAllPath(&g);
//	search_graph(&g);
//	printf("please input the start point v0:\n");
//	scanf("%d", &v0);
//	printf("please input the end point i:\n");
//	scanf("%d", &i);
//	dijkstra(g, v0, p, d);
//	help(g, p, d, i); 
//	print_g(g, p, d);
	return 0;
}
