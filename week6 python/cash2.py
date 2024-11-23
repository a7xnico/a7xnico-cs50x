from cs50 import get_float

# Prompt user for a positive amount of change
while True:
    change = get_float("Amount of change owed in dollars: ")
    if change > 0:
        break

# Define coin values in cents
coin_values = [25, 10, 5, 1]
total_coins = 0
cents = int(change * 100)

# Calculate the minimum number of coins needed
for value in coin_values:
    total_coins += cents // value
    cents %= value

print(total_coins)
