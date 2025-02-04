class Node:
    def __init__(self,data=None):
        # Represents a single node in a linked list 
        self.data = data
        self.next = None       #instead of null, we have none here

class linkedList:
    def __init__(self):
        self.head = None        #initialize an empty linked list

    def append(self,data):      # A function that adds an element to the end of the linked list
        newNode = Node(data)
        if self.head == None:   # If the head is empty, it means we have encountered an empty list, hence make the newNode the head
            self.head = newNode
            return 
        temp = self.head 
        while temp.next:        #if the list has elements, then we traverse to the end of the list and append the element there
            temp = temp.next
        temp.next = newNode     
    def display(self):
        if self.head is None:
            print("The list is empty!")
            return
        temp = self.head
        while temp:
            print(f"{temp.data}->",end=' ')
            temp=temp.next
        print("None")

#main function body

l1 = linkedList()
l1.append(23)
l1.append(11)
l1.append(12)
l1.append(32)
l1.append(45)
l1.display()