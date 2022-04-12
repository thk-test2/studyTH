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
    - ~~cancelline~~
    - [링크](https://google.com)
    - `quote`
    - > BlockQuote
       ```c++
        코드 
       ```
    - 지수: 2<sup>n</sup>

## 220412
1. BOJ 2075: N번째 큰 수 [문제](https://www.acmicpc.net/problem/2075)
    - Algorithm: 자료 구조, 정렬, 우선순위 큐
    - Idea
        - 최대 힙에 다 때려넣고 N번 pop을 해서 찾으면 된다고 생각함. 그러나 메모리 초과
    - Solve
        1. 최소 힙에 넣으면서 힙의 사이즈가 N 이상이면, 새로 들어온 숫자와 top()을 비교
        2. top() 보다 크면 pop() 을 수행하고 새로 들어온 숫자를 삽입
        3. 배열 순회 완료후에 최소 힙의 top()이 N번째 큰 숫자가 된다.

## 220411
1. BOJ 19236: 청소년 상어 [문제](https://www.acmicpc.net/problem/19236)
    - Algorithm: 시뮬레이션, 백트래킹
    - Idea
        - 백트래킹에 여러 조건을 달아 고려할 것이 많은 문제
        - 맵 자체는 4x4여서 DP 최적화 없이 DFS로 탐색하면 된다.
    - Solve
        1. 한 사이클은 다음과 같이 구성된다.
            - 물고기들 이동 -> 상어가 가능한 물고기를 잡아먹고, 자리를 차지한다. 
            - 방향은 먹은 물고기의 방향을 갖게 된다.
        2. 물고기를 1번부터 순서대로 이동시켜야 하기 때문에, 맵 배열 외에 추가로 Fish 배열을 사용하였다.
            - Fish 배열의 각 원소는 물고기 위치, 방향, 생존 여부(valid)를 담고 있다.
            - 상어가 잡아먹으면 valid = false.
            - 맵 배열은 Fish 배열의 id를 담고 있다.
        3. 물고기들은 이동할 곳에 상어만 없으면 이동이 가능하다.
            - 물고기가 없음을 표시하기 위해 '0'으로 맵을 마킹하는 것이 불필요하다.
        4. 상어는 해당 방향에 valid를 체크하여 물고기를 잡아먹고 진행한다.
            - 진행 전후로 Fish 배열과 맵 배열을 status를 저장하고 **복원**해준다.
        5. 더 이상 먹을 것이 없으면 최대값을 체크하고 갱신해준다.
            - 여기서도 당연히 배열들의 status를 복원해준다.
            - 맵을 복원하지 않고 리턴하였다가 버그 찾는데 매우 오랜 시간이 걸렸다.

2. BOJ 1406: 에디터 [문제](https://www.acmicpc.net/problem/1406)
    - Algorithm: 자료 구조, 스택, 연결 리스트
    - Idea
        - 메모리 풀 방식의 연결 리스트를 구현(노가다)해주었다. (48 ms)
        - **STL List**로도 구현이 가능하며, 시간이 약간 더 걸린다. (68 ms)
        - 2 개의 **Stack**으로 구현한 코드를 보니 시간이 더 빨랐다. (44 ms)

## 220410
1. BOJ 15829: Hashing [문제](https://www.acmicpc.net/problem/15829)
    - Algorithm: 문자열, 해싱
    - Idea: hash 값을 구하는 문제
    - Solve: 문자열에 31을 곱해 더해나갈때 매번 modular 연산으로 overflow가 나지 않도록 한다.

2. BOJ 3033: 가장 긴 문자열 [문제](https://www.acmicpc.net/problem/3033)
    - Algorithm: 문자열, 해싱, 라빈-카프
    - Idea
        1. 2번 이상 등장하는 부분 문자열의 길이를 이분탐색으로 찾는다.
        2. 시간 복잡도: 이분탐색: O(L*logL) + 2번 이상 등장하는지 check: O(L)
    - Solve
        1. low = 0, high = L-1 에서 시작하여 이분 탐색을 수행한다.
        2. 현재 mid(부분 문자열의 길이)에 대해 문자열 전체를 순회한다.
            - 한 글자씩 이동하면서 Hash에 없으면 추가하고, 이전 것을 발견하면 2번 이상 등장하는 것이므로 True를 리턴
            - 여기서 라빈-카프 알고리즘의 Rolling Hash 기법을 사용한다. 라빈-카프 설명은 [링크](https://m.blog.naver.com/ndb796/221240679247)를 참고.
        3. 이분 탐색을 계속 수행하여 가능한 mid의 최대 값을 구한다.
        4. **Note**
            - 가능한 부분 문자열이 많기 때문에 string을 hash에 담으면 메모리가 overflow 된다.(unordered_map도 마찬가지)
            - 문자열을 char 배열로 입력받고, hash에 해당 문자열 주소를 담는 방식을 사용하였다.

3. SWEA 8382: 방향 전환 [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWyNQrCahHcDFAVP)
    - Algorithm: BFS 또는 계산
    - Idea: BFS로 구현하거나, 규칙을 찾아 계산을 해주면 된다.
    - Solve
        - BFS
            1. x좌표, y좌표, 이동방향, 이동횟수를 관리하는 node를 선언한다.
            2. BFS로 진행하는데 항상 목표지점으로 다가가도록 가지치기 한다.
                - 현재 좌표와 목표 좌표를 비교하여 진행 방향을 결정한다.
        - 규칙을 찾아서 계산
            1. 제약 조건: 이전에 가로 이동을 했으면 이번에는 세로 이동을 해야 한다. 반대도 마찬가지.
            2. 가로-세로 이동을 번갈아 해야하기 때문에 다음 규칙이 생긴다.
                - 현재 좌표와 목표 좌표를 연결했을 때, 기울기가 1이면 일반 BFS와 다를 것이 없다.<br/>
                  가로-세로 또는 세로-가로 반복해서 가면 되기 때문.
                - 기울기가 1이 아니라면 해당 좌표로 가기위해 다른 방향으로 2번씩 이동이 추가된다.<br/>
                  기울기 1과의 격차를 계산해서 격차 * 2 만큼 더해준다.

## 220409
1. BOJ 11000
    - Algorithm: 정렬, PQ
    - Idea
        - 정렬과 PQ를 이용한 문제
        - 시간 복잡도: O(N*logN) = vector에 데이터 삽입 O(1*N) + vector 정렬 O(N*logN) + PQ를 이용한 쿼리 처리 O(N*logN)
    - Solve ([풀이 참고](https://velog.io/@soosungp33/BOJ-11000%EB%B2%88-%EA%B0%95%EC%9D%98%EC%8B%A4-%EB%B0%B0%EC%A0%95C))
        1. 시작 시간을 기준으로 오름차순으로 정렬해준다.
        2. PQ를 오름차순으로 설정해주고, 첫 강의가 끝나는 시간을 넣어준다.
        3. 나머지 강의를 확인하면서 조건에 따라 PQ를 컨트롤한다.
            - 모든 강의실 중에 가장 빨리 끝나는 강의실을 선택한다. (**q.top()**)
            - 해당 강의실이 끝나기 전에 현재 강의가 시작되면(q.top()>s), 강의실을 하나 늘려준다. (**q.push(t)**)
            - 해당 강의실이 끝난 후에 강의가 시작되면(q.top()<=s), 강의실을 늘릴 필요 없이 그 강의실에서 강의를 시작한다. (**q.pop(), q.push(t)**)
        4. 최종적으로 남아있는 강의실의 개수를 출력한다.(**q.size()**)

## 220408
1. BOJ 11660: 구간 합 구하기 5 [문제](https://www.acmicpc.net/problem/11660)
    - Algorithm: Prefix Sum
    - Idea
        - Prefix Sum은 누적합을 구해놓고 특정 구간의 합을 빠르게 구하는 유형이다.
    - Solve
        1. 2차원 배열의 누적합을 구해 놓는다.<br/>
        `sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];`
        2. 특정 구간합을 구하는 수식. 2차원 공간의 면적을 구하는 것과 동일하다.<br/>
        `answer = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];`

2. BOJ 11003: 최솟값 찾기 [문제](https://www.acmicpc.net/problem/11003)
    - Algorithm: O(N):Deque / O(NlogN): Priority Queue, Seg Tree
    - Idea
        - O(N*logN)이면 아슬아슬하고 O(N)이어야 넉넉히 풀리는 문제
        - O(N*logN)이 왜 안 될 수 있는지 [다음 글](https://www.acmicpc.net/board/view/36198)을 읽어보자.
        - 개인적으로 PQ 문제들이 다양한 접근방식을 고민하기에 좋은것 같다.<br/>
        - PQ, Multi PQ, Seg Tree, Deque, Hash 등 다양하게 생각해보자.
    - Solve
        - PQ방식
            1. 큐에 값과 index를 같이 넣는다.
            2. top()의 index가 윈도우를 벗어나있으면 pop()하고 다음걸 확인한다.
        - Deque 방식
            1. PQ 방식처럼 큐에 값과 index를 같이 넣는다.
            2. front()의 index가 윈도우를 벗어나있으면 들어올 때까지 pop() 해준다.
            3. back()의 값이 새로 들어온 쿼리보다 크면 작을 때 까지 pop()하고 새 쿼리를 넣는다.
            4. front()의 값이 최소값이 된다.

## 220407
1. SWEA 1257: K번째 문자열 [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18KWf6ItECFAZN)
    - Algorithm: 문자열, 조합
    - Idea
        - 모든 문자열 조합을 구하는 방법을 사용했다.
        - LCP(Longest Common Prefix)를 활용하는 방법이 있다고 한다.
    - Solve
        - 모든 문자열 조합을 구해서 set에 넣으면 자동 정렬이 되고 중복도 제거된다. 이후 K번째 문자열을 구한다.
        - 문자열 조합을 만들 때 재귀말고 **반복문**으로 구현하는 방법도 있다는 것을 알아두자.
            ```C++
                for (int i = 0; i < str.size(); ++i) {
                    string temp = { str[i] };
                    s.insert(temp);
                    for (int j = i + 1; j < str.size(); ++j) {
                        temp += str[j];
                        s.insert(temp);
                    }
                }
            ```

2. BOJ 9612: Maximum Word Frequency [문제](https://www.acmicpc.net/problem/9612)
    - Algorithm: Hash
    - Idea: unordered_map을 활용하거나 직접 구현하여 Hash에 key-value를 저장한다.
    - Solve
        1. str을 입력받아서 unordererd_map에 추가하며 value를 증가시켜 준다.
            - `m[str]++`
        2. 해당 str의 value가 기존 최대값보다 크고 사전순으로 나중이면 최대값과 정답 str을 갱신해준다.
        3. 주의할 것은 key가 없어도 m[key]를 하면 해당 pair가 생성된다.
            - m.count(key)를 써서 검사하고 m[key]로 값을 확인하자.
            - unordered_map은 중복을 허용하지 않는다. m.count(key)는 해당 key가 존재하면 1을, 없으면 0을 리턴한다.

## 220406
1. SWEA 4340: 파이프 연결 [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWL6LhM6A60DFAUY)
    - Algorithm: 백트래킹, DP
    - Idea
        - 파이프를 돌릴 수 있다는 것은, 같은 타입의 파이프를 모두 사용할 수 있다는 것을 의미한다.
        - 들어온 방향에 따라 어떻게 이동이 되는지 생각한다.
            1. 직선 파이프는 들어온 방향이 유지 된다.
            2. 구부러진 파이프는 들어온 방향에서 왼쪽이나 오른쪽으로 가게된다.
    - Solve
        1. 가지치기 전에 먼저 틀을 구현해준다. 재귀함수의 파라미터는 i와 j좌표, 현재까지의 길이, 들어온 방향이다.
        2. 들어온 방향과 현재 파이프 타입을 고려하여 다음 방향으로 탐색을 수행한다.
            - 구부러진 파이프는 좌우로 나갈 수 있다. 방향 배열 또는 enum과 로직을 활용하여 다음 방향을 결정하자.
            - 목표에 도착하면 최소 길이를 갱신한다.
        3. 가지치기를 생각해보자.(어렵다..)
            1. `memo[i][j][inputDir]`: 현재 좌표와 나가는 방향을 인자로 하는 memo 배열 활용하여 현재 길이가 더 크면 리턴.
                - 이를 위해 지나는 path를 저장하고, 목표에 도달시 지나온 경로의 memo 배열에 기록해줘야 한다.
            2. 현재까지의 길이와, 기존 최소길이를 비교한다. 그리고 **현재 길이+도달할 수 있는 가장 빠른 길이**가 기존 최소길이보다 크면 더 진행할 필요가 없다.
                ```C++
                    int left = N * 2 - i - j + 1;
                    if (length + left >= minLength) return;
                ```

## 220404
1. BOJ 9252: LCS 2 [문제](https://www.acmicpc.net/problem/9252)
    - Algorithm: DP
    - Idea: memo 배열을 만드는 것도 문제지만, LCS를 어떻게 도출할지 고민해야 함.
    - Solve
        1. memo 배열 만들기
            1. 문자열A, 문자열B의 한글자씩 비교해봅니다.
            2. 두 문자가 다르다면 LCS[i - 1][j]와 LCS[i][j - 1] 중에 큰값을 표시합니다.
            3. 두 문자가 같다면 LCS[i - 1][j - 1] 값을 찾아 +1 합니다.
            4. 위 과정을 반복합니다.
        2. 최장 공통 부분 문자열 찾기
            1. LCS 배열의 가장 마지막 값에서 시작합니다. 결과값을 저장할 result 배열을 준비합니다.
            2. LCS[i - 1][j]와 LCS[i][j - 1] 중 현재 값과 같은 값을 찾습니다.
                - 만약 같은 값이 있다면 해당 값으로 이동합니다.
                - 만약 같은 값이 없다면 result배열에 해당 문자를 넣고 LCS[i -1][j - 1]로 이동합니다.
            3. 2번 과정을 반복하다가 0으로 이동하게 되면 종료합니다. result 배열의 역순이 LCS 입니다.
        3. 구글에 **그림으로 알아보는 LCS 알고리즘** 설명을 읽어보자.

2. BOJ 1987: 알파벳 [문제](https://www.acmicpc.net/problem/1987)
    - Algorithm: 백트래킹
    - Idea: 백트래킹 기본기 점검을 위한 문제.
    - Solve
        - 방문한 곳을 다시 방문하지 않도록 visited를 사용하고,
        - 한번 지나간 알파벳도 다시 사용하지 않도록 alphabet 배열을 추가로 사용한다.
        - 다시 돌아와서 탐색할 때 visited와 alphabet을 false로 해야 다른 경우의 수를 탐색할 수 있다.

## 220403
1. SWEA 1798: 범준이의 제주도 여행 계획 [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4x9oyaCR8DFAUx)
    - Algorithm: 백트래킹
    - Idea: 백트래킹 수행 중 따져야 할 것이 많은 문제
    - Solve
        1. 관광지와 그 외의 것들로 구분해서 관리하는 것이 편하다.
        2. 허용된 시간(540분) 안에서 관광지를 최대한 돌고 540이 초과되면 호텔이나 공항을 선택한다.
            - M번째 날엔 공항을, 그 외에는 호텔을 선택한다.
        3. 최대 만족도를 계속 갱신해준다.

2. SWEA 8189: 우편함 [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWwtU7XqhL0DFAWU)
    - Algorithm: 구현
    - Idea: 시간을 1씩 증가시키면서 문제의 조건에 맞게 구현한다.
    - Solve
        1. 메일함을 확인하는 조건은 설정한 메일함의 용량에 도달했을 때, 그리고 메일 수령 이후 특정 시간이 지났을 때이다.
            - 메일함을 확인할 때는 절반만 확인해준다.
        2. `while` 문 안에서 시간을 증가시키면서 구현해주자.

3. BOJ 11437: LCA [문제](https://www.acmicpc.net/problem/11437)
    - Algorithm: Lowest Common Ancestor
    - Idea: 좀 더 공부를 하고 업데이트 할 것.

4. BOJ 11066: 파일 합치기 [문제](https://www.acmicpc.net/problem/11066)
    - Algorithm: DP
    - Idea: `memo` 배열의 인자와 채워나가는 순서를 고민해야 하는 문제
    - Solve
        1. memo 배열은 2차원으로, 첫번째는 합치는 범위의 시작 index, 두번째는 종료 index 이다.
        2. 재귀나 for 문의 기법을 사용해서 가장 작은 단위부터 memo 배열을 채워 나간다.
            - 가장 작은 단위는 연속된 파일이다. ex) memo[0][1] / memo[3][4]
            - 연속된 파일을 합치는 것은 더해주기만 하면 된다.
        3. 합치는 범위를 늘려가면서 하위 범위의 값들을 비교하여 최소값을 선택해준다.
            - for문이 좀 더 빠르니 하위 범위의 값을 먼저 구하는 기법을 알아두자. 이중 for문을 써서 바깥에서 range를 1씩 늘려가는 것이다.
                ```c++
                  // range
                  for(int r = 1; r < k; r++)
                    // start
                    for(int s = 0; s + r < k; s++) {
                      // end
                      int e = s + r;
                      ...
                      for(int k = s; k < e; k++)
                        dp[s][e] = min(dp[s][e], ...
                    }
                ``` 

5. BOJ 11049: 행렬 곱셈 순서 [문제](https://www.acmicpc.net/problem/11049)
    - Algorithm: DP
    - Idea: 위 **파일 합치기** 문제와 비슷함. 더해줘야 하는 offset만 다르다.

## 220401
1. SWEA 6855: 신도시 전기 연결하기 [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWhUBBUqQO0DFAW_)
    - Algorithm: Sort
    - Idea
        - 도시 간 거리가 높은 곳부터 발전소를 배치하자.
        - PS에서 **정렬**이 쓰이는 경우가 많다. 아이디어가 떠오르지 않으면 정렬을 생각해보자.
    - Solve
        1. 도시의 위치를 입력 받은 후, 도시 간 거리를 구해서 배열에 저장한다.
        2. 도시 간 거리를 정렬한 다음, 뒤에서 K개는 발전소를 배치할 것이기 때문에 `N-K` 까지의 거리를 합산한다.

## 220331
1. SWEA 7701: 염라대왕의 이름 정렬 [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWqU0zh6rssDFARG)
    - Algorithm: Hash, Priority Queue
    - Idea: 우선순위 큐의 우선순위 조정을 할 수 있으면 된다. 
    - Solve
        - 우선순위 조정을 위한 struct 선언: 길이가 짧은 것이 우선순위가 높고, 길이가 같으면 사전 순서가 앞인 것이 우선순위가 높다.
        - Hash를 이용해 중복된 원소가 삽입되지 않도록 한다.

## 220330
1. SWEA 1227: 미로2 [문제](https://swexpertacademy.com/main/code/problem/problemSolver.do?contestProbId=AV14wL9KAGkCFAYD)
    - Algorithm: BFS
    - Idea: 맵을 탐색하여 목표 지점에 도착할 수 있는지 확인하는 문제.
        - N이 **10~20** 이면 **DFS나 BFS** 사용 가능
        - N이 **30~100** 이면 **BFS**일 가능성이 큼
        - visited 배열 등, 배열 초기화시 memset을 사용하자. for문보다 빠르게 초기화 가능
    - Solve
        - 일반적인 BFS로 모든 맵을 탐색해주면 된다.
        - 참고로 공백이 있는 string을 cin으로 입력받는 방법을 알아두자.
            - `#include <string>` 하여 `getline(cin, str);`을 사용한다.
        - cin 함수들 알아둘 것
            - `cin.clear()`: cin 객체의 *내부 상태 플래그* 를 초기화시켜 cin 관련 기능이 정상동작 하도록 함
            - `cin.fail()`: cin 오류시 1을 반환하고 아니면 0을 반환함
            - `cin.ignore()`: 입력 버퍼에 있는 모든 내용을 추출해서 버림

2. SWEA 7988: 내전 경기 [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWvQZmdKUoEDFASy)
    - Algorithm: 이분 그래프, Hash
    - Idea: 노드를 탐색하며 **이분 그래프** 기법으로 팀을 나누어 본다.
    - Solve
        1. 노드의 값이 string이기 때문에 hash를 사용하여 int로 변환해 준다. (string - key)
            - 인접 노드 벡터를 선언하여 변환된 int에 맞게 입력을 받는다.
        2. 이분 그래프 탐색을 진행하며 색을 번갈아서 칠한다.
            - 색을 번갈아 칠한다는 것은 **인접한 노드들을 자신과 반대의 색으로 칠한다는 의미**이다.
            - visit 배열은 0, 1, 2의 상태를 가져야 하기 때문에 int로 선언해야 한다. 0은 미방문, 1과 2는 다른 팀을 의미.
            - dfs로 탐색을 진행하며, 자신은 **color**로, 인접 노드들은 **3 - color**로 색칠해 준다. 최초 color 값은 1.
        3. 색칠을 끝내고 다시 한번 그래프를 탐색하여 인접노드와 자신의 색이 같은 경우가 있는지 검사한다. 없으면 성공.

## 220328
1. BOJ 1655: 가운데를 말해요 [문제](https://www.acmicpc.net/problem/1655)
    - Algorithm: Priority Queue
    - Idea: 최대 힙과 최소 힙을 활용하여 최대 힙의 top이 가운데 값을 유지하게 한다.
    - Solve
        1. 최대 힙의 크기는 최소 힙의 크기와 같거나, 하나 더 크다.
        2. 최대 힙의 최대 원소는 최소 합의 최소 원소보다 작거나 같다.
        3. 이때 알고리즘에 맞지 않다면 최대 힙, 최소 힙의 가장 위의 값을 swap해준다.

2. BOJ 12865: 평범한 배낭 [문제](https://www.acmicpc.net/problem/12865)
    - Algorithm: DP
    - Idea: DP 배열의 차원과 의미에 대해 고민해야 하는 문제. 구글링으로 해결..
    - Solve
        1. DP의 핵심이 되는 memo 배열을 어떻게 구성할지 생각해본다.
            - 모든 아이템의 상태를 저장하려면 100 bit가 필요하여 불가능하다.
            - `memo[A][B] = C` : A번째 아이템까지 왔고, 가방의 무게가 B일 때 가방의 물건들의 가치는 C 이다.
        2. 모든 아이템의 상태를 저장할 수 없기 때문에, for 문 2개가 필요하다.
            - 바깥의 for문은 탐색하는 물건 순서이다.
            - 안쪽의 for문은 1부터 최대 가능한 무게 K 까지를 탐색한다.
        3. 바깥 for문은 물건을 순서대로 탐색하고, 안쪽 for문에서는 memo[i][j]의 의미를 생각하여 값을 계산한다.
            1. `memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - W[i]] + V[i]);`
                - memo[i-1][j]의 의미는 **기존에 탐색했던 물건들로만 무게 j를 만드는 경우**를 의미한다.
                - memo[i-1][j-W[i]]의 의미는 기존에 탐색했던 물건들로 무게 j-W[i]를 만들고, **현재 물건을 가방에 넣는 경우** 를 의미한다.
                - 즉, 현재 물건을 넣을지 안 넣을지에 대해서 판단해주는 부분이다.
            2. `memo[i][j] = memo[i-1][j]` 
                - else에 해당하는 부분은 현재 무게를 넣을 수 없는 경우이다. 

3. SWEA 2115: 벌꿀채취 [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V4A46AdIDFAWu)
    - Algorithm: 백트래킹
    - Idea: 백트래킹을 꼭 재귀로만 구현할 필요 없다는 것을 다시 확인한 문제.
        - 선택 대상이 적거나, 혹은 너무 많아서 *스택 오버플로우* 가 발생한다면 for문으로 구현해야 한다.
    - Solve
        1. 2명의 일꾼이 작업하는 범위는 가로로 배치되며, 겹치지 않아야 한다.
            - 2명으로 제한되기 때문에 재귀로 구현하는 것 보다는 for문 2개가 간편하다.
            - 두번째 일꾼이 일할 때 최초 루프는 ax+M에서 시작하고 이후 루프에서는 0에서 부터 탐색해야 한다. 기법을 알아두자.
        2. 이제 일하는 범위를 정했다면 각 범위내에서 최대 가치를 얻는 값을 구해야 한다.
            1. 주어진 무게 안에서 최대의 가치를 얻는 **배낭** 문제와 같다. 배낭 문제는 **DP** 로 구현한다.
            2. 하지만 최대 무게가 30이고, 일할 수 있는 최대 벌통의 개수가 5개이므로 조합으로 값을 구해도 된다.

## 220326
1. BOJ 1038: 감소하는 수 [문제](https://www.acmicpc.net/problem/1038)
    - Algorithm: 백트래킹
    - Idea: 감소하는 수를 만드는 것이 은근히 까다로웠던 문제. 감소하는 수의 **최대값**이 무엇일지 생각해보자.
    - Solve
        1. 감소하는 수의 최대값은 **9876543210** 이다.
        2. 지저분한 방법
            1. 숫자 조합을 만드는데, 자리수를 하나씩 늘려가면서 감소하는 수인지 체크한다.
                - 처음 호출부에서 자리수를 하나씩 증가시켜야 하며, `selected[]`을 쓰고 매번 초기화를 해야 한다.
            2. 재귀 안에서 for loop을 돌 때 i = 0 부터 증가시키는 것은 가지치기 조건을 생각하기 까다롭다.
        3. 간단한 방법
            1. 재귀 안에서 for loop을 돌때 **i = 9 부터 내려오면서** `now % 10` 보다 작으면 감소하는 수를 만들고 다음 단계로 넘어간다.
                - 다음 수: `now * 10 + i`
            2. N번째 값을 출력한다. vector의 size보다 더 크면 -1 출력.
        4. 백트래킹에서 **STL의 활용과 반복문을 유연하게 생각할 필요**가 있다. 고정된 형태가 아니다.

2. BOJ 7662: 이중 우선순위 큐 [문제](https://www.acmicpc.net/problem/7662)
    - Algorithm: Priority Queue
    - Idea: 우선순위 큐 구현에 매몰되지 말고 STL을 잘 활용하자.
    - Solve
        1. 우선순위 큐 2개(최소 힙과 최대 힙)을 준비한다. 구현을 해도 되고, 굳이 update가 필요없다면 STL을 사용한다.
            1. Push 할 때 두개의 힙에 모두 Push 해준다. check 배열을 하나 두고 count를 1씩 증가시킨다.
                - 같은 값이 들어올 수 있기 때문에 check 배열은 bool이 아니라 int여야 한다.
            2. Max 값 제거시 **최대 힙의 front 원소가 invalid**(check 배열이 false) 하면 제거해준다. 그리고 check 배열의 해당 원소 count를 1감소 시킨다.
            3. Min 값 제거시 최소 힙의 front 원소가 invalid 하면 제거해준다. 그리고 check 배열의 해당 원소 count를 1 감소 시킨다.
            4. 연산이 끝나고 출력 전에 다시 invalid한 값들을 모두 제거해준다.
        2. 간단한 방법: multi set을 쓰면 끝난다.

3. BOJ 1305: 광고 [문제](https://www.acmicpc.net/problem/7662)
    - Algorithm: KMP
    - Idea: 현재 광고판에서 가능한 가장 짧은 패턴을 찾아내는 문제. 옆으로 이동한다는 가정은 신경쓸 필요가 없다.
    - Solve
        1. KMP 알고리즘에서 pattern의 prefix와 postfix가 일치하는 길이를 테이블에 기록하는데, 이를 **Fail Table**이라고 한다.
            - pattern의 원소를 처음부터 하나씩 늘려가며 prefix와 postfix가 일치하는 최대 길이를 테이블의 원소로 기록한다.
        2. 몇 가지 광고판의 Fail Table을 생각해보자. 
            - `aaaaa` -> table은 `0, 1, 2, 3, 4` 가 된다.
            - `abcd` -> table은 `0, 0, 0, 0` 이 된다.
            - `aabaaa` -> table은 `0, 1, 0, 2, 2` 가 된다.
        3. 어떤 경우든 string의 길이에서 table의 마지막 값을 빼면 가능한 pattern의 최소 길이가 된다.

## 220324
1. BOJ 10971: 외판원 순회 2 [문제](https://www.acmicpc.net/problem/10971)
    - Algorithm: 백트래킹, DP
    - Idea: 일반적인 백트래킹으로도 풀 수 있지만, **DP를 이용하여 최적화** 할 수 있는 문제.
    - Solve
        1. 평범한 방식: 모든 노드를 방문한 후, 최초 시작 지점으로 갈 수 있는지 확인하여 최소값을 갱신한다.
            -  visited 배열을 써서 다시 방문하지 않고, cost[current][i]가 0인 경우를 가지치기 해주었다.
        2. 최적화를 위해 DP 방식을 생각해보자.
            1. 일단 방문한 노드들의 state는 **bit masking**으로 나타낼 수 있다. visited 대신
            2. 그리고 **한번 더** 가지치기 할 수 있는 경우가 있다.
                - 1>2>3>4>1과 2>3>4>1>2 는 자세히 보면 **같은 값**을 가지게 된다. 3>4>1>2>3 도 마찬가지이다.
                - 따라서 전체적인 순서가 같다면 **1번에서 출발한 경우**만 따지면 된다.
            3. 마지막으로 memo 배열을 사용해서, 같은 bit state와 같은 current 노드일때는 이후의 계산을 하지 않는다.
                - memo의 차원은 2차원으로, 최대 경우의 수로 선언하면 `memo[1<<10][10]`가 될 것이다. (최대 10개의 노드)
                - 각 단계의 state를 기록하는 **bit masking**에 익숙해지자.
            4. 이전에 다룬 SWEA 3234 준환이의 양팔 저울과 유사한 접근방식이다.

2. BOJ 2193: 이친수 [문제](https://www.acmicpc.net/problem/2193)
    - Algorithm: DP
    - Idea: memo 배열을 **2차원**으로 생각해본다.
    - Solve
        1. 규칙: 1이 2번 연속 나타날 수 없다.
        2. *i번째에서 0으로 끝나는 이친수* 를 생각해 보자.
            - `memo[i][0] = memo[i-1][0] + memo[i-1][1]`
            - i-1에서 0으로 끝나는 경우와 1로 끝나는 경우를 합한 경우의 수가 된다.
        3. *i번째에서 1로 끝나는 이친수* 는 규칙에 따라 i-1에서 0으로 끝나는 경우의 수만 가능하다.
            - `memo[i][1] = memo[i-1][0]`
        4. N번째 까지 계산한 후 `memo[N][0] + memo[N][1]` 값을 출력한다.

3. BOJ 1904: 01타일 [문제](https://www.acmicpc.net/problem/1904)
    - Algorithm: DP
    - Idea: N이 2, 3, 4의 경우를 따져보고 규칙을 찾아보자.
    - Solve
        1. 이친수와 비슷하지만 약간 다르다. 1은 제한이 없고 0은 2개씩 붙여서 사용해야 한다.
        2. memo[i]와 memo[i-1] 관계를 생각해보자.
            - 길이가 단 1개 차이이므로 memo[i-1]에서 맨 앞에 1을 붙이는 경우가 된다.
            - 즉, `memo[i] = memo[i-1] + 알파`
        3. 이제 알파를 찾아보자. memo[i]와 memo[i-2] 관계가 될 것이다.
            - 길이가 2개 차이이므로 00을 붙이거나 11, 10을 붙이는 경우의 수가 될 것이다.
            - 하지만 00 외에는 2번 memo[i-1] 경우의 수와 중복된다.
            - 따라서 `memo[i] = memo[i-1] + memo[i-2]`. 즉 피보나치 수열이 된다.
        4. N이 최대 1,000,000 이므로 숫자가 매우 커지게 된다. 문제에서 요구한대로 계산할 때 모듈러 15746를 이용한다.

## 220323
1. BOJ 14889: 스타트와 링크 [문제](https://www.acmicpc.net/problem/14889)
    - Algorithm: 백트래킹
    - Idea: 짝수 사람들을 두 팀으로 나누고 능력치를 합산하여 능력치 차가 최소가 되도록 한다.
    - Solve
        1. `N/2`의 사람들을 선택하면 나머지는 자동으로 다른 팀이 된다. 이렇게 하여 시도했지만 시간 초과가 났다.
            - 각 경우의 수에서 사람번호를 찍어보니 **중복으로 선택되는 경우**가 있었다.
            - 1번을 선택한 상태에서 나머지 조합을 구한 다음에, index를 증가하여 이후 경우의 수를 구하면 1번에서 선택된 경우를 다시 따지게 된다.
            - 다시 말하면 **1번을 포함한 상태에서 나머지 조합만을 구하거나, 2번 부터의 조합을 구하면 된다**는 것이다.
            - *팀 구분없이 능력치 최소값* 만 구하면 되기 때문.
        2. 더 시간을 줄일 수 있던 것은 *능력치를 합산하는* 부분이었다.
            - 나는 재귀로 팀에서 2명씩 선택하는 조합을 구현했는데, **2개의 for문**으로도 2명씩 합산하는 것을 구현할 수 있었다.
            - **이중 for문**이 반드시 좋다고 할 수 없지만, 나처럼 조합을 만드는 재귀 안에서 또 능력치 합산을 위한 재귀를 추가하는 것보다 빨랐다.(1700ms > 60ms)

2. BOJ 11053: 가장 긴 증가하는 부분 수열 [문제](https://www.acmicpc.net/problem/11053)
    - Algorithm: DP
    - Idea: i번째 최대값 `best[i]`를 계속 갱신하여 답을 찾는다. 원소의 개수가 1000개 이하여서 **이중 for문**으로 가능하다.
    - Solve
        1. i 이전까지 가장 긴 값을 j를 이용해 탐색한다.
        2. `arr[i] > arr[j]` 이면 현재의 최대값 `best[i]`과 `best[j]+1` 을 비교하고 더 크면 갱신한다.
        3. `best[]`의 원소 중 최대값을 출력한다.

3. BOJ 12015: 가장 긴 증가하는 부분 수열 2 [문제](https://www.acmicpc.net/problem/12015)
    - Algorithm: DP, Binary search
    - Idea: 원소의 개수가 백만개이므로 이중 for문으로는 시간초과가 난다.
        - 이번엔 실제로 증가하는 부분수열을 만들어 본다.
    - Solve
        1. 부분 수열을 만들기 위한 **vector**나 배열을 준비하고 **0번째 숫자**를 넣는다.
        2. i를 증가시키며 vector의 **마지막 값**과 비교하여 더 크면 맨 뒤에 추가한다.
        3. 크지 않다면 **binary search**를 이용해 vector의 **마지막 바로 이전 값**보다 크거나 같은 곳에 덮어쓴다.
            - 이 경우 마지막 값을 덮어쓸 수 있는데, 어짜피 길이는 같다.
            - 그리고 마지막 값보다 작은 수로 갱신하므로 이후 탐색시 **더 긴 수열**이 될 수 있다.
        4. 탐색을 완료 후 부분 수열의 길이를 출력한다. 
            - for문 하나와 binary search를 활용하므로 `O(NlogN)`의 시간복잡도를 갖는다.

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
