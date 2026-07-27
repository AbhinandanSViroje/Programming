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

    #it create an object for open class 
    # "rb" is read and binaray(Computers store everything as bytes).
    # means Since duplicate detection should work for every file type(jpg,png,pdf,mp4,zip,txt,csv), we use "rb"
    fobj = open(FileName,"rb")

    #creates an MD5 object which is empty It has not processed anything yet(Imagine an empty fingerprint machine.)
    hobj = hashlib.md5() 

    # Read the first 1024 bytes (1 KB) of the file and store them in Buffer.
    # Reading the file in small chunks improves memory efficiency, especially for large files.
    Buffer = fobj.read(1024)

    # Continue processing the file until there is no more data to read.
    # len(Buffer) > 0 means the buffer still contains bytes from the file.
    while(len(Buffer)> 0):

        # Update the MD5 hash object with the current chunk of data.
        # The hash object gradually generates the checksum as each chunk is processed.(Exactly like eating food)
        hobj.update(Buffer)

        # Read the next 1024-byte chunk from the file.
        # When the end of the file is reached, read() returns an empty bytes object (b'')->0
        # causing the loop to terminate.
        Buffer = fobj.read(1024)

    #closeFile
    fobj.close()

    # Return the final MD5 checksum (hexadecimal string) of the file,
    # which serves as a unique fingerprint for comparing file contents.
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

    # Initialize a Boolean variable to store the result of path validation.
    Ret = False

    # Check whether the specified directory path exists.
    Ret = os.path.exists(DirectoryName)

    # If the path does not exist, display an error message and exit the function.
    if Ret == False:
        print("Path is Invaild")
        return

    # Verify that the given path refers to a directory.
    Ret = os.path.isdir(DirectoryName)

    # If the path is not a directory, display an error and exit.
    if Ret == False:
        print("It is not a Directory ")
        return

    # Create an empty dictionary to store checksums and their corresponding files.
    Duplicate = {}

    # Traverse the specified directory and all its subdirectories.
    for FolderName,SubFolder,FileName in os.walk(DirectoryName):

        # Process each file present in the current directory.
        for fname in FileName:

            # Create the complete path of the current file.
            fname = os.path.join(FolderName,fname)

            # Calculate the MD5 checksum of the current file.
            CheckSum = CalculateCheckSum(fname)

            # Check whether this checksum already exists in the dictionary.
            if CheckSum in Duplicate:

                # Add the current file to the existing list of files having the same checksum.
                Duplicate[CheckSum].append(fname)
            else:

                # Store the checksum as the key and initialize a list with the current file.
                Duplicate[CheckSum] = [fname]

    return Duplicate

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

    # Find duplicate files by grouping them according to their MD5 checksums.
    MyDict = FindDuplicate(DirectoryName)

    # Extract only those file lists that contain duplicate files
    # (i.e., lists having more than one file)
    Result = list(filter(lambda X : len(X) > 1 ,MyDict.values()))

    # Initialize a counter to keep track of files within each duplicate group.
    Count = 0

    # Initialize a counter to store the total number of deleted duplicate files.
    TotalDeleted = 0

    # Process each group of duplicate files.
    for value in Result:

        # Process each file within the current duplicate group.
        for subvalue in value:

            # Increment the file counter for the current duplicate group.
            Count = Count + 1

            # Keep the first file and delete all remaining duplicate files.
            if(Count > 1):

                # Delete the duplicate file from the file system.
                os.remove(subvalue)

                # Increment the total number of deleted files.
                TotalDeleted = TotalDeleted + 1

        # Reset the counter before processing the next duplicate group.
        Count = 0

    # Display the total number of duplicate files deleted.
    print("Total Deleted files : ",TotalDeleted)

    # Return the list of duplicate file groups.
    return Result

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
    DeleteDuplicate("Marvellous")

##########################################################
#
#   Starter of the automation script
#
##########################################################

if __name__ == "__main__":
    main()