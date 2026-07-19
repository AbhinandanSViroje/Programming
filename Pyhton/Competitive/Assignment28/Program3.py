def main():
    try:
        FileName = input("Enter the FileName: ")
        fobj = open(FileName,"r")

        Data = fobj.readline()
        while(Data != ""):
            print(Data)
            Data = fobj.readline()
            
            

    except FileNotFoundError as fobj:
        print("file is not present in current directory")

if __name__ == "__main__":
    main()