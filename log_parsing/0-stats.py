#!/usr/bin/python3
""" Task 0: 0. Log parsing """
import sys
import signal

# Initialize global variables
total_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
valid_codes = set(status_codes.keys())
line_count = 0


# Function to print statistics
def print_stats():
    """
    Prints the current statistics:
    - Total file size processed.
    - The count of each HTTP status code that has been encountered.

    Only prints the status codes that have been counted
    (i.e., codes with a count > 0).
    """
    print(f"File size: {total_size}")
    for code in sorted(status_codes):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")


# Function to handle keyboard interruption (CTRL + C)
def signal_handler(sig, frame):
    """
    Handles the keyboard interruption (CTRL + C).
    This function is called when the user presses CTRL + C.
    It prints the current statistics before exiting the program.

    Args:
        sig (int): Signal number (in this case, SIGINT).
        frame: The current stack frame (not used in this function).
    """
    print_stats()
    sys.exit(0)

if __name__ == "__main__":
    # Register signal handler for CTRL + C
    signal.signal(signal.SIGINT, signal_handler)

    for line in sys.stdin:
        # Split the line into parts to extract necessary fields
        parts = line.split()

        # Check if the input format matches the expected number of parts
        if len(parts) < 7:
            continue  # Skip line if it doesn't have the correct format
        
        # Check if status code and file size are valid integers
        if parts[-2].isdigit() and parts[-1].isdigit():
            status_code = int(parts[-2])
            file_size = int(parts[-1])

            # Update total file size and status code counts
            total_size += file_size

            if status_code in valid_codes:
                status_codes[status_code] += 1
            
            line_count += 1

            # Print stats every 10 lines
            if line_count % 10 == 0:
                print_stats()
