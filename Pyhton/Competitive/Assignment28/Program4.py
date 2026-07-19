def main():
    try:
        FileName1 = input("Enter the FileName1 : ")
        FileName2 = input("Enter the FileName2 : ")

        fobj1 = open(FileName1,"r")
        fobj2 = open(FileName2,"w")

        Data = fobj1.readline()
        while(Data != ""):
            fobj2.write(Data)
            Data = fobj1.readline()

        print("Contents of ABC.txt copied into Demo.txt.")
     
                  

    except FileNotFoundError as fobj:
        print("file is not present in current directory")

if __name__ == "__main__":
    main()