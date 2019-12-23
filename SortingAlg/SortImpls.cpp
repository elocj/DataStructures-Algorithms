//
// Created by Anthony Joo on 2019-02-08.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Swaps the given array values
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Implements Bubble Sort Sorting Algorithm
void BubbleSort(vector<int> &array, const int start, const int end)
{
    bool sorted = false;
    int pass = 1;
    while (!sorted && (pass < end + 1)) {
        sorted = true;
        for (int index = start; index < end + 1 - pass; index++) {
            int nextIndex = index + 1;
            if (array[index] > array[nextIndex]) {
                swap(array[index], array[nextIndex]);
                sorted = false;
            }
        }
        pass++;
    }
}


// Implements Insertion Sort Sorting Algorithm
void InsertionSort(vector<int> &array, const int start, const int end)
{
    for (int i = start + 1; i < end + 1; i++)
    {
        int key = array[i];
        int j = i-1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= start && array[j] > key)
        {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
    }
}

// A function to merge the two halves from merge or iterative merge sort into one sorted dataset.
void merge(vector<int> &array, const int low, const int mid, const int high)
{
    // We have low to mid and mid+1 to high already sorted.
    int i, j, k, temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;

    // Merge the two parts into temp[].
    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
        {
            temp[k] = array[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = array[j];
            k++;
            j++;
        }
    }

    // Insert all the remaining values from i to mid into temp[].
    while (i <= mid)
    {
        temp[k] = array[i];
        k++;
        i++;
    }

    // Insert all the remaining values from j to high into temp[].
    while (j <= high)
    {
        temp[k] = array[j];
        k++;
        j++;
    }


    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++)
    {
        array[i] = temp[i-low];
    }
}

// Implements the Merge Sort Sorting Algorithm
void MergeSort(vector<int> &array, const int first, const int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;
        MergeSort(array, first, mid);
        MergeSort(array, mid + 1, last);
        merge(array, first, mid, last);
    }
}

// Implements the Iterative Merge Sort Sorting Algorithm
void IterativeMergeSort(vector<int> &array, const int start, const int stop)
{
    for(int sz = 1; sz < stop + 1 - start; sz += sz)
    {
        for(int lo = start; lo < stop + 1 - sz; lo += sz + sz)
        {
            merge(array, lo, lo + sz - 1, min(lo + sz + sz - 1, stop + 1 - 1));
        }
    }
}

// Implements the Shell Sort Sorting Algorithm
void ShellSort(vector<int> &array, const int start, const int end)
{
    for (int gap = ((end + 1 - start) / 2); gap > 0; gap = gap / 2)
    {
        for (int unsorted = gap; unsorted + start < end + 1; unsorted++)
        {
            int nextItem = array[unsorted + start];
            int loc = unsorted + start;
            while ((loc >= gap + start) && (array[loc - gap] > nextItem))
            {
                array[loc] = array[loc - gap];
                loc = loc - gap;
            } // end while
            array[loc] = nextItem;
        } // end for
    } // end for
}

// Partitions given array around a calculated pivot
int partition(vector<int> &array, const int low, const int high)
{
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

// Implements the Quick Sort Sorting algorithm
void QuickSort(vector<int> &array, const int low, const int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(array, low, high);

        // Separately sort elements before
        // partition and after partition
        QuickSort(array, low, pi - 1);
        QuickSort(array, pi + 1, high);
    }
}