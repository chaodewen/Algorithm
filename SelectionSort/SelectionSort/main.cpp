//
//  main.cpp
//  SelectionSort
//
//  Created by Dewen Chao on 15/10/19.
//  Copyright © 2015年 Dewen Chao. All rights reserved.
//

#include <iostream>

#define N 10

using namespace std;

// 简单选择排序
// 从前向后选择位置，对于每个位置找出从当前位置起到最后一个位置的最小数交换至当前位置
// 时间复杂度O(N^2)，但是交换次数很少，最差N-1次
// 由于交换所需CPU时间比比较更多，所以N值较小时，选择排序比冒泡排序快
void selectionSort(int arr[], int len) {
    for(int i = 0; i < N - 1; i ++) {
        int minIndex = i;
        for(int j = i + 1; j < N; j ++) {
            if(arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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
    
    selectionSort(arr, N);
    
    for(int i = 0; i < N; i ++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // 正确性验证
//    for(int i = 0; i < 10000; i ++) {
//        for(int j = 0; j < N; j ++) {
//            arr[j] = rand() % 100;
//        }
//        selectionSort(arr, N);
//        for(int j = 0; j < N - 1; j ++) {
//            if(arr[j] > arr[j + 1]) {
//                cout << "Error!" << endl;
//                break;
//            }
//        }
//    }
    
    return 0;
}
