# Title: Connect 4 game
# Author: Omar Elgammal
# Supervised by: Dr. Mohamed El-Ramly Structured programming class - FCAI
# Last modification: 22 - Mar - 2022

# This game version is resizable
# You can change (col, row) values to set the board size
col = 10
row = 8
global p
turn = 1
global player_symbol
board = [[" " for t in range(col)] for x in range(row)]

# Function that displays board


def print_board():
    print()
    for y in range(1, col + 1):
        print(" ", y, end=" ")
    print()
    for x in range(1, row+1):
        for y in range(0, col):
            print("|", end=" ")
            print(board[-x][y], end=" ")
            if y == col - 1:
                print("|", end="")

        print()
    print("-"*col*4)

# Function that determines the turn of which player and takes input from player


def play():
    global p
    global player_symbol
    global turn
    if turn % 2 == 1:
        player = "Player X your turn: "
        player_symbol = "X"
    else:
        player = "Player O your turn: "
        player_symbol = "O"
    turn += 1
    s = input(player)
    x = 1
    for i in range(1, col + 1):
        if s == str(i):
            x = 0
            break
    if x:
        print("Invalid input. Please choose a column from 1 to", col)
        turn -= 1
        play()
    else:
        p = int(s)

# Function that stores the input in the board


def board_update():
    global p
    global turn
    player_input = p - 1

    for i in range(0, row):
        if board[i][player_input] == " ":
            board[i][player_input] = player_symbol
            break
        elif board[row - 1][player_input] != " ":
            print("Column is full")
            turn -= 1
            break

# Function that checks if the player wins


def check_winner():

    # checking horizontal
    for x in range(0, row):
        for y in range(0, col - 3):
            if board[x][y] == player_symbol and board[x][y + 1] == player_symbol and \
                    board[x][y + 2] == player_symbol and board[x][y + 3] == player_symbol:
                return True

    # checking vertically
    for y in range(0, row):
        for x in range(0, row - 3):
            if board[x][y] == player_symbol and board[x + 1][y] == player_symbol and \
                    board[x + 2][y] == player_symbol and board[x + 3][y] == player_symbol:
                return True

    # checking \ diagonal
    for x in range(0, row - 3):
        for y in range(3, col):
            if board[x][y] == player_symbol and board[x + 1][y - 1] == player_symbol and \
                    board[x + 2][y - 2] == player_symbol and board[x + 3][y - 3] == player_symbol:
                return True

    # checking / diagonal
    for x in range(0, row - 3):
        for y in range(0, col - 3):
            if board[x][y] == player_symbol and board[x + 1][y + 1] == player_symbol and \
                    board[x + 2][y + 2] == player_symbol and board[x + 3][y + 3] == player_symbol:
                return True

    return False


while True:
    print_board()
    play()
    board_update()
    if check_winner():
        print_board()
        print("Player", player_symbol, "is the winner")
        break
    if turn == (col * row + 1):
        print_board()
        print("The game is draw")
        break
