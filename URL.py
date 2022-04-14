import os

languages_comment = {
    ".cpp": ("/*", " *", " */"),
    ".rs":  ("/*", " *", " */"),
    ".c":   ("/*", " *", " */"),
    ".py":  ("#", "#", ""),
}

platforms_url = {
    "adventofcode": ("https://adventofcode.com", "/{year}/day/{day}"),
    "codechef":     ("https://www.codechef.com", "/{contest}/problems/{problem}"),
    "codeforces":   ("https://codeforces.com",   "/problemset/problem/{contest}/{problem}"),
    "kattis":       ("https://open.kattis.com",  "/problems/{problem}"),
    "leetcode":     ("https://www.leetcode.com", "/problems/{problem}"),
    "projecteuler": ("https://projecteuler.net", "/problem={problem}"),
    "uva":          ("https://onlinejudge.org",  "/external/{1}/{0}.pdf"),
}


# Default
def create_url_0(plat: str, dir: str, file: str):
    print(plat, dir, str)
    return ""

# Advent of Code
def create_url_1(plat: str, dir: str, file: str):
    return (
        "{0} Year {{year}} - Day {{day}}\n"
        "{1} {3}{4}\n"
        "{2}\n\n"
    ).format(
        *languages_comment[os.path.splitext(file)[-1]],
        *platforms_url[plat],
    ).format(
        year = dir.lstrip("0").upper(),                       # Year
        day  = os.path.splitext(file)[0].lstrip("0").upper()  # Day
    )

# CodeChef & Codeforces
def create_url_2(plat: str, dir: str, file: str):
    return (
        "{0} Contest {{contest}} - Problem {{problem}}\n"
        "{1} {3}{4}\n"
        "{2}\n\n"
    ).format(
        *languages_comment[os.path.splitext(file)[-1]],
        *platforms_url[plat],
    ).format(
        contest = dir.lstrip("0").upper(),            # Contest
        problem = os.path.splitext(file)[0].upper(),  # Problem
    )

# Kattis & LeetCode & Project Euler
def create_url_3(plat: str, dir: str, file: str):
    return (
        "{0} Problem {{problem}}\n"
        "{1} {3}{4}\n"
        "{2}\n\n"
    ).format(
        *languages_comment[os.path.splitext(file)[-1]],
        *platforms_url[plat],
    ).format(
        problem = os.path.splitext(file)[0].lower()  # Problem
    )

# UVa Online Judge
def create_url_4(plat: str, dir: str, file: str):
    return (
        "{0} Problem {{0}}\n"
        "{1} {3}{4}\n"
        "{2}\n\n"
    ).format(
        *languages_comment[os.path.splitext(file)[-1]],
        *platforms_url[plat],
    ).format(
        os.path.splitext(file)[0].lstrip("0"),
        os.path.splitext(file)[0].lstrip("0")[0:-2],
    )


platforms_url_creator = {
    "adventofcode": create_url_1,
    "codechef":     create_url_2,
    "codeforces":   create_url_2,
    "kattis":       create_url_3,
    "leetcode":     create_url_3,
    "projecteuler": create_url_3,
    "uva":          create_url_4,
}


def add_url_file(root: str, plat: str, dir: str, file: str):
    with open(os.path.join(root, plat, dir, file), 'r') as old:
        data = old.read()
    if plat in platforms_url_creator and not platforms_url[plat][0] in data:
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
