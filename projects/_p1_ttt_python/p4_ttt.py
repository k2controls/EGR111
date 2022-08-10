''' Project 1 - tic tac toe
Python Solution
'''
print("This initial tic tac toe solution")
print("displays either X as the winner or")
print("O as the winner based on the user's")
print("selection. If the user enter 'C' a")
print("'Cat\'s' game is displayed")
print()
user_entry = ""
c1 = c2 = c3 = c4 = c5 = c6 = c7 = c8 = c9 = 0
while user_entry != "Q":
    user_entry = input("Enter X, O or C: ")
    if user_entry == '0':
        print("Please enter the character O and not the number 0.")
    elif user_entry == "O":
        print("O|O|O")
        print("-----")
        print("X|X| ")
        print("-----")
        print("X| | ")
    elif user_entry == "X":
        print("O|O|O")
        print("-----")
        print("X|X| ")
        print("-----")
        print("X| | ")
    elif user_entry == "C":
        print("O|X|O")
        print("-----")
        print("X|O|X")
        print("-----")
        print("X|O|X")
    else:
        print("Invalid entry. Please try again.")    
print("Done.")
