# Pipex
Pipex is a simple c program that mimics the functionality of a shell command that looks like this:

   ```console
    < file1 cmd1 | cmd2 > file2
   ```

## Project goals

The project is part of the [Codam](https://www.codam.nl/studying-at-codam) curriculum. The main learning goals are:
- Introduction to forking in c processes
- Buildup for future project of rebuilding bash in C

## Usage

**Pipex is run as:**
   ```console
    ./pipex file1 "cmd1" "cmd2" file2
   ```
- File1: path to input file
- First bash command with parameters
- Second bash command
- File2: path to output file

**Return values**

Return value should be the same as the exit code of the second command
