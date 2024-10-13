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


# Register signal handler for CTRL + C
signal.signal(signal.SIGINT, signal_handler)

# Main loop to read stdin
try:
    for line in sys.stdin:
        """
        Main loop that reads input from stdin line by line.

        For each line, it checks if the line matches the expected format:

<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

        If the line matches, it extracts the status code and file size
        and updates the respective statistics. Every 10 lines,
        the statistics are printed.
        """
        parts = line.split()
        if len(parts) < 7:
            continue  # Skip line if it doesn't have the correct format
        try:
            # Extract relevant data from the line
            file_size = int(parts[-1])
            status_code = int(parts[-2])

            # Update file size
            total_size += file_size

            # Update status code count if valid
            if status_code in valid_codes:
                status_codes[status_code] += 1

            line_count += 1

            # Print statistics every 10 lines
            if line_count % 10 == 0:
                print_stats()

        except (ValueError, IndexError):
            continue  # Skip line if there are parsing issues

except KeyboardInterrupt:
    """
    Catch the KeyboardInterrupt exception when the user presses CTRL + C.
    When this happens, the statistics are printed one final time before
    the program exits.
    """
    # Handle keyboard interrupt, print final statistics
    print_stats()
    sys.exit(0)
