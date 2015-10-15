//
//  main.cpp
//  ShellSort
//
//  Created by Dewen Chao on 15/10/15.
//  Copyright © 2015年 Dewen Chao. All rights reserved.
//

#include <iostream>

#define N 10

using namespace std;

// 根据当前增量gap进行的直接插入排序
void straightInsertionSortByGap(int arr[], int len, int gap) {
    int i, j;
    for(i = gap; i < len; i += gap) {
        // 出现后面比前面小的情况，要找出应该把后面的放在前面序列的什么位置
        // 这里不是<=所以排序稳定
        if(arr[i] < arr[i-gap]) {
            // 必须使用temp而不是arr[i]，因为下面的赋值操作会修改数组的值
            int temp = arr[i];
            for(j = i - gap; j >= 0 && arr[j] > temp; j -= gap) {
                arr[j+gap] = arr[j];
            }
            arr[j+gap] = temp;
        }
    }
}

// 借助直接插入排序完成的希尔排序（缩小增量排序）
// 基本思想：把记录按步长gap分组，对每组记录采用直接插入排序方法进行排序
// 随着步长逐渐减小，所分成的组包含的记录越来越多
// 当步长的值减小到1时，整个数据合成为一组，构成一组有序记录，则完成排序
// 一般建议步长为N/2，排序过程不稳定
// 希尔排序时间复杂度与步长密切相关，但是目前还没有求最好步长的方法
// 一般认为时间复杂度为O(N^2)
// 比冒泡和插入快，适用于中小规模数据量
// 专家们提倡，几乎任何排序工作在开始时都可以用希尔排序
// 若在实际使用中证明它不够快，再改成快速排序这样更高级的排序算法
void shellSort(int arr[], int len) {
    int gap = len / 2;
    while(gap >= 1) {
        straightInsertionSortByGap(arr, len, gap);
        gap /= 2;
    }
}

int main(int argc, const char * argv[]) {
    int arr[N];
    srand((unsigned)time(NULL));
    for(int i = 0; i < N; i ++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
    
    shellSort(arr, N);
    
    for(int i = 0; i < N; i ++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // 测试straightInsertionSortByGap正确性
//    for(int cnt = 0; cnt < 10000; cnt ++) {
//        int gap;
//        do {
//            gap = rand() % N;
//        }while(gap == 0);
//        
//        for(int i = 0; i < N; i ++) {
//            arr[i] = rand() % 100;
//        }
//        straightInsertionSort(arr, N, gap);
//        int temp = 0;
//        for(int i = 0; i < N; i += gap) {
//            if(i == 0) {
//                temp = arr[i];
//            }
//            else if(temp <= arr[i]){
//                temp = arr[i];
//            }
//            else {
//                cout << "Error!" << endl;
//            }
//        }
//    }
    
    //测试shellSort正确性
//    for(int cnt = 0; cnt < 10000; cnt ++) {
//        for(int i = 0; i < N; i ++) {
//            arr[i] = rand() % 100;
//        }
//        shellSort(arr, N);
//        for(int i = 0; i < N - 1; i ++) {
//            if(arr[i + 1] < arr[i]) {
//                cout << "Error!" << endl;
//                break;
//            }
//        }
//    }
    
    return 0;
}
