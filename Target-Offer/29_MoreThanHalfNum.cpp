// Created by D_Major on 2020/1/25.

#include <iostream>
#include <vector>

using namespace std;

/* 返回pivot所在的位置, 并且一侧小于等于pivot, 一侧大于pivot, 不过是无序的. 当有重复时取最后一个位置 */
int partition(vector<int>& input,int low,int high)
{
    int pivotkey=input[low];   //pivot:枢纽, 这里以区间左端点作为划分
    //这里的pivotkey也可以是[low,high]区间一个随机数，也可以是三数取中，九数取中，详情见<<大话数据结构>>
    //int pivotkey=input[RandInRange(start,end)];
    while(low<high)
    {
        while(low<high && pivotkey<input[high]) // 和第一个遇到的大于等于的数交换
            high--;
        swap(input[low],input[high]); // 交换后pivot就移到后边了
        while(low<high && pivotkey>=input[low]) // 此时pivot在下标high处, 和第一个遇到的小于的数交换
            low++;
        swap(input[low],input[high]); // 交换后pivot就回到了low处, 保证了该轮循环3个数的顺序
    }
    return low;
}

/* 检查result的值的个数是否大于整个数组的一半 */
bool CheckMoreThanHalf(const vector<int>& numbers,const int length,const int result)
{
    int times=0;
    for(int i=0;i<length;i++)
    {
        if(numbers[i]==result)
            times++;
    }
    return times * 2 > length;
}

int MoreThanHalfNum_Solution(vector<int> numbers) {
    int length=numbers.size();
    if(numbers.empty()||length<0)
        return 0;
    int middle=length>>1;
    int start=0;
    int end=length-1;
    int index=partition(numbers,start,end);
    while(index!=middle)
    {
        if(index>middle)
        {
            end=index-1;
            index=partition(numbers,start,end);
        }
        else
        {
            start=index+1;
            index=partition(numbers,start,end);
        }
    }
    int result=numbers[middle];           //这里的只是得到了中位数，但其个数是否超过一半还需要判断
    if(!CheckMoreThanHalf(numbers,length,result))    //此时需要检查result的值的个数是否大于整个数组的一半
        return 0;
    return result;
}

/* 针对数组特点, 记录当前数字出现的次数 */
int MoreThanHalfNum_Solution_2(vector<int> numbers) {
    int length=numbers.size();
    if(numbers.empty() || length<=0)
        return 0;
    int result = numbers[0], count = 1;
    for (int i = 1; i < length; i++) {
        if (count == 0) {
            result = numbers[i];
            count = 1;
        }
        else if (numbers[i] == result) count++;
        else count--;
    }
    if(!CheckMoreThanHalf(numbers,length,result))    //此时需要检查result的值的个数是否大于整个数组的一半
        return 0;
    return result;
}