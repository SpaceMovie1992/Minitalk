# Minitalk
## Minitalk

### Project Instructions

- **Executable Files:** Name your executable files `client` and `server`.
- **Makefile:** Include a Makefile which compiles your source files without relinking.
- **Libft:** You are allowed to use your libft.
- **Error Handling:** Thoroughly handle errors to prevent unexpected program termination (e.g., segmentation fault, bus error, double free).
- **Memory Management:** Ensure your program doesn't have memory leaks.
- **Global Variables:** You may have one global variable per program (one for the client and one for the server), but you must justify their use.
- **Allowed Functions:**
  - `write`
  - `ft_printf` or any equivalent you coded
  - `signal`
  - `sigemptyset`
  - `sigaddset`
  - `sigaction`
  - `kill`
  - `getpid`
  - `malloc`
  - `free`
  - `pause`
  - `sleep`
  - `usleep`
  - `exit`

### Mandatory Part

You must create a communication program consisting of a client and a server.

#### Server:
- The server must be started first and print its PID after launch.
- It should be able to receive strings from several clients in a row without needing to restart.
- The communication between client and server must be done only using UNIX signals (`SIGUSR1` and `SIGUSR2`).

#### Client:
- Takes two parameters: the server PID and the string to send.
- Sends the string passed as a parameter to the server.
- After the string is received, the server must print it.
- The server must display the string quickly.

### Submission

Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop.
