# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonhseo <wonhseo@student.42gyeongsan.kr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 12:25:42 by wonhseo           #+#    #+#              #
#    Updated: 2024/04/10 12:25:43 by wonhseo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import subprocess
import random
import argparse
from tqdm import tqdm

def generate_random_numbers(size, upper_limit=501):
    """
    Generate a list of random numbers without duplicates.

    Args:
    - size: The number of random numbers to generate.
    - upper_limit: The upper limit for the random numbers (default: 501).

    Returns:
    - A list of unique random numbers.
    """
    return random.sample(range(upper_limit), size)

def run_command(command):
    """
    Run a shell command and return its output.

    Args:
    - command: The shell command to execute.

    Returns:
    - The output of the command.
    """
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    output, _ = process.communicate()
    return output.decode().strip()

def main():
    parser = argparse.ArgumentParser(description='Generate random numbers, pass them to push_swap, and check output with checker.')
    parser.add_argument('size', type=int, help='size of the list')
    parser.add_argument('repetitions', type=int, help='number of repetitions')
    parser.add_argument('--checker-suffix', default='', help='suffix for checker (e.g., _linux, _mac)')
    parser.add_argument('--verbose', action='store_true', help='enable verbose output with progress bar')
    args = parser.parse_args()

    size = args.size
    repetitions = args.repetitions
    checker_suffix = args.checker_suffix
    verbose = args.verbose
    
    max_line_count = 0
    if verbose:
        progress_bar = tqdm(range(repetitions))
        replay_command = ""
    else:
        progress_bar = range(repetitions)
        
    for _ in progress_bar:
        numbers = generate_random_numbers(size)
        input_string = ' '.join(map(str, numbers))

        push_swap_command = f"./push_swap '{input_string}'"
        checker_command = f"{push_swap_command} | ./checker{checker_suffix} '{input_string}'"
        line_count_command = f"{push_swap_command} | wc -l"

        checker_output = run_command(checker_command)
        line_count_output = int(run_command(line_count_command))

        if checker_output != "OK":
            raise ValueError("Checker failed: " + checker_command)
        
        max_line_count = max(max_line_count, line_count_output)
        if verbose:
            progress_bar.set_postfix({'Max Line Count': max_line_count})
            if max_line_count == line_count_output:
                replay_command = push_swap_command
    if verbose:
        print("ALL OK", replay_command, sep='\n')
    else:
        print("ALL OK", f"Max Line Count: {max_line_count}", sep='\n')

if __name__ == "__main__":
    main()
