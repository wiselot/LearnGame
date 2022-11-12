#include <iostream>
#include <cmath>
#include <time.h>

/* 已弃用
unsigned int log10n(unsigned int n){
	if(n/10 == 0) return 1;
	return (n != 0) ? (1 + log10n(n/10)):0;
}
*/

int main()
{
	int mode;
	std::cout << "选择模式:\t1:目标得分\t2:无尽冲刺";
	std::cin >> mode;
	int goal;
	if(mode==1){
		std::cout << " 输入目标得分:";
		std::cin >> goal;
		/* 目标分数 */
	}
	std::cout << " 输入一个负数即可结束";
	float g = 0;
	std::cout << "F1: 1\tF2: 1" << std::endl;
	int n = 3;
	int in = 1;
	int f_front1 = 1;
	int f_front2 = 1;
	auto begin = clock();
	while(in>0){
		if(mode==1&&g>=goal)
			break;
		std::cout << "F" << n << " = ";
		std::cin >> in;
		if(in == f_front1 + f_front2)
			g += log(in)/log(10);
		f_front2 = f_front1;
		f_front1 = in;
		n++;
	}
	auto end = clock();
	std::cout << " 结束! 得分为" << g << "用时 " << (end-begin)/CLOCKS_PER_SEC << "s" << std::endl;
	return 0;
}
