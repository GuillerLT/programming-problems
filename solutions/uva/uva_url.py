#!/usr/bin/python3

import os


def uva_url():
    for f in (f for f in os.listdir('.') if os.path.isfile(f) and f != 'uva_url.py'):
        problem = os.path.splitext(f)[0].lstrip("0")
        prefix = problem[0:-2]
        with open(f, 'r') as old:
            data = old.read()
        if "\n" in data and not "problem" in data.splitlines()[0].lower():
            with open(f, 'w') as new:
                if os.path.splitext(f)[1] == '.cpp' or os.path.splitext(f)[1] == '.rs':
                    new.write('/* Problem {}\n'.format(problem))
                    new.write(' * https://onlinejudge.org/external/{}/{}.pdf\n'.format(prefix, problem))
                    new.write(' */\n\n')
                elif os.path.splitext(f)[1] == '.py':
                    new.write('# Problem {}\n'.format(problem))
                    new.write(' * https://onlinejudge.org/external/{}/{}.pdf\n'.format(prefix, problem))
                new.write(data)


if __name__ == "__main__":
    uva_url()
