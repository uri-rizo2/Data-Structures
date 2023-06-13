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

