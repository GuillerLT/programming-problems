#!/usr/bin/python3

import os

for f in (f for f in os.listdir('.') if os.path.isfile(f) and f != 'projecteuler_url.py'):
    problem = os.path.splitext(f)[0].lstrip("0")
    with open(f, 'r') as old:
        data = old.read()
    if "\n" in data and not "problem" in data.splitlines()[0].lower():
        with open(f, 'w') as new:
            if os.path.splitext(f)[1] == '.cpp' or os.path.splitext(f)[1] == '.rs':
                new.write('/* Problem {}\n'.format(problem))
                new.write(' * https://projecteuler.net/problem={}\n'.format(problem))
                new.write(' */\n\n')
            elif os.path.splitext(f)[1] == '.py':
                new.write('# Problem {}\n'.format(problem))
                new.write('# https://projecteuler.net/problem={}\n\n'.format(problem))
            new.write(data)
