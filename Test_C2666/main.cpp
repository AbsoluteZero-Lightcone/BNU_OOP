/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa
  * @version V1.3.4
  * @date    2024-03-07
  * @brief   C2666 Error test program.
  * @encode  UTF-8
  ******************************************************************************
  */
#include <iostream>

class Date {
private:
	int _a;
public:
	int get()const { return _a; }
	Date operator-(int n)const { return Date(0); }

// 关键是这两个 const ：
	//int operator-(      Date& date)      { return 0; }
	//int operator-(      Date& date)const { return 0; }
	  int operator-(const Date& date)      { return 0; }
	//int operator-(const Date& date)const { return 0; }
// 和这个只有一个参数的构造函数：
	Date(int a = 0) :_a(a) {}
};

void external_test() {
	Date date1,date2;
	std::cout << date2 - date1 << std::endl;     // Date - Date 重载不受影响
	std::cout << (date2 - 1).get() << std::endl; // Date - int  的重载受影响

	// 在尝试复现问题的过程中我发现 构造函数 Date(int a = 0) 对这个问题的产生起到了决定性作用。
	// 找到核心问题之后我对这些语法有了新的理解：
	// 1.只有一个参数的构造函数会被编译器当成隐式类型转换的方法
	// 2.而 Date - int 的重载，会被编译器尝试理解成 不是我们期望的 Date - Date(int) 的形式，并且与 Date - Date 产生多义性
		// 这样我们就能解释了为什么只有 Date - int  的重载受影响，而 Date - Date 重载不受影响
		// 但是到这里仍然不清楚 const 起到了什么作用
		
	// 不过好在现在的问题就简化成了：
		// const 为什么能控制编译器 是否将 int 转换成 Date ？

		// 我个人猜测实现原理有两种可能：
	
			// 一种是 const 控制编译器是否尝试类型转换
			//		即选择“先尝试类型转换，再匹配重载函数”还是“不尝试类型转换，再匹配重载函数”
		
			// 另一种是 const 不能控制编译器是否尝试类型转换，编译器不管有没有const都尝试，
			//		但是const能改变不同类型的重载函数的“匹配优先级”
			// 
			//		就比如，
			//		没有const时	
			//			“匹配重载函数时的 Date - Date(int) 尝试”（不期望） 和
			//			“匹配重载函数时的 Date - int 尝试”（期望）
			//			被编译器看作同等重要，致使出现了多义性
			//		而添加const修饰之后，
			//			编译器认为“匹配重载函数时的 Date - int 尝试”的匹配优先级
			//			高于“匹配重载函数时的 Date - Date(int) 尝试”
			//			于是正常编译

	// 总结一下现在还没有解决的问题：
	// 1.实际的编译器行为是否为我的两种猜测中的一种？
	// 2.如果实际情况更接近第二种猜测的话，	编译器在匹配重载函数时有什么约定的顺序吗？
	//									const/votatile 在影响这个优先级的时候有什么规则吗？（比如这里const就好像是提高了优先级一样）
	//									为什么把两个const都去掉也能够提高优先级（即int operator-(Date& date)为什么也能跑）
	// 3.如果在之后也遇到了其他的编译器报错Cxxxx，您有没有什么比较趁手的调试工具或者比较有效的调试方法来解决问题呢？
	//   也就是说，我如何才能明确地掌握“编译器都干了什么”，使得在以后的工作中能由我来警告编译器而不是编译器来警告我？
}

int main() {
	external_test();
	return 0;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
