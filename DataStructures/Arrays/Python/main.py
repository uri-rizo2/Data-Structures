import functionModule.py
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
