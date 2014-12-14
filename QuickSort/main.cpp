#include <iostream>
#include <ctime>
#include <cstdlib>//QuickSort
#define N 10

using namespace std;

int cmp(const void *pa, const void *pb)
{
    return *(int *)pa - *(int *)pb;
}

void QuickSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int l = left, r = right;
        int key = arr[l];
        while(l < r)
        {
            while(l < r && arr[r] > key)
            {
                r--;
            }
            if(l < r)
            {
                arr[l++] = arr[r];
            }
            while(l < r && arr[l] < key)
            {
                l++;
            }
            if(l < r)
            {
                arr[r--] = arr[l];
            }
        }
        arr[l] = key;
        QuickSort(arr, left, l - 1);
        QuickSort(arr, l + 1, right);
    }
}

int main()
{
    int arr[N];
    int myarr[N];

    srand(time(NULL));

    for(int i = 0; i < N; i++)
    {
        arr[i] = rand() % 100;//C++ function
        myarr[i] = arr[i];
    }

    for(int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    qsort(arr, N, sizeof(int), cmp);

    for(int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    QuickSort(myarr, 0, N - 1);

    for(int i = 0; i < N; i++)
    {
        cout << myarr[i] << " ";
    }
    cout << endl;

    //check whether QuickSort is right
    for(int i = 0; i < 10000; i++)
    {
        for(int j = 0; j < N; j++)
        {
            arr[j] = rand() % 100;//function
            myarr[j] = arr[j];
        }
        qsort(arr, N, sizeof(int), cmp);
        QuickSort(myarr, 0, N - 1);
        for(int j = 0; j < N; j++)
        {
            if(arr[j] != myarr[j])
            {
                cout << "    qsort:";
                for(int k = 0; k < N; k++)
                {
                    cout << arr[k] << " ";
                }
                cout << endl;

                cout << "QuickSort:";
                for(int k = 0; k < N; k++)
                {
                    cout << myarr[k] << " ";
                }
                cout << endl;

                cout << "QuickSort Wrong!" << endl;

                return 0;
            }
        }
    }

    cout << "QuickSort Right!" << endl;

    return 0;
}
