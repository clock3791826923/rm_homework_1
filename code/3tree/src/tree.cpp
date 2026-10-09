#include<iostream>
void buildTestTree(int* tree, int n)//这里我按完全二叉树顺序造了一棵5个节点的树，用于测试
{
    for (int i = 0; i < 5; i++)
    {
        tree[i]=i+1;
    }
    for (int i=5; i<n; i++)
    {
        tree[i]=-1;
    }
}
void preorderTraversal(const int* tree, int n, int i)//前序遍历 根左右
{
    if (i>=n || tree[i]==-1)
    {
        return;
    }
    std::cout<<tree[i]<<" ";
    preorderTraversal(tree, n, 2*i+1);
    preorderTraversal(tree, n, 2*i+2);
}
void inorderTraversal(const int* tree, int n, int i)//中序遍历 从最左侧子节点开始 左根右
{
    if (i>=n || tree[i]==-1)
    {
        return;
    }
    inorderTraversal(tree, n, 2*i+1);
    std::cout<<tree[i]<<" ";
    inorderTraversal(tree, n, 2*i+2);
}
void postorderTraversal(const int* tree, int n, int i)//后序遍历 从最左侧子节点开始 左右根
{
    if (i>=n || tree[i]==-1)
    {
        return;
    }
    postorderTraversal(tree, n, 2*i+1);
    postorderTraversal(tree, n, 2*i+2);
    std::cout<<tree[i]<<" ";
}
int main()
{
    int n=7,i;
    int tree[10];
    // 构建⼀棵简单的测试树（填充数组）
    buildTestTree(tree, n);
    // 前序遍历：根 -> 左 -> 右
    i=0;
    std::cout<<"前序遍历："<<std::endl;
    preorderTraversal(tree, n, i);
    std::cout<<std::endl;
    // 中序遍历：左 -> 根 -> 右
    i=0;
    std::cout<<"中序遍历："<<std::endl;
    inorderTraversal(tree, n, i);
    std::cout<<std::endl;
    // 后序遍历：左 -> 右 -> 根
    i=0;
    std::cout<<"后序遍历："<<std::endl;
    postorderTraversal(tree, n, i);
    std::cout<<std::endl;
    return 0;
}