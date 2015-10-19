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

void bubbleSort(int arr[], int len) {
    
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
    
    return 0;
}
