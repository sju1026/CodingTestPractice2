"""
1. 아이디어
- 2중 for => 값 1 && 방문 X => BFS
- BFS 돌면서 그림 개수 +1, 최대값을 갱신

2. 시간복잡도
- BFS : O(V+E) = O(V + 4V = 5V = 5m * 5n = 5(500 * 500))
- V : m * n
- E : v * 4
- V + E : 5 * 250000 = 100만 < 2억 >> 가능

3. 자료구조
- 그래프 전체 지도 : int[][]
- 방문 : bool[][]
- Queue(BFS)

"""
from collections import deque

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
map = [list(map(int, input().split())) for _ in range(n)]
chk = [[False] * m for _ in range(n)]

dy = [0, 1, 0, -1] # 우, 하, 좌, 위 순
dx = [1, 0, -1, 0]

# BFS 함수
def bfs(y, x):
    # 그림의 사이즈 구하기
    rs = 1 # result

    q = deque()
    # Queue에 넣기
    q.append((y, x))
    # Queue에 새로 들어가지 않을 때 까지 반복
    while q:
        # 각각의 Queue를 새로운 변수에 추가
        ey, ex = q.popleft()
        # 4방향(동, 서, 남, 북)으로 이동하면서 새로운 1이 존재하는지 확인
        for k in range(4):
            # 하나씩 추가하면서 확인
            ny = ey + dy[k]
            nx = ex + dx[k]
            # 그림의 사이즈 이상 넘어가는 것 방지
            if 0<=ny<n and 0<=nx<m:
                if map[ny][nx] == 1 and chk[ny][nx] == False:
                    rs += 1
                    chk[ny][nx] = True
                    q.append((ny, nx))
    return rs

cnt = 0 # 1이 연결되어 있는 수
maxv = 0 # 1로 연결된 것의 최대값

# 2중 for - y 후 x
for j in range(n):
    for i in range(m):
        if map[j][i] == 1 and chk[j][i] == False:
            # 방문을 True로 설정
            chk[j][i] = True
            # 전체 그림 갯수를 +1
            cnt += 1
            # BFS > 그림 크기를 구해주고
            # 최닷값 갱신
            maxv = max(maxv, bfs(j, i))

print(cnt) # Count 출력
print(maxv) # MaxValue 출력
