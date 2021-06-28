#!/usr/bin/python3

import os

def readme():
    def count_folder(dir):
        count = 0
        for e in (e for e in os.listdir(dir)):
            e = dir + "/" + e
            if os.path.isdir(e):
                count += count_folder(e)
            elif os.path.isfile(e) and "_url." not in e:
                count += 1
        return count

    platforms_count = dict()
    for d in (d for d in os.listdir("./problems/") if os.path.isdir("./problems/" + d)):
        platforms_count[d] = count_folder("./problems/" + d)
    platforms_count = sorted(platforms_count.items(), key=lambda plat_count: plat_count[1], reverse=True)

    with open("README.md", "w") as README:
        README.write("Platform | # solutions\n")
        README.write("-------- | -----------\n")
        total = 0
        for (plat, count) in platforms_count:
            total += count
            README.write("{} | {}\n".format(plat, count))
        README.write("**Total** | {}\n".format(total))

if __name__ == "__main__":
    readme()
