def PrintEven(a):
    for i in range(1,a+1):
        if(i % 2 == 0):
            print(i)
        
a = int(input("Enter the number : "))

PrintEven(a)