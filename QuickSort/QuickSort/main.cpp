//
//  main.cpp
//  QuickSort
//
//  Created by Dewen Chao on 15/10/8.
//  Copyright © 2015年 Dewen Chao. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib> // QuickSort

#define N 10

using namespace std;

// 时间复杂度O(NlogN)~O(N^2)
// 快速排序的基本思想是：每次从无序的序列中找出一个数作为中间点（可以把第一个数作为中间点）
// 然后把小于中间点的数放在中间点的左边，把大于中间点的数放在中间点的右边
// 对以上过程重复最好logN次、最差N次得到有序的序列
// 快速排序是通常被认为在同数量级O(NlogN)的排序方法中平均性能最好的
// 但若初始序列按关键码有序或基本有序时，快排序反而蜕化为冒泡排序
// 为改进之，通常以“三者取中法”来选取基准记录
// 即将排序区间的两个端点与中点三个记录关键码居中的调整为支点记录
// 快速排序是一个不稳定的排序方法
void quickSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int l = left, r = right;
        // 此处可以调换第一个数和中间数，即选择不同的key
        // swap(arr[l], arr[(l + r) / 2]);
        int key = arr[l];
        while(l < r)
        {
            while(l < r && arr[r] >= key)
            {
                r--;
            }
            if(l < r)
            {
                arr[l++] = arr[r];
            }
            while(l < r && arr[l] <= key)
            {
                l++;
            }
            if(l < r)
            {
                arr[r--] = arr[l];
            }
        }
        arr[l] = key;
        quickSort(arr, left, l - 1);
        quickSort(arr, l + 1, right);
    }
}

//int cmp(const void *pa, const void *pb)
//{
//    return *(int *)pa - *(int *)pb;
//}

int main()
{
    int myarr[N];
    
    srand((unsigned)time(NULL));
    
    for(int i = 0; i < N; i++)
    {
        myarr[i] = rand() % 100;
        cout << myarr[i] << " ";
    }
    cout << endl;
    
    quickSort(myarr, 0, N - 1);
    
    for(int i = 0; i < N; i++)
    {
        cout << myarr[i] << " ";
    }
    cout << endl;
    
    // check whether QuickSort is right
//    int arr[N];
//    for(int i = 0; i < 10000; i++)
//    {
//        for(int j = 0; j < N; j++)
//        {
//            arr[j] = rand() % 100;
//            myarr[j] = arr[j];
//        }
//        qsort(arr, N, sizeof(int), cmp);
//        quickSort(myarr, 0, N - 1);
//        for(int j = 0; j < N; j++)
//        {
//            if(arr[j] != myarr[j])
//            {
//                cout << "    qsort:";
//                for(int k = 0; k < N; k++)
//                {
//                    cout << arr[k] << " ";
//                }
//                cout << endl;
//                
//                cout << "QuickSort:";
//                for(int k = 0; k < N; k++)
//                {
//                    cout << myarr[k] << " ";
//                }
//                cout << endl;
//                
//                cout << "QuickSort Wrong!" << endl;
//                
//                return 0;
//            }
//        }
//    }
//    cout << "QuickSort Right!" << endl;
    
    return 0;
}
