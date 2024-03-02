#ifndef __INLINE_TEST_H
#define __INLINE_TEST_H

class temp{
    private:
    int a ;
    public:
    temp(int a){
        this->a = a;
    }
};


class inline_test{
    private:
    int hour,minute,second;
    int &m_ref;// 引用只能用初始化列表进行初始化（因为只有一次赋值（赋一个指向）机会），因为只有创建引用时的第一次赋值是起别名，之后（class实例化之后立即）的引用名访问的就是指向的变量了
    const int m_const;// 常数只能用初始化列表进行初始化（因为只有一次赋值机会）
    temp temp1;// class未提供无参构造函数，必须使用()小括号提供初始化参数
    public:
    //inline_test():hour(0),minute(0),second(0),m_ref(){}
    inline_test(int& val,temp t_temp):m_ref(val),m_const(val),temp1(t_temp)
    {}
    


};

#endif
