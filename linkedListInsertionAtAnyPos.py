class node:
    def __init__(self,data=None):
        self.data = data
        self.next = None
class linkedList:
    def __init__(self):
        self.head = None
    def insertion(self,data,position):
        k=1
        newNode = node(data)
        p = self.head
        q = None
        if position == 1:  #for insertion of the head or the first position
            if self.head is None:
                self.head =  newNode
            else:
                newNode.next = p
                self.head = newNode
            print(f"{data} was successfully inserted")
        else:               #for insertion at any other position
            while k<position and p is not None:  #p contains the copy of the head
                k += 1
                q=p
                p=p.next
            if k != position:
                print("The position does not exist")
                return
            else:
                q.next = newNode
                newNode.next = p
                print(f"{data} was succesfully inserted ")
    
    def display(self):
        if self.head is None:
            print("The list is empty")
            return
        
        temp = self.head
        while temp:
            print(f"{temp.data}->",end='')
            temp=temp.next
        print('None')
        
#main function
l1 = linkedList()
while True:
    n = int(input("Enter the data :"))
    pos = int(input("Enter the position: "))
    l1.insertion(n,pos)
    
    ch = int(input("Enter 1 to quit: "))
    if ch == 1:
        break
    
print("The linked list after insertions:")
l1.display()