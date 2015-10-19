//
//  main.cpp
//  BinarySearch
//
//  Created by Dewen Chao on 15/10/10.
//  Copyright © 2015年 Dewen Chao. All rights reserved.
//

#include <iostream>
#include <ctime>

#define N 10

using namespace std;

// 当要查找的数有多个时只能返回一个结果
// 时间复杂度最差情况O(logN)、最好情况O(1)
int binarySearch(int x, int arr[], int len) {
    int low = 0;
    int high = len - 1;
    
    while(low <= high) {
        int mid = (high + low) / 2;
        if(arr[mid] == x) {
            return mid;
        }
        else if(arr[mid] > x) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

bool cmp(int a, int b) {
    return a <= b;
}

int main(int argc, const char * argv[]) {
    int arr[N];
    srand((unsigned)time(NULL));
    for(int i = 0; i < N; i ++) {
        arr[i] = rand() % 100;
    }
    sort(arr, arr + N, cmp);
    for(int i = 0; i < N; i ++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int x = rand() % 100;
    cout << x;
    cout << " was found in ";
    cout << binarySearch(x, arr, N) << endl;
    
    // 正确性测试
//    for(int i = 0; i < 10000; i ++) {
//        int testX = rand() % 100;
//        int index = -1;
//        for(int j = 0; j < N; j ++) {
//            arr[j] = rand() % 100;
//        }
//        sort(arr, arr + N, cmp);
//        for(int j = 0; j < N; j ++) {
//            if(arr[j] == testX) {
//                index = j;
//                break;
//            }
//        }
//        int bs = binarySearch(testX, arr, N);
//        if(index != bs && bs == -1) {
//            cout << "Error Found!" << endl;
//            for(int j = 0; j < N; j ++) {
//                cout << "----->" << arr[j] << " ";
//            }
//            cout << "----->" << endl;
//            cout << "----->" << "x:" << testX << endl;
//            cout << "----->" << "realIndex:" << index << endl;
//            cout << "----->" << "binarySch:" << bs << endl;
//        }
//    }

    // Debug专用代码
//    int arr[N] = {50, 52, 31, 93, 69, 37, 8, 62, 18, 81};
//    for(int i = 0; i < N; i ++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//    cout << binarySearch(31, arr, N) << endl;
    
    return 0;
}
