def NumberInReverse(No): 
    for i in range(No,0,-1):                    #i = No
        print(i)                                #while( i != 0):
                                                    #print(i)
                                                    #i = i - 1                      
def main():
    print("Enter the Number : ")
    Value = int(input())
    
    NumberInReverse(Value)
   

if __name__ == "__main__":
    main()