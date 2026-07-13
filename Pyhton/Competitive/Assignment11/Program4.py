def ReverseDigit(num):
    iDigit = 0
    iReverse = 0
    while(num != 0):
        iDigit = num % 10                   # in this the last number get stored in iDigit
        iReverse = (iReverse * 10) + iDigit # print(iDigit, end ="") we can also do this
        num = num // 10                     # it does perform integer division so the decimal point  get discarded basically it removes the last number

    print(iReverse)
    
    print()
def main():

    print("Enter the number : ")
    num = int(input())

    ReverseDigit(num)

    

if __name__ == "__main__":
    main()