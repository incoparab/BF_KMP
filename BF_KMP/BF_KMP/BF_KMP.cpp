// BF_KMP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
using namespace std;
int BF(string str0 = "aaaaaaaaab",string str="aac")
{
    int sum = 0;
    int len1 = str0.length();
    int len2 = str.length();
    for (int i=0; i < len1; i++)
    {
        for (int j = 0; j < len1-len2; j++)
        {
            sum++;
            if (str0[i + j] == str[j])
            {
                if (j == len2 - 1) return sum;
                else continue;
            }
            else break;
        }
    }
    return sum;
}
void get_next(string str, int* next, int len)
{
    next[0] = -1;           //next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
    int k = -1;            //k初始化为0
    for (int q = 1; q <= len - 1; q++)
    {
        while (k > -1 && str[k + 1] != str[q])           //如果下一个不同，那么k就变成next[k]，注意next[k]是小于k的，无论k取任何值。
        {
            k = next[k];            //往前回溯
        }
        if (str[k + 1] == str[q])       //如果相同，k++
        {
            k = k + 1;
        }
        next[q] = k;        //这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给next[q]
    }
}
int KMP(string str0="aaaaaaaaab", string str="aac")
{
    int sum = 0;
    int len1 = str0.length();
    int len2 = str.length();
    int* next = new int[len2];
    get_next(str, next, len2);    
    int i = 0;
    int j = 0;        //i指向模式串T，j指向主串S
    while (j < len1) 
    {
        sum++;
        if (str[i] == str0[j]) 
        {
            i++;
            j++;
            if (i == len2)
            {
                delete[]next;
                return sum;
            }
        }
        else
        {
            i = next[i];
            if (i == -1) 
            {
                j++;
                i++;
            }
        }
    }
    delete[]next;
    return sum;
}
int main()
{
    cout << "请输入一个字符串：";
    string str0;
    getline(cin, str0);
    cout << "请输入一个子串";
    string str;
    getline(cin, str);
    cout <<"BF算法的比较次数为："<< BF(str0,str) << endl;
    cout << "KMP算法的比较次数为："<< KMP(str0, str) << endl;
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
