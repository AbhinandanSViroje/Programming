def main():
    try:
        FileName = input("Enter the FileName: ")
        fobj = open(FileName,"r")

        Count = 0
        Data = fobj.readline()
        while(Data != ""):
            Words = Data.split()
            WordsCnt = len(Words)
            Count = Count + WordsCnt
            Data = fobj.readline()
            
            
        print("The total Number of Words in Demo.txt are : ",Count)

    except FileNotFoundError as fobj:
        print("file is not present in current directory")

if __name__ == "__main__":
    main()