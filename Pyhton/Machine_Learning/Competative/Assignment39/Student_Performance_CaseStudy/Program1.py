import pandas as pd

from sklearn.tree import DecisionTreeClassifier

#step 1 : LoadData
def LoadData(DataPath):

    df = pd.read_csv(DataPath)
    print("Data Loaded Successfully")

    print("First five Data from CSV")
    print(df.head())


    X = df[["StudyHours","Attendance","PreviousScore","AssignmentsCompleted","SleepHours"]]
    Y = df["FinalResult"]

    X_train,X_test,Y_train,Y_Test = train_test_split(X,Y,test_size=0.5,random_state=42)


    

def main():
    #Step 1
    df = LoadData("student_performance_ml.csv")

if __name__ == "__main__":
    main()




