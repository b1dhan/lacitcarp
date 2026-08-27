def solve_n_queens(n):
    board = [-1] * n

    def is_safe(row, col):
        for prev_row in range(row):
            prev_col = board[prev_row]

            # Same column
            if prev_col == col:
                return False

            # Same diagonal
            if abs(prev_row - row) == abs(prev_col - col):
                return False

        return True

    def backtrack(row):
        if row == n:
            print_board()
            return True

        found = False

        for col in range(n):
            if is_safe(row, col):
                board[row] = col

                if backtrack(row + 1):
                    found = True

                board[row] = -1

        return found

    def print_board():
        for row in range(n):
            for col in range(n):
                if board[row] == col:
                    print("Q", end=" ")
                else:
                    print(".", end=" ")
            print()
        print()

    backtrack(0)


n = int(input("Enter the value of N: "))
solve_n_queens(n)

