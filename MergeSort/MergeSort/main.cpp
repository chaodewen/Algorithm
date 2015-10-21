//
//  main.cpp
//  MergeSort
//
//  Created by Dewen Chao on 15/10/20.
//  Copyright © 2015年 Dewen Chao. All rights reserved.
//

#include <iostream>

#define N 10

using namespace std;

// from[]数组start~mid组和mid+1~end组的归并过程，结果存放在to[]中
void merge(int from[], int to[], int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;
    while(i <= mid && j <= end) {
        if(from[i] <= from[j]) {
            to[k++] = from[i++];
        }
        else {
            to[k++] = from[j++];
        }
    }
    while(i <= mid) {
        to[k++] = from[i++];
    }
    while(j <= end) {
        to[k++] = from[j++];
    }
}

// 2-路归并排序，将序列划分为每个数一组，两两合并为顺序，合并后组数减少组内数字个数增加
// 递归调用得到结果存放在to[]中
// 归并排序算法比较占用内存，但却是效率高且稳定的排序算法
// 最好、最坏和平均时间复杂度都是O(NlogN)
void mergeSort(int from[], int to[], int start, int end) {
    int temp[N];
    if(start == end) {
        to[start] = from[start];
    }
    else {
        int mid = (start + end) / 2;
        mergeSort(from, temp, start, mid);
        mergeSort(from, temp, mid + 1, end);
        merge(temp, to, start, mid, end);
    }
}

int main(int argc, const char * argv[]) {
    int arr[N];
    int result[N];
    
    srand((unsigned int) time(NULL));

    for(int i = 0; i < N; i ++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
    
    mergeSort(arr, result, 0, N - 1);
    
    for(int i = 0; i < N; i ++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    // 正确性检查
//    for(int cnt = 0; cnt < 10000; cnt ++) {
//        for(int i = 0; i < N; i ++) {
//            arr[i] = rand() % 100;
//        }
//        mergeSort(arr, result, 0, N - 1);
//        for(int i = 0; i < N - 1; i ++) {
//            if(result[i] > result[i + 1]) {
//                cout << "Error!" << endl;
//            }
//        }
//    }
    
    return 0;
}
