#include<stdio.h>
//先一步步针对特定的关卡进行编写程序
#define o_i	8
#define o_j 1
#define v_i 1
#define v_j 19

int main() {
	int site[9][20] = { 0 };		//全局的初始化，这样出现多余的位置点的原因是：返回墙定义√
	int i, j, d = 0;//√


	/*
	for (j = 1;j <= 10;j++) {		//第二行1到10列
		site[2][j] = 1;
	}								//对有效地址的幅值
	for (j =10; j <= 19; j++) {		//第一行10到19列,需要重新幅值因为上文跳出时已经是11了
		site[1][j] = 1;
	}								//这是第一种情况下的有效路径
	*/									
	for (i = 8, j = 1; i >= 1; i--, j++) {
		site[i][j] = 1;
	}								//阶梯形状，前阶
	for (i = 8, j = 2; i >= 1; i--, j++) {
		site[i][j] = 1;
	}								//阶梯形状，后阶梯

	for (	i=1; j <= 19; j++) {	//这里的i=1是问题的关键
		site[i][j] = 1;
	}

	//site[2][10] = 100;			//胜利的原点，现阶段不考虑此位点可变√
	site[v_i][v_j] = 100;			//第二种情况
				

	//数值定义	0，无效地址；1，有效地址；#，人员现在所处的位置；50，可以互通；100，通关地址
	
	int r , l ;						//左右两个方向的位移记录
	i = o_i;
	j = o_j;						//[2][3]是起始点,这个定义为变量，最好是有一个源数据，之前有被定义过
	printf("[%d][%d]为起始点\n",o_i,o_j);
	printf("[%d][%d]为胜利点\n\n", v_i, v_j);


	run_right:for (r=0;site[i][j]!= 0;j++, r++) //不考虑上下位置变化，如何引入site
	{
		printf("[%d][%d]\n", i, j);
		if (site[i][j] == 100)					//胜利判定
		{
			printf("向右走%d步成功到达！\n", r);
			goto over;
		}

		if (site[i - 1][j] == 1) {				//可以采用递归算法实现
			--i;
			printf("向右走%d步后，向下掉一层\n",r,i,j);
			goto run_right;
		}

	}

	run_left:for (l=0 ; site[i][j] != 0; j--, l++) //不考虑上下位置变化，如何引入site
	{
		printf("[%d][%d]  ", i, j);
		if (site[i][j] == 100)
		{
			printf("向左走%d步后成功到达！\n", l);
			goto over;
		}
		if (site[i - 1][j] == 1) {
			--i;
			printf("向左走%d步，向下掉一层",l);
			goto run_left;
		}

	}

	over:while (1);//用于持续显示结果
	return 0;
}


/*
模型二	完成（√）

建立模型：
简单模型，2,1到 2,10；1，10到1，,19都是可行的；其它位置点屏蔽掉
相当于将会出现一个掉下的新动作

举一反三：阶梯形状的路径

实现多次判别的方式：递归算法

思考：
1，需要重新对位置变量进行规划用来满足多出来的新的维度；
2，各个运动进行分立处理；
3，可以使用Goto语句进行功能分模块化，暂分为两大模块左右两个方向，掉下的逻辑包含其中；
4，想办法将位置初始值和终点以及各个可通行位点进行宏定义；

运行日志：
第一次：i,j出现重复定义的低级错误；（×）
第二次：向下掉的动作出现判定故障，经查是移动位点的i值没有及时更新；（×）
第三次：使用宏定义对起始点和终点进行简化处理；（√）
第四次：将阶梯图形引入输出结果错误，经思考发现是阶梯图形的衔接处没有设置全备；（×）
第五次：运行失败，原因程序第28行i=1的幅值为其关键所在；（×）
第六次：加入更加明确的实时位置坐标；（√） 2017.07.03	19:01


*/