import numpy as np


def bfs(v, f, r):
    for k in range(0, n):
        if matrix[v][k] == 1 and visited[k] == 0:
            r = r + 1
            queue[r] = k
            visited[k] = 1
            print((k + 1), end=" ")

    f = f + 1
    if f <= r:
        bfs(queue[f], f, r)


n = int(input("Enter Number of Nodes: "))

queue = np.zeros(n, dtype=np.uint8)
visited = np.zeros(n, dtype=np.uint8)

matrix = []
print("Enter Adjacent Matrix:")
for i in range(0, n):
    x = input().split()
    a = []
    for j in range(0, n):
        a.append(int(x[j]))
    matrix.append(a)

matrix = np.array(matrix, dtype=np.uint8)

s = int(input("Enter Starting Node: "))
f = 0
r = 0
queue[r] = s - 1
visited[s - 1] = 1

print("Breadth First Search: ", s, end=" ")

bfs((s - 1), f, r)
