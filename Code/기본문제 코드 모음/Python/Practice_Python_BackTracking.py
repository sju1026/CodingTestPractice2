"""
1. 아이디어
- 백트래킹 재귀함수 안에서, for 돌면서 숫자 선택(이때 방문여부 확인)
- 재귀함수에서 M개를 선택할 경우 print

2. 시간복잡도
- N! > 10까지 가능 문제 = 8 까지 >> 가능

3. 자료구조
- 결과값 저장 int[]
- 방문여부 체크 bool[]

"""

import sys
input = sys.stdin.readline

N, M = map(int, input().split())
rs = []
chk = [False] * (N+1) # 결과값 출력시 N - 1을 해주는 것 방지 => 1로 바로 인덱스 접근이 가능하게 하기 위해

def recur(num):
    if num == M:
        # 결과값 print시 string으로 변경 후 출력
        print(' '.join(map(str, rs))) 
        return
    for i in range(1, N+1):
        if chk[i] == False:
            chk[i] = True
            rs.append(i)
            recur(num + 1)
            chk[i] = False
            rs.pop()

# 모든 경우를 확인하기 때문에 동작 X
# 트리구조로 생각했을 때 마지막을 빼주는 동작이 필요
    # 빼는 동시에 방문여부도 다시 돌려주어야 함
recur(0)
