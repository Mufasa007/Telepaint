#include<stdio.h>
//先一步步针对特定的关卡进行编写程序
#define o_i	8
#define o_j 10
#define v_i 1
#define v_j 1
#define c_i_1 1
#define c_j_1 1
#define c_i_2 3
#define c_j_2 9
								//原点，胜利点位置宏定义

int main() {
	int site[9][20] ;			//全局的初始化，随机为大众值但是各个随机值是不同的
	int i, j;					//i,j是中间变量，不要和其他的特异性位点坐标搞混了	

	for (i = 0, j = 0; i <= 9;i++) {
		for (j=0	; j <= 20;j++) {
			site[i][j] = 1;
		}
	}
	for (i = 0, j = 0; i <= 9;i++) {
		site[i][j] = 0;

	}
	for (i = 0, j = 20; i <= 9; i++) {
		site[i][j] = 0;

	}
	for (i = 0, j = 0; j <= 20; j++) {
		site[i][j] = 0;

	}
	for (i = 9, j = 0; j <= 20; j++) {
		site[i][j] = 0;

	}								//以上是初始赋值

	for (i = 2, j = 1; j <= 18; j++) {
		site[i][j] = 0;
	}								//这里是特异性的block区块

	site[v_i][v_j] = 100;			//胜利点定位
	site[c_i_1][c_j_1] = 50;
	site[c_i_2][c_j_2] = 50;

	for (i = 9, j = 0; i >=0; i--) {
		for (j = 0; j <= 20; j++) {
			if (i==o_i&j==o_j) {
				printf(" B ");
			}
			else if (site[i][j]==0) {
				printf(" # ");

			}
			else if(site[i][j]==1){
				printf("   ");
			}
			else if(site[i][j]==100){
				printf(" V ");
			}
			else if (site[i][j]==50) {
				printf(" * ");

			}
		}
		printf("\n\n");
	}								//下个版本转换为switch语句进行编程
		
	
	int r , l ;						//左右两个方向的位移记录
	i = o_i;
	j = o_j;						//[2][3]是起始点,这个定义为变量，最好是有一个源数据，之前有被定义过
	printf("[%d][%d]为起始点%d\n",i,j,site[i][j]);
	printf("[%d][%d]为胜利点%d\n\n", v_i, v_j,site[v_i][v_j]);


	run_right:for (r=0;site[i][j]!=0;j++, r++)	//这里需要重新选定判定，想要将判定直接定义为1，通过if语句跳出程序
	{		
		if (site[i][j] == 100)					//胜利判定
		{
			printf("向右走%d步成功到达！      site[%d][%d]\n", r,i,j);
			goto over;
		}

		if (site[i - 1][j] == site[8][2]) {		//可以采用递归算法实现
			--i;
			if (r == 0) {
				printf("向下掉一层   site[%d][%d]\n",i,j);
			}
			else { 
				printf("向右走%d步   site[%d][%d]\n", r, i+1, j);	//这里的i+1是为了显示向右移动的位置
				printf("向下掉一层   site[%d][%d]\n",i,j);
			}
			goto run_right;
		}

		if (site[i][j+1]==0) {
			printf("向右走%d步后撞墙，返回！   site[%d][%d]\n",r,i,j);
			goto run_left;
		}

	}

	run_left:for (l=0 ; site[i][j] != 0; j--, l++) 
	{
		if (site[i][j] == 100)
		{
			printf("向左走%d步后成功到达！      site[%d][%d]\n", l,i,j);
			goto over;
		}
		if (site[i - 1][j] == site[8][2]) {
			--i;
			printf("向左走%d步，向下掉一层   site[%d][%d]\n",l);
			goto run_left;
		}
		if (site[i][j - 1] == 0) {
			printf("向左走%d步后撞墙，返回！   site[%d][%d]\n", r, i, j);
			goto run_right;
		}

	}

	over:while (1);//用于持续显示结果
	return 0;
}


/*
模型三	完成（√）

建立模型：
引入随机通道

举一反三：水平、高空通道

实现多次判别的方式：递归算法

思考：
1，可以只用定义block的区块即可，因为在之前的程序中引入了判定移动的if语句，初始值全部设为1；
2，

运行日志：
第一次：运行出错，有一部分程序没有显示出来；（×）原因：起始点的数值为0，本质原因是数组无法统一一次赋初值；
第二次：运行出错；（×）原因：初始化后，数组中各个位点的随机数值是不同的，现在只能对数组进行for赋值，嵌套式的循环赋值；
第三次：运行成功；（√）下面进行阶梯型运行测试；
第四次：运行成功；（√）优化block区块的定义同时对图像进行直观输出，下一步加入通道区块；
第五次：运行成功；（√）优化通道定义数值

*/