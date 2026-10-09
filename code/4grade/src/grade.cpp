#include<iostream>
#define MAX_STUDENTS 100
// 1. 初始化成绩数组（n为学⽣⼈数，scores为学⽣分数）
void initScores(int* scores, int n)
{
    for (int i=0; i<n; i++)
    {
        scores[i]=-1;
    }
}
// 2. 录⼊成绩
void inputScores(int* scores, int n)
{
    std::cout<<"请输⼊ " << n << " 个学⽣的成绩："<<std::endl;
    for (int i=0; i<n; i++)
    {
        int score;
        std::cin >> score;
        while (score < 0 || score > 100) 
        {
            std::cout << "成绩必须在0到100之间，重输"<< std::endl;
            std::cin >> score;
        }
        scores[i] = score;
    }
}
// 3. 计算平均分
double calcAverage(const int* scores, int n)
{
    double sum = 0.0;
    for (int i=0; i<n; i++)
    {
        if (scores[i]!=-1)
        {
            sum += scores[i];
        }
    }
    return sum/n;
}
// 4. 安全查询
// ⽬的：确保任何查询都不会导致程序崩溃
// 返回值：如果下标越界，打印“下标越界”并返回 -1；如果下标合法但成绩未录⼊，也返回 -1。
int safeGet(const int* scores, int n, int index)
{
    if (index < 0 || index >= n) 
    {
        std::cout << "下标越界" << std::endl;
        return -1;
    }
    if (scores[index] == -1)
    {
        return -1;
    }
    return scores[index];
}
// 5. 统计分数段（counts为各个分数段的个数）
void countGrades(const int* scores, int n, int* counts)
{
    for (int i = 0; i<n; i++)
    {
        if (scores[i]!=-1)
        {
            if (scores[i]>=90)
            {
                counts[4]++;
            }
            else if (scores[i]>=80)
            {
                counts[3]++;
            }
            else if (scores[i]>=70)
            {
                counts[2]++;
            }
            else if (scores[i]>=60)
            {
                counts[1]++;
            }
            else
            {
                counts[0]++;
            }
        }
    }
}
// 6. 找最⾼分与最低分
void findMinMax(const int* scores, int n, int* max, int* min)
{
    *max = -1;
    *min = 101;
    for (int i=0; i<n; i++)
    {
        if (scores[i]!=-1)
        {
            if (scores[i]>*max)
            {
                *max = scores[i];
            }
            if (scores[i]<*min)
            {
                *min = scores[i];
            }
        }
    }
}
//7.打印所有结果
void printResults(const int* scores, int n, double avg, const int* counts, int max, int min)
{
    std::cout << "平均分：" << avg << std::endl;
    std::cout << "最高分：" << max << std::endl;
    std::cout << "最低分：" << min << std::endl;
    std::cout << "各分数段人数统计：" << std::endl;
    std::cout << "不及格人数：" << counts[0] << std::endl;
    std::cout << "60-69分人数：" << counts[1] << std::endl;
    std::cout << "70-79分人数：" << counts[2] << std::endl;
    std::cout << "80-89分人数：" << counts[3] << std::endl;
    std::cout << "90-100分人数：" << counts[4] << std::endl;
}
int main() 
{
    int scores[MAX_STUDENTS];
    int n; 
    int counts[5] = {0};
    int max = -1, min = -1;
    double avg = 0.0;
    int testIndex;
    // 1. 初始化数组
    initScores(scores, MAX_STUDENTS);
    // 2. 读取学⽣⼈数
    std::cout << "请输⼊学⽣⼈数：";
    std::cin >> n;
    // 3. 调⽤各函数（要求 0 <= score <= 100）
    inputScores(scores, n);
    avg = calcAverage(scores, n);
    findMinMax(scores, n, &max, &min);
    countGrades(scores, n, counts);
    // 7. 安全查询测试
    std::cout << "请输⼊要查询的下标：";
    std::cin >> testIndex;
    int queried = safeGet(scores, n, testIndex);
    if (queried == -1) {
    std::cout << "查询失败" << std::endl;
    } 
    else 
    {
        std::cout << "下标 " << testIndex << " 的成绩是：" << queried << std::endl;
    }
    // 8. 打印所有统计结果
    printResults(scores, n, avg, counts, max, min);
    return 0;
}