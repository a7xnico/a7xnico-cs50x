from cs50 import get_int
def main():
    credit_card = get_int("Credit Card: ") # Asks user for the credit card
    sum_every_other_digit = every_other_digit(credit_card) # the sum of digits with the luhm algorithm
    num_digits = number_of_digits(credit_card) # the number of digits on the card
    amex = is_valid_amex(credit_card, num_digits) # checks validity of these cards
    master = is_valid_mastercard(credit_card, num_digits)
    visa = is_valid_visa(credit_card, num_digits)

    if sum_every_other_digit % 10 != 0: # throws invalid numbers
        print("INVALID")
    elif amex
        print("AMEX")
    elif master
        print("MASTERCARD")
    elif visa
        print("VISA")
    else:
        print("INVALID")

def is_valid_amex(credit_card, num_digits):
    first_two_digits = credit_card // pow(10, 13) # checks the first two digits with this
    if (num_digits == 15) and (first_two_digits == 34 or first_two_digits == 37): # looks if is a valid amex card
        return True
    else:
        return False


def is_valid_mastercard(credit_card, num_digits):
    first_two_digits = credit_card // pow(10, 14)
    if (num_digits == 16) and (first_two_digits > 50 and first_two_digits < 56): # needs both of them to be true
        return True
    else:
        return False

def is_valid_visa(credit_card, num_digits):
    if num_digits == 13:
        first_digit = credit_card // pow(10, 12) # checks the first digit of the card
        if first_digit == 4:
            return true
    elif num_digits == 16: # can be eithter 13 or 16 digits
        first_digit = credit_card // pow(10, 15)
        if first_digit == 4:
            return True

    return False

def number_of_digits(credit_card): # counts the amount of digits in the card
    count = 0
    while credit_card > 0:
        count += 1
        credit_card = credit_card // 10
    return count

# checks every other digit to utilize the algorithm to check a valid card
def every_other_digit(credit_card):
    sumation = 0
    is_alternate_digit = False
    while credit_card > 0:
        if is_alternate_digit == True:
            last_digit = credit_card % 10
            product = multiply_and_sum(last_digit)
            sumation += product
        else:
            last_digit = credit_card % 10
            sumation += last_digit
        is_alternate_digit = not is_alternate_digit
        credit_card = credit_card // 10
    return sumation
# helper function ofr the luhm algorithm
def multiply_and_sum(last_digit):
    multiply = last_digit * 2
    sumation = 0
    while multiply > 0:
        last_digit_multiply = multiply % 10
        sumation += last_digit_multiply
        multiply = multiply // 10
    return sumation

main()
