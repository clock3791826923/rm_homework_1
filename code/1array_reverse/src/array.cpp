#include <iostream>
void reverseArray(int *arr, int n)
{
    int *l=arr;
    int *r=arr+n-1;
    while (l<r)
    {
        int temp=*l;
        *l=*r;
        *r=temp;
        l++;
        r--;
    }
}
int main()
{
    int n;
    std::cout<<"请输入n"<<std::endl;
    std::cin>>n;
    if (n <= 0)
    {
        std::cout<<"数组长度必须大于0"<<std::endl;
        return 0;
    }
    int arr[n];
    std::cout<<"请输入数组元素" <<std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin>>arr[i];
    }
    reverseArray(arr, n); // 调用数组反转函数
    std::cout<<"数组反转后为："<<std::endl;
    int *p =arr;
    for (int i = 0; i < n; i++)
    {
        std::cout<<*p<< " ";
        p++;
    }
    std::cout<<std::endl;
    return 0;
}