def NumberInSequnece(No):
    for i in range(1, No+1):
        print(i, end = " ")
    
def main():
    print("Enter the Number : ")
    Value = int(input())
    
    NumberInSequnece(Value)
   

if __name__ == "__main__":
    main()