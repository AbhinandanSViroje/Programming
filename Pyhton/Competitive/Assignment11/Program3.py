def SumDigit(num):
    iDigit = 0
    iSum = 0

    while(num != 0):
        iDigit = num % 10                   # in this the last number get stored in iDigit
        iSum = iSum + iDigit
        num = num // 10                     # it does perform integer division so the decimal point  get discarded basically it removes the last number

    print(iSum)
    
def main():

    print("Enter the number : ")
    num = int(input())

    SumDigit(num)

    

if __name__ == "__main__":
    main()