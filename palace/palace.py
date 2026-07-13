import random

# Initialize player resources
player_resources = {
    "money": 50,
    "workers": 10,
    "research": 0
}

# List to track player actions
action_log = []

# Function to log actions
def log_action(action):
    action_log.append(action)

# Function to handle events
def handle_event(event_type):
    global player_resources
    if event_type == "Market Downturn":
        player_resources["money"] -= 10
        player_resources["workers"] -= 2
        log_action("Market Downturn: Lost 10 money and 2 workers.")
    elif event_type == "Technological Breakthrough":
        player_resources["research"] += 5
        log_action("Technological Breakthrough: Gained 5 research points.")
    elif event_type == "Worker Strike":
        player_resources["workers"] -= 1
        log_action("Worker Strike: Lost 1 worker.")
    else:
        print("Unknown event type.")

# Function to display current resources
def display_resources():
    print("\nCurrent Resources:")
    for resource, amount in player_resources.items():
        print(f"  {resource.capitalize()}: {amount}")

# Function to display action log
def display_actions():
    if action_log:
        print("\nAction Log:")
        for action in action_log:
            print(f"  - {action}")
    else:
        print("No actions logged.")

# Main game loop
def main():
    print("Welcome to the Crystal Palace Game Simulation!")

    # Simulate a few events
    events = ["Market Downturn", "Technological Breakthrough", "Worker Strike"]
    for _ in range(5):  # Simulate 5 random events
        event = random.choice(events)
        handle_event(event)

    # Display final resources and action log
    display_resources()
    display_actions()

if __name__ == "__main__":
    main()
