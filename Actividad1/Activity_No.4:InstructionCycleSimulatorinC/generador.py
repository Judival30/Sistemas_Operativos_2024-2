import random

def generar_numeros_aleatorios(cantidad):
    memory = []
    used = []
    for num in range(200):
        key = "D" + str(num)
        memory.append(key)
 

    ins = ["SET", "LDR", "ADD",
           "INC", "DEC", "STR",
           "SHW"]
    show = ["ACC", "ICR", "MAR",
            "UC", "PC"]
    for _ in range(int(cantidad * 0.2)):
        dir = memory[random.randint(0, len(memory) - 1)]
        used.append(dir)
        num = random.randint(0, 100000)
        print("%s %5s %5d NULL NULL" % ("SET", dir, num))
    print("%s %5s NULL NULL NULL" % ("LDR", used[random.randint(0, len(used) - 1)]))
    for _ in range(int(cantidad * 0.8)):
        inst = ins[random.randint(0, len(ins) - 1)]
        if inst == "ADD":
            print(inst, end="  ")
            num = random.randint(1, 3)
            for i in range(num):
                print(used[random.randint(0, len(used) - 1)], end= " ")
            for i in range(3 - num + 1):
                print("NULL", end= " ")
            print()
        elif inst == "SHW":
            prop = random.randint(0, 10)
            if prop < 8:
                print("SHW %5s NULL NULL NULL" % (used[random.randint(0, len(used) - 1)]))
            else:
                print("SHW %5s NULL NULL NULL" % (show[random.randint(0, len(show) - 1)]))
        elif inst == "SET":
            dir = memory[random.randint(0, len(memory) - 1)]
            used.append(dir)
            num = random.randint(0, 100000)
            print("SET %5s %d NULL NULL" % (dir, num))
        elif inst == "STR":
            dir = memory[random.randint(0, len(memory) - 1)]
            used.append(dir)
            print("STR %5s NULL NULL NULL" % (dir))
        elif inst == "PAUSE":
            print("PAUSE NULL NULL NULL NULL")
        else:
            print("%s %5s NULL NULL NULL" % (inst, used[random.randint(0, len(used) - 1)]))
    print("END NULL NULL NULL NULL")

    
cantidad = int(input())
generar_numeros_aleatorios(cantidad)
 
