#!/usr/bin/python3

import os

for d in (d for d in os.listdir('.') if os.path.isdir(d)):
    for f in (f for f in os.listdir(d) if os.path.isfile(os.path.join(d, f))):
        contest = d.upper()
        problem = os.path.splitext(f)[0].upper()
        with open(os.path.join(d, f), 'r') as old:
            data = old.read()
        if "\n" in data and not "problem" in data.splitlines()[0].lower():
            with open(os.path.join(d, f), 'w') as new:
                if os.path.splitext(f)[1] == '.cpp' or os.path.splitext(f)[1] == '.rs':
                    new.write('/* Contest {} - Problem {}\n'.format(contest, problem))
                    new.write(' * https://www.codechef.com/{}/problems/{}\n'.format(contest, problem))
                    new.write(' */\n\n')
                elif os.path.splitext(f)[1] == '.py':
                    new.write('# Contest {} - Problem {}\n'.format(contest, problem))
                    new.write('# https://www.codechef.com/{}/problems/{}\n\n'.format(contest, problem))
                new.write(data)
