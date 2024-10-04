# Custom Unix Shell

This project is a custom-built Unix shell that supports several commonly used Unix external and internal commands, with extended functionalities for each. The shell is designed to handle both standard operations as well as additional options for enhanced control and flexibility.

## Features

### Supported External Commands:

1. **`cat` (concatenate files and print to standard output)**
   - `cat`: Standard usage to display file contents.
   - `cat -n`: Display file contents with line numbers.
   - `cat -e`: Display file contents and mark the end of each line with a `$`.

2. **`date` (display or set date and time)**
   - `date`: Display the current date and time.
   - `date -R`: Display the date and time in RFC-2822 format.
   - `date -u`: Display the current date and time in UTC.

3. **`ls` (list directory contents)**
   - `ls`: List directory contents.
   - `ls -a`: List all files, including hidden files.
   - `ls -l`: List directory contents in long format, including file permissions, ownership, and size.

4. **`mkdir` (make directories)**
   - `mkdir`: Create a new directory.
   - `mkdir -v`: Create a new directory and display a message for each directory created.
   - `mkdir -m`: Create a new directory with specified permissions.

5. **`rm` (remove files or directories)**
   - `rm`: Remove files or directories.
   - `rm -v`: Remove files or directories with verbose output.
   - `rm -d`: Remove empty directories.

### Supported Internal Commands:

1. **`echo`**: Print a message to the standard output.
2. **`cd`**: Change the current working directory.
3. **`pwd`**: Display the current working directory.

## How to Run

1. Clone the repository:

    ```bash
    git clone https://github.com/shrey17sept/Custom-Unix-Shell.git
    ```

2. Compile the shell:

    ```bash
    gcc -o custom_shell custom_shell.c
    ```

3. Run the shell:

    ```bash
    ./custom_shell
    ```

4. Use the supported commands directly in the shell.

## Command Usage Examples

- **`cat` command**:
    - `cat file.txt`: Display contents of `file.txt`.
    - `cat -n file.txt`: Display contents of `file.txt` with line numbers.
    - `cat -e file.txt`: Display contents of `file.txt` with end-of-line markers.

- **`date` command**:
    - `date`: Show current date and time.
    - `date -R`: Show date and time in RFC-2822 format.
    - `date -u`: Show date and time in UTC.

- **`ls` command**:
    - `ls`: List files in the current directory.
    - `ls -a`: List all files, including hidden files.
    - `ls -l`: List files in long format, showing permissions and ownership.

- **`mkdir` command**:
    - `mkdir new_directory`: Create `new_directory`.
    - `mkdir -v new_directory`: Create `new_directory` with a verbose message.
    - `mkdir -m 755 new_directory`: Create `new_directory` with permissions set to `755`.

- **`rm` command**:
    - `rm file.txt`: Remove `file.txt`.
    - `rm -v file.txt`: Remove `file.txt` with verbose output.
    - `rm -d empty_directory`: Remove an empty directory.

## Future Work

- Add support for piping and redirection.
- Improve error handling and command parsing.
