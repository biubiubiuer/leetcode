from typing import List


def permutation(s: str) -> List[str]:
    def dfs(begin, path):
        if begin == size:
            res.append(path)
            return
        for i in range(size):
            if not used[i]:
                if i > 0 and s[i] == s[i - 1] and not used[i - 1]:
                    continue
                used[i] = True
                path += s[i]
                dfs(begin + 1, path)
                path = path[:len(path) - 1]
                used[i] = False

    size = len(s)
    if size == 0:
        return []

    res = []
    used = [False] * 9

    dfs(0, "")
    return res


def main():
    s = input()
    res = permutation(s)
    print(res)


if __name__ == "__main__":
    main()
