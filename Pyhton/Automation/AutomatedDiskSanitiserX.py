##########################################################
#
#   Importing required libraries
#
##########################################################

import sys
import os
import hashlib
import time
import schedule

#####################################################################
#
#   Function name :     CalculateCheckSum
#   Input :             FileName (Path of the file)
#   Description :       Reads the file in binary mode, processes
#                       its contents in chunks of 1024 bytes,
#                       generates an MD5 hash, and returns the
#                       hexadecimal checksum of the file.
#   Date :              27/07/2026   
#   Author :            Abhinandan Sanjeev Viroje
#
#####################################################################

def CalculateCheckSum(FileName):
    fobj = open(FileName,"rb")

    hobj = hashlib.md5() 

    Buffer = fobj.read(1024)

    while(len(Buffer)> 0):
        hobj.update(Buffer)
        Buffer = fobj.read(1024)

    fobj.close()

    return hobj.hexdigest()

###################################################################################
#
#   Function name :     FindDuplicate
#   Input :             Enter the DirectoryName
#   Description :       Scans all files in the specified directory, 
#                       calculates the MD5 checksum of each file, 
#                       groups files having the same checksum, 
#                       and returns a dictionary containing duplicate files.
#   Date :              27/07/2026   
#   Author :            Abhinandan Sanjeev Viroje
#
###################################################################################

def FindDuplicate(DirectoryName):
    Border = "-"*40
      
    Ret = False

    Ret = os.path.exists(DirectoryName)

    if Ret == False:
        print("Automation Error : There is no Such Directory path with name ",DirectoryName)
        return

    Ret = os.path.isdir(DirectoryName)

    if Ret == False:
        print("Automation Error : It is not a Directory with name ",DirectoryName)
        return

    AbhinandanLog = "AbhinandanLog"
    Ret = os.path.exists(AbhinandanLog)

    if(Ret == True):
        Ret = os.path.isdir(AbhinandanLog)
        if(Ret == False):
            print("Unable to Procced as Directory name is Exixting but it is not a Directory")
            return
    else:
        os.mkdir(AbhinandanLog)
        print("Directory for logfile Created Successfully")

    timestamp = time.strftime("%Y-%m-%d_%H-%M-%S")

    LogFileName = os.path.join(AbhinandanLog,"Abhinandan_%s.log"%timestamp)
    fobj = open(LogFileName,"w")
    print(f"Log file gets Successfully created with name{LogFileName}")

    fobj.write(Border+"\n")
    fobj.write(" Automatiom Disk Sanitiser Script \n")
    fobj.write(Border+"\n\n")

    Duplicate = {}
    TotalFiles = 0
    TotalDuplicates = 0

    for FolderName,SubFolder,FileName in os.walk(DirectoryName):
        for fname in FileName:
            TotalFiles = TotalFiles + 1

            fname = os.path.join(FolderName,fname)
            CheckSum = CalculateCheckSum(fname)

            if CheckSum in Duplicate:
                TotalDuplicates = TotalDuplicates + 1
                Duplicate[CheckSum].append(fname)
            else:
                Duplicate[CheckSum] = [fname]

    fobj.write(Border+"\n")
    fobj.write(f"Total files are : {TotalFiles}\n")
    fobj.write(f"Total Duplicate files are : {TotalDuplicates}\n")

    fobj.write(Border+"\n")
    fobj.write("Log file gets created at : \n "+timestamp)
    fobj.write("\n"+Border+"\n")

    fobj.close()
    
    return Duplicate, LogFileName

#####################################################################################################################
#
#   Function name :     DeleteDuplicate
#   Input :             Enter the DirectoryName
#   Description :       Deletes duplicate files from the specified directory by comparing their MD5 checksums. 
#                       The first occurrence of each file is retained, 
#                       while all other duplicate copies are removed.
#   Date :              27/07/2026   
#   Author :            Abhinandan Sanjeev Viroje
#
#####################################################################################################################

def DeleteDuplicate(DirectoryName):

    Border = "-"*40

    MyDict, LogFileName = FindDuplicate(DirectoryName)
    
    Result = list(filter(lambda X : len(X) > 1 ,MyDict.values()))

    Count = 0

    TotalDeleted = 0

    TotalFreeSpace = 0

    fobj = open(LogFileName,"a")

    fobj.write(Border+"\n")
    fobj.write(" Delete Files \n")
    fobj.write(Border+"\n\n")

    for value in Result:
        for subvalue in value:
            Count = Count + 1
            if(Count > 1):
                Size = os.path.getsize(subvalue)
                TotalFreeSpace = TotalFreeSpace + Size
                os.remove(subvalue)
                fobj.write(subvalue+"\n")
                TotalDeleted = TotalDeleted + 1
        Count = 0

    TotalFreeSpace = TotalFreeSpace/1024
    fobj.write("\n"+Border+"\n")
    fobj.write(f"Total Deleted files : {TotalDeleted}\n")
    fobj.write(f"Total Space Freed : {TotalFreeSpace:.2f} KB \n")
    fobj.write("\n"+Border+"\n\n")

    fobj.write(Border+"\n")
    fobj.write("------------ End of log file -----------\n")
    fobj.write(Border+"\n")
    
    fobj.close()

##########################################################
#
#   Function name :     main
#   Input :             Enter the Directory name
#   Description :       It controls the script
#   Date :              27/07/26   
#   Author :            Abhinandan Sanjeev Viroje
#
##########################################################

def main():
    Border = "-"*60
       
    print(Border)
    print(" Disk Sanitiser Automation Script ")
    print(Border)

    if(len(sys.argv) == 2):
        if(sys.argv[1] == "--h" or sys.argv[1] == "--H"):
            print("This Automation Script is used to perform the following tasks:")
            print("1 : It scans the specified directory.")
            print("2 : It calculates the MD5 checksum of every file.")
            print("3 : It detects duplicate files based on checksum.")
            print("4 : It deletes duplicate copies while keeping the first occurrence.")
            print("5 : It generates a detailed log file.")
            print("6 : It records the deleted files in the log.")
            print("7 : It displays the total number of deleted files.")
            print("8 : It displays the total disk space freed after deletion.")
            print("9 : It runs automatically at the specified time interval.")

        elif(sys.argv[1] == "--u" or sys.argv[1] == "--U"):
            print("Use the Automation Script as:")
            print(f"python3 {sys.argv[0]} Directory_Name Time_Interval")
            print("Directory_Name : Path of the directory to be scanned.")
            print("Time_Interval : Time interval in minutes for periodic execution.")
            print("Example:")
            print(f"python3 {sys.argv[0]} Demo 5")
            print(f"python3 {sys.argv[0]} /Users/Abhinandan/Documents 10")

        else:
            print("Unable to proceed as there is no matching argument.")
            print("Please use --h or --u for more details.")

    elif(len(sys.argv)==3):

        try:
            TimeInterval = int(sys.argv[2])

            if(TimeInterval <= 0):
                print("Automation Error : Time Interval Should be greater than 0")
                return
        except ValueError:
            print("Automation Error : Time Interval should be a Positive Integer.")
            return

        
        print("Scheduler Started Successfully")
        print("Press ctrl + C to abort the automation script")

        schedule.every((TimeInterval)).minutes.do(DeleteDuplicate, sys.argv[1]) 

        try:
            while True:
                schedule.run_pending()
                time.sleep(1)

        except KeyboardInterrupt:
            print(" ")
            print(Border)
            print("Automation script stopped successfully.")
            print("Thank you for using Disk Sanitiser Automation Script.")
            print(Border)

    else:
        print("Invaild number of arguments")
        print("Unalble to procced as argument are not matching")
        print("Please use --h or --u flag for getting more detail")

##########################################################
#
#   Starter of the automation script
#
##########################################################

if __name__ == "__main__":
    main()

    