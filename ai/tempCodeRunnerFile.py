from itertools import permutations

def solve_crypto(word1, word2, result):
    # Get unique letters
    letters = list(set(word1 + word2 + result))

    if len(letters) > 10:
        print("More than 10 unique letters. No solution possible.")
        return

    first_letters = {word1[0], word2[0], result[0]}

    for perm in permutations(range(10), len(letters)):
        mapping = dict(zip(letters, perm))

        # Leading letter cannot be zero
        if any(mapping[ch] == 0 for ch in first_letters):
            continue

        n1 = int("".join(str(mapping[ch]) for ch in word1))
        n2 = int("".join(str(mapping[ch]) for ch in word2))
        res = int("".join(str(mapping[ch]) for ch in result))

        if n1 + n2 == res:
            print("Solution Found:")
            for ch in sorted(mapping):
                print(f"{ch} = {mapping[ch]}")
            print(f"\n{n1} + {n2} = {res}")
            return

    print("No solution found.")

# Example
word1 = input("Enter first word: ").upper()
word2 = input("Enter second word: ").upper()
result = input("Enter result word: ").upper()

solve_crypto(word1, word2, result)