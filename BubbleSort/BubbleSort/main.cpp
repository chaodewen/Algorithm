//
//  main.cpp
//  BubbleSort
//
//  Created by Dewen Chao on 15/10/19.
//  Copyright © 2015年 Dewen Chao. All rights reserved.
//

#include <iostream>

#define N 10

using namespace std;

// 冒泡排序相邻进行比较，大的向数组尾部浮，每趟可以确定当前比较区间的最大值
// 使用改进后的方法，即当一次遍历中没有出现交换时可以确定已经成功排序，此时最好时间复杂度为O(N)
// 正常情况下最差时间复杂度O(N^2)
// 冒泡排序是稳定的
void bubbleSort(int arr[], int len) {
    for(int i = 0; i < len - 1; i ++) {
        for(int j = 0; j < len - 1 - i; j ++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int arr[N];
    srand((unsigned int) time(NULL));
    
    for(int i = 0; i < N; i ++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
    
    bubbleSort(arr, N);
    
    for(int i = 0; i < N; i ++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // 正确性验证
//    for(int i = 0; i < 10000; i ++) {
//        for(int j = 0; j < N; j ++) {
//            arr[j] = rand() % 100;
//        }
//        bubbleSort(arr, N);
//        for(int j = 0; j < N - 1; j ++) {
//            if(arr[j] > arr[j + 1]) {
//                cout << "Error!" << endl;
//                break;
//            }
//        }
//    }
    
    return 0;
}
