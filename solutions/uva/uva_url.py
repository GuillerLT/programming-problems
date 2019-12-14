import os

for f in os.listdir('.'):
    if os.path.isfile(f) and f != 'uva_url.py':
        problem = os.path.splitext(f)[0].lstrip("0")
        prefix = problem[0:-2]
        if not "problem" in open(f).readline().lower():
            with open('tmp', 'w') as new, open(f) as old:
                if os.path.splitext(f)[1] == '.cpp':
                    new.write(
                        '/* Problem {}\n'.format(problem))
                    new.write(
                        ' * https://onlinejudge.org/external/{}/{}.pdf\n'.format(prefix, problem))
                    new.write(' */\n\n')
                elif os.path.splitext(f)[1] == '.py':
                    new.write(
                        '# Problem {}\n'.format(problem))
                    new.write(
                        '# https://onlinejudge.org/external/{}/{}.pdf\n'.format(prefix, problem))
                new.write(old.read())
                os.rename('tmp', os.path.join(f))
