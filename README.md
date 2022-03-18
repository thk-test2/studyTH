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

## 220318
1. BOJ 11286: [문제](https://www.acmicpc.net/problem/11286)
    - Algorithm: 자료구조, 우선순위 큐
    - Idea
        - 기본 우선순위 큐 구현 + 커스텀 노드의 우선순위를 판별한다.
    - Solve
        1. 문제의 조건에 맞게 비교함수를 구현할 것
        2. 그 외에는 똑같다. insert()에서는 마지막 노드에서 parent로 올라가며 탐색. <br/> pop()은 1번 노드를 저장하고 마지막 노드를 1번 노드로 옮긴 후 재배치.
        3. 특정 노드를 갱신하는 **update**를 연습해야 한다.<br/><br/>
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
            - `bit.to_ulong()`: unsigned long 값을 반환<br/><br/>
3. SWEA 2112: [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu)
    - Algorithm: 백트래킹, 구현
    - Idea
        - 특정 line을 0또는 1로 칠해가며 모든 경우의 수를 탐색
    - Solve
        1. check(): 현재 film의 상태가 합격할 수 있는 상태인지 확인하는 함수
        2. testColumn(): 조합을 재귀로 구현한다. 각 line을 0, 1로 칠하는 경우의 수를 따진다. 
            - 칠하기 전에 해당 column을 저장해두고 다시 복원한다. 전체 array를 저장하는 것은 낭비.
            - check()를 호출하여 통과할 수 있는지 확인한다.<br/><br/>
4. BOJ 10844: [문제](https://www.acmicpc.net/problem/10844)
    - Algorithm: DP
    - Idea
        - 계단수 길이를 하나씩 늘어날때, 마지막 숫자는 이전 수 마지막 숫자와 1씩 차이가 나는 것을 이용
    - Solve
        1. dp[i][j]: i번째 계단수가 j로 끝날 때 개수. 0과 9를 제외하고 다음과 같은 규칙이 있다.
            - `dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]`
            - 0 일때는 `dp[i][j] = dp[i-1][j-1]` : 1에서 오는 경우만 있다.
            - 9 일때는 `dp[i][j] = dp[i-1][j+1]` : 8에서 오는 경우만 있다.
        2. 초기값 dp[1][1~9] 는 전부 1이고, dp[1][0]은 0이다. 이후 위 수식에 의해 계산한다.<br/><br/>
5. SWEA 3234: [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWAe7XSKfUUDFAUw)
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
1. SWEA 1808: [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4yC3pqCegDFAUx)
    - Algorithm: 백트래킹
    - Idea
        - 숫자만 눌러서 만들 수 있으면 바로 리턴, 아니면 재귀를 통한 탐색
    - Solve
        1. makeNums(): 누를 수 있는 숫자들을 조합하여 만들 수 있는 숫자들을 구하고, 누른 횟수를 made[]에 저장한다.
        2. calculate(): made[] 배열로 나눠간다. 나눠지면 made[i] 숫자만큼 더하고 곱하기 횟수를 반영한다. N이 1이되면 성공
        3. 참고한 솔루션과 다른 것은 calculate에서 나누기를 N/2부터 시작하는 것이다. <br/>`N/2 < i < N` 값은 나머지가 0이 될 수 없기 때문<br/><br/>
2. BOJ 11659: [문제](https://www.acmicpc.net/problem/11659)
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
    - 공부한 것 README에도 기록하기<br/><br/>
2. SWEA 6731: [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWefzFeq5P8DFAUh)
    - Algorithm: N/A
    - Idea
        - 모든 경우의 수를 탐색하는 백트래킹으로 생각했지만, 경우의 수가 너무 많고 가지치기 조건이 생각나지 않았다.
    - Solve
        1. 구글링을 통해 뒤집은 지점에서 해당 행,열의 흑돌의 개수를 세었을 때 홀수가 된다는 사실을 알았다.
        2. 따라서 2차원 배열을 돌면서 홀수인 지점을 선택해주면 된다. 솔루션의 출처를 참고.