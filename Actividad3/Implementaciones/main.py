from cscan import CSCAN
from scan import SCAN
from sys import stdin

def main():
    n = int(stdin.readline().strip())
    for i in range(n):
        print("Case #%d:" % (i + 1))
        head = int(stdin.readline().strip())
        request = list(map(int, stdin.readline().strip().split()))
        sequence, dis = CSCAN(request, head)
        print("CSAN Results: Move %d, sequence" % dis)
        
        sequence, dis = SCAN(request, head)
        print("SAN Results: Move %d, sequence" % dis)
       
main()
