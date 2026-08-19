//////////////////////////////////////////////////////
//
//  Header Files Inclusion
//
//////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdbool.h>

//////////////////////////////////////////////////////
//
//  User Defined Macros
//
//////////////////////////////////////////////////////

#define MAXINODE 5
#define MAXFILESIZE 50
#define MAXOPENFILES 5

#define READ 1
#define WRITE 2
#define EXECUTE 4

#define START 0
#define CURRENT 1
#define END 2

#define EXECUTE_SUCCESS 0

#define REGULARFILE 1
#define SPECIALFILE 2

//////////////////////////////////////////////////////
//
//  User Defined Macros for error handling
//
//////////////////////////////////////////////////////

#define ERR_INVAILD_PARAMETER -1

#define ERR_NO_INODES -2

#define ERR_FILE_ALREADY_EXIST -3
#define ERR_FILE_NOT_EXIST -4

#define ERR_PERMISSION_DENIED -5

#define ERR_INSUFFICIENT_SPACE -6
#define ERR_INSUFFICIENT_DATA -7

#define ERR_MAX_FILES_OPEN -8

//////////////////////////////////////////////////////
//
//  Structure Name :    BootBlock
//  Description :       It holds the information to
//                      boot the operating system
//
//////////////////////////////////////////////////////

struct BootBlock
{
    char Information[100];
};

//////////////////////////////////////////////////////
//
//  Structure Name :    SuperBlock
//  Description :       It holds the information of
//                      complete File system
//
//////////////////////////////////////////////////////

struct SuperBlock
{
    int TotalInodes;
    int FreeInodes;
};

//////////////////////////////////////////////////////
//
//  Structure Name :    Inode
//  Description :       It holds information of file
//
//////////////////////////////////////////////////////

#pragma pack(1)
struct Inode
{
    char FileName[20];
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int FileType;
    int ReferenceCount;
    int Permission;
    char *Buffer;
    struct Inode *next;
};

typedef struct Inode INODE;
typedef struct Inode* PINODE;
typedef struct Inode** PPINODE;

//////////////////////////////////////////////////////
//
//  Structure Name :    FileTable
//  Description :       It holds information of opened
//                      files
//
//////////////////////////////////////////////////////

#pragma pack(1)
struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Mode;
    PINODE ptrinode;
};

typedef struct FileTable FILETABLE;
typedef struct FileTable* PFILETABLE;

//////////////////////////////////////////////////////
//
//  Structure Name :    UAREA
//  Description :       It holds information of process
//
//////////////////////////////////////////////////////

struct UAREA
{
    char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];
};

//////////////////////////////////////////////////////
//
//  Global variables used in the project
//
//////////////////////////////////////////////////////

struct BootBlock bootobj;
struct SuperBlock superobj;
struct UAREA uareaobj;

PINODE head = NULL;

//////////////////////////////////////////////////////
//
//  Function Name :     InitialiseUAREA
//  Description :       It is used to initialise UAREA
//  Author :            Abhinandan Sanjeev viroje
//  Date :              31/07/2026
//
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//
//  Function Name :     InitialiseSuperBlock()
//  Description :       It is used to initialise super block
//  Author :            Abhinandan Sanjeev viroje
//  Date :              31/07/2026
//
//////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
//
//  Function Name :     CreateDILB()
//  Description :       It is used to create linked list of inodes
//  Author :            Abhinandan Sanjeev viroje
//  Date :              31/07/2026
//
/////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//
//  Function Name :     StartAuxillaryDataInitialisation()
//  Description :       It is used to call all such functions
//                      which are used to initialise auxillary data
//  Author :            Abhinandan Sanjeev viroje
//  Date :              31/07/2026
//
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//
//  Function Name :     DisplayHelp()
//  Description :       It is used to display help to
//                      the user of project
//  Author :            Abhinandan Sanjeev viroje
//  Date :              1/08/2026
//
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//
//  Function Name :     ManPageDisplay()
//  Description :       It is used to display man page 
//                      of specific command
//  Input :             Name of command
//  Author :            Abhinandan Sanjeev viroje
//  Date :              1/08/2026
//
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//
//  Function Name :     IsFileExist()
//  Description :       It is used to check whether the
//                      file is presnt or not
//  Input :             Name of file 
//  Output :            True of presnt
//                      False is not present
//  Author :            Abhinandan Sanjeev viroje
//  Date :              1/08/2026
//
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//
//  Function Name :     CreateFile()
//  Description :       It is used to create new file
//  Input :             Name of file & Permissions
//  Output :            File Descriptor
//  Author :            Abhinandan Sanjeev viroje
//  Date :              1/08/2026
//
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//
//  Function Name :     LsFile()
//  Description :       It is used to display names of 
//                      all files
//  Input :             None
//  Output :            None
//  Author :            Abhinandan Sanjeev viroje
//  Date :              1/08/2026
//
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//
//  Function Name :     LsFile_All()
//  Description :       It is used to display all details  
//                      of all files
//  Input :             None
//  Output :            None
//  Author :            Abhinandan Sanjeev viroje
//  Date :              2/08/2026
//
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//
//  Function Name :     stat_file()
//  Description :       It is used to display all details  
//                      of specific files
//  Input :             File name
//  Output :            Exit status of function
//  Author :            Abhinandan Sanjeev viroje
//  Date :              2/08/2026
//
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//
//  Function Name :     unlink_file()
//  Description :       It is used to delete
//                      the specific file
//  Input :             File name
//  Output :            Exit status of function
//  Author :            Abhinandan Sanjeev viroje
//  Date :              2/08/2026
//
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//
//  Function Name :     write_file()
//  Description :       It is used to write the data
//                      into specific file
//  Input :             File Descriptior
//                      Data that we want to write
//                      Size of data
//  Output :            Number of bytes succesfully written
//  Author :            Abhinandan Sanjeev viroje
//  Date :              2/08/2026
//
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//
//  Function Name :     read_file()
//  Description :       It is used to read the data
//                      from specific file
//  Input :             File Descriptior
//                      address of empty buffer
//                      Size of data
//  Output :            Number of bytes succesfully read
//  Author :            Abhinandan Sanjeev viroje
//  Date :              2/08/2026
//
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//
//  Entry Point function of the CVFS project
//
//////////////////////////////////////////////////////