from cs50 import get_int


def main():
    while True:  # Infinite loop
        height = get_int("Height: ")
        if check_height(height):  # checks if the input is correct
            break
        else:
            print("Height must be between 1 and 8")

    for row in range(height):
        make_row(height, row)  # same mechanism as in mario-less


def check_height(height):
    return height > 0 and height <= 8  # returns the correct values


def make_row(height, row):
    for space in range(height - row - 1):
        print(" ", end="")
    for column in range(row + 1):
        print("#", end="")
    print("  ", end="")  # new line, this is the space between the 2 pyramids
    for column in range(row + 1):  # new column
        print("#", end="")  # easier than the first, just needs to do this without the spaces
    print()


main()
