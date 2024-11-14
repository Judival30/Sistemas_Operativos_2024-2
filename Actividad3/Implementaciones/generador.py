import random

def main():
    ncases = 100
    print(ncases)
    for i in range(100):
        head = random.randint(0, 1000)
        request = [random.randint(0, 1000) for i in range(random.randint(0, 500))]
        print(head)
        print(*request)

main()