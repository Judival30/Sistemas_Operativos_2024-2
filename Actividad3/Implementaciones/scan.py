from collections import deque



def SCAN(requests : list, headPos, diskSize = None):
    
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
        # Al llegar al final, invertir y moverse a la izquierda
        if len(l) != 0:
            dis += abs(headPos - (diskSize - 1))
            headPos = diskSize - 1
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
        # Al llegar al principio, invertir y moverse a la derecha
        if len(r) != 0:
            dis += headPos  # Mover al inicio del disco (pista 0)
            headPos = 0
            for tr in r:
                sequence.append(tr)
                dis += abs(headPos - tr)
                #print(headPos, " - ", tr)
                headPos = tr

    return sequence, dis


# Ejemplo de uso
requests = [12, 34, 52, 14,25,68,39]
head = 53
direction = True # True derecha - False izquierda
print("Solicitudes :", *requests)
print("Cabeza empieza en :", head)
sequence, total_distance = SCAN(requests, head, 90) 


print("Secuencia de atención de solicitudes:", *sequence)
print("Distancia total recorrida:", total_distance)
