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
    model1 = DecisionTreeClassifier(max_depth=1)
    model2 = DecisionTreeClassifier(max_depth=3)
    model3 = DecisionTreeClassifier(max_depth=None)

    model1 = model1.fit(X_train,Y_train)
    model2 = model2.fit(X_train,Y_train)
    model3 = model3.fit(X_train,Y_train)

    print("Data Train Successfully")

    return model1,model2,model3

#step 4 : (Evaluate the model)Test  the Model

def EvaluateData(model1,model2,model3,X_test,Y_Test,X_train,Y_train):

    Border = "-"*40
    Y_train_Pred1 = model1.predict(X_train)
    Y_pred1 = model1.predict(X_test)
    Y_train_Pred2 = model2.predict(X_train)
    Y_pred2 = model2.predict(X_test)
    Y_train_Pred3 = model3.predict(X_train)
    Y_pred3 = model3.predict(X_test)

    # pRediction of Models
    print(Border)
    print("Predicted values :",Y_pred1)
    print(Border)

    print(Border)
    print("Predicted values :",Y_pred2)
    print(Border)

    print(Border)
    print("Predicted values :",Y_pred3)
    print(Border)

    print(Border)
    print("Actual Values :",Y_Test)
    print(Border)

    # Accuracy  of Models
    print("Model1 : max_depth=1 : ")
    print(Border)
    accuracy1 = accuracy_score(Y_pred1,Y_Test)
    print(f"The Accuracy Score of Testing model1 is  : {accuracy1:.2%}")
    accuracy2 = accuracy_score(Y_train_Pred1,Y_train)
    print(f"The Accuracy Score of Trainning model1 is   : {accuracy2:.2%}")
    print(Border)

    print("Model2 : max_depth=3 : ")
    print(Border)
    accuracy3 = accuracy_score(Y_pred2,Y_Test)
    print(f"The Accuracy Score of Testing model2 is  : {accuracy3:.2%}")
    accuracy4 = accuracy_score(Y_train_Pred2,Y_train)
    print(f"The Accuracy2 Score of Trainning model2 is  : {accuracy4:.2%}")
    print(Border)

    print("Model3 : max_depth=None : ")
    print(Border)
    accuracy5 = accuracy_score(Y_pred3,Y_Test)
    print(f"The Accuracy Score of Testing model3 is   : {accuracy5:.2%}")
    accuracy6 = accuracy_score(Y_train_Pred3,Y_train)
    print(f"The Accuracy2 Score of Trainning model3 is  : {accuracy6:.2%}")
    print(Border)
    
def main():
    #Step 1
    df = LoadData("student_performance_ml.csv")

    #step2
    X_train,X_test,Y_train,Y_Test = SplitData(df)

    #step3
    model1,model2,model3 = TrainModel(X_train,Y_train)

    #Step4
    EvaluateData(model1,model2,model3,X_test,Y_Test,X_train,Y_train)
    
if __name__ == "__main__":
    main()

