import random


def partition(array, low, high):
    pivot = array[high]
    i = low - 1

    for j in range(low, high):
        if array[j] < pivot:
            i += 1
            array[i], array[j] = array[j], array[i]

    array[i + 1], array[high] = array[high], array[i + 1]
    return i + 1


def quick_sort(array, low, high):
    if low < high:
        pivot_index = partition(array, low, high)
        quick_sort(array, low, pivot_index - 1)
        quick_sort(array, pivot_index + 1, high)


def selection_sort(array):
    size = len(array)
    for i in range(size - 1):
        min_index = i
        for j in range(i + 1, size):
            if array[j] < array[min_index]:
                min_index = j
        if min_index != i:
            array[i], array[min_index] = array[min_index], array[i]


def bubble_sort(array):
    size = len(array)
    for i in range(size - 1):
        for j in range(size - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]


def linear_search(array, target):
    for i, element in enumerate(array):
        if element == target:
            print("Element found:", element)
            return i
    return -1


def binary_search(array, target):
    left = 0
    right = len(array) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if array[mid] == target:
            return mid

        if array[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1


def binary_search_recursive(array, left, right, target):
    if left > right:
        return -1

    mid = left + (right - left) // 2

    if array[mid] == target:
        return mid

    if array[mid] < target:
        return binary_search_recursive(array, mid + 1, right, target)
    else:
        return binary_search_recursive(array, left, mid - 1, target)


def insert_element(array, position, element):
    # Check if the position is valid
    if position < 0 or position > len(array):
        print("Invalid position!")
        return

    # Shift elements to the right from the given position
    array.append(None)
    for i in range(len(array) - 1, position, -1):
        array[i] = array[i - 1]

    # Insert the element at the given position
    array[position] = element


def remove_element(array, position):
    # Check if the position is valid
    if position < 0 or position >= len(array):
        print("Invalid position!")
        return

    # Shift elements to the left from the given position
    for i in range(position, len(array) - 1):
        array[i] = array[i + 1]

    # Remove the last element
    array.pop()


def insertion_sort_asc(array):
    size = len(array)
    for i in range(size):
        for j in range(i, 0, -1):
            if array[j] < array[j - 1]:
                array[j], array[j - 1] = array[j - 1], array[j]
            else:
                break


def insertion_sort_desc(array):
    size = len(array)
    for i in range(size):
        for j in range(i, 0, -1):
            if array[j] > array[j - 1]:
                array[j], array[j - 1] = array[j - 1], array[j]
            else:
                break


def generate_random_array(size, lower_limit, upper_limit):
    return [random.randint(lower_limit, upper_limit) for _ in range(size)]


def print_array(array):
    print("[", end="")
    for i, element in enumerate(array):
        if i < len(array) - 1:
            print(element, end=", ")
        else:
            print(element, end="")
    print("]")


# Testing the implemented sorting algorithms

array_size = 10
lower_limit = 1
upper_limit = 100

# Generate a random array
array = generate_random_array(array_size, lower_limit, upper_limit)

print("Original array:")
print_array(array)

# Sort the array using quick sort
quick_sort(array, 0, array_size - 1)
print("Array sorted using quick sort:")
print_array(array)

# Generate a new random array
array = generate_random_array(array_size, lower_limit, upper_limit)

print("Original array:")
print_array(array)

# Sort the array using selection sort
selection_sort(array)
print("Array sorted using selection sort:")
print_array(array)

# Generate a new random array
array = generate_random_array(array_size, lower_limit, upper_limit)

print("Original array:")
print_array(array)

# Sort the array using bubble sort
bubble_sort(array)
print("Array sorted using bubble sort:")
print_array(array)

# Testing the search algorithms

target = random.randint(lower_limit, upper_limit)

# Perform a linear search on the array
linear_search_result = linear_search(array, target)
if linear_search_result != -1:
    print("Linear search: Element found at index", linear_search_result)
else:
    print("Linear search: Element not found")

# Perform a binary search on the array
binary_search_result = binary_search(array, target)
if binary_search_result != -1:
    print("Binary search: Element found at index", binary_search_result)
else:
    print("Binary search: Element not found")

# Perform a recursive binary search on the array
recursive_binary_search_result = binary_search_recursive(array, 0, len(array) - 1, target)
if recursive_binary_search_result != -1:
    print("Recursive binary search: Element found at index", recursive_binary_search_result)
else:
    print("Recursive binary search: Element not found")

# Testing the insert and remove operations

position = random.randint(0, array_size)
element = random.randint(lower_limit, upper_limit)

print("Original array:")
print_array(array)

# Insert an element at a random position
insert_element(array, position, element)
print(f"Array after inserting {element} at position {position}:")
print_array(array)

# Remove an element from the same random position
remove_element(array, position)
print(f"Array after removing element at position {position}:")
print_array(array)

# Sorting the array using insertion sort in ascending order
insertion_sort_asc(array)
print("Array sorted in ascending order using insertion sort:")
print_array(array)

# Sorting the array using insertion sort in descending order
insertion_sort_desc(array)
print("Array sorted in descending order using insertion sort:")
print_array(array)
