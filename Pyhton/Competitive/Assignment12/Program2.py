def PrimeFact(num):
    fact = 0
    for i in range(1,num+1):
        if(num % i == 0):
            print(i)

def main():
    print("Enter the number : ")
    num = int(input())

    PrimeFact(num)
if __name__ == "__main__":
    main()