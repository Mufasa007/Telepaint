# TELEPAINT 智力解题游戏的解题探究


![](http://i.imgur.com/CPgfYMF.jpg)

# 记录

	模型一	完成（√）
	2017.07.02	21：35
	建立模型：
	最简单模型，1,1到 1,19都是可行的，其它位置点屏蔽掉
	起始位置为1,10
	情况1；终点为1,19
	情况2；终点为1,1

	思考：
	起始向右、可以碰墙反向

	运行日志：
	1，第一次出现死循环，修改
	2，第二次出现里面的数值重新优化，新增一些多余位置点用于反向判别
	3，优化程序，使用goto语句最简单的模型可以完成了yeah
	4，出现反向bug，进行程序review
	5，反向的情况得以实现	
	
	模型二	完成（√）
	2017.07.03	19:01
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
	第六次：加入更加明确的实时位置坐标；（√）	

# 简述
	这个游戏的玩法是通过小人的移动到达另外一个亟待救援的人员身旁即为获得胜利！

![](http://i.imgur.com/hAPxjnI.jpg)

# 游戏规则
	人物：图中的油漆罐般的小人可以向着一个方向走，撞墙后返回；
		 火柴棒般的小人是静止的等待救援的人员
	移动：图片中的各个有颜色的亮点是可以通过点击进行互通的
	物品：可以推动的箱子、由机关触发的墙壁、可以使用钥匙消除的石阶、可以刺死小人的荆棘
	

![](http://i.imgur.com/7mMrF1O.jpg)

# 实现目标
	1，可以使用图像识别将游戏中的各个目标进行识别分类、定位、数值化处理；
	2，运行程序解决关卡难题，并输出关卡实现的路径；
	3，学有余力的情况下可以使用TensorFlow进行独立自主学习训练解题；
# 其它
	平台：Microsoft Visual Studio 2017
	实现过程：1，先通过人工识别编程实现；2，借鉴人工转换到电脑独立自主完成。

# 关于我
	Mufasa	武汉大学	电子信息学院
	欢迎有兴趣的朋友一起加入这个有趣的小项目:-D
	邮箱：wanyu@mufasa.site
	写于：2017.06.30	22:02
