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

    return df

def main():
    #Step 1
    df = LoadData("student_performance_ml.csv")

if __name__ == "__main__":
    main()
