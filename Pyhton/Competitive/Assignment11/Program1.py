def checkPrime(num):
    if (num<=1):
        print("It is not prime")
    for i in range(2,num):
        if(num % i == 0):
            return "It is not prime"
        else:
            return "It is prime"
            

def main():
    print("Enter the number : ")
    num = int(input())

    Ret = checkPrime(num)

    print(Ret)

if __name__ == "__main__":
    main()