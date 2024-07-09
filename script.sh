#!/bin/bash

# Function to process each directory
process_directory() {
    local dir="$1"
    echo "Processing directory: $dir"
    # Enter the directory
    cd "$dir" || return
    # Copy all .md files to README.md
    cp *.md README.md 2>/dev/null  # Redirect errors to /dev/null
    # Optionally, display the copied files
    echo "Copied files:"
    ls -l *.md 2>/dev/null
    # Return to previous directory
    cd - >/dev/null || return
}

# Main script starts here

# Use find to locate all directories from the current directory downwards
# Adjust the starting directory and depth as needed
find . -type d | while read -r dir; do
    # Skip the current directory (.)
    if [[ "$dir" != "." ]]; then
        process_directory "$dir"
    fi
done
