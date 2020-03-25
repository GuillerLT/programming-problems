#!/usr/bin/python3

import os

for d in os.listdir('.'):
    if os.path.isdir(d):
        for f in os.listdir(d):
            if os.path.isfile(os.path.join(d, f)):
                problemset = d.lstrip("0")
                problem = os.path.splitext(f)[0].upper()
                if not "problem" in open(os.path.join(d, f)).readline().lower():
                    with open('tmp', 'w') as new, open(os.path.join(d, f)) as old:
                        if os.path.splitext(f)[1] == '.cpp' or os.path.splitext(f)[1] == '.rs':
                            new.write(
                                '/* Problemset {} - Problem {}\n'.format(problemset, problem))
                            new.write(
                                ' * https://codeforces.com/problemset/problem/{}/{}\n'.format(problemset, problem))
                            new.write(' */\n\n')
                        elif os.path.splitext(f)[1] == '.py':
                            new.write(
                                '# Problemset {} - Problem {}\n'.format(problemset, problem))
                            new.write(
                                '# https://codeforces.com/problemset/problem/{}/{}\n\n'.format(problemset, problem))
                        new.write(old.read())
                    os.rename('tmp', os.path.join(d, f))
