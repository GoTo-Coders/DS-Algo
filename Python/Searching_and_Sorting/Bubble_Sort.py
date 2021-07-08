'''
    Bubble Sort is a simple algorithm which is used to sort a given set of n elements 
    provided in form of an array with n number of elements. 
    Bubble Sort compares all the element one by one and sort them based on their values.
'''

list = [4, 6, 3, 6, 2, 7, 4, 9, 4, 7]

# for traverse the entire list
for j in range(0, 9):
    # checking if the list is already sorted
    if_sorted = False
    for i in range(0, 9):
        # comparing two elements
        if list[i] > list[i + 1]:
            swap = list[i]
            # swapping elements
            list[i] = list[i + 1]
            list[i + 1] = swap
            if_sorted = True
    if if_sorted == False:
        break
print(list)

'''
    Input = 4, 6, 3, 6, 2, 7, 4, 9, 4, 7
    Output = 2, 3, 4, 4, 4, 6, 6, 7, 7, 9

    Best complexity: n
    Average complexity: n^2
    Worst complexity: n^2
    Space complexity: 1
'''
