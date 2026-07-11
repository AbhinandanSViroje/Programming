def ChkDivisible(a):
    if(a  % 3 == 0 and a % 5 == 0):
        print(a, " is  Divisible by 3 and 5")
    else:
        print(a, " is not Divisible by 3 and 5")

a = int(input("Enter the number : "))

ChkDivisible(a)