class Stack():
    def __init__(self):
        self.items=[]
        
    def push(self,item):
        self.items.append(item)
        
    def is_empty(self):
        return not self.items
        
    def pop(self):
        return self.items.pop()
    
    def peek(self):
        return self.items[-1]
    
    def size(self):
        return len(self.items)
    
    def __str__(self):
        return str(self.items)
        
def reversestring(mystring):
    reversedstr=""
    mystack=Stack()
    for i in mystring:
        mystack.push(i)
    while not mystack.is_empty():
        reversedstr+=mystack.pop()    
    return reversedstr
x=input()
print(reversestring(x))