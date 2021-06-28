#!/usr/bin/python3

import os


def leetcode_url():
    for f in (f for f in os.listdir('.') if os.path.isfile(f) and f != 'leetcode_url.py'):
        problem = os.path.splitext(f)[0].lower()
        with open(f, 'r') as old:
            data = old.read()
        if "\n" in data and not "problem" in data.splitlines()[0].lower():
            with open(f, 'w') as new:
                if os.path.splitext(f)[1] == '.cpp' or os.path.splitext(f)[1] == '.rs':
                    new.write('/* Problem {}\n'.format(problem))
                    new.write(' * https://www.leetcode.com/problems/{}\n'.format(problem))
                    new.write(' */\n\n')
                elif os.path.splitext(f)[1] == '.py':
                    new.write('# Problem {}\n'.format(problem))
                    new.write('# https://www.leetcode.com/problems/{}\n\n'.format(problem))
                new.write(data)


if __name__ == "__main__":
    leetcode_url()
