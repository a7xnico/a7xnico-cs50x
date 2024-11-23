from cs50 import get_int


def main():
    while True:  # Infinite loop to get the correct height value
        height = get_int("Height: ")  # Get int is the easier version for python
        if height > 0 and height <= 8:  # If the input is correct breaks the while loop
            break
        else
        # Gives to the user the correct input
        print("Incorrect value, Height must be between 1 and 8")
    for row in range(height):  # manages all the rows
        make_row(height, row)  # calls the function with the needed data


def make_row(height, row):
    for i in range(height - row - 1):  # For loop to make the spaces
        print(" ", end="")  # end="" is to keep the spaces in the same line

    for j in range(row + 1):  # for loop to make all the columns
        print("#", end="")  # the same, keeps the hashes in the same line
    print()  # gives the space to the next row


main()  # calls main to finally make the program run
