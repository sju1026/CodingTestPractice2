"""
1. 아이디어
- 투포인터 활용
- for문으로, 처음 K개 값을 저장
- 다음 인덱스 더해주고, 이전 인덱스 빼줌
- 이때마다 최대값을 갱신

2. 시간복잡도
- O(N) = 1e5 > 가능

3. 자료구조
- 각 숫자들 N개 저장 배열 : int[]
    - 숫자들 최대 100 > int 가능
- K개의 값을 저장 변수 : int
    - 최대 : K * 100 = 1e5 * 100 = 1e7 >> int 가능
- 최대값 : int

"""
import sys
input = sys.stdin.readline

N, K = map(int, input().split())
nums = list(map(int, input().split()))
# K개를 더해주는 변수
each = 0

# K 개를 더해주기
for i in range(K):
    each += nums[i]
maxv = each

# 다음 인덱스 더해주고, 이전 인덱스 빼주기
for i in range(K, N):
    each += nums[i]
    each -= nums[i - K]
    maxv = max(maxv, each)

print(maxv)
