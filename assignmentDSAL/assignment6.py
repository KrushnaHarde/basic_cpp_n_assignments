# Program to store first year percentage and sort using Quick Sort

def partition(arr, low, high):
    """Partition function for Quick Sort."""
    pivot = arr[high]
    i = low - 1  # Index of smaller element

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def quick_sort(arr, low, high):
    """Perform Quick Sort on the array."""
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)


# Input first year percentages
percentages = []
print("Enter the number of students:")
n = int(input("Number of students: "))
print(f"Enter the percentages of the {n} students:")
for _ in range(n):
    percentage = float(input("Percentage: "))
    percentages += [percentage]

# Perform Quick Sort
quick_sort(percentages, 0, len(percentages) - 1)
print("\nPercentages sorted using Quick Sort:", percentages)

# Display top five scores
print("\nTop five scores:", percentages[-5:][::-1])

