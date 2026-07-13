from cs50 import get_float

def main():
    # Loop until a valid input is received
    while True:
        # Get the change owed from the user
        change = get_float("Change owed: ")

        # If the input is non-negative, break the loop
        if change >= 0:
            break

    # Convert the change to cents (avoid floating point issues)
    cents = round(change * 100)

    # Initialize the coin count
    coins = 0

    # Calculate the number of coins needed (starting with the largest coin first)
    coins += cents // 25  # Quarters
    cents %= 25

    coins += cents // 10  # Dimes
    cents %= 10

    coins += cents // 5   # Nickels
    cents %= 5

    coins += cents // 1   # Pennies

    # Output the result (minimum number of coins)
    print(coins)

if __name__ == "__main__":
    main()
