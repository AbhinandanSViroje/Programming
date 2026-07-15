def Addition(No1,No2):
    Ans = No1 + No2
    return Ans

def SubStraction(No1,No2):
    Ans = No1 - No2
    return Ans

def Division(No1,No2):
    Ans = No1 / No2
    return Ans

def Multiplication(No1,No2):
    Ans = No1 * No2
    return Ans
    

def main():
    print("Enter first Number : ")
    iValue1 = int(input())
    print("Enter first Number : ")
    iValue2 = int(input())

    Ret1 = Addition(iValue1,iValue2)
    Ret2 = SubStraction(iValue1,iValue2)
    Ret3 = Division(iValue1,iValue2)
    Ret4 = Multiplication(iValue1,iValue2)

    print("Addition is : ",Ret1)
    print("Substraction is : ",Ret2)
    print("Division is : ",Ret3)
    print("Multiplication is : ",Ret4)

if __name__ == "__main__":
    main()