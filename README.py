import os
from typing import Dict

platforms_name = {
    "adventofcode": "Advent of Code",
    "codechef":     "CodeChef",
    "codeforces":   "Codeforces",
    "ctci":         "Cracking the Coding Interview",
    "hackerearth":  "HackerEarth",
    "kattis":       "Kattis",
    "leetcode":     "LeetCode",
    "projecteuler": "Project Euler",
    "uva":          "UVa Online Judge",
}

languages_name = {
    ".cpp": "C++",
    ".cxx": "C++",
    ".hpp": "C++",
    ".hxx": "C++",
    ".rs":  "Rust",
    ".c":   "C",
    ".h":   "C",
    ".py":  "Python",
}


def get_freq_lang(root: str, plat: str, dir: str) -> Dict[str, int]:
    freq_lang = dict()
    for entry in os.listdir(os.path.join(root, plat, dir)):
        if os.path.isdir(os.path.join(root, plat, dir, entry)):
            for (lang, freq) in get_freq_lang(root, plat, os.path.join(dir, entry)).items():
                freq_lang[lang] = freq_lang.get(lang, 0) + freq
        elif os.path.isfile(os.path.join(root, plat, dir, entry)):
            lang = os.path.splitext(entry)[-1]
            freq_lang[languages_name.get(lang, lang)] = freq_lang.get(languages_name.get(lang, lang), 0) + 1
    return freq_lang


def get_freq_lang_plat(root: str) -> Dict[str, Dict[str, int]]:
    freq_lang_plat = dict()
    for plat in os.listdir(root):
        if os.path.isdir(os.path.join(root, plat)):
            freq_lang_plat[platforms_name.get(plat, plat)] = get_freq_lang(root, plat, "")
    return freq_lang_plat


def gen_readme(freq_lang_plat: Dict[str, Dict[str, int]]):
    with open("README.md", "w") as README:
        # Platforms
        README.write("# Platforms\n")
        README.write("Platform | # solutions\n")
        README.write("-------- | -----------\n")
        for (plat, freq) in sorted(
            ((plat, sum(freq_lang.values()))
             for (plat, freq_lang) in freq_lang_plat.items()),
            key=lambda plat_freq: plat_freq[1],
            reverse=True
        ):
            README.write("{} | {}\n".format(plat, freq))
        README.write("**Total** | {}\n\n".format(
            sum(sum(freq_lang.values())
                for freq_lang in freq_lang_plat.values())
        ))

        # Solutions per language
        README.write("# Languages\n")
        README.write("Language | # solutions\n")
        README.write("-------- | -----------\n")
        for (lang, freq) in sorted(
            ((lang, sum(freq_lang.get(lang, 0)
                        for freq_lang in freq_lang_plat.values()))
             for lang in set(lang
                             for freq_lang in freq_lang_plat.values()
                             for lang in freq_lang.keys())),
            key=lambda lang_freq: lang_freq[1],
            reverse=True
        ):
            README.write("{} | {}\n".format(lang, freq))
        README.write("**Total** | {}\n\n".format(
            sum(
                sum(freq_lang.values())
                for freq_lang in freq_lang_plat.values()
            )
        ))


if __name__ == "__main__":
    gen_readme(get_freq_lang_plat("solutions"))
