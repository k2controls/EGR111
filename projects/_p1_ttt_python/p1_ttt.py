''' Project 1 - tic tac toe
Python Solution
'''
print("This initial tic tac toe solution")
print("displays either X as the winner or")
print("O as the winner based on the user's")
print("selection. If the user enter 'C' a")
print("'Cat\'s' game is displayed")
print()
user_entry = input("Enter X, O or C: ")
if user_entry == '0':
    print("Please enter the character O and not the number 0.")
if user_entry == "O":
    print("O|O|O")
    print("-----")
    print("X|X| ")
    print("-----")
    print("X| | ")
if user_entry == "X":
    print("O|O|O")
    print("-----")
    print("X|X| ")
    print("-----")
    print("X| | ")
if user_entry == "C":
    print("O|X|O")
    print("-----")
    print("X|O|X")
    print("-----")
    print("X|O|X")
    
