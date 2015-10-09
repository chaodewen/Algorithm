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
