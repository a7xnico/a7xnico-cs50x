from cs50 import get_float

while True:
    change = get_float("Amount of change owed in dollars: ") # Prompts user for the change
    if change > 0: # eliminates all negative inputs
        break
    else:
        print("Change must be more than 0") # Gives the information to the user

coins = [0.25, 0.10, 0.05, 0.01] # the coin values
max = len(coins) # the amount of different coins
total_coins = 0 # initialize the total coins that are needed
cents = int(change * 100) # change the change value to cents

for i in range(max): # loop through every coin
    num_coins = cents // (coins[i] * 100) # calculates the number of coins needed
    total_coins += num_coins # adds those coins to the counter
    cents = cents % (coins[i] * 100) # takes the value from the coins using modulo operator

print(int(total_coins)) # Hands the user the total coins needed in an integer
