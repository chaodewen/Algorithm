//
//  main.cpp
//  StraightInsertionSort
//
//  Created by Dewen Chao on 15/10/10.
//  Copyright © 2015年 Dewen Chao. All rights reserved.
//

#include <iostream>
#include <ctime>

#define N 10

using namespace std;

// 直接插入排序时间复杂度O(N^2)
void straightInsertionSort(int arr[], int len) {
    int i, j;
    for(i = 1; i < len; i ++) {
        // 出现后面比前面小的情况，要找出应该把后面的放在前面序列的什么位置
        // 这里不是<=所以排序稳定
        if(arr[i] < arr[i-1]) {
            // 必须使用temp而不是arr[i]，因为下面的赋值操作会修改数组的值
            int temp = arr[i];
            for(j = i - 1; j >= 0 && arr[j] > temp; j --) {
                arr[j+1] = arr[j];
            }
            arr[j+1] = temp;
        }
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
    
    straightInsertionSort(arr, N);
    
    for(int i = 0; i < N; i ++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
