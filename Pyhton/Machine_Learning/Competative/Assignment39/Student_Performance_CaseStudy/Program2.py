import pandas as pd

from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score,confusion_matrix

#step 1 : LoadData
def LoadData(DataPath):

    df = pd.read_csv(DataPath)
    print("Data Loaded Successfully")

    print("First five Data from CSV")
    print(df.head())

    return df

#step 2 : Split the data
def SplitData(df):
    X = df[["StudyHours","Attendance","PreviousScore","AssignmentsCompleted","SleepHours"]]
    Y = df["FinalResult"]

    X_train,X_test,Y_train,Y_Test = train_test_split(X,Y,test_size=0.5,random_state=42)

    return  X_train,X_test,Y_train,Y_Test

#step 3 : Train the Model
def TrainModel(X_train,Y_train):
    model = DecisionTreeClassifier()

    model = model.fit(X_train,Y_train)
    print("Data Train Successfully")

    return model

def EvaluateData(model,X_test,Y_Test):
    Y_pred = model.predict(X_test)
    print("Predicted values :",Y_pred)
    print("")
    print("Actual Values :",Y_Test)

def main():
    #Step 1
    df = LoadData("student_performance_ml.csv")

    #step2
    X_train,X_test,Y_train,Y_Test = SplitData(df)

    #step3
    model = TrainModel(X_train,Y_train)



if __name__ == "__main__":
    main()




