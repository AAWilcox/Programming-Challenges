# Filename:             backpack.py
# Programmer:           Alyssa Wilcox
# Date:                 2/16/2022
# Description:          You have two backpacks of volumes A and B. You also have N objects, for each
#                       object i you know its volume Vi. You are planning to go on a trip, so you decide
#                       to pack the objects. You take each object in order and try to pack it in the
#                       backpack that's got the most room left. If you can't pack an object you are
#                       going to leave it home. Find the number of objects left home.

# Get the volumes of each bag
A = int(input("What is the volume of bag A? "))
B = int(input("What is the volume of bag B? "))

# Lists to hold the items in each bag
# Not necessary in the scope of this problem!
bag_A = []
bag_B = []

# Get the number of items
N = int(input("How many objects are there? "))

# The number of items left home
ans = 0

# Get the volumes of the N items. Store values in a list
volumes = []
print("Please input the volumes of the objects")
for i in range(0, N):
    val = int(input())
    volumes.append(val)

# Go through each item volume, but them in a bag or leave home
for i in volumes:
    # There is more room in bag A than B and bag A has enough space for the item
    if(A >= B and i <= A):
        # Put item in bag A
        bag_A.append(i)
        # Update the volume of bag A
        A -= i
    # There is more room in bag B than A and bag B has enough space for the item
    elif(A < B and i <= B):
        # Put the item in bag B
        bag_B.append(i)
        # Update the volume of bag B
        B -= i
    # Item does not fit in either bag. Leave it home
    else:
        ans = ans + 1

# Show which items are in each bag
print("Items in bag A: %s" % bag_A)
print("Items in bag B: %s" % bag_B)

print("Number of items left home: %s" % ans)



