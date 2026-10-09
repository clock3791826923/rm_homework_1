#include<iostream>
long long climbStairsIter(int n)
{
    long long b[n+1];
    b[0]=1; b[1]=1;
    for (int i=2; i<=n; i++)
    {
        b[i]=b[i-1]+b[i-2];
    }
    return b[n];
}
long long climbStairsRecur(int n)
{
    if (n<=1)
    {
        return 1;
    }
    return climbStairsRecur(n-1)+climbStairsRecur(n-2);
}
int main()
{
    //递归可以处理树状结构，但是占内存
    //迭代适合线性结构，节省内存
    int n;
    std::cout<<"请输入阶梯数"<<std::endl;
    std::cin>>n;
    if (n<=1)
    {
        std::cout<<1<<std::endl;
        return 0;
    }
    // 计算爬到第 n 阶楼梯的⽅法数（⽤迭代实现）
    long long sum1=climbStairsIter(n);
    // 计算爬到第 n 阶楼梯的⽅法数（⽤递归实现）
    long long sum2=climbStairsRecur(n);
    std::cout<<"迭代实现："<<sum1<<std::endl;
    std::cout<<"递归实现："<<sum2<<std::endl;
    return 0;
}