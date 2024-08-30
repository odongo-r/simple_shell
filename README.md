# Simple Shell

A simple Unix shell designed for learning and experimentation. This shell provides basic functionalities including command execution, built-in commands, and support for user-defined aliases.

## Features

- Basic command execution
- Built-in commands for navigation and environment management
- User-defined aliases
- Simple history management

## Installation

### Prerequisites

- GCC (GNU Compiler Collection)
- Make (optional, for build automation)

### Build Instructions

1. **Clone the Repository**

```
   git clone https://github.com/odongoron/simple-shell.git
   cd simple-shell
 ```

2. **Compile the Shell**

Use the following command to compile the shell:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple-shell
```
This will generate an executable named simple-shell.


## Usage
**Starting the Shell**

To start the shell, simply run:

```
./simple-shell
```

**Command Syntax**

    Exit the Shell

  ```
    exit

  ```

Exit the shell. Optionally, a status code can be provided.

**Change Directory**

```
cd [directory]

```

Change the current working directory to directory. If no directory is specified, change to the home directory.

**Display Environment Variables**

```
env
```
Display the current environment variables.

**Set Environment Variable**

```
setenv VARIABLE=value
```
Set an environment variable VARIABLE to value.

**Unset Environment Variable**

```
unsetenv VARIABLE
```
Unset the environment variable VARIABLE.

**Create or Modify Alias**

```
alias name=command
```
Create a new alias name with the command command.

**Remove Alias**

```
unalias name
```
Remove the alias name.

**Display Help**

  ```
    help
  ```
Display a help message with a summary of available built-in commands.

## Aliases

Aliases are used to create shortcuts for longer commands. Use the following syntax:

  **Define Alias**

```
    alias name=command
```
Remove Alias

```
    unalias name
```

## Environment Variables

The shell respects standard environment variables:

    HOME: The home directory of the current user.
    PATH: A colon-separated list of directories where the shell looks for executable files.

**Exit Status**

The shell returns the following exit statuses:

    0: Successful execution.
    1: An error occurred.

**Files**

    ~/.simple_shell_history: History file for the shell commands.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request if you have suggestions or improvements.

## Author

Ronald Odongo and Victor Maiyo

## License

This project is licensed under the MIT License. See the LICENSE file for details.
