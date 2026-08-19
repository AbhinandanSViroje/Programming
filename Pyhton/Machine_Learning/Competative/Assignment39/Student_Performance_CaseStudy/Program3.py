from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score

def main():
    Independent =[[35,1],
                  [85,1],
                  [32,0],
                  [25,0],
                  [95,1],
                  [75,1],
                  [83,1],
                  [34,0]]

    #1 = pass , 2 = fail
    Dependent =[1,1,2,2,1,1,1,2]

    model = DecisionTreeClassifier()

    model = model.fit(Independent,Dependent)
    print("model train succuessfully")

    Result = model.predict([[52,1],[31,0]])
    print("Predictaed :",Result)

if __name__ == "__main__":
    main()
