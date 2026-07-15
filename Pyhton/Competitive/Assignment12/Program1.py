def ChkVowel(ch):
    if( ch == 'a' or ch == 'e' or ch == 'i'  or  ch == 'o' or ch == 'u' or ch == 'A' or ch == 'E' or ch == 'I'  or  ch == 'O' or ch == 'U' ):
        return "Vowel"

def main():
    print("Enter the Character : ")
    ch = input()

    Ret = ChkVowel(ch)
    print(Ret)

if __name__ == "__main__":
    main()


