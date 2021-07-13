"""
    Insertion sort is a simple sorting algorithm
    that builds the final sorted array one item at a time
"""
list=[2,5,3,7,9,4,1,0,6,11]

i=1
# to traverse through 1 to len(list)
while(i<10):
  element=list[i]
  j=i
  i=i+1

  while(j>0 and list[j-1]>element):
    # swap  
    list[j]=list[j-1]
    j=j-1

  list[j]=element

i=0
while(i<10):
  print (list[i])
  i=i+1

"""
    Best complexity: n
    Average complexity: n^2
    Worst complexity: n^2
    Space complexity: 1
    
    Input: 2, 5, 3, 7, 9, 4, 1, 0, 6, 11
    Output: 0, 1, 2, 3, 4, 5, 6, 7, 9, 11
"""
