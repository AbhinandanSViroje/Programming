#Accepting number:-
print("Enter the Number : ")
num = int(input())

#variable for addtion of perfect number
iSum = 0

for i in range(1,num):
    if( num % i == 0):
        iSum = iSum + i

if(iSum == num):
    print("It is perfect number ")

else:
    print("It is not perfect number ")

#output:

#Enter the Number : 
# 7
# It is not perfect number 

