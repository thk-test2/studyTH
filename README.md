### 목적
- 공부한 내용, 문제 해결방법 등 기록하기

### 공부 주제
- 알고리즘 문제
- 프로그래밍 언어: Cpp, Python, Qt 등
- 빌드 시스템
- 컴퓨터 구조
- SW 설계 및 최적화

### 기타
- 마크다운 [문법](https://gist.github.com/ihoneymon/652be052a0727ad59601)
    - *기울이기*
    - **강조**
    - ~~cancelline~
    - [링크](https://google.com)
    - `quote`
    - > BlockQuote
       ```c++
        코드 
       ```
    - 지수: 2<sup>n</sup>

## 220322
1. BOJ 9663: N-Queen [문제](https://www.acmicpc.net/problem/9663)
    - Algorithm: 백트래킹, DP
    - Idea
        - 백트래킹의 대표적인 문제라고 한다. 처음에는 단순히 경우의 수를 세어보려고 했지만 어림 없었다. 위키피디아를 참고 했다.
    - Solve
        1. 위키 코드에서는 아래로 한 행씩 늘려가며 탐색한다. 퀸은 가로/세로/대각을 공격할 수 있기 때문에, 각각 다른 행에 놓아야 한다.
            - 그래서 y의 값과 놓여진 퀸의 개수가 같다. 종료 조건은 `y == N` 이 된다.
        2. 백트래킹 기본 형태에 따라 유망하지 않은 경우를 가지치기한다.
            - y-1 행까지 탐색하며 세로와 대각에 퀸이 배치되어 있는지 확인한다.
        3. 2번 과정을 통과했다면 y번째 줄의 j번째 칸에 퀸을 놓는 것이 가능하다. 유망한 경우이므로 탐색한다.
    - 백트래킹 기본 개념
        1. 알고리즘
            1. 상태 공간 트리를 DFS로 탐색
            2. 방문 중인 노드가 유망한지 체크
            3. 만약 유망하지 않으면, 부모 노드로 되돌아감(backtrack)
        2. 기본 형태
            ```c++
                void checknode(node v)
                {
                    node u;
                    if (promising(v))
                        if (v에 해답이 있으면)
                            해답을 출력;
                        else
                            for (v의 모든 자식 노드 u에 대해서)
                                checknode(u);
                 }
            ```

## 220321
1. 노트: 백트래킹과 DP 기본기를 확실히 다지기로 하였다.

2. BOJ 15654: N과 M (5) [문제](https://www.acmicpc.net/problem/15654)
    - Algorithm: 백트래킹
    - Idea: 배열에 입력값을 받아 정렬 후 순열을 구해준다. 재귀로 순열을 구하는 기본적인 문제

3. BOJ 15663: N과 M (9) [문제](https://www.acmicpc.net/problem/15663)
    - Algorithm: 백트래킹
    - Idea
        - 입력값은 중복이 있을 수 있지만, 한번 출력한 조합은 더 이상 출력하지 말아야 한다.
        - 최적화에 대한 고민이 필요한 문제.
    - Solve
        - 최초 접근방식은 printed 벡터를 두어 한번 출력한 값을 저장하고, 다음에 printed를 확인하여 중복 출력을 막는 것이었다.
            - 확인용 벡터를 써야 하므로 메모리가 추가로 필요하고 불필요한 연산이 들어가는 느낌이 있었다.
        - 두번째 접근은 각 재귀단계에서 prev 변수를 두어 이전에 선택한 것은 건너뛰게 하는 것이다. 재귀 마지막까지 가서 확인하는 불필요한 작업이 없어진다.
            - 기본적인 selected[] 외에 prev 변수를 추가로 확인하는 것.

4. BOJ 11727: 2×n 타일링 2 [문제](https://www.acmicpc.net/problem/11727)
    - Algorithm: DP
    - Idea: 기본적인 관계식을 구하는 문제.
    - Solve
        - 처음에 관계식을 잘못 구했다. `memo[i] = memo[i-1]*memo[1]*2 + memo[i-2]*memo[2]*2 + ... + memo[i/2]*memo[i/2]*2`
            - 위 수식은 중복된 경우를 따지게 된다.
        - memo[i]를 memo[i-1]와 memo[i-2]에서 만드는 방법을 생각해보자.
            1. memo[i-1]에서 1만큼 늘어났고, 1x2 타일을 쓰는 방법밖에 없다.
            2. memo[i-2]에서 2만큼 늘어났고, 1x2 타일 2장을 쓰는 방식은 memo[i-1]과 중복된다.<br/>가능한 경우는 2x1 타일 2장과 2x2 타일 1장을 쓰는 2가지가 존재한다.
            3. 수식을 정리하면 `memo[i] = memo[i-1] + memo[i-2]*2`

## 220318
1. BOJ 11286: 절댓값 힙 [문제](https://www.acmicpc.net/problem/11286)
    - Algorithm: 자료구조, 우선순위 큐
    - Idea
        - 기본 우선순위 큐 구현 + 커스텀 노드의 우선순위를 판별한다.
    - Solve
        1. 문제의 조건에 맞게 비교함수를 구현할 것
        2. 그 외에는 똑같다. insert()에서는 마지막 노드에서 parent로 올라가며 탐색. <br/> pop()은 1번 노드를 저장하고 마지막 노드를 1번 노드로 옮긴 후 재배치.
        3. 특정 노드를 갱신하는 **update**를 연습해야 한다.

2. 07_bitwise_1_basic
    - Algorithm: Bitwise 연산 연습
    - 간단한 정리
        1. `t1 |= (1 << n)`: t1의 n번째 bit를 1로 바꾼다.
        2. `t1 &= ~(1 << n)`: t1의 n번째 bit를 0으로 바꾼다.
        3. `t1 ^= (1 << n)`: t1의 n번째 bit을 토글.
        4. `(t1 >> n) & 1`: t1의 n번째 bit가 1인지 판별.
        5. STL bitset을 사용해도 됨. 
            - `bit.set(2)`: 2번째 bit를 1로 set
            - `bit.reset(2)`: 2번째 bit를 0으로 set
            - `bit.flp()`: 모든 bit 반전
            - `bit.to_ulong()`: unsigned long 값을 반환

3. SWEA 2112: 보호 필름 [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu)
    - Algorithm: 백트래킹, 구현
    - Idea
        - 특정 line을 0또는 1로 칠해가며 모든 경우의 수를 탐색
    - Solve
        1. check(): 현재 film의 상태가 합격할 수 있는 상태인지 확인하는 함수
        2. testColumn(): 조합을 재귀로 구현한다. 각 line을 0, 1로 칠하는 경우의 수를 따진다. 
            - 칠하기 전에 해당 column을 저장해두고 다시 복원한다. 전체 array를 저장하는 것은 낭비.
            - check()를 호출하여 통과할 수 있는지 확인한다.

4. BOJ 10844: 쉬운 계단 수 [문제](https://www.acmicpc.net/problem/10844)
    - Algorithm: DP
    - Idea
        - 계단수 길이를 하나씩 늘어날때, 마지막 숫자는 이전 수 마지막 숫자와 1씩 차이가 나는 것을 이용
    - Solve
        1. dp[i][j]: i번째 계단수가 j로 끝날 때 개수. 0과 9를 제외하고 다음과 같은 규칙이 있다.
            - `dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]`
            - 0 일때는 `dp[i][j] = dp[i-1][j-1]` : 1에서 오는 경우만 있다.
            - 9 일때는 `dp[i][j] = dp[i-1][j+1]` : 8에서 오는 경우만 있다.
        2. 초기값 dp[1][1~9] 는 전부 1이고, dp[1][0]은 0이다. 이후 위 수식에 의해 계산한다.

5. SWEA 3234: 준환이의 양팔저울 [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWAe7XSKfUUDFAUw)
    - Algorithm: 백트래킹, DP
    - Idea
        - **조건**: 왼쪽 추들의 합계보다 오른쪽이 작거나 같아야 한다.
        - 추를 하나하나 조건에 맞게 놓으면서, 반복되는 계산을 `memo[]`에 기록하여 다시 계산하지 않도록 한다.
    - Solve
        1. 각 재귀 함수 안에서 1번 ~ N번 추를 확인하여 왼쪽 + 가능하면 오른쪽에 배치한다.
        2. 재귀 단계가 N번째에 도달하면 모든 추를 놓은 것이므로 1개의 경우의 수가 확인된 것이다. 1을 리턴한다.
            - 재귀의 리턴값을 이전 재귀에서 합산하여 다시 리턴하는 것을 반복한다.
        3. 반복되는 계산?
            - 단계가 진행될 때, 나머지 추들을 배치하는 것은 계산이 반복된다.
            - 추 1, 2, 4가 있다고 하자. 맨 처음 4를 왼쪽에 배치하고, 이후 1, 2를 배치하는 것은 최초 한번만 계산하면 되는 것이다.
            - 위의 결과를 현재 단계, 추의 state를 인자로 하는 memo[] 배열에 기록하여 재활용 하면 된다.
            - `memo[9][520][520]`: 추가 최대 9개 이므로 첫번째 인자는 단계, 두번째 세번째 인자는 각 단계에서 왼쪽, 오른쪽 추의 state를 bit로 나타낸 것이다.

## 220317
1. SWEA 1808: 지희의 고장난 계산기 [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4yC3pqCegDFAUx)
    - Algorithm: 백트래킹
    - Idea
        - 숫자만 눌러서 만들 수 있으면 바로 리턴, 아니면 재귀를 통한 탐색
    - Solve
        1. makeNums(): 누를 수 있는 숫자들을 조합하여 만들 수 있는 숫자들을 구하고, 누른 횟수를 made[]에 저장한다.
        2. calculate(): made[] 배열로 나눠간다. 나눠지면 made[i] 숫자만큼 더하고 곱하기 횟수를 반영한다. N이 1이되면 성공
        3. 참고한 솔루션과 다른 것은 calculate에서 나누기를 N/2부터 시작하는 것이다. <br/>`N/2 < i < N` 값은 나머지가 0이 될 수 없기 때문

2. BOJ 11659: 구간 합 구하기 4 [문제](https://www.acmicpc.net/problem/11659)
    - Algorithm: 세그먼트 트리
    - Idea
        - 세그먼트 트리 기본문제. 입력받을 때 누적합을 구하는 dp 접근 방식도 있는것 같다.
    - Solve
        1. makeTree(): 재귀로 leaf node에 도착한 뒤 tree[idx] 값 입력. 돌아오면서 합으로 채워짐
        2. getSum(): start, end가 찾고자 하는 범위 내에 있으면 바로 tree[idx] 리턴, 아니면 탐색
        3. update(): 문제에서 요구하는 것은 아니지만 테스트 용도로 넣음. leaf node에 도착하여 값 업데이트하고 돌아오면서 부모들도 업데이트.

## 220316
1. 수정내용
    - 폴더 구조, 레거시 파일들 정리
    - 공부한 것 README에도 기록하기

2. SWEA 6731: 홍익이의 오델로 게임 [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWefzFeq5P8DFAUh)
    - Algorithm: N/A
    - Idea
        - 모든 경우의 수를 탐색하는 백트래킹으로 생각했지만, 경우의 수가 너무 많고 가지치기 조건이 생각나지 않았다.
    - Solve
        1. 구글링을 통해 뒤집은 지점에서 해당 행,열의 흑돌의 개수를 세었을 때 홀수가 된다는 사실을 알았다.
        2. 따라서 2차원 배열을 돌면서 홀수인 지점을 선택해주면 된다. 솔루션의 출처를 참고.