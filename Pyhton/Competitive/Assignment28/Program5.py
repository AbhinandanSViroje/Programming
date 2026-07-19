def main():
    try:
        FileName1 = input("Enter the FileName1 : ")
        Word = input("Enter the word : ")

        fobj1 = open(FileName1,"r")
    
        Data = fobj1.readline()

        while(Data != ""):
            Words = Data.split()
            if Word in Words:
                return True
            Data = fobj1.readline()
            
        if(Word == True):
            print("Is is Founded")
        else:
            print("It is not found")

            
            
    except FileNotFoundError as fobj:
        print("file is not present in current directory")

if __name__ == "__main__":
    main()