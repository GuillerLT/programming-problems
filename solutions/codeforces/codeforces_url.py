#!/usr/bin/python3

import os


def codeforces_url():
    for d in (d for d in os.listdir('.') if os.path.isdir(d)):
        for f in (f for f in os.listdir(d) if os.path.isfile(os.path.join(d, f))):
            problemset = d.lstrip("0")
            problem = os.path.splitext(f)[0].upper()
            with open(os.path.join(d, f), 'r') as old:
                data = old.read()
            if "\n" in data and not "problem" in data.splitlines()[0].lower():
                with open(os.path.join(d, f), 'w') as new:
                    if os.path.splitext(f)[1] == '.cpp' or os.path.splitext(f)[1] == '.rs':
                        new.write('/* Problemset {} - Problem {}\n'.format(problemset, problem))
                        new.write(' * https://codeforces.com/problemset/problem/{}/{}\n'.format(problemset, problem))
                        new.write(' */\n\n')
                    elif os.path.splitext(f)[1] == '.py':
                        new.write('# Problemset {} - Problem {}\n'.format(problemset, problem))
                        new.write('# https://codeforces.com/problemset/problem/{}/{}\n\n'.format(problemset, problem))
                    new.write(data)


if __name__ == "__main__":
    codeforces_url()
