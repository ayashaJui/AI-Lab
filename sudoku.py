# Each cell may contain a number from one to nine, and
# each number can only occur once in each row, column, and box
# A Sudoku starts with some cells containing numbers (clues), and
# the goal is to solve the remaining cells. Proper Sudoku's have one solution.
import numpy as np


def solve(board):
    place = empty_place(board)
    if not place:
        return True
    else:
        row, col = place

    for num in range(1, 10):
        if valid_place(board, num, row, col):
            board[row][col] = num

            if solve(board):
                return True

            board[row][col] = 0
    return False


def empty_place(board):
    for i in range(0, len(board)):
        for j in range(0, len(board[0])):
            if board[i][j] == 0:
                return i, j


def valid_place(board, num, row, col):
    for i in range(0, len(board[0])):
        if board[row][i] == num:
            return False

    for i in range(0, len(board)):
        if board[i][col] == num:
            return False

    box_row = (row // 3) * 3
    box_col = (col // 3) * 3

    for i in range(box_row, box_row + 3):
        for j in range(box_col, box_col + 3):
            if board[i][j] == num:
                return False

    return True


def display_board(board):
    for i in range(0, len(board)):
        if i % 3 == 0 and i != 0:
            print("- - - - - - - - - - - -")
        for j in range(0, len(board[0])):
            if j % 3 == 0 and j != 0:
                print(" | ", end="")
            if j == 8:
                print(board[i][j])
            else:
                print(board[i][j], end=" ")


sudoku_board = []

print("Sudoku Solver::-\n")
n = 9

print("Enter values(with clues) in matrix form(9X9): ")
for r in range(0, n):
    x = input().split()
    a = []
    for c in range(0, n):
        a.append(int(x[c]))
    sudoku_board.append(a)

sudoku_board = np.array(sudoku_board, dtype=np.uint8)

print("\nInput Board")
print("------------------\n")
display_board(sudoku_board)

sol = solve(sudoku_board)

print("\n")

if sol:
    print("Solved Board:")
    print("------------------\n")

    display_board(sudoku_board)
else:
    print("Sorry...Sudoku can not be solved")
