DIRS = {(0, 1), (0, -1), (1, 0), (-1, 0)}


def is_connected(cells):
    if len(cells) == 0:
        return True

    start = next(iter(cells))
    stack = [start]
    visited = {start}

    while stack:
        x, y = stack.pop()

        for dx, dy in DIRS:
            nx = x + dx
            ny = y + dy

            if (nx, ny) in cells and (nx, ny) not in visited:
                visited.add((nx, ny))
                stack.append((nx, ny))

    return len(visited) == len(cells)


def move_to_origin(shape):
    min_x = min(x for x, y in shape)
    min_y = min(y for x, y in shape)

    new_shape = []

    for x, y in shape:
        nx = x - min_x
        ny = y - min_y
        new_shape.append((nx, ny))

    new_shape.sort()

    return tuple(new_shape)


def normalize(shape):
    all_shapes = []

    for type_id in range(8):
        new_shape = []

        for x, y in shape:
            if type_id == 0:
                nx, ny = x, y

            elif type_id == 1:
                nx, ny = -x, y

            elif type_id == 2:
                nx, ny = x, -y

            elif type_id == 3:
                nx, ny = -x, -y

            elif type_id == 4:
                nx, ny = y, x

            elif type_id == 5:
                nx, ny = -y, x

            elif type_id == 6:
                nx, ny = y, -x

            else:
                nx, ny = -y, -x

            new_shape.append((nx, ny))

        new_shape = move_to_origin(new_shape)
        all_shapes.append(new_shape)

    return min(all_shapes)


def can_fit(shape, n, m):
    max_x = max(x for x, y in shape)
    max_y = max(y for x, y in shape)

    height = max_x + 1
    width = max_y + 1

    if height <= n and width <= m:
        return True

    if height <= m and width <= n:
        return True

    return False


def expand(current, n, m):
    next_shapes = set()

    for shape in current:
        cells = set(shape)

        boundary = set()

        for x, y in cells:
            for dx, dy in DIRS:
                nx = x + dx
                ny = y + dy

                if (nx, ny) not in cells:
                    boundary.add((nx, ny))

        for pos in boundary:
            new_cells = set(cells)
            new_cells.add(pos)

            new_shape = normalize(new_cells)

            if can_fit(new_shape, n, m):
                next_shapes.add(new_shape)

    return next_shapes


def solve():
    k, n, m = map(int, input().split())

    initial = set()

    for i in range(n):
        row = list(map(int, input().split()))

        for j in range(m):
            if row[j] == 1:
                initial.add((i, j))

    # 初始棋子不是一个连通块
    if not is_connected(initial):
        print(-1)
        return

    # 初始棋盘没有棋子
    if len(initial) == 0:
        if k == 0:
            print(0)
            return

        # 第一个棋子放在哪里都等价
        current = {((0, 0),)}

        ans = 1

        # 已经用了 1 个棋子
        # 再枚举使用 2、3、...、k 个棋子
        for _ in range(1, k):
            current = expand(current, n, m)

            ans += len(current)

            if len(current) == 0:
                break

        print(ans)
        return

    # 初始棋盘本来就有棋子
    start = normalize(initial)

    current = {start}

    # 不增加棋子时，初始图形本身算一种
    ans = 1

    # 增加 1、2、...、k 个棋子
    for _ in range(k):
        current = expand(current, n, m)

        ans += len(current)

        if len(current) == 0:
            break

    print(ans)


def main():
    T = int(input())

    for _ in range(T):
        solve()


if __name__ == "__main__":
    main()
