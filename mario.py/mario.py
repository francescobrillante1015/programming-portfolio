from cs50 import get_int

def main():
    # Loop until the user provides a valid input
    while True:
        # Get the height of the pyramid from the user
        height = get_int("Height: ")

        # Check if the height is between 1 and 8, inclusive
        if 1 <= height <= 8:
            break

    # Generate the pyramid
    for i in range(1, height + 1):
        # Print spaces to align the pyramid
        print(" " * (height - i) + "#" * i)

if __name__ == "__main__":
    main()
