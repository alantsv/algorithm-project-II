import sys


def optimal_bst(keys, frequencies):
    n = len(keys)
    cost = [[0 for j in range(n)] for i in range(n)]  # Cria matriz com elementos = nulo

    # Popula diagonal
    for i in range(n):
        cost[i][i] = frequencies[i]

    for chain_length in range(2, n+1):
        for i in range(n - chain_length + 1):
            j = i + chain_length - 1
            cost[i][j] = sys.maxsize

            for r in range(j+1):
                sub1 = cost[i][r-1] if r > i else 0
                sub2 = cost[r+1][j] if r < j else 0

                c = sub1 + sub2 + sum(frequencies[i:j+1])

                if c < cost[i][j]:
                    cost[i][j] = c

    return cost[0][n-1]


if __name__ == "__main__":
    keys = [10, 12, 20]
    frequencies = [34, 8, 50]

    cost = optimal_bst(keys, frequencies)

    assert cost == 142
    print cost
