# Dining Philosophers Using Processes and System V Semaphores

## Overview

This project implements the Dining Philosophers problem using Linux processes and System V semaphores.

Five philosophers are created as separate processes using fork(). Semaphores are used to control access to the five forks and avoid deadlock.

## Features

- Five philosophers using processes
- System V semaphores for synchronization
- Fork acquisition and release
- Thinking, Hungry and Eating states
- Deadlock avoidance
- Parent waits for child processes

## Technologies Used

- C Programming
- Linux
- Processes
- System V Semaphores
- `fork()`
- `wait()`
- `semget()`
- `semop()`
- `semctl()`

## Project Structure

```text
main.c
```
## How to run
```bash
./a.out
```
