def main():
    try:
        FileName = input("Enter the FileName: ")
        fobj = open(FileName,"r")

        Count = 0
        Data = fobj.readline()
        while(Data != ""):
            Data = fobj.readline()
            Count = Count + 1
            
        print("The total Number of lines in Demo.txt are : ",Count)

    except FileNotFoundError as fobj:
        print("file is not present in current directory")

if __name__ == "__main__":
    main()