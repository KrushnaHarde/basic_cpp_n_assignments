def fiboSearch(arr, key):
    n = len(arr)
    fib2 = 0
    fib1 = 1
    fib = fib2 + fib1

    while fib < n:
        fib2 , fib1 = fib1, fib
        fib = fib2 + fib1

    offset = -1
    while fib > 1:
        i = min(n-1, offset + fib2)

        if arr[i] < key:
            # move to left by 1
            fib,fib1 = fib1, fib2
            fib2 = fib - fib1
            offset = i
        elif arr[i] > key:
            # move to left by 2
            fib = fib2
            fib1 = fib1 - fib2
            fib2 = fib - fib1
        else:
            return i

    if fib1 and offset + 1 < n and arr[offset+1] == key:
        return offset + 1

    return -1

