import os

languages_comment = {
    ".cpp": ("/*", " *", " */"),
    ".rs":  ("/*", " *", " */"),
    ".c":   ("/*", " *", " */"),
    ".py":  ("#", "#", ""),
}

platforms_url = {
    "codechef":     ("https://www.codechef.com", "/{0}/problems/{1}"),
    "codeforces":   ("https://codeforces.com",   "/problemset/problem/{0}/{1}"),
    "kattis":       ("https://open.kattis.com",  "/problems/{0}"),
    "leetcode":     ("https://www.leetcode.com", "/problems/{0}"),
    "projecteuler": ("https://projecteuler.net", "/problem={0}"),
    "uva":          ("https://onlinejudge.org",  "/external/{1}/{0}.pdf"),
}


# Default
def create_url_0(plat: str, dir: str, file: str):
    return ""

# CodeChef & Codeforces
def create_url_1(plat: str, dir: str, file: str):
    return (
        "{0} Contest {{0}} - Problem {{1}}\n"
        "{1} {3}{4}\n"
        "{2}\n\n"
    ).format(
        *languages_comment.get(os.path.splitext(file)[-1], ("", "", "")),
        *platforms_url.get(plat, ("", "{}{}"))
    ).format(
        dir.lstrip("0").upper(),           # Contest
        os.path.splitext(file)[0].upper()  # Problem
    )

# Kattis & LeetCode & Project Euler
def create_url_2(plat: str, dir: str, file: str):
    return (
        "{0} Problem {{0}}\n"
        "{1} {3}{4}\n"
        "{2}\n\n"
    ).format(
        *languages_comment.get(os.path.splitext(file)[-1], ("", "", "")),
        *platforms_url.get(plat, ("", "{}{}"))
    )

# UVa Online Judge
def create_url_3(plat: str, dir: str, file: str):
    return (
        "{0} Problem {{0}}\n"
        "{1} {3}{4}\n"
        "{2}\n\n"
    ).format(
        *languages_comment.get(os.path.splitext(file)[-1], ("", "", "")),
        *platforms_url.get(plat, ("", "{}{}"))
    ).format(
        os.path.splitext(file)[0].lstrip("0"),
        os.path.splitext(file)[0].lstrip("0")[0:-2]
    )


platforms_url_creator = {
    "codechef":     create_url_1,
    "codeforces":   create_url_1,
    "kattis":       create_url_2,
    "leetcode":     create_url_2,
    "projecteuler": create_url_2,
    "uva":          create_url_3,
}


def add_url_file(root: str, plat: str, dir: str, file: str):
    with open(os.path.join(root, plat, dir, file), 'r') as old:
        data = old.read()
    if not platforms_url.get(plat, ("", "{}{}"))[0] in data:
        with open(os.path.join(root, plat, dir, file), 'w') as new:
            new.write(platforms_url_creator.get(plat, create_url_0)(plat, dir, file))
            new.write(data)



def add_url_plat(root: str, plat: str, dir: str):
    for entry in os.listdir(os.path.join(root, plat, dir)):
        if os.path.isdir(os.path.join(root, plat, dir, entry)):
            add_url_plat(root, plat, os.path.join(dir, entry))
        elif os.path.isfile(os.path.join(root, plat, dir, entry)):
            add_url_file(root, plat, dir, entry)


def add_url(root: str):
    for plat in os.listdir(root):
        if os.path.isdir(os.path.join(root, plat)):
            add_url_plat(root, plat, "")


if __name__ == "__main__":
    add_url("solutions")
