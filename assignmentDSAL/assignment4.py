''' Write a Python program to store roll numbers of student in 
array who attended training program in random order. Write 
function for searching whether particular student attended 
training program or not, using Linear search and Sentinel 
search. '''

# Program to store roll numbers and search using Linear and Sentinel Search

def linear_search(arr, key):
    """Perform Linear Search."""
    for i in range(len(arr)):
        if arr[i] == key:
            return i  # Return the index if the roll number is found
    return -1  # Return -1 if not found

def sentinel_search(arr, key):
    """Perform Sentinel Search."""
    n = len(arr)
    last = arr[-1]  # Save the last element
    arr[-1] = key  # Set the last element as the key (sentinel)

    i = 0
    while arr[i] != key:
        i += 1

    arr[-1] = last  # Restore the last element

    if i < n - 1 or arr[-1] == key:  # Check if the key is found
        return i
    return -1  # Return -1 if not found

# Input roll numbers
roll_numbers = []
print("Enter the number of students who attended the training program:")
n = int(input("Number of students: "))
print(f"Enter the roll numbers of the {n} students:")
for _ in range(n):
    roll_number = int(input("Roll Number: "))
    roll_numbers += [roll_number]  # Using concatenation to avoid append

# Input roll number to search
print("Enter the roll number you want to check:")
key = int(input("Roll Number to Search: "))

# Linear Search
index_linear = linear_search(roll_numbers, key)
if index_linear != -1:
    print(f"[Linear Search] Success: Roll number {key} was found at position {index_linear + 1} (1-based index).")
else:
    print(f"[Linear Search] Failure: Roll number {key} was not found in the list.")

# Sentinel Search
index_sentinel = sentinel_search(roll_numbers, key)
if index_sentinel != -1:
    print(f"[Sentinel Search] Success: Roll number {key} was found at position {index_sentinel + 1} (1-based index).")
else:
    print(f"[Sentinel Search] Failure: Roll number {key} was not found in the list.")
    

'''Write a Python program to store roll numbers of student 
array who attended training program in sorted order. Write 
function for searching whether particular student attended 
training program or not, using Binary search and Fibonacci 
search.'''

# Program to store roll numbers in sorted order and search using Binary and Fibonacci Search

def binary_search(arr, key):
    """Perform Binary Search."""
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == key:
            return mid  # Return the index if found
        elif arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1
    return -1  # Return -1 if not found

def fibonacci_search(arr, key):
    """Perform Fibonacci Search."""
    n = len(arr)
    fib2 = 0  # (m-2)'th Fibonacci number
    fib1 = 1  # (m-1)'th Fibonacci number
    fib = fib2 + fib1  # m'th Fibonacci number

    while fib < n:
        fib2, fib1 = fib1, fib
        fib = fib2 + fib1

    offset = -1

    while fib > 1:
        i = min(offset + fib2, n - 1)

        if arr[i] < key:
            fib = fib1
            fib1 = fib2
            fib2 = fib - fib1
            offset = i
        elif arr[i] > key:
            fib = fib2
            fib1 = fib1 - fib2
            fib2 = fib - fib1
        else:
            return i  # Return the index if found

    if fib1 and offset + 1 < n and arr[offset + 1] == key:
        return offset + 1

    return -1  # Return -1 if not found

# Input roll numbers
roll_numbers = []
print("Enter the number of students who attended the training program:")
n = int(input("Number of students: "))
print(f"Enter the roll numbers of the {n} students in any order:")
for _ in range(n):
    roll_number = int(input("Roll Number: "))
    roll_numbers += [roll_number]

# Sort the roll numbers
for i in range(len(roll_numbers)):
    for j in range(len(roll_numbers) - i - 1):
        if roll_numbers[j] > roll_numbers[j + 1]:
            roll_numbers[j], roll_numbers[j + 1] = roll_numbers[j + 1], roll_numbers[j]

print("Sorted Roll Numbers:", roll_numbers)

# Input roll number to search
print("Enter the roll number you want to check:")
key = int(input("Roll Number to Search: "))

# Binary Search
index_binary = binary_search(roll_numbers, key)
if index_binary != -1:
    print(f"[Binary Search] Success: Roll number {key} was found at position {index_binary + 1} (1-based index).")
else:
    print(f"[Binary Search] Failure: Roll number {key} was not found in the list.")

# Fibonacci Search
index_fibonacci = fibonacci_search(roll_numbers, key)
if index_fibonacci != -1:
    print(f"[Fibonacci Search] Success: Roll number {key} was found at position {index_fibonacci + 1} (1-based index).")
else:
    print(f"[Fibonacci Search] Failure: Roll number {key} was not found in the list.")