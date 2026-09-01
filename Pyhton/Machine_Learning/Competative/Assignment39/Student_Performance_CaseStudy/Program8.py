import pandas as pd
import matplotlib.pyplot as plt

from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score,confusion_matrix

#step 1 : Dataset Loading

filename = "student_performance_ml.csv"

df = pd.read_csv(filename)
print("Data loaded Succesfully...")

print("Top Data from CSV File : ")
print(df.head())

print("")
# Step 2 : Data Analysis

print("Data Information : ")
print(df.info())

print("")

print("Check if Data has an empty infomartion or not : ")
print(df.isnull().sum())

print("")

print("The Statistical of Data : ")
print(df.describe())

# Step 3 : Visualization

X = df[["StudyHours","Attendance","PreviousScore","AssignmentsCompleted","SleepHours"]]
Y = df["FinalResult"]

plt.scatter(
    df["StudyHours"],
    Y,
    marker="o",
    alpha=0.8,
    edgecolors="black",
    linewidths=1,
    label = "Students"
)

plt.title("student_performance")
plt.xlabel("StudyHours")
plt.ylabel("Y")
plt.grid(True)
plt.legend()
plt.show()

# Step 4 : Tranning the Data(train_test_split)

X_train,X_test,Y_train,Y_test = train_test_split(X,Y,test_size=0.5,random_state=42)
print("train_test_split is Done.")

print("")
# Step 5 : Model Trainning

model = DecisionTreeClassifier(max_depth=3)

model = model.fit(X_train,Y_train)
print("Model Trainning is Done.")

print("")
# Step 6 : Prediction

Y_pred = model.predict(X_test)
print("Model Prediction is Done.")

print("")
# Step 7 : Accuracy Calculation 

print("Accuracy Score : ")
accuracy = accuracy_score(Y_test,Y_pred)
print(f"Accuracy : {accuracy:.2%}")

print("")
# Step 8 : Confusion matrix

print("Confusion Matrix : ")
cm = confusion_matrix(Y_test,Y_pred)
print(cm)






