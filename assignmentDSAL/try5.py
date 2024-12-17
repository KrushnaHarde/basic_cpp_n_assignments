def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key

    return arr


def shellSort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            j = i
            temp = arr[i]
            while j >= 0 and arr[j-gap] > temp:
                arr[j] = arr[j-gap]
                j -= gap
            arr[j] = temp
        gap //=2
    return arr


def quickSort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)


def partition(arr, low, high):
    pivot = arr[low]
    i = low + 1

    for j in range(low+1, high):
        if arr[j] <= pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[low], arr[i-1] = arr[i-1], arr[low]
    return i-1


def partition2(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        i += 1
        arr[i], arr[j] = arr[j], arr[i]
    arr[high], arr[i+1] = arr[i+1], arr[high]
    return i+1
