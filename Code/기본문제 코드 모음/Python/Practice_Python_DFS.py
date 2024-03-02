"""
1. 아이디어
- 2중 for, 값 1 && 방문X ==> DFS
- DFS를 통해 찾은 값을 저장 후 정렬해서 출력

2. 시간복잡도
- DFS : O(V + E)
- V, E : N^2, 4N^2
- V + E : 5N^2 ~= N^2 ~= 625 < 2억 >> 가능

3. 자료구조
- 그래프 저장 : int[][]
- 방문여부 : bool[][]
- 결과값 : int[]
"""

import sys
input = sys.stdin.readline

N = int(input())
map = [list(map(int, input().strip())) for _ in range(N)]
chk = [[False] * N for _ in range(N)]

result = []
each = 0 # 각각의 연산

dy = [0, 1, 0, -1] # 우, 하, 좌, 상
dx = [1, 0, -1, 0] # 시계 반대방향

def dfs(y, x):
    # 연속된 노드의 크기를 each를 사용
    global each
    each += 1
    # 각 노드에서 4방향을 전부 탐색
    for k in range(4):
        ny = y + dy[k]
        nx = x + dx[k]
        if 0<=ny<N and 0<=nx<N:
            if map[ny][nx] == 1 and chk[ny][nx] == False:
                chk[ny][nx] = True
                # 재귀호출 -> 4방향확인 후 있다면 있는 노드에서 다시 4방향확인
                # 이미 방문한 경우 확인 X
                dfs(ny, nx)

for j in range(N):
    for i in range(N):
        # 1인 동시에 방문 x
        if map[j][i] == 1 and chk[j][i] == False:
            # 방문 체크 표시
            chk[j][i] = True
            # 새로운 노드를 탐색할 때마다 크기를 0으로 초기화
            each = 0
            # DFS 로 크기 구하기
            # BFS : 함수 호출, 리턴값으로 크기
            dfs(j,i)
            # 크기를 결과 리스트에 넣기
            result.append(each)

result.sort()
print(len(result))
for i in result:
    print(i)