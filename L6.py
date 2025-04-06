import re
import itertools


# ex 2
def generate_words(alphabet, max_len):
    words = set()
    for i in range(1, max_len + 1):
        for p in itertools.product(
            alphabet, repeat=i
        ):  # generaza toate combinatile posibile de litere de lungime i
            words.add("".join(p))
    return words


# Helper: filter words that match regex
def language_from_regex(regex, alphabet, max_len):
    pattern = re.compile(f"^{regex}$")
    all_words = generate_words(alphabet, max_len)
    return set(
        filter(lambda w: pattern.match(w), all_words)
    )  # returnam doar cuvintele care match-uiesc pattern ul dorit


# 5 operatiuni
def union(L1, L2):
    return L1 | L2


def intersection(L1, L2):
    return L1 & L2


def difference(L1, L2):
    return L1 - L2


def concatenation(L1, L2):
    return set(a + b for a in L1 for b in L2)


def kleene_star(L, max_iters=3):
    result = {""}
    for i in range(1, max_iters + 1):
        for combo in itertools.product(L, repeat=i):
            result.add("".join(combo))
    return result


if __name__ == "__main__":
    alphabet = input("Introdu alfabetul (ex: ab): ").strip()
    max_len = int(input("Lungime maxima a cuvintelor generate: "))

    regex1 = input("Regex pentru L1: ").strip()  # whitespace remover
    regex2 = input("Regex pentru L2: ").strip()

    L1 = language_from_regex(regex1, alphabet, max_len)
    L2 = language_from_regex(regex2, alphabet, max_len)

    while True:
        print("\n--- Meniu ---")
        print("1. Reuniune (L1 U L2)")
        print("2. Intersecție (L1 ∩ L2)")
        print("3. Diferență (L1 - L2)")
        print("4. Concatenare (L1 · L2)")
        print("5. Kleene Star (L1*)")
        print("6. Afișare L1 și L2")
        print("0. Ieșire")

        opt = input("Selectează opțiunea: ")

        if opt == "1":
            print("L1 U L2 =", union(L1, L2))
        elif opt == "2":
            print("L1 ∩ L2 =", intersection(L1, L2))
        elif opt == "3":
            print("L1 - L2 =", difference(L1, L2))
        elif opt == "4":
            print("L1 · L2 =", concatenation(L1, L2))
        elif opt == "5":
            print("L1* =", kleene_star(L1))
        elif opt == "6":
            print("L1 =", L1)
            print("L2 =", L2)
        elif opt == "0":
            break
        else:
            print("Opțiune invalidă.")


# ex1.1
# 0i1j i>j

# alegem un cuvant care sa apartina lb. s=0^(p+1)1^p /
# i=p+1, j=p, deci i>j
# |s|=(p+1)+p = 2p+1 >= p

# w=xyz
# x=0k xy^iz
# y=0m , m>0 //neaparat un 0 a.i. sa fie |0| > |1|
# z=0^(p+1-k-m)1p // am scazut k si m deoarece am consumat k si m in xy
# aplicam i = 0 , xy^0z = xz = 0^(p+1-m)1^p (dupa calcul complet se simplifica k)
# nr de 0 uri = 0^(p+1-m)
# nr de 1 : p
# p+1-m <= p => i<= j // m nu e 0 deci daca scadem e mai mic (i era p+1 din care scadem un m > 0 deci nu mai e i =p+1 ca va fi i=p+1-(>0) ))
# deci xz nu apartine L deci nu e lb regulat.
