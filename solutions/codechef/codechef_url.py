import os

for d in os.listdir('.'):
    if os.path.isdir(d):
        for f in os.listdir(d):
            if os.path.isfile(os.path.join(d, f)):
                contest = d.upper()
                problem = os.path.splitext(f)[0].upper()
                if not "problem" in open(os.path.join(d, f)).readline().lower():
                    with open('tmp', 'w') as new, open(os.path.join(d, f)) as old:
                        if os.path.splitext(f)[1] == '.cpp':
                            new.write(
                                '/* Contest {} - Problem {}\n'.format(contest, problem))
                            new.write(
                                ' * https://www.codechef.com/{}/problems/{}\n'.format(contest, problem))
                            new.write(' */\n\n')
                        elif os.path.splitext(f)[1] == '.py':
                            new.write(
                                '# Contest {} - Problem {}\n'.format(contest, problem))
                            new.write(
                                '# https://www.codechef.com/{}/problems/{}\n\n'.format(contest, problem))
                        new.write(old.read())
                    os.rename('tmp', os.path.join(d, f))
