import pandas as pd

#step 1 : LoadData

def LoadData(DataPath):

    df = pd.read_csv(DataPath)

    print("Data of first 5 datal oaded successfully")

    #First 5 data
    print(df.head())

    print("Data of last 5 Data loaded successfully")

    #Last 5 Data
    print(df.tail())

    print("Total Number of Row and Column : ")

    #Total number of rows and column
    print(df.shape)

    print("List of Columns names : ")
    
    #List of Columns names
    print(df.columns)

    print("Data type  of each Columns : ")

    #Data type  of each Columns
    print(df.dtypes)

    print("Display total number of students : ")

    #Display total number of students
    print(df.shape[0])

    #Count number of student pass and fail
    count = df["FinalResult"].value_counts()

    cpass = count[1]
    cFail = count[0]

    print("Total number of students pass : ",cpass)
    print("Total number of students Fail : ",cFail)

    #Average of Columns 
    Avg = df["StudyHours"].mean()
    print("Average of StudyHours column is :",Avg)
    print("Average of Attendance Column is :",df["Attendance"].mean())

    #Max and min
    print("Maximum of PreviousScore column is : ",df["PreviousScore"].max())
    print("Minimum of SleepHours column is : ",df["SleepHours"].min())

    #calculate the perecentage of pass and fail
    print("The percentage of pass is : ",cpass/df.shape[0]*100)
    print("The percentage of fail is : ",cFail/df.shape[0]*100)

    


    


    return df

def main():
    #Step 1
    df = LoadData("student_performance_ml.csv")

if __name__ == "__main__":
    main()
