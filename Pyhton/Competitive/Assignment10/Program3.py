def Factorial(a):
    iCount = 1
    for i in range(1,a+1):
        iCount = iCount * i

    print(iCount)
        
a = int(input("Enter the number : "))

Factorial(a)