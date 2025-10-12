/*从X星截获一份电码，是一些数字，如下：
13
1113
3113
132113
1113122113
…
YY博士经彻夜研究，发现了规律：
第一行的数字随便是什么，以后每一行都是对上一行“读出来”
比如第2行，是对第1行的描述，意思是：1个1，1个3，所以是：1113
第3行，意思是：3个1,1个3，所以是：3113
请你编写一个程序，可以从初始数字开始，连续进行这样的变换。
输入
第一行输入一个数字组成的串，不超过100位
第二行，一个数字n，表示需要你连续变换多少次，n不超过20
输出一个串，表示最后一次变换完的结果。
输出
输出一个串，表示最后一次变换完的结果。
样例输入
5
7
样例输出
13211321322115*/
#include <stdio.h>//蓝桥杯2015 C/C++
#include <string.h>
int main(){
	char a[600000],b[600000],temp;
	int i,j,k,length,n;
	int counta=1,ant=-1;
	int countb=0,bnt=-1;
	gets(a);
	scanf("%d",&n);
//	length=strlen(a);
	for(i=1;i<=n;i++){
		length=strlen(a);
		for(j=1;j<length;j++){
			if(a[j]==a[j-1]){
				counta++;
				if(j==length-1){
						if(counta<10){
						b[++bnt]=counta+48;
					} else{
						b[++bnt]=counta/10+48;
						b[++bnt]=counta%10+48;
					}
					counta=1;
					b[++bnt]=a[j-1];
				}
			} else{
				if(counta<10){
					b[++bnt]=counta+48;
				} else{
					b[++bnt]=counta/10+48;
					b[++bnt]=counta%10+48;
				}
				counta=1;
				b[++bnt]=a[j-1];
				if(j==length-1){
					b[++bnt]=counta+48;
					b[++bnt]=a[j];
				}
			}
		}
		if(length==1){
			b[++bnt]='1';
			b[++bnt]=a[0];
		}
		for(k=0;k<=bnt;k++){
			a[k]=b[k];
		}
		while(a[k]!='\0'){
			a[k]='\0';
			k++;
		}
		counta=1;
		bnt=-1;
	}
	for(i=0;i<strlen(a);i++){
		printf("%c",a[i]);
	}
	printf("\n");
	return 0;
}
//注意输进去的全是字符
//蓝桥杯2022 C/C++ 迷宫
/*题目描述
爱丽丝刚从一处地下迷宫中探险归来，你能根据她对于自己行动路径的回忆，帮她画出迷宫地图吗？ 
迷宫地图是基于二维网格的。爱丽丝会告诉你一系列她在迷宫中的移动步骤，每个移动步骤可能是上下左右四个方向中的一种，
表示爱丽丝往这个方向走了一格。你需要根据这些移动步骤给出一个迷宫地图，并满足以下条件： 
1、爱丽丝能在迷宫内的某个空地开始，顺利的走完她回忆的所有移动步骤。 
2、迷宫内不存在爱丽丝没有走过的空地。 
3、迷宫是封闭的，即可通过墙分隔迷宫内与迷宫外。任意方向的无穷远处视为迷宫外，
所有不与迷宫外联通的空地都视为是迷宫内。（迷宫地图为四联通，即只有上下左右视为联通） 
4、在满足前面三点的前提下，迷宫的墙的数量要尽可能少。 
输入格式
第一行一个正整数 N，表示爱丽丝回忆的步骤数量。
接下来一行 N 个英文字符，仅包含 UDLR 四种字符，分别表示上（Up）、下（Down）、左（Left）、右（Right）。 
输出格式
请通过字符画的形式输出迷宫地图。迷宫地图可能包含许多行，用字符 ‘*’ 表示墙，用 ‘ ’（空格）表示非墙。
你的输出需要保证以下条件：
1、至少有一行第一个字符为 ‘*’。
2、第一行至少有一个字符为 ‘*’。
3、每一行的最后一个字符为 ‘*’。
4、最后一行至少有一个字符为 ‘*’。
样例输入
17
UUUULLLLDDDDRRRRU
样例输出
 ***** 
*     *
* *** *
* *** *
* *** *
*     *
 ***** 
//机考的题要求打印的是下面那种
样例输出
*******
*     *
* *** *
* *** *
* *** *
*     *
******* 
提示
爱丽丝可以把第六行第六个字符作为起点。
外墙墙墙墙墙外
墙内内内内内墙
墙内墙墙墙内墙
墙内墙墙墙内墙
墙内墙墙墙内墙
墙内内内内内墙
外墙墙墙墙墙外
对于所有数据，0 < N ≤ 100.
*/
//昨天程序的bug在于
//如果她走过的路径是这样的
/*
	*	*
	*	*
	*	*
	*	*
	*	**********
	*	*
***************
****        *
			*
*/
//那么这道题就不止两种状态
//应该设置成三种状态 初始0 有空格1 空格周围墙2
//同时解决输入时的问题
#include <stdio.h>
//void f(int m,int n,int b[500][500],int x,int y);
void f(int m,int n,int *p);
int main(){
	int N,i,j,k;
	scanf("%d",&N);
	char a[300];
	getchar();
	gets(a);
	int b[500][500];
	for(i=0;i<500;i++){
		for(j=0;j<500;j++){
			b[i][j]=0;
		}
	}
	b[200][200]=1;
	f(200,200,&b[0][0]);
//	printf("%d",b[2][199]);
	int hen=200,shu=200;
	for(i=0;i<N;i++){
		if(a[i]=='U'){
			b[hen][--shu]=1;
			f(hen,shu,&b[0][0]);
		}
		if(a[i]=='D'){
			b[hen][++shu]=1;		
			f(hen,shu,&b[0][0]);
		}
		if(a[i]=='L'){
			b[--hen][shu]=1;
		f(hen,shu,&b[0][0]);
		}
		if(a[i]=='R'){
			b[++hen][shu]=1;
		f(hen,shu,&b[0][0]);
		}
	}
	//现在是找出打印范围的上下左右四个面
	int shang=-1,xia=500;
	for(i=0;i<500;i++){
		for(j=0;j<500;j++){
			if(b[i][j]==2){
				shang=i;
				break;
			}
		}
		if(shang==i){
			break;
		}
	}
	for(i=499;i>=0;i--){
		for(j=499;j>=0;j--){
			if(b[i][j]==2){
				xia=i;
				break;
			}
		}
		if(xia==i){
			break;
		}
	}
	int zuo=500;
	for(i=shang;i<=xia;i++){
		for(j=0;j<=499;j++){
			if(b[i][j]==2&&j<zuo){
				zuo=j;
				break;
			}
		}
	}
	int you=-1;
	for(i=shang;i<=xia;i++){
		for(j=499;j>=0;j--){
			if(b[i][j]==2&&j>you){
				you=j;
				break;
			}
		}
	}
	for(i=shang;i<=xia;i++){
		for(j=zuo;j<=you;j++){
			if(b[i][j]==0){
				printf("*");
			} else if(b[i][j]==1){
				printf(" ");
			} else if(b[i][j]==2){
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}
//void f(int m,int n,int b[500][500],int x,int y)
void f(int m,int n,int*p){
	int i,j;
	for(i=m-1;i<=m+1;i++){
		for(j=n-1;j<=n+1;j++){
			if(p[i*500+j]==0){
				p[i*500+j]=2;
			}
		}
	}
}
//回头看一下二维数组的传参分析
//什么鸟迷宫
//这道题最亏的地方在于没有考虑横向极端情况
//从最本质的出发，传递什么东西也是这样。。。