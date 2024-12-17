# Program to store second year percentage and sort using Insertion Sort and Shell Sort

def insertion_sort(arr):
    """Perform Insertion Sort on the array."""
    for i in range(1, len(arr)):
        # sorts part of array left to i
        # place ith element 
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def shell_sort(arr):
    """Perform Shell Sort on the array."""
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2
    return arr

# Input second year percentages
percentages = []
print("Enter the number of students:")
n = int(input("Number of students: "))
print(f"Enter the percentages of the {n} students:")
for _ in range(n):
    percentage = float(input("Percentage: "))
    percentages += [percentage]

# Perform Insertion Sort
sorted_percentages_insertion = insertion_sort(percentages[:])
print("\nPercentages sorted using Insertion Sort:", sorted_percentages_insertion)

# Perform Shell Sort
sorted_percentages_shell = shell_sort(percentages[:])
print("\nPercentages sorted using Shell Sort:", sorted_percentages_shell)

# Display top five scores (using Shell Sort result as it is sorted similarly)
print("\nTop five scores:", sorted_percentages_shell[-5:][::-1])