def two_sum(nums, target):
    num_indices = {}  # Dictionary to store numbers and their indices
    
    for index, num in enumerate(nums):
        complement = target - num  # Find the complement required to reach the target
        
        # If the complement is in the dictionary, return its index along with the current index
        if complement in num_indices:
            return [num_indices[complement], index]
        
        # Otherwise, store the current number and its index in the dictionary
        num_indices[num] = index
    
    # If no solution is found
    return None

# Take input from the user for the list of integers
nums = list(map(int, input("Enter the list of integers separated by space: ").split()))

# Take input from the user for the target value
target = int(input("Enter the target value: "))

result = two_sum(nums, target)

if result:
    print("Indices of the two numbers that add up to the target:", result)
else:
    print("No solution found.")
