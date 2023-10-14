while True:
    print("Welcome to calculator!")

    def add (x,y):
        return x + y

    def substract (x,y):
        return x - y

    def multiplication (x,y):
        return x * y

    def division (x,y):
        return x / y

    def Power (x,y):
        return x**y

    print("These are the available operations ? ")
    print("1) Add")
    print("2) Substract")
    print("3) Multiplication")
    print("4) Division")
    print("5) Power")

    operation = int(input("Type one of the above operation :"))

    x = int(input("Enter 1st Digit :\n"))
    y = int(input("Enter 2nd Digit or power : \n"))

    if operation == 1 :
        print( x , "+", y ,"=",
                        (x+y))

    elif operation == 2 :
        print( x , "-", y ,"=",
                        (x-y))

    elif operation == 3 :
        print( x , "*", y ,"=",
                        (x*y))

    elif operation == 4 :
        print( x , "/", y ,"=",
                        (x/y))
    elif operation == 5 :
        print( x , "^", y ,"=",
                        (x**y))

    else :
        print("I dont't understand select one of above")

    rerun = input("Would you like to do another calculation ?")

    rerun = rerun.lower()

    if rerun != "yes":
        break

