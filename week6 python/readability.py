from cs50 import get_string


def main():
    while True:  # Infinite loop to get the desired text
        text = get_string("TEXT: ")
        length = len(text)
        if length > 1:
            break
    letters = count_letters(text)  # function to count letters
    words = count_words(text)  # function to count words
    sentences = count_sentences(text)  # function to count sentences
    index = calculate_index(letters, words, sentences)  # using the index to calculate the grade
    # types the level of the text
    if index < 1:
        print("Before grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print("Grade ", index)


def count_letters(text):
    letters = int(0)
    for char in text:  # goes through every character in the text
        if char.isalpha():  # checks if the character is alphabetical
            letters += 1  # sums it to the letters counter
    return letters  # returns the counter


def count_words(text):
    if len(text) == 0:
        return 0
    words = int(1)  # starts with the first word
    for char in text:
        if char.isspace():  # checks when a new word is started with an space between each word
            words += 1  # sums the words to the counter
    return words


def count_sentences(text):
    sentences = int(0)
    for char in text:
        if char in ['.', '!', '?']:  # checks the end of sentences with this
            sentences += 1
    return sentences


def calculate_index(letters, words, sentences):  # uses the index to calculate the level
    L = letters / words * 100
    S = sentences / words * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)
    return index


main()  # calls main to make the program work
