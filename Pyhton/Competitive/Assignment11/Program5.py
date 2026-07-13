def Palindrome(num):
    iDigit = 0
    iReverse = 0
    temp = num
    while(num != 0):
        iDigit = num % 10                   # in this the last number get stored in iDigit
        iReverse = (iReverse * 10) + iDigit
        num = num // 10                     # it does perform integer division so the decimal point  get discarded basically it removes the last number


    if( iReverse == temp  ):
        return "Palindrome"
    
    
    print()
def main():

    print("Enter the number : ")
    num = int(input())

    Ret = Palindrome(num)

    print(Ret)

    

if __name__ == "__main__":
    main()