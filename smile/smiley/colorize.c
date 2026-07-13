from cs50 import get_string

def main():
    # Get input from the user
    text = get_string("Text: ")

    # Initialize counters for letters, words, and sentences
    letters = 0
    words = 1  # Starting at 1 because words are separated by spaces
    sentences = 0

    # Loop through each character in the input text
    for char in text:
        if char.isalpha():  # Count letters (both uppercase and lowercase)
            letters += 1
        elif char == " ":
            words += 1  # Increment word count when space is found
        elif char in ".!?":  # Count sentences by periods, exclamation marks, and question marks
            sentences += 1

    # Calculate averages
    L = (letters / words) * 100  # Average number of letters per 100 words
    S = (sentences / words) * 100  # Average number of sentences per 100 words

    # Calculate Coleman-Liau index
    index = 0.0588 * L - 0.296 * S - 15.8

    # Round the index to the nearest integer
    grade = round(index)

    # Output the grade level based on the index
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")

if __name__ == "__main__":
    main()
