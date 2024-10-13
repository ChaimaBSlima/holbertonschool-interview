#!/usr/bin/python3
import sys
import signal

# Initialize global variables
total_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
valid_codes = set(status_codes.keys())
line_count = 0


# Function to print statistics
def print_stats():
    print(f"File size: {total_size}")
    for code in sorted(status_codes):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")


# Function to handle keyboard interruption (CTRL + C)
def signal_handler(sig, frame):
    print_stats()
    sys.exit(0)


# Register signal handler for CTRL + C
signal.signal(signal.SIGINT, signal_handler)

# Main loop to read stdin
try:
    for line in sys.stdin:
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
    # Handle keyboard interrupt, print final statistics
    print_stats()
    sys.exit(0)
