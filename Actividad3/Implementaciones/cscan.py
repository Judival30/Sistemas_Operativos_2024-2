from collections import deque



def CSCAN(requests : list, headPos, diskSize = None):
    
    if diskSize == None:
        diskSize = max(requests)
    requests.sort()

    l, r = deque(), deque()
    for tr in requests:
        if tr < headPos:
            l.appendleft(tr)
        else:
            r.append(tr)
    dir =  abs(headPos - r[0]) <= abs(headPos - l[0])    
    sequence = []
    dis = 0

    # Movimiento hacia la derecha
    if dir:
        for tr in r:
            sequence.append(tr)
            dis += abs(headPos - tr)
            #print(headPos, " - ", tr)
            headPos = tr
        # Al llegar al final, empezar desde el 0 
        if len(l) != 0:
            dis += abs(headPos - (diskSize - 1))
            #print(headPos, " - ", (diskSize - 1))
            headPos = 0
            dis += diskSize - 1
            for tr in l:
                sequence.append(tr)
                dis += abs(headPos - tr)
                #print(headPos, " - ", tr)
                headPos = tr

    # Movimiento hacia la izquierda
    else:
        for tr in l:
            sequence.append(tr)
            dis += abs(headPos - tr)
            #print(headPos, " - ", tr)
            headPos = tr
        # Al llegar al principio, empezar en 0
        if len(r) != 0:
            dis += headPos 
            #print(headPos, " - ", (diskSize - 1))
            headPos = diskSize - 1
            dis += diskSize - 1
           
            for tr in r:
                sequence.append(tr)
                dis += abs(headPos - tr)
                #print(headPos, " - ", tr)
                headPos = tr

    return sequence, dis



requests = [12, 34, 52, 14,25,68,39]
head = 53
print("Solicitudes :", *requests)
print("Cabeza empieza en :", head)
sequence, total_distance = CSCAN(requests, head, 90)


print("Secuencia de atención de solicitudes:", *sequence)
print("Distancia total recorrida:", total_distance)