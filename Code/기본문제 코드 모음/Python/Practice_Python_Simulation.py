"""
1. 아이디어
- while 문으로 특정 조건 종료될 때까지 반복
- 4방향을 for문으로 탐색
- 더이상 탐색이 불가능할 경우, 뒤로 한칸 후진
- 후진이 불가능하면 종료

2. 시간복잡도
- O(NM) : 50^2 = 2500 < 2억 >> 가능

3. 자료구조
- map : int[][]
- 로봇청소기 위치, 방향, 전체 정소한 곳 수

"""

import sys
input = sys.stdin.readline

N, M = map(int, input().split()) # 가로 세로 크기
y, x, d = map(int, input().split()) # y, x, 방향
map = [list(map(int, input().split())) for _ in range(N)]
cnt = 0

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

while 1:
    # 청소가 안된 경우만 청소하도록
    if map[y][x] == 0:
    # 현재 위치 청소
        map[y][x] = 2
        cnt += 1
    sw = False
    # 4방향 확인
    for i in range(1, 5):
        # 내가 바라보는 방향
        ny = y + dy[d - i]
        nx = x + dx[d - i]
        if 0 <= ny < N and 0 <= nx < M:
            if map[ny][nx] == 0:
                # 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.

                # dy, dx 범위 초과로 인한 수정 -> 1 ~ 4까지의 숫자로 조정
                d = (d - i + 4 ) % 4
                y = ny
                x = nx
                sw = True
                break

    # 4방향 모두 있지 않은 경우
    if sw == False:
        # 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
        ny = y - dy[d]
        nx = x - dx[d]
        if 0 <= ny < N and 0 <= nx < M:
            if map[ny][nx] == 1:
                break
            else:
                y = ny
                x = nx
        else:
            break
print(cnt)