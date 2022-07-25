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

## 220725
### LeetCode 34. Find First and Last Position of Element in Sorted Array: [Problem](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
- Algorithm: Array, Binary Search / Level: Medium
- Idea
    - 감소하지 않는 숫자 배열이 주어질 때, target number의 시작과 끝 index를 구하는 문제.
- Solve
    1. 먼저 stl::find로 target이 있는지 찾는다. 없으면 `{-1, -1}`을 리턴
    2. stl::lower_bound와 upper_bound로 iterator를 찾고, stl::distance를 써서 index를 구해준다.
- Complexity
    1. Time: O(N) = stl::find O(N) + lower_bound, upper_bound O(logN)
    2. Space: O(1) = 값 저장 변수 외에 추가 공간이 쓰이지 않는다.

### LeetCode 315. Count of Smaller Numbers After Self: [Problem](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)
- Algorithm: Array, Merge Sort / Level: Hard
- Idea
    - 숫자 배열이 주어질 때 각 원소의 오른쪽에 자신보다 작은 원소가 몇 개인지 세는 문제.
    - Counting Inversion 이라는 알고리즘을 사용한다.(다시 풀어볼 것)
- Solve [출처](https://www.geeksforgeeks.org/counting-inversions/)
    1. The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step until the base case is reached.
    2. Create a function merge that counts the number of inversions when two halves of the array are merged, create two indices i and j, i is the index for the first half, and j is an index of the second half.
        - if a[i] is greater than a[j], then there are (mid – i) inversions.
        - because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
    3. Create a recursive function to divide the array into halves and find the answer by summing the number of inversions is the first half, the number of inversion in the second half and the number of inversions by merging the two.
    4. The base case of recursion is when there is only one element in the given half.
    5. Print the answer
- Complexity
    1. Time: O(NlogN)
    2. Space: O(N)

## 220722
### LeeCode 407. Trapping Rain Water II: [Problem](https://leetcode.com/problems/trapping-rain-water-ii/)
- Algorithm: Array, BFS, Priority Queue, Matrix / Level: Hard
- Idea
    - 3차원의 맵이 주어질 때, 빗물이 고일 수 있는 영역크기 구하기.
    - 2차원일 때처럼 DP나 투 포인터로는 풀 수 없다.
- Solve: [참고](https://leetcode.com/problems/trapping-rain-water-ii/discuss/89496/Concise-C%2B%2B-method-with-explanation)
    - 우선순위 큐 + BFS 활용
        - 가장자리의 bar들 중 가장 낮은 높이부터 물을 채워 들어오는 개념이다.
        - 아래 예제를 보면, 2부터 출발하여 물을 채워 들어오면서 빗물을 계산한다.
            ```
              4 4 4 4      4 4 4 4
              4 0 1 2  =>  4 0 2 2
              4 4 4 4      4 4 4 4
            ```
- Complexity
    1. Time: O(MN * logMN) = MxN의 맵에 대한 BFS 탐색
    2. Space: O(MN + MN) = 우선순위 큐 + visited 배열

### LeetCode 86. Partition List: [Problem](https://leetcode.com/problems/partition-list/)
- Algorithm: Linked List, Two Pointers / Level: Medium
- Idea
    - 연결 리스트와 숫자 x가 주어질 때, x보다 작은 노드들은 x보다 크거나 같은 노드들보다 왼쪽에 배치하라.
    - 각 partition의 노드 들의 순서는 유지되어야 한다.
- Solve
    1. 리스트를 탐색하며 x보다 작은 노드들을 별도의 리스트로 구성한다.
    2. 기존 리스트의 왼편에 연결한다.
- Complexity
    1. Time: O(N) = 노드들을 loop 한번으로 탐색
    2. Space: O(1) = ListNode 포인터 외에 추가 공간 쓰이지 않음

## 220721
### LeetCode 92. Reverse Linked List II: [Problem](https://leetcode.com/problems/reverse-linked-list-ii/)
- Algorithm: Linked List / Level: Medium
- Idea
    - 연결 리스트와 left와 right 포지션이 주어질 때, left부터 right까지의 노드들을 역순으로 연결하라.
- Solve
    - 리스트 전체를 역순으로 연결하는 것은 다음 식을 리스트 끝까지 반복해주면 된다.
        - `node = new ListNode(val, node)`
        - 새 ListNode를 생성하고 node를 가리키게 한 다음, node를 새 ListNode로 당겨오는 것이다.
    - 따라서 3구간으로 나누어 위 수식을 left - right까지 적용 후 다시 연결하면 된다.
- Complexity
    1. Time: O(N)
    2. Space: O(N): 새 노드를 생성하는 방식이므로 추가 공간이 필요

## 220720
### LeetCode 792. Number of Matching Subsequences: [Problem](https://leetcode.com/problems/number-of-matching-subsequences/)
- Algorithm: Hash Table, String, Trie(?), Sorting / Level: Medium
- Idea
    - 문자열 s와 문자열 배열 words[]가 주어질 때, s의 subsequence인 words의 원소 개수 구하기.
- Solve
    - Brute force에서 중복 계산 줄이기
        1. 부분 문자열(subsequence)를 판별하는 것은 반복문 하나가 필요하다.
        2. 모든 words[]의 원소들을 순회하는 것도 반복문이 하나 필요하다. 따라서 O(N^2)의 시간이 걸린다.
        3. 하지만 words[]에 중복된 원소가 있을 수 있기 때문에, hash table을 써서 이미 검사한 문자열은 pass 하였다.
- Complexity(N = words.size())
    1. Time: O(N * words[i]의 평균 길이)
    2. Space: O(N + N) = 해쉬 테이블 + visited 배열

### LeetCode 42. Trapping Rain Water: [Problem](https://leetcode.com/problems/trapping-rain-water/)
- Algorithm: Array, Two Pointers, DP, Stack / Level: Medium
- Idea
    - height 배열이 주어질 때, 빗물이 고일 수 있는 영역을 구하는 문제.
    - DP 또는 투 포인터로 O(N) 복잡도에 해결할 수 있다.
- Solve
    - DP 솔루션
        1. i번째 지점에서 고일 수 있는 빗물은 `min(left_max[i], right_max[i]) - height[i]` 이다.
        2. 미리 left_max[]와 right_max[]를 구한 후 위 수식으로 빗물을 합산하면 된다.
- Complexity
    1. Time: O(N) = left_max O(N) + right_max O(N) + 빗물 계산 O(N)
    2. Space: O(N + N) = left_max O(N) + right_max O(N)

## 220719
### LeetCode 210. Course Schedule II: [Problem](https://leetcode.com/problems/course-schedule-ii/)
- Algorithm: DFS, BFS, Graph, 위상정렬 / Level: Medium
- Idea
    - 먼저 처리가 필요한 태스크의 관계가 주어질 때 가능한 태스크 시퀀스 구하기.
    - Course Schedule 1번 문제는 위상정렬 없이 풀었으나, 시퀀스를 구하기 위해서는 추가 메모리가 많이 필요해서 위상정렬로 품.
- Solve
    - 위상 정렬 로직 [참고](https://www.youtube.com/watch?v=qzfeVeajuyc&ab_channel=%EB%8F%99%EB%B9%88%EB%82%98)
        1. 진입 차수(degree)가 0인 정점을 큐에 삽입한다.
        2. 큐에서 원소를 꺼내 연결된 모든 간선을 제거한다.
        3. 간선 제거 이후에 진입 차수가 0이 된 정점을 큐에 삽입한다.
        4. 큐가 빌때까지 2번 ~ 3번을 반복한다. 모든 원소를 방문하기 전에 큐가 empty면 cycle이 존재하는 것이다.
            - 모든 원소를 방문했다면 큐에서 꺼낸 순서가 위상 정렬의 결과이다.
- Complexity
    1. Time: O(V+E) = 큐에서 degree가 0인 정점 탐색 + 간선의 수(총 degree의 합)
    2. Space: O(V+E + V + E) = adjacency vector O(V+E) + degree 배열 O(V) + DFS 탐색 O(E)

## 220717
### BOJ 1854. K번째 최단경로 찾기: [Problem](https://www.acmicpc.net/problem/1854)
- Algorithm: 그래프 이론, 다익스트라, 우선순위 큐
- Idea
    - 다익스트라처럼 각 정점까지의 최단 경로가 아니라, k번째 최단 경로를 구하는 문제.
    - 못 풀어서 [여기](https://jungahshin.tistory.com/57)를 참고했다.
- Solve
    1. 2개의 우선순위 큐를 활용한다.
        1. 각 정점마다의 최단 경로를 저장하기 위한 heap(내림차순)
        2. 다익스트라 알고리즘을 위한 pq(오름차순)
    2. 핵심 로직
        - heap의 원소가 k개 미만이면 계속 원소를 넣어준다.
        - 이미 k개가 들어있으면 heap[i].top()과 next cost를 비교하여, top()이 더 크면 pop하고 next cost를 새로 넣어준다.
- Complexity
    1. Time: O(VlogE x K) = 우선순위 큐를 활용한 다익스트라 O(VlogE) x K개의 최단 경로 찾기
    2. Space: O(V+E + VK) = 인접 리스트 O(V+E) + heap O(VK)

### LeetCode 207. Course Schedule: [Problem](https://leetcode.com/problems/course-schedule/)
- Algorithm: BFS, DFS, Graph, Topological Sort / Level: Medium
- Idea
    - 수강이 필요한 강의 수와 강의 들간의 선결 조건(prerequisites)가 주어질 때, 모든 강의를 들을 수 있는지 판별하기.
- Solve
    1. prerequisites으로 adjacency vector를 만들고, 이를 탐색하여 단방향 그래프에서 cycle이 일어나는지 판별하였다.
        - cycle이 있으면 선결 조건간에 모순이 생겨 수강이 불가능하다.
    2. 탐색은 모든 노드에 대해 DFS로 탐색하였다.
        - dependency가 없이 독립적인 노드가 있을 수 있기 때문이다.
        - 매 탐색마다 visited와 stack를 새로 선언해주었다.(낭비가 될 수 있다)
- Complexity
    1. Time: O(E*(V+E)) = E개의 간선에 대해 DFS O(V+E)
    2. Space: O(V+E + V + E) = adjacency vector O(V+E) + visited 배열 O(V) + DFS 탐색 O(E)

## 220716
### LeetCode 576. Out of Boundary Paths: [Problem](https://leetcode.com/problems/out-of-boundary-paths/)
- Algorithm: DP / Level: Medium
- Idea
    - 2차원 맵과 공의 시작위치가 주어질때, 공이 맵 밖으로 나가는 경우의 수 찾기.
    - 맵은 최대 50x50이며, local queue나 stack을 사용하기에는 경우의 수가 너무 많아서 memory overflow의 가능성이 있다.
        - 재귀를 활용한 DFS + DP로 풀이했다.
- Solve
    1.  DP 배열의 정의
        - `memo[maxMove][row][col]`: maxMove 만큼의 이동횟수가 남아있고, row와 col의 위치에 있을때 가능한 경우의 수
    2. dfs를 돌며 4방향을 모두 탐색해 준다. 물론 종료 조건을 생각해야 한다.
        - `row < 0 || row >= m || col < 0 || col >= n` 이면 맵 밖을 나간 것이므로 1을 리턴.
        - maxMove가 0 이하면 실패한 것이므로 0을 리턴.
        - memoization이 되어 있다면 해당 값을 리턴.
- Complexity
    1. Time: O(4^N) = N개 stage마다 4방향의 선택지가 있다. memoization을 하므로 실제로는 더 적게 걸림
    2. Space: O(N x m x n) = N개의 move x m개의 row x n개의 column

### LeetCode 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts: [Problem](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/)
- Algorithm: Array, Greedy, Sorting / Level: Medium
- Idea
    - 2차원 맵과 맵을 자르는 horizontalCut, verticalCut 배열이 주어질 때 잘린 조각 중 가장 큰 크기 구하기.
    - hCut과 vCut 배열에서 가장 큰 간격을 구해서 곱하면 되는데, 숫자가 크므로 int overflow에 주의한다.
- Solve
    1. hCut과 vCut을 오름차순으로 정렬한다.
        - 계산의 편의를 위해 hCut과 vCut에 0(시작점)과 끝점(각각 v, w)를 더한 다음 정렬한다.
    2. hCut과 vCut 간격 중 최대 값을 찾는다.
    3. 최대 간격들을 곱하여 리턴한다.
        - `return (long)max_h * max_v % 1000000007;`
- Complexity
    1. Time: O(N*logN) = 정렬 O(NlogN) + 간격 찾기 O(2N)
    2. Space: O(1) = 각 array의 최대 간격을 저장하는 변수 2개를 추가로 사용한다.

### BOJ 17142. 연구소: [Problem](https://www.acmicpc.net/problem/17142)
- Algorithm: 그래프 이론, DFS, BFS
- Idea
    - 2차원 맵에 바이러스를 놓을 수 있는 위치가 주어질 때, 바이러스가 맵 전체에 퍼지는 최소 시간 구하기.
    - 구현량이 많은 BFS/DFS 문제이다.
- Solve
    - 바이러스 위치 선택은 DFS를 이용한 조합으로, 해당 위치에서 퍼지는 시간은 BFS로 구현했다.
- Complexity
    1. Time: 바이러스 후보지 중 M개를 선택하는 조합 * O(N^2)
    2. Space: O(N^2 + N^2 + N + M) = 상태 저장 배열 O(N^2) + visited 배열 O(N^2) + 바이러스 선택 배열 O(N) + 재귀 함수 스택 O(M)

## 220715
### LeetCode 695. Max Area of Island: [Problem](https://leetcode.com/problems/max-area-of-island/)
- Algorithm: BFS, DFS / Level: Medium
- Idea
    - 0과 1로 이루어진 맵이 주어진다. 1은 섬을 의미하는데, 섬의 면적 중 최대 크기를 구하여라.
- Solve
    1. 맵의 크기가 50x50으로 BFS나 DFS 모두 사용할 수 있다.
        - 맵을 탐색하다가 1을 만나면 BFS/DFS로 면적을 구한다.
        - 굳이 visited 배열을 쓰지않고 이미 방문한 섬을 0으로 바꾸면 다시 방문하지 않는다.
    2. 최대 크기를 구하여 리턴한다.
- Complexity
    1. Time: O(R*C) = 맵을 모두 탐색하므로
    2. Space: 최악 O(R*C) = 맵이 모두 1일때.

## 220714
### LeetCode 105. Construct Binary Tree from Preorder and Inorder Traversal: [Problem](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
- Algorithm: Binary Tree, Divide and Conquer / Level: Medium
- Idea
    - 이진 트리의 preorder, inorder 순회결과가 배열로 주어졌을 때, 원본 트리를 만들어서 리턴하는 문제
- Solve
    1. 규칙을 찾아보자.
        - 임의의 stage에서 preorder 배열의 첫번째 원소가 inorder 배열에 있다면?
            - 이 원소가 해당 stage의 root node라는 의미이다. 새 TreeNode를 만들어서 값을 할당 해준다.
    2. 임의의 stage에서 root node를 만든 후
        - root node의 값이 inorder의 첫번째 원소라면?
            - 해당 node의 왼쪽에는 더 이상 노드들이 없다는 의미이다. 오른쪽으로 재귀 호출을 수행한다.
        - root node의 값이 inorder의 첫번째 원소가 아니라면?
            - 왼쪽에 노드들이 있다는 의미이므로, root node를 기준으로 inorder 배열을 나누어서 왼쪽과 오른쪽 재귀호출을 수행한다.
- Complexity
    1. Time: O(N) = 모든 노드를 탐색하므로
    2. Space: O(N + N) = N개의 stage가 있고 + 원본 트리가 N 만큼 차지함.
        - 사실 원본 트리에는 null leaf node들이 추가되므로 N보다 좀 더 크다.

## 220713
### LeetCode 102. Binary Tree Level Order Traversal: [Problem](https://leetcode.com/problems/binary-tree-level-order-traversal/)
- Algorithm: Binary Tree, BFS / Level: Medium
- Idea
    - 이진 트리가 주어질 때 각 height에 위치한 노드들을 같은 vector에 담아 리턴하기.
- Solve
    1. 트리의 최대 높이를 구한다. 이 높이가 vector의 size가 된다.
        - 최대 높이를 구하고 미리 vector에 empty vector들을 높이 개수만큼 삽입해두었다.
    2. preorder로 순회하며 각 vector[height]에 해당 노드의 value를 삽입한다.
- Complexity
    1. Time: O(N) = height 계산할 때 모든 노드를 순회하므로 O(N) + 마찬가지로 levelOrder일 때 O(N)
    2. Space: O(N) = Tree의 크기

### LeetCode 1710. Maximum Units on a Truck: [Problem](https://leetcode.com/problems/maximum-units-on-a-truck/)
- Algorithm: Array, Greedy, Sorting, Priority Queue / Level: Easy
- Idea
    - Box의 종류와 Box에 담을 수 있는 Unit, 그리고 최대 Box 개수를 의미하는 truckSize가 주어진다.
    - truckSize를 초과하지 않는 최대 Unit 구하기.
- Solve
    1. 우선순위 큐 정의
        - `boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]`
        - 위와 같은 pair를 second가 클수록, second가 같으면 first가 큰 순으로 정렬하는 우선순위 큐에 삽입한다.
    2. 우선순위 큐 순회
        - answer에 pq.top().first와 pq.top().second를 곱하여 누적 해나간다.
        - 우선순위 큐가 empty가 되거나 truckSize가 0이 되면 순회를 중단한다.
- Complexity
    1. Time: O(NlogN) = 우선순위 큐 삽입 O(N*logN) + 우선순위 큐 pop연산 O(N)
    2. Space: O(N) = 우선순위 큐

## 220712
### LeetCode 473. Matchsticks to Square: [Problem](https://leetcode.com/problems/matchsticks-to-square/)
- Algorithm: Array, DP, Backtracking, Bitmask / Level: Medium
- Idea
    - 성냥개비 길이 배열이 주어질 때, 정사각형을 만들 수 있는지 검사하는 문제.
    - 두 가지 관점에서 백트래킹 함수를 만들 수 있다.
- Solve
    1. 첫번째 방법
        - 4개의 그룹을 만들고, 매 stage에서 4개의 그룹을 선택하는 것.
        - 마지막에 4개의 그룹의 길이를 비교하여 판별한다.
    2. 두번째 방법: DP + bitmasking
        - 매 stage에서 모든 성냥개비를 순회하고 안 쓰인 성냥개비를 선택하여 검사한다.
        - bitmasking을 통해 성냥개비 사용유무를 체크할 수 있고, memoization 배열 인자에도 쓰인다.
- Complexity
    1. Time: O(N x 2^N) = 매 stage마다 최대 2^N개의 bit mask 경우의 수
    2. Space: O(N + 2^N) = N개의 stage가 있고 + DP배열 4 x 2^N = O(2^N)

## 220711
### LeetCode 199. Binary Tree Right Side View: [Problem](https://leetcode.com/problems/binary-tree-right-side-view/)
- Algorithm: Binary Tree, Hash Map / Level: Medium
- Idea
    - 이진 트리를 오른편에서 바라본다고 가정했을 때, 보이는 원소들을 맨 위에서부터 순서대로 나열하기.
    - 무조건 right 포인터를 따라가면서 할 수 없다. left height가 더 큰 경우도 있기 때문이다.
- Solve
    1. unordered_map 활용
        - 보통의 preorder traversal을 왼쪽부터 수행하면서 unordered_map에 {height, val} 쌍을 저장한다.
        - left 먼저 탐색하고 right를 탐색할 때 기존 값을 덮어쓰게 되고, height가 더 길어지면 새 쌍을 넣게된다.
        - 탐색을 마치고 vector에 1부터 height까지 값을 저장하여 리턴해준다.
    2. Space를 아낄 수 있는 방법: [링크](https://leetcode.com/problems/binary-tree-right-side-view/discuss/56003/My-C%2B%2B-solution-modified-preorder-traversal)
        - hash map을 쓰지않아 공간이 절약된다.
- Complexity
    1. Time: O(N) = 모든 트리 원소들을 순회 O(N) + vector에 값 복사 O(N)
    2. Space: O(N) = unordered_map O(N) + vector에 height 만큼의 원소 저장 O(logN)

## 220710
### LeetCode 746. Min Cost Climbing Stairs: [Problem](https://leetcode.com/problems/min-cost-climbing-stairs/)
- Algorithm: Array, DP / Level: Easy
- Idea
    - cost 배열이 주어질 때 마지막 계단에 도달하는 최소 cost 합 구하기. 계단 오르기 기본 문제이다.
    - 리트코드 데일리 문제이다. 이번 달은 Array, DP 위주인 것 같다.
- Solve
    1. DP 배열의 정의
        - `memo[i]`: i번째 계단에 도달할 때까지의 최소 cost 합
    2. 점화식
        - `memo[i] = min(cost[i-1] + memo[i-1], cost[i-2] + memo[i-2]);`
        - 연습을 위해 for문과 recursive 두 가지로 풀었다.
- Complexity
    1. Time: O(N) = cost 배열 순회 O(N)
    2. Space: O(N) = DP 배열 O(N)

## 220709
### LeetCode 1696. Jump Game VI: [Problem](https://leetcode.com/problems/jump-game-vi/)
- Algorithm: Array, DP, 우선순위 큐, 슬라이딩 윈도우 / Level: Medium
- Idea
    - 정수 배열과 최대로 점프할 수 있는 범위 k가 주어질 때, 마지막 원소에 도달할 때 얻을 수 있는 가장 큰 점수 구하기.
    - 배열 크기가 10^5 까지이며, O(N*K) 솔루션은 시간이 초과된다.
- Solve
    1. DP 배열의 정의
        - `memo[i]`: i에 도달했을 때 얻을 수 있는 가장 큰 점수.
    2. 우선순위 큐(PQ)의 활용
        - k보다 작은 모든 j를 체크하지 말고, memo[index]를 크기 순으로 정렬하는 PQ를 활용한다.
        - PQ에는 index와 해당 index의 memo[index] 값이 pair로 삽입된다. `{index, memo[index]}`
        - PQ.top()의 index와 i와의 거리가 k보다 커지면 제거하고, 다음 최대값을 검사한다.
    3. i와의 거리가 k보다 작거나 같은 memo[index]를 PQ에서 찾아서 현재 DP 배열 값을 갱신한다.
        - `memo[i] = max(memo[i], memo[cur.first] + nums[i]);`
        - 이후 탐색을 위해 다시 `{i, memo[i]}`를 PQ에 삽입한다.
- Complexity
    1. Time: O(N*logK) = for문 O(N) + 우선순위 큐 탐색 O(logK)
    2. Space: O(N+K) = DP 배열 O(N) + 우선순위 큐 O(K)

## 220708
### LeetCode 1473. Paint House III: [Problem](https://leetcode.com/problems/paint-house-iii/)
- Algorithm: Array, DP / Level: Hard
- Idea
    - houses 배열과 cost 배열, 그리고 target 이웃 그룹의 수가 주어진다.
    - target 이웃 그룹의 수를 만족하는 가장 작은 페인트칠의 cost 합 구하기.
        - 같은 색의 집이 붙어있을 때 이웃 그룹이라고 한다.
- Solve
    1. DP 배열의 정의
        - `memo[idx][ncount][color]`
        - i번째 까지 house를 검사했고, ncount 만큼의 이웃 그룹이 있으며, 직전 색이 color일 때의 최소값.
    2. 재귀적으로 순회하며 DP 배열을 채우고 최소값을 찾는다.
        - house[i]가 0이 아니면 작년에 칠한 것이므로 cost 증가 없이 다음 단계로 넘어간다.
        - house[i]가 0이면 가능한 color를 다 칠하고 cost를 증가하여 다음 단계로 간다.
        - 모든 경우의 수를 다 검사하되, memo 배열로 중복 검사를 막는다.
- Complexity
    1. Time: O(M * N^2) = house O(N) x 이웃그룹 O(N) x 컬러 개수 O(M)
    2. Space: O(M * N^2) = 위와 같다.

## 220707
### LeetCode 97. Interleaving String: [Problem](https://leetcode.com/problems/interleaving-string/)
- Algorithm: String, DP / Level: Medium
- Idea
    - s1, s2, s3 스트링이 주어졌을 때, s3가 s1과 s2의 interleaving 스트링인지 판별하는 문제.
    - interleaving은 s1과 s2의 문자 순서가 유지된 채로 교차되어 만들어진 string을 말한다. 
        - 몇 번째에서 교차되었는지는 상관없지만, s1과 s2의 순서는 유지되어야 한다.(hash로 개수만 세는 것이 아니다.)
- Solve
    1. DP를 이용한 완전 탐색으로 풀었다. DP 배열의 정의는 다음과 같다.
        - `memo[i][j]`: s3가 i+j에서 interleaving 중인지 여부. s1은 i번째, s2는 j번째 원소 일때
    2. 재귀나 for문을 이용하여 순회한다.
        - 길이가 200 이하여서 재귀로 풀어도 된다.
        - 수천 ~ 수만개가 주어지기도 하므로 for문도 활용할 줄 알아야 한다.
            - for문 풀이 [참고](https://leetcode.com/problems/interleaving-string/discuss/31879/My-DP-solution-in-C%2B%2B)
- Complexity
    1. Time: O(s1.length * s2.length) = s1과 s2의 길이
    2. Space: O(s1.length * s2.length) = DP 배열의 크기

## 220705
### LeetCode 128. Longest Consecutive Sequence: [Problem](https://leetcode.com/problems/longest-consecutive-sequence/)
- Algorithm: Array, 해쉬, 유니온-파인드 / Level: Medium
- Idea
    - 수열이 주어질 때, 가장 긴 연속적인 부분집합의 길이를 구하는 문제. O(N)의 시간 복잡도를 만족해야 한다.
    - 원소의 범위가 `-10^9 ~ 10^9` 이므로 카운팅 정렬을 쓰면 메모리가 초과된다.
        - 카운팅 정렬은 원소의 범위가 작고, 모든 원소가 연속적일 때 쓰인다.
- Solve
    1. 먼저 unordered_set, 즉 해쉬 테이블에 모든 원소를 집어 넣는다. 이 때 O(1*N)의 시간이 쓰인다.
    2. hash를 순회하며 `현재 원소 - 1`이 hash에 없는 원소를 찾는다.
        - 이것이 연속적인 부분집합의 시작점이 되기 때문이다.
        - 찾은 이후 `현재 원소 + 1`이 hash에 있는지 반복적으로 검사하여 길이를 갱신해준다.
    3. 이 과정에서 반복문이 2개가 쓰이는데, 시간 복잡도가 O(N^2)가 아니라 O(N)인 이유를 알아보자.
        - 6,5,4,3,2,1인 수열이 주어질 때, `현재 원소 - 1` 조건 때문에 마지막 원소 1부터 내부 반복문을 수행하게 된다.
        - 1에 도달하는데 O(N), 길이 검사하는 과정이 O(N)이므로 결과적으로 O(N)이 된다.
- Complexity
    1. Time: O(N) = 해쉬 테이블에 넣는 과정 O(N) + 길이 검사 과정 O(N)
    2. Space: O(N) = 해쉬 테이블

## 220704
### LeetCode 135. Candy: [Problem](https://leetcode.com/problems/candy/)
- Algorithm: Array, 그리디 / Level: Hard
- Idea
    - 조건을 만족하며 학생들에게 캔디를 분배할 때, 분배하는 캔디 개수의 최소값 구하기.
    - 조건
        1. 각 학생들은 최소 1개의 캔디를 받아야 한다.
        2. 이웃 학생들보다 rating이 높은 학생은 더 많은 캔디를 받아야 한다.
- Solve
    1. 확실한 조건일때 캔디를 assign 하고, 이를 바탕으로 캔디 분배를 확장해 나간다.
        - 최초에 확실한 조건은 다음 3가지 뿐이다. 그 외에는 이웃들의 캔디 숫자가 확정되어야 판단할 수 있다.
        ``` c++
           if (ratings[0] <= ratings[1]) {
               candy[0] = 1;
           }
           if (ratings[N-1] <= ratings[N-2]) {
               candy[N-1] = 1;
           }
           if (i > 0 && i < N-1) {
               if (ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1]) {
                   candy[i] = 1;
               }
           }
        ```
    2. while 문을 돌며 candy 벡터의 빈칸을 채우고 sum에 합산한다.
        - 특정 경우는 먼저 검사하면 더 빠르게 판단할 수 있다.
        - 예를 들어 계속 감소하는 rating은 while문의 순회가 비효율적이게 된다.  
- Complexity
    1. Time: 캔디 벡터를 모두 채울 때까지 반복 순회하므로 알 수 없다.
    2. Space: O(N) = 캔디 벡터

## 220703
### LeetCode 216. Combination Sum III: [Problem](https://leetcode.com/problems/combination-sum-iii/)
- Algorithm: 백트래킹 / Level: Medium
- Idea
    - k개의 숫자를 써서 n을 만들 수 있는 경우의 수 구하기.
    - 재귀없이 백트래킹을 구현해보려 했으나, 잘 안 되서 다른코드를 참고했다. 좀 더 연습이 필요하다.
- Solve
    - 재귀를 쓴다면 쉬운 백트래킹 문제가 된다.
- Complexity
    1. Time: O(K * 10) = K 단계 x 각 단계에서 숫자 10개 검사
    2. Space: O(K) = 숫자 조합을 담는 벡터

### BOJ 10942. 팰린드롬?: [Problem](https://www.acmicpc.net/problem/10942)
- Algorithm: DP
- Idea
    - 수열이 주어질 때, 특정 구간의 숫자들이 팰린드롬인지 판별하는 문제.
- Solve
    1. DP 배열의 정의
        - `memo[S][E]`: S번째부터 E까지의 숫자가 팰린드롬인지 확인한 결과를 저장. 초기값은 -1
        - 팰린드롬이라면 1, 아니면 0을 저장한다.
    2. 재귀로 팰린드롬 여부를 판별하고, memoization으로 중복 검사를 하지 않도록 한다.
        - S == E 이면 숫자 하나이므로 팰린드롬이다.
        - S+1과 E-1이 팰린드롬이며, Arr[S]와 Arr[E]가 같으면 S부터 E까지도 팰린드롬이다.
- Complexity
    1. Time: O(N^2) = memo 배열을 채우는데 걸리는 시간
    2. Space: O(N^2) = memo 배열 크기

### LeetCode 376. Wiggle Subsequence: [Problem](https://leetcode.com/problems/wiggle-subsequence/)
- Algorithm: DP, 그리디 / Level: Medium
- Idea
    - 수열이 주어질 때, 가장 긴 wiggle subsequence의 길이 구하기.
    - wiggle subsequence란 구성 원소들이 순서대로 증가와 감소를 반복하는 부분 수열을 말한다.
- Solve
    1. DP 배열의 정의
        - `up[i]`: i번째 까지를 검사했을 때, 마지막 두개의 원소가 증가하는 방향으로 끝난 부분수열의 최장 길이.
        - `down[i]`: 마지막 두개의 원소가 감소하는 방향으로 끝난 부분수열의 최장 길이.
        - subsequence를 직접 구하는 것이 아니라, 각 조건의 최장 길이만 기록하는 것이다.
    2. 다음 조건을 확인하여 DP 배열들을 갱신해준다.
        1. nums[i] > nums[i-1] 일 때
            - `up[i] = down[i-1] + 1`: down[i-1]에 감소하는 방향의 최장길이가 기록되어 있으므로.
            - `down[i] = down[i-1]`: 현재는 증가하는 방향이므로 기존의 최장길이를 유지함.
        2. nums[i] < nums[i-1]일 때
            - `up[i] = up[i-1]`
            - `down[i] = up[i-1] + 1`
        3. nums[i] == nums[i-1] 일 때는 둘 다 i-1번째 값과 동일.
- Complexity
    1. Time: O(N) = 반복문 1개
    2. Space: O(N) = up[N] + down[N]

## 220629
### LeetCode 136. Single Number: [Problem](https://leetcode.com/problems/single-number/)
- Algorithm: Array / Level: Easy
- Idea
    - 주어진 array에서 한번만 등장하는 숫자 찾기.
    - 시간 복잡도는 O(N)이어야 하고 constant extra space만 사용해야 한다.
- Solve
    1. 처음 element를 prev에 저장하고 계속 비교해 나간다. cnt는 1로 지정한다.
    2. prev와 다른 element를 만났을 때 cnt가 1이면 한번만 등장한 숫자이다.
- Complexity
    1. Time: O(N) = for문 O(N)
    2. Space: O(1) = prev와 cnt 변수

### LeetCode 322. Coin Change: [Problem](https://leetcode.com/problems/coin-change/)
- Algorithm: Array, DP / Level: Medium
- Idea
    - 달성해야하는 숫자(amount)와 coin 배열이 주어졌을 때, amount를 만들 수 있는 최소 동전의 개수 구하기.
    - 한달 전에 풀었지만 풀이가 전혀 생각이 나지 않았다. 제대로 이해하지 못 했다는 것이다.
- Solve
    1. DP 배열의 정의
        - 처음에 생각한 것은 `dp[level][동전 1의 개수][동전 2의 개수][...]` 인데, 동전의 개수가 무한하므로 불가능하다.
            - 버릇처럼 재귀를 이용한 탐색과 그에 따른 dp 배열 구성이 먼저 생각이 났다. 결국 다시 솔루션을 봤다.
        - `dp[amount]`: amount를 만들 수 있는 최소 동전의 개수
    2. 1부터 amount까지 탐색하며 최소 동전의 개수를 구해 나간다.
        - for문 2개를 활용하는데, 바깥은 amount, 안쪽은 coins 집합을 순회한다.
- Complexity
    1. Time: O(N^2) = for문 2개
    2. Space: O(N) = dp 배열

## 220628
### LeetCode 38. Count and Say: [Problem](https://leetcode.com/problems/count-and-say/)
- Algorithm: String / Level: Medium
- Idea
    - 주어지는 number에 맞는 string을 재귀적으로 추가하는 문제
- Solve
    1. 함수 구조는 보통의 백트래킹과 유사하다.
        - n == 1일 때는 끝에 도달한 것이므로 "1" 을 리턴한다.
        - 그 외의 경우는 각 숫자 cnt를 세어서 string을 추가해 나간다.
- Complexity
    1. Time: O(N^2) = 재귀 O(N) * 반복문으로 string 탐색 O(N)
    2. Space: O(N) = 재귀 함수 O(N)

## 220623
### BOJ 2211. 네트워크 복구: [Problem](https://www.acmicpc.net/problem/2211)
- Algorithm: 그래프 이론, 다익스트라
- Idea
    - 1번 컴퓨터로부터 다른 컴퓨터까지의 최소 경로가 되는 간선 set 구하기.
- Solve
    1. 다익스트라 알고리즘을 적용한다.(특정 노드에서 다른 모든 노드까지 최소 경로 구하기)
        - 시간 복잡도를 줄이기 위해 Priority Queue로 최소 경로를 갱신하며 다음 노드를 선택하였다.
    2. 이 문제에서는 최소 거리 뿐 아니라, 경로도 구해야 한다.
        - 최소 경로 갱신이 일어날 때 이전 노드를 기록해주면 된다. `path[next] = cur.first`
    3. 최소 거리와 경로를 탐색한 후 답을 출력한다.
        - 선택된 간선의 개수는 N-1개가 될 것이다. (1번 컴퓨터를 기준으로한 MST라고 볼 수 있을것 같다)
        - `path` 배열을 순회하며 선택된 간선들을 출력한다.
- Complexity
    1. Time: O(ElogE) = 간선의 수 O(E) * 우선순위 큐 O(logE)
    2. Space: O(E) = 우선순위 큐 O(E) + Path O(E)

## 220622
### BOJ 9935. 문자열 폭발: [Problem](https://www.acmicpc.net/problem/9935)
- Algorithm: 문자열, 자료구조, 스택
- Idea
    - 문자열이 주어질 때 폭발 문자열을 연쇄적으로 제거하고 남은 문자열 구하기.
    - kmp, 라빈 카프, hash 등을 생각했으나 substr 연산이 오래 걸려서 시간초과 되는 것 같다.
        - 스택을 이용한 다음 [풀이](https://blog.encrypted.gg/103)를 참고했다.
        - 공식을 아는 것도 중요하지만 이런 문제 해결력도 갖추어야 한다.
- Solve
    1. 문자열을 탐색하면서 다음 조건대로 스택에 넣는다.
        - {문자, 폭발 문자열과 일치하는 개수}
        - 예를 들어 문자열이 ABDABCD이고 폭발 문자열이 ABC 이면 스택에는 다음 값이 들어가게 된다.
            - {A, 1} {B, 2} {D, 0} {A, 1} {B, 2} {C, 3} {D, 0}
    2. 진행하다가 폭발 문자열 길이와 match_cnt가 같게되면 match_cnt만큼 pop() 해준다.
        - 스택이 비어있으면 match_cnt는 0이 되고, 그렇지 않으면 top의 match_cnt로 갱신해준다.(이어서 탐색하기 위해)
    3. 스택에 남아있는 문자열을 역순으로 출력한다.
- Complexity
    1. Time: O(N) = pop연산 최대 O(N) + push연산 최대 O(N)
    2. Space: O(N) = 스택 O(N)

## 220621
### BOJ 1141. 접두사: [Problem](https://www.acmicpc.net/problem/1141)
- Algorithm: 문자열, 정렬, Trie
- Idea
    - 문자열 집합이 주어진다.
    - 각 원소들이 다른 원소의 접두사가 되지 않는 부분 집합의 최대 원소 개수 구하기.
- Solve
    - Trie 자료형에 주어진 문자열들을 담고, leaf 노드의 개수를 세주었다.
    - leaf 노드는 문자열의 끝이므로, 접두사가 아니기 때문이다.
- Complexity
    1. Time O(N·L)
        - Trie를 만드는 시간은 O(N·L): 문자열 N개, 평균 길이를 L이라고 했을 때.
        - Trie를 탐색하는 시간 O(N·L): 현재 구현에서는 매 재귀함수마다 alphabet 배열 전체를 탐색해야 하므로 생성보다 더 걸린다.
    2. Space
        - O(N·L) = 문자열 N개 * 문자열 평균 길이 L

## 220620
- STL 자료구조, 각 정렬의 구현과 특징 복습하였음.
- **공간 복잡도**에 대한 이해를 확실히 해야 함.
    - 알고리즘 수행에 필요한 추가 공간
    - 재귀 함수 호출에 필요한 Call stack도 포함해야 함.

## 220619
### LeetCode 33. Search in Rotated Sorted Array: [Problem](https://leetcode.com/problems/search-in-rotated-sorted-array/)
- Algorithm: Binary Search, 정렬
- Idea
    - 어떤 int 배열이 오름차순으로 정렬되어 있다. 이 때 O(logN) 시간복잡도 안에서 특정 target을 찾는 문제.
    - 단, 이 배열은 특정 index에서(pivot) 로테이션 되어 있을 수 있다.
    - 예를 들어 [0,1,2,4,5,6,7] 배열이 pivot index=3으로 로테이션 된다면 [4,5,6,7,0,1,2]가 된다.
- Solve
    1. 먼저 pivot index를 찾도록 했다.
        - `target >= nums[pivot] && target <= nums[nums.size()-1]`
        - 위 수식을 만족하면 target은 pivot부터 마지막 요소 사이에 있다고 볼 수 있다.
    2. 따라서 pivot을 찾고 pivot 기준 왼쪽과 오른쪽을 결정한 뒤, 해당 구간에서 binary search를 하면 된다.
        - pivot을 찾는 함수도 binary search를 응용하여 O(logN)의 시간복잡도를 지킬 수 있게 하였다.
- Complexity
    1. Time: O(logN) = findPivot O(logN) + 구간 search O(logN)
    2. Space: O(N) = 추가 공간 없음

### LeetCode 56. Merge Intervals: [Problem](https://leetcode.com/problems/merge-intervals/)
- Algorithm: Array, 정렬
- Idea
    - 구간들이 주어질 때 겹치는 구간들을 merge하여 리턴하기.
- Solve
    1. 먼저 `vector<vector<int>> intervals`를 다음 기준으로 정렬하였다.
        - 시작점이 빠른 순서. 시작점이 같으면 종료지점이 더 먼 순서.
    2. 이제 for 루프를 돌며 다음 기준으로 merge하여 정답 vector에 push하였다.
        - 초기값 s와 e를 첫번째 구간값으로 셋팅한다.
        - 다음 구간 시작점이 첫번째 구간 안에 포함되고(겹치고), 종료지점이 더 멀면 e를 다음 구간 종료지점으로 갱신한다.
        - 겹치지 않으면 정답 vector에 push한다.
- Complexity
    1. Time: O(NlogN) = 구간 정렬 O(NlogN) + merge O(N)
    2. Space: O(N^2) = 최초 구간들 O(N^2) + 정답 배열 O(N^2)
- **Note**: [참고](https://leetcode.com/problems/merge-intervals/discuss/874757/help-please-line-1052-char-9-runtime-error-reference-binding-to-null-pointer-of-type)
    - 구간을 정렬하기 위한 Compare() 함수에서 우선순위를 판별할 수 없을 때 UndefinedBehaviorSanitizer 에러가 발생한다.
        - 즉 Compare(a, b)도 true이고 Compare(b, a)도 true인 경우이다.
    - 이런 경우가 발생하지 않도록 a와 b의 요소가 같을 때 주의해서 return 값을 명시하도록 하자.
    
### LeetCode 240. Search a 2D Matrix II: [Problem](https://leetcode.com/problems/search-a-2d-matrix-ii/)
- Algorithm: Array, 정렬, 이분 탐색, 매트릭스
- Idea
    - 2차원 배열이 주어진다. 각 행은 오름차순으로 정렬되어 있고, 각 열도 오름차순으로 정렬되어 있다.
    - 이 때 target을 찾는 효율적인 알고리즘을 구하는 문제.
- Solve
    1. Brute force
        - 0번째 행부터 마지막 행까지 순회하며 stl find()를 써서 target을 찾는다.
        - 시간 복잡도: O(N^2). 1452ms 소요됨
    2. Brute force + binary search
        - 0번째 행부터 마지막 행까지 순회 + 각 행에서 binary search를 써서 target을 찾는다.
        - 시간 복잡도: O(NlogN). 509ms 소요됨
    3. 더 빠른 방법(?)
        - 0번째 행부터 순서대로 탐색하는 것이 아니라, 유망한 행을 먼저 탐색하면 더 빠르게 답을 구할 수 있을 것이다.
        - 내일 좀 더 해보자.

## 220618
### BOJ 14238. 출근 기록: [Problem](https://www.acmicpc.net/problem/14238)
- Algorithm: 백트래킹, DP
- Idea
    - 출근할 수 있는 조건이 주어질 때, 가능한 조합 하나 구하여 출력하기.
    - DP가 어려워질수록 DP 배열에 대한 정의가 까다로워 지는 것 같다.
- Solve
    1. DP 배열의 정의
        - `memo[a][b][c][p1][p2]`: a, b, c 일자 만큼 출근했고 전날에 p1이, 전전날에 p2가 출근했을 때 출근가능 여부이다.
    2. 재귀를 돌면서 조건에 맞추어 가지치기를 해준다.
        - A는 항상 출근할 수 있고, B는 전날에 근무했으면(p1 == B) 근무를 하지 못한다. C는 전날과 전전날에 근무했으면 할 수가 없다.
    3. 어제 본 BOJ 12996. Acka 문제처럼 memo 배열의 초기값은 -1로 셋팅해준다. 0으로 하면 중복 계산이 일어날 수 있기 때문.
- Complexity
    1. Time: 백트래킹 + DP는 가지치기와 memo 때문에시간 복잡도를 말하기가 어렵다.
        - 굳이 따져보면 중복 계산이 일어나지 않으므로 3^n이 아닐까.
    2. Space: O(S^3) = memo[S][S][S][3][3] 이므로.

### BOJ 16236. 아기 상어: [Problem](https://www.acmicpc.net/problem/16236)
- Algorithm: 구현, DFS/BFS
- Idea
    - 유명한 아기 상어 시리즈. DP 없는 DFS/BFS 문제 중에서 구현량이 많아 어려운 유형인 것 같다.
    - 필요한 데이터 구조와 method를 잘 정의하여 하나하나 구현해 나가야 한다.
- Solve
    1. 구현한 method
        - travel(): main loop에 해당된다. 재귀적으로 다음 단계로 진행한다.
        - eatableFishes(): 먹을 수 있는 물고기들의 index를 구한다.
        - calDistance(): 먹을 수 있는 물고기까지의 거리를 계산한다.
        - selectTarget(): 조건에 맞게 먹을 물고기를 선택한다.
        - eatFish(): 선택된 물고기 위치로 상어를 이동시키고 먹는다.
    2. 주의해야 할 반례
        - 다음 반례는 먹을 수 있는 물고기는 있지만, 상어보다 크기가 큰 물고기로 둘러싸여 있어서 갈 수 없다.
        ```
            3
            9 2 2
            2 2 3
            1 3 1
            answer : 2
        ```

### LeetCode 73. Set Matrix Zeroes: [Problem](https://leetcode.com/problems/set-matrix-zeroes/)
- Algorithm: Array, Matrix, Hash Table
- Idea
    - 주어진 matrix에서 element가 0인 것이 있으면, 해당 row와 column을 모두 0으로 만들어야 한다.
    - in place, 즉 추가 저장공간 없이 수행해야 한다.
- Solve
    1. 처음에 이중 for문을 돌며 element가 0이면 해당 row의 가장 첫번째와 해당 column의 가장 첫번째 것에 0으로 표시를 한다.
        - 즉 다음과 같다. `matrix[0][j] = matrix[i][0] = 0`
        - 이렇게 하는 이유는 추가공간 없이 나중에 모든 row와 column을 바꾸기 위해서이다.
    2. 그런데 표시를 한 해당 row의 가장 첫번째나 column의 가장 첫번째가 0인지 여부도 판별해야 한다.
        - 이것은 flag를 두어 기록을 하면 된다. `if (i == 0) row = true; if (j == 0) column = true`
        - 1번에서 해당 element가 바뀌게 되면 기존 값을 알 수 없기 때문에 flag로 미리 기록을 하는 것이다.
    3. 다시 이중 for문을 돌며 첫 element가 0으로 표시되어 있으면 해당 row와 column을 전부 0으로 바꿔준다.
        - 이 때 i와 j는 1부터 시작한다. i와 j가 0인 경우는 다음에 flag에 의해서 처리할 것이다.
    4. 이제 flag를 보고 i와 j가 0일 때의 작업을 수행한다.
- Complexity
    1. Time: O(N^2) = 최초 O(N^2) + 0으로 바꾸기 O(N^2)
    2. Space: O(M*N) = no extra space

## 220617
### LeetCode 12. Generate Parentheses: [Problem](https://leetcode.com/problems/generate-parentheses/)
- Algorithm: 백트래킹
- Idea
    - n개의 괄호 쌍 만들기. 왼쪽 오른쪽이 바뀌지 않게 조합을 만들어야 한다.
- Solve
    - 재귀를 돌 때, 오른쪽 괄호가 먼저 나오지 않도록 (왼쪽 괄호의 수 < 3)이면 왼쪽을 먼저 넣어준다.
    
### LeetCode 621. Task Scheduler: [Problem](https://leetcode.com/problems/task-scheduler/)
- Algorithm: 해쉬 테이블, 정렬
- Idea
    - 주어진 task 배열과 idle 타임을 고려하여 task 스케쥴링 하기.
    - 같은 task는 idle 타임이 지나야 수행할 수 있다.
- Solve
    1. hash map과 sorting을 사용하여 빈도수 대로 task를 정렬한다.
    2. (n+1)*(최대 빈도수 -1) 의 의미에 대해 생각해보자.
        - 가장 빈도수가 많은 task를 idle 타임을 고려하여 배치한 것이다.
    3. 이제 hash map을 돌며 최대 빈도수와 같은 task(자기 자신 포함)를 세어서 위 계산에 더해준다.
        - 그보다 빈도수가 낮은 task는 idle 슬롯에 배치를 할 수 있기 때문이다.
    4. 정답은 tasks.size()와 2-3에서 계산한 값 중 큰 값이다.
        - task 종류가 많으면 idle 타임을 모두 채우고 결국 tasks.size()가 찾는 값이 되기 때문이다.
- Complexity
    1. Time: O(NlogN) = sorting O(NlogN)
    2. Space: O(N) = vector O(N)

### BOJ 12996. Acka: [Problem](https://www.acmicpc.net/problem/12996)
- Algorithm: 백트래킹, DP
- Idea
    - 세 사람이 녹음해야 하는 곡의 수가 주어질 때, 앨범을 만들 수 있는 경우의 수 구하기.
- Solve
    1. 모든 DP 문제가 그렇듯 DP 배열에 대한 정의가 중요하다.
        - `memo[S][s1][s2][s3]`: 불러야 할 노래가 S개 남아있고 세 사람이 각각 불러야 할 노래가 s1,s2,s3일 때 가능한 경우의 수.
    2. 백트래킹 + DP 조합으로 구하였다.
        - 노래 한곡을 부르려면 1, 2, 3, 12, 13, 23, 123의 7가지 경우가 있다.(각 번호의 사람들이 부른다는 의미이다.)
        - S, s1, s2, s3가 음수가 되지 않게 하면서 위 경우들에 맞게 재귀를 호출해주면 된다.
    3. **주의**: 처음에 memo 배열의 초기값을 0으로 하였다가 시간초과가 발생했다.
        - memo 배열의 목적은 중복된 계산을 줄이려고 하는 것이다. 그런데 한 재귀함수를 다 계산해도 그 단계의 memo 배열 값이 0일 수 있다.
        - memo 배열 값이 0이 아닐때 리턴하게 되면, 이후 다시 같은 조건으로 들어올때 중복으로 계산하게 된다.
            - `if (memo[S][s1][s2][s3] != 0) return memo[S][s1][s2][s3];`
        - 따라서 memo 배열의 초기값은 -1로 set하고, 다음 조건대로 해야 의도대로 계산을 줄일 수 있다.
            - `if (memo[S][s1][s2][s3] != -1) return memo[S][s1][s2][s3];`

## 220616
### LeetCode 5. Longest Palindromic Substring: [Problem](https://leetcode.com/problems/longest-palindromic-substring/)
- Algorithm: DP(?), 2 포인터
- Idea
    - Substring 중 가장 긴 Palindrome을 찾는 문제.
    - DP라고 분류되어 있는데 어떤 부분이 DP인지 모르겠다. 2 포인터로 좌우 문자를 비교해가며 풀 수 있다.
- Solve
    1. 메인 for 루프에서 i를 0부터 N-1까지 탐색한다.
    2. 주어진 string size가 짝수와 홀수인 경우를 나누어 palindrome 여부를 판별한다.
    3. 좌우 문자가 같으면 2 포인터를 확장시켜가며 가장 긴 palindrome을 찾는다.
- Complexity
    1. Time: O(N^2) = 메인 for 루프 O(N) * 2 포인터 O(N)
    2. Space: O(N) = N개의 문자

## 220615
### LeetCode 17. Letter Combinations of a Phone Number: [Problem](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
- Algorithm: 백트래킹
- Idea
    - 숫자와 문자가 적힌 다이얼과 누를 수 있는 버튼이 주어질 때 가능한 문자 조합 구하기.
- Solve
    1. 지금까지 접한 다이얼 문제와 다르게 각 숫자에 해당하는 문자 그룹이 있는 것이 새로웠다.
        - Ex) 2 = "abc", 3 = "def", 4 = "ghi"
    2. 큰 줄기에서는 기존 접근방식과 비슷하다.
        - 재귀에 level과 만들고 있는 string을 넘겨준다.
        - 현재 level 그룹에서 loop를 돌며 string을 만든다.
        - 재귀 단계가 digits size에 도달하면 answer vector에 추가한다.
- Complexity
    1. Time: O(N^2): 재귀 O(N) * 버튼 루프 O(N)
        - 가지치기가 없으므로 O(N^2)으로 보인다.
    2. Space: O(N)

### BOJ 11047. 동전 0: [Problem](https://www.acmicpc.net/problem/11047)
- Algorithm: 그리디
- Idea
    - 동전의 종류가 주어질 때, 가치의 합을 K로 만들 수 있는 최소 동전의 개수 구하기.
    - 그리디 라는 것을 알고 풀어서 어렵지 않았다.
- Solve
    1. K 보다 작거나 같은 동전을 찾는다. 이 때 upper_bound를 써서 logN의 시간으로 찾게 하였다.
    2. K에서 해당 동전을 쓴 금액을 빼서 K를 갱신한다. 이 때 쓰인 동전의 개수를 누적하여 기록한다.
    3. K가 0이 될 때까지 1~2번을 반복한다.
- Complexity
    1. Time: O(NlogN) = 동전 N개를 logN으로 탐색
    2. Space: O(N) = vector의 공간

## 220614
### LeetCode 139. Word Break: [Problem](https://leetcode.com/problems/word-break/)
- Algorithm: Hash Table, DP
- Idea
    - string S가 주어진 단어들로 구성될 수 있는지 확인하는 문제. 단어들이 겹치면 안 된다.
- Solve
    1. 단어들은 unique하므로 hash table에 보관하여 검색 속도를 높일 수 있다.
    2. dp[s.size()+1] 배열을 정의한다. dp[i]는 i-1까지의 substring이 hash table에 존재한다는 의미이다.
        - i는 1부터 N까지 순회하고 j는 i-1에서 0까지 감소시키며 탐색한다.
        - dp[j] == true이면 j-1까지는 hash table에 있다는 의미이므로, s.substr(j, i-j)가 hash에 있는지 확인한다.
    3. 최종 dp[N] 값을 리턴한다.
- Complexity
    1. Time: O(N^2) = for loop O(N) x for loop O(N) x hash table O(1)
    2. Space: O(N) = hash table O(N) + dp O(N)

## 220613
### BOJ 14938. 서강그라운드: [Problem](https://www.acmicpc.net/problem/14938)
- Algorithm: 그래프 이론, 다익스트라
- Idea
    - 허용되는 거리(M) 내에서 얻을 수 있는 최대 아이템 개수 구하기.
    - 처음에는 전체 노드를 순회 + BFS로 시도했으나 실패. BFS 경로 탐색이 최소 경로가 아닐 수 있기 때문이다.
        - 안 되는 이유는 [이 글](https://www.acmicpc.net/board/view/48932)을 읽어보자.
- Solve
    1. 모든 노드를 순회하며 각각 다익스트라 알고리즘으로 다른 노드까지의 최소 거리를 구한다.
    2. 최소 거리 배열을 순회하며 M 이하면 sum에 누적하여 더해준다.
    3. 누적 sum 중의 최대값이 찾고자 하는 값이다.
- Complexity
    1. Time: O(NxElogN) = for문 O(N) x 다익스트라 O(ElogN)
        - N은 노드의 개수, E는 Edge의 수 이다.
- **Note**: 다익스트라 시간 복잡도 O(ElogV) [참고](https://gamedevlog.tistory.com/98)
    - 우선순위 큐에서 꺼낸 현재 노드에 연결된 간선 모두 확인 - 간선의 개수(E) 만큼 확인
    - 우선순위 큐에 간선을 넣고 빼는 과정 - logE
        - 모든 간선을 우선순위 큐에 넣고 뺀다고 했을 때 O(ElogE) 의 시간 복잡도를 갖는다.
    - 이때, 중복 간선을 포함하지 않는 경우, E는 항상 V^2 이하이다. (모든 노드가 연결 되어 있는 경우 V * (V-1))
    - logE < log(V^2)이다. log(V^2)은 2logV이기 때문에 O(logV)로 표현할 수 있다.
        - 따라서, 다익스트라 알고리즘 전체 시간 복잡도를 O(ElogV) 로 표현할 수 있다. (ElogE)

## 220612
### BOJ 9470. Strahler 순서: [Problem](https://www.acmicpc.net/problem/9470)
- Algorithm: 그래프 이론
- Idea
    - Strahler 순서를 구하는 문제. Strahler 순서는 유입되는 하천의 S 순서와 개수에 따라 결정된다.
- Solve
    1. 주어진 간선 정보들을 adjacency 벡터에 저장한다.
    2. for문으로 노드 1번부터 순회하며 BFS로 연결된 노드의 S순서를 갱신한다.
        - 다른 노드에 연결되어 BFS로 갱신된 것들은 for문에서 자기 차례가 되었을때 중복으로 검사하지 않도록 한다.
        - visited 배열로 중복 검사를 막아주었다.
    - 위상 정렬로 풀 수도 있다고 한다. [참고](https://www.acmicpc.net/source/44295799)
- Complexity
    1. Time: O(M * P) = main for문 O(M) x 간선 BFS O(P) 
    2. Space: O(M * P) = adjacency vector O(MxP) + Straheler 구조체배열 O(M x 50) + visited O(M)

### SWEA 4335. 무인도 탈출: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWL6HGz6Ai4DFAUY)
- Algorithm: 백트래킹, DP 
- Idea: 엄청난 구현량의 백트래킹 문제. 못 풀었음. 다시 도전해 볼 것..

### BOJ 1927. 최소 힙: [Problem](https://www.acmicpc.net/problem/1927)
- Algorithm: 우선순위 큐
- Idea: 기본적인 최소 힙을 구현하였다.
- Complexity
    1. Time: O(NlogN) = N개 * 삽입 O(logN)
    2. Space: O(N) = N개 element

### BOJ 2042. 구간 합 구하기: [Problem](https://www.acmicpc.net/problem/2042)
- Algorithm: 세그먼트 트리
- Idea: 기본적인 세그먼트 트리를 구현하였다.
- Complexity
    1. Time: O(NlogN) = N개 * 삽입 O(logN)
    2. Space: O(N) = 트리 element O(4N)

## 220611
### LeetCode 15. 3Sum: [Problem](https://leetcode.com/problems/3sum/)
- Algorithm: Arrays, Two Pointers, Sorting
- Idea
    - 배열의 3개 요소의 합이 0이 되는 경우 찾기. 중복된 set이 없도록 한다.
    - 3중 for문으로는 시간 초과가 발생한다. O(N^2)로 해결할 수 있는 방법이 필요
- Solve
    1. for루프 1개와 2포인터를 조합하여 푼다.
        - 바깥쪽 for문은 i를 0부터 size-2 이전까지 탐색한다. 여기까지는 동일
        - 2포인터는 l은 i+1, h는 size-1부터 감소시키며 nums[i] = nums[l] + nums[k]인 경우를 찾는다.
    2. 중복을 피하기 위해 nums는 정렬하며, 2포인터 내에서 같은 값을 건너뛰도록 한다.
        - nums[l] == nums[l+1]이면 l++
        - nums[h] == nums[h-1]이면 h--
- Complexity
    1. Time: O(N^2) = for루프 O(N) * 2포인터 O(2N)
    2. Space: O(N^2) = vector<vector<int>> answer

### LeetCode 49. Group Anagrams: [Problem](https://leetcode.com/problems/group-anagrams/)
- Algorithm: Array, Hash Table, String, Sorting
- Idea
    - 주어진 string 배열에서 anagram들을 그룹으로 묶어서 리턴하기
- Solve
    1. string 배열을 처음부터 순회하면서 각 string을 검사한다.
        - string을 sort하여 hash map에 없으면 추가, 있으면 기존 그룹에 추가한다.
    2. 최종 그룹들을 리턴한다.
- Complexity
    1. Time: O(N) = For문 1개 O(N) * Hash map O(1)
    2. Space: O(N^2) = vector<vector<string>> answer + Hash map O(N)

### LeetCode 3. Longest Substring Without Repeating Characters: [Problem](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
- Algorithm: Hash Table, String, Sliding Window
- Idea
    - 중복된 요소를 포함하지 않는 가장 긴 연속수열 구하기
    - 중복된 요소는 hash table로 검사하면 된다.
- Solve
    1. for문으로 처음부터 순회하면서 hash table에 없으면 추가하고 뒤의 포인터를 증가시킨다.
    2. 있으면 맨 앞 값을 hash table에서 제거하고 앞의 포인터를 증가시킨다.
    3. 매번 반복마다 수열의 최대 길이를 검사하여 저장한다.
- Complexity
    1. Time: O(N) = 2 pointer O(2*N) + hash O(N)
    2. Space: O(N) = hash O(N)

### LeetCode 94. Binary Tree Inorder Traversal: [Problem](https://leetcode.com/problems/binary-tree-inorder-traversal/)
- Algorithm: DFS, Binary Tree
- Idea: inorder로 출력하는 문제
- Solve
    - left 탐색 전 출력을 하면 preorder 이다. 
    - left 탐색을 마치고 right 탐색 전에 출력을 하면 inorder 가 된다.
    - right 탐색까지 마치고 출력하면 postorder 이다.
- Complexity
    1. O(N) 특정 값을 찾는 것이 아니라 그냥 나열이므로.

### LeetCode 103. Binary Tree Zigzag Level Order Traversal: [Problem](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
- Algorithm: BFS, Binary Tree
    - Idea
    - level이 짝수이면 왼쪽부터, 홀수이면 오른쪽부터 그룹으로 만들어서 벡터에 담는 문제.
- Solve
    1. 나는 먼저 maximum depth를 구한 다음 빈 vector들을 삽입해 놓았다.
        - preorder traversal을 하며 각 벡터에 level이 짝수면 앞에, 홀수면 뒤에 삽입하였다.
    2. 다른 방법으로 level order traversal을 응용하면 된다고 한다. 공부해 볼 것.

## 220610
### LeetCode 55. Jump Game: [Problem](https://leetcode.com/problems/jump-game/)
- Algorithm: DP, 백트래킹
    - Idea
    - 주어진 숫자 array의 끝에 도달할 수 있는지 확인하는 문제
- Solve
    1. 내가 푼 방법
        1. 재귀를 이용해서 점프할 수 있는 가장 큰 값부터 탐색하며, visited 배열을 이용해 기록한다.
        2. 마지막 element에 도달하였다면 return 해준다.
    2. for문 하나로 푸는 방법
        1. int 변수(reachable)를 하나 선언한다.
        2. for문을 돌며 reachable과 nums[i]+i 를 비교하여 더 큰 값으로 갱신해준다.
        3. i가 reachable보다 크면 마지막에 도달할 수 없는 것이다.
- Complexity
    1. Time
        - 백트래킹: O(N^2)
        - for문 1개: O(N)
    2. Space
        - 백트래킹: O(N) = nums 배열 O(N) + visited 배열 O(N)
        - for문 1개: O(N) = nums 배열 O(N)

## 220609
### LeetCode 62. Unique Paths: [Problem](https://leetcode.com/problems/unique-paths/)
- Algorithm: DP
- Idea:
    - M*N 행렬의 오른쪽 끝에 도달할 수 있는 유니크 경로의 개수 구하기. 
    - 오른쪽 또는 아래쪽으로만 이동할 수 있다.
- Solve
    1. memo[m][n]의 의미는 해당 위치에 도달할 수 있는 고유한 경로의 개수이다.
    2. 오른쪽 또는 아래로만 움직일 수 있으므로 memo 배열의 관계, 즉 점화식은 다음과 같다.
        - `memo[i][j] = memo[i-1][j] + memo[i][j-1]`
    3. for문 두개를 이용해 답을 구한다.
- Complexity
    1. Time: O(M*N) = M열 N행
    2. Space: O(M*N) = M열 N행

### LeetCode 143. Reorder List: [Problem](https://leetcode.com/problems/reorder-list/)
- Algorithm: Linked List
- Idea
    - 링크드 리스트 항목들의 순서를 바꾸는 문제. 첫번째 노드가 마지막을, 두번째 노드가 마지막에서 두번째 것을 가리키게 한다.
    - Ex) 1 -> 2 -> 3 -> 4  => 1 -> 4 -> 2 -> 3
- Solve
    1. `vector<ListNode*> v` 를 하나 선언해서 순서대로 담았다.
    2. for문을 전체 개수의 절반까지만 반복하며 주어진 규칙대로 연결해준다.
        - 새로운 마지막 노드의 next를 nullptr로 바꿔주는 것이 필요하다. 해당 조건을 잘 생각해보자.
- Complexity
    1. Time: O(N) = vector 담기 O(N) + for문 순회 O(N/2)
    2. Space: O(N) = vector O(N)

### BOJ 16197. 두 동전: [Problem](https://www.acmicpc.net/problem/16197)
- Algorithm: 백트래킹, 시뮬레이션
- Idea
    - 두 개의 동전 중 하나만 떨어지게 하는 최소의 이동횟수 구하기.
    - 둘 다 떨어지거나 이동횟수가 10을 초과하면 리턴.
- Solve
    1. 백트래킹(DFS)로 접근하였다. 동전 2개의 위치를 주의해서 체크해주면 된다.
        - 동전이 하나만 떨어졌는지, 둘 다 떨어졌는지 체크하는 함수를 구현해주었다.
    2. 하나만 떨어졌으면 기존 answer와 비교하여 answer를 갱신해준다.
- Complexity
    1. Time: 버튼이 4방향이고 최대 10번까지 누르므로 최대 4^10 경우의 수를 가진다. 그러나 가지치기가 이루어지므로 정확한 복잡도는 모르겠다.
    2. Space: O(N*M) = map 배열

## 220606
### BOJ 10422. 괄호: [Problem](https://www.acmicpc.net/problem/10422)
- Algorithm: DP, 카탈란수
- Idea
    - 올바른 괄호수의 개수를 구하는 문제.
    - O(N^2)의 DP 풀이 또는 카탈란 수로 O(N)으로 풀 수 있다고 한다. 여기서는 DP 풀이를 소개한다.
    - 카탈란 수를 공부하고 다시 풀어보자.
- Solve
    1. 늘 그렇듯 먼저 DP 배열을 정의한다.
        - `memo[2501][2501]`: 현재 왼쪽 괄호와 오른쪽 괄호의 상태가 다음과 같을 때 괄호수의 개수
        - Top down 방식이고 최종 값에만 의미가 있다. L = 2이면 memo[1][1], L = 4이면 memo[2][2]에 해당한다.
    2. 처음에 왼쪽 괄호와 오른쪽 괄호의 개수는 동일한 점을 이용한다.
        - 재귀함수를 돌며 왼쪽 괄호와 오른쪽 괄호를 1씩 감소시키고, 모두 0이되면 1을 리턴하여 이전 memo에 더해준다.
    3. 이 [링크](https://kth990303.tistory.com/265)의 설명을 참고했다.
        - 그런데 이 풀이는 L이 5000인 경우 내 컴퓨터에서 함수 stack overflow가 발생했다. dp(2500, 2500)
        - 로컬 PC의 stack memory는 1MB인데 백준은 스택, 힙, 정적 메모리를 모두 합쳐서 제한한다고 한다. 따라서 1MB 이상 쓸 수 있다.
- Complexity
    1. Time: O(N^2) = N/2번 탐색 * N/2번 탐색
    2. Space: O(N^2) = O(N/2) * O(N/2)

## 220605
### BOJ 12869. 뮤탈리스크: [Problem](https://www.acmicpc.net/problem/12869)
- Algorithm: DP, 백트래킹
- Idea
    - SCV 3기의 체력이 주어질 때 뮤탈리스크가 공격해야 하는 횟수의 최대값 구하기.
    - DP문제 해결과정은 [다음책]((http://www.kyobobook.co.kr/product/detailViewKor.laf?mallGb=KOR&ejkGb=KOR&barcode=9788931586053))에서 말하는 수학적 사고의 과정과 닮은것 같다.
        - 수학적 사고는 정의, 분석, 체계화의 과정으로 진행된다.
        - DP 문제 해결도 dp 배열의 정의, 요소 분석, 관계를 파악하여 점화식 세우기의 과정을 거친다.
        - 수학적 사고 연습을 위해 DP 문제를 많이 풀어봐야 겠다.
- Solve
    1. DP배열(memo)의 정의는 다음과 같다.
        - memo[hp1][hp2][hp3]: 현재 hp 들을 파괴하는데 필요한 최소 공격 횟수
        - 초기값으로 INF(987654321)을 넣어 최초 비교시 갱신될 수 있게 한다.
    2. 백트래킹 방식으로 hp들을 넘겨주며, hp가 모두 0이 되면 0을 리턴한다.(hp가 모두 0이면 공격 할 필요가 없다)
        - 계산과정 중 hp가 음수가 되면 0을 넘겨주도록 하였다.
        - 현재 memo 배열 값이 INF가 아니면 이미 계산된 것이므로 배열 값을 리턴한다.

### BOJ 2023. 신기한 소수: [Problem](https://www.acmicpc.net/problem/2023)
- Algorithm: DP, 백트래킹
- Idea
    - 1에서 N자리까지 모두 소수인 숫자를 찾아야 한다.
    - 소수를 판별하기 위한 isPrime() 구현은 알아두자. Square root 까지만 검사하면 된다.
- Solve
    1. 처음 접근은 hash map을 활용해서 한번 계산한 것은 다시 계산하지 않도록 한 것이다.
        - 1의 자리부터 10개를 전부 검사하는데, 다음에 나올 방법보다 더 많은 계산을 하므로 느리다.
    2. 한 자리 소수를 생각해보면 2, 3, 5, 7 이다. 첫 반복문을 이 4개로 시작하면 계산을 줄일 수 있다.
        - 그리고 처음에 0을 전달하느냐 아니냐에 따라 계산 횟수가 많이 차이가 난다.
        - 0을 전달하면 N자리 소수를 탐색할 때 1 ~ N-1 자리 소수도 중복으로 계산한다.

## 220604
### BOJ 2616. 소형기관차: [Problem](https://www.acmicpc.net/problem/2616)
- Algorithm: DP, 누적합
- Idea
    - 소형 기관차 3개를 썼을 때 가장 많은 손님을 끌 수 있는 경우를 찾기.
    - 누적합을 이용해서 구간의 합을 빠르게 구할 수 있다. 여기에 DP 요소를 결합해야 한다.
- Solve
    1. DP 배열 memo[4][50001]에서 첫째 parameter는 소형 기관차의 개수이며 두번째는 객실 번호이다.
    2. for문 2개를 사용하는데 i는 0부터 3까지 사용하는 소형 기관차의 개수만큼 반복한다.
        - j의 시작점은 i * S 이고 종료지점은 N이다. (S: 소형 기관차가 끌 수 있는 개수, N: 객차의 수)
    3. 다음 점화식을 수행하며 마지막 배열의 원소가 찾고자 하는 값이다.
        - `memo[i][j] = max(memo[i][j-1], memo[i-1][j-S] + presum[j] - presum[j-S]);
        - 첫번째 값의 의미는 바로 전 값이다.
        - 둘째 값은 소형기관차를 1개 덜 쓸때의 최대값 + 그 이후 j까지의 객차 손님수의 합(기관차 1개 더 사용)이다.
        - 가장 큰 값으로 갱신되며 그 값이 유지가 될 것이다.

### BOJ 13904. 과제: [Problem](https://www.acmicpc.net/problem/13904)
- Algorithm: 그리디, 정렬
- Idea: 하루에 한 과제를 할 수 있다고 할 때, 과제 duedate을 감안하여 가장 높은 점수를 받을 수 있는 경우 찾기.
- Solve
    1. duedate와 point를 vector에 담고 다음 조건대로 정렬한다.
        1. 과제 점수가 높은 순
        2. 마감일이 적게 남은 순
    2. for문 2개를 이용하여 가장 우선순위가 높은 것부터 탐색한다.
        - 두번째 for문에서는 가장 우선순위가 높은 것의 duedate부터 1씩 감소시키며 해당날짜에 과제를 수행했는지 확인한다.
        - visited 배열을 두면 해당 날짜에 과제를 수행했는지 확인할 수 있다.
    3. 과제 점수가 높은 순으로 정렬했기 때문에 visited 배열이 false이면 바로 sum에 더해주면 된다.
        - 점수가 높은데 visited 배열이 true여서 당장 더하지 못하면, j(day)를 1씩 감소시키며 빈 slot을 찾는다.
        - 이것의 의미는 과제 duedate대로 수행하는 것이 아니라, duedate가 여유있더라도 점수가 높은 것을 선택한다는 것이다.

### BOJ 11559. Puyo Puyo: [Problem](https://www.acmicpc.net/problem/11559)
- Algorithm: 구현, BFS
- Idea: 
    - 현재 Puyo의 배치에서 몇 연쇄가 일어날 수 있는지 판단하는 문제.
    - 현재 상태에서 터질 수 있는 애들이 다 터진다음 이동시키는 것이 1연쇄이다.
- Solve
    1. 구현한 method
        - scan_arr(): simulation main()에 해당한다. 현재 map 전체를 스캔하고, 가능한 덩어리들을 터트린 다음, puyo들을 이동시킨다.
        - bfs(): Puyo가 터질 수 있는 조건(4개 이상 연결)은 BFS로 탐색하도록 했다.
        - move_puyos(): 터질 수 있는 뭉탱이들을 다 터뜨린 후 중력의 방향으로 이동시킨다. 

## 220602
### BOJ 5557. 1학년: [Problem](https://www.acmicpc.net/problem/5557)
- Algorithm: DP
- Idea: 마지막 숫자를 만들 수 있는 경우의 수를 구하는 문제. Top down 또는 bottom up 방식으로 풀 수 있다.
- Solve
    1. Top down 방식은 백트래킹에 dp(memo) 를 조합하는 방식으로 구현한다.
        - 최초 함수 호출시 인자로 (0, 0)을 전달하면 틀리고 (1, arr[0])를 전달해야 통과되었다. 반례를 모르겠다.
        - SWEA의 백트래킹 문제로 자주 보이는 유형이다.
    2. 이중 for문을 이용한 bottom up 방식도 알아두도록 하자.
- Complexity (Bottom up)
    1. Time: O(N*E) = N개 x 가능한 합의 범위 20
    2. Space: O(N*E) = N개 x 가능한 합의 범위 20

## 220601
### BOJ 15656. N과 M (7): [Problem](https://www.acmicpc.net/problem/15656)
- Algorithm: 백트래킹, 정렬
- Idea: 일반적인 백트래킹 문제. 연습을 위해 merge sort를 구현하였다.
- Complexity
    1. Time: O(NlogN) = Merge Sort O(NlogN)
    2. Space: O(N) = Merge Sort O(2*N)

## 220526
### LeetCode 300. Longest Increasing Subsequence: [Problem](https://leetcode.com/problems/longest-increasing-subsequence/)
- Algorithm: DP
- Idea: 일반적인 LIS 문제.
- Solve
    1. for문 2개를 이용하면 O(N^2)의 시간이 걸린다.
    2. 이분탐색을 이용하면 O(N*logN)의 복잡도를 가진다.

### BOJ 1135. 뉴스 전하기: [Problem](https://www.acmicpc.net/problem/1135)
- Algorithm: Greedy, DFS
- Idea
- Solve
    1. 처음에 현재 자식의 수가 가장 많은 노드부터 dfs를 시작하도록 하였다. 그러나 답이 아니었다. 다음 [링크](https://www.acmicpc.net/board/view/760) 설명을 읽어보자.
        1. 그러나 많은 자식을 가지고 있다고 해서 가장 먼저 뉴스를 전하는 것이 올바른 선택이 아닐 수 있다.
        2. 노드 1, 2가 있다고 가정하자. 노드 1의 자식노드의 수는 노드 2보다 많다.
        3. 하지만 노드 1의 자식들은 균형이 잘 맞춰져 있어서 깊이가 별로 깊지 않다.
        4. 노드 2는 노드 1보다 자식의 수가 적지만 한 쪽으로 치우쳐져 링크드 리스트 같은 형식을 이루고 있다.
        5. 이런 경우 노드 1에 먼저 준다고 항상 더 빠르게 전파할 수 있는 것은 아니다.
    2. 그럼 어떻게 선택해야 할까?
        - 가장 많은 시간이 걸리는 자식을 선택해야 한다. 이는 재귀와 분할정복으로 구현한다.
        - 설명을 읽어보자. [링크](https://kibbomi.tistory.com/232)
            - 설명에서는 가장 오래 걸리는 자식을 선택한다고 되어있는데, 구현은 반대로 되어있다.
            - 나는 Max PQ를 사용하여 가장 오래 걸리는 자식을 선택하도록 하였다.

## 220525
### BOJ 14002. 가장 긴 증가하는 부분 수열 4: [Problem](https://www.acmicpc.net/problem/14002)
- Algorithm: DP
- Idea: 부분 수열 길이를 계산할 때 가장 큰 부분수열도 같이 기록한다.
- Solve
    1. DP 배열을 선언해서 동일하게 가장 긴 부분수열의 길이를 계산한다.
    2. vector<int> LIS[1001] 배열을 선언하여, DP 배열이 갱신될 때 LIS를 저장한다.
    3. LIS를 answer에 계속 갱신시켜 최대 LIS를 출력한다.
- Note: LIS 길이를 찾을 때 이분탐색을 사용하기도 하는데, 이 때 vector에 만들어지는 수열은 LIS가 아닐 수 있다. [링크 참고](https://www.acmicpc.net/board/view/75744)

## 220523
### LeetCode 242. Valid Anagram: [Problem](https://leetcode.com/problems/valid-anagram/)
- Algorithm: Hashing
- Idea: unordered_map을 활용해서 anagram을 판별하는 문제.
- Solve
    - Note: find()를 써서 키가 있는지 먼저 확인을 하자. um[key] 를 하면 자동으로 Entry가 생성이 된다.
    - 즉 다음과 같이 활용. `if (um.find(t[i]) != um.end() && um[t[i]] > 0)`

## 220520
### BOJ 2357. 최솟값과 최댓값: [Problem](https://www.acmicpc.net/problem/2357)
- Algorithm: 세그먼트 트리
- Idea: 최소값 세그먼트 트리와 최대값 세그먼트 트리를 구현한다.
- Complexity
    - Time: O(NlogN) = 삽입 O(NlogN) + 쿼리 O(NlogN)
    - Space: O(N) = Array O(N) + 트리 O(4*N)

### BOJ 6443. 애너그램: [Problem](https://www.acmicpc.net/problem/6443)
- Algorithm: 백트래킹
- Idea: 주어진 알파벳으로 가능한 모든 조합을 구하는 문제
- Solve
    1. 처음에는 주어진 string을 정렬하고 string size 내에서 조합을 구하며, 중복은 hashing으로 하려고 했다.
        - 그런데 메모리와 시간 초과가 났다. hashing을 하지 않고도 중복없이 출력해야 하는것 같았다.
    2. 아이디어가 떠오르지 않아 구글의 도움을 받았다.
        - string을 입력받을 때 각 alphabet의 개수를 세어 저장한다.
        - 재귀 함수 내에서 alphabet 개수(26개) 만큼 for문을 돌며 alphabet[i]가 0보다 클 때 이후 단계를 진행한다.
        - 이렇게 하면 모든 단계를 진행하고 hashing으로 중복을 제거하는 것이 아니라, 필요없는 단계를 진행하지 않는다.

### BOJ 1697. 숨바꼭질: [Problem](https://www.acmicpc.net/problem/1697)
- Algorithm: BFS
- Idea
    - 일직선 상에서 수빈이와 동생의 위치가 주어졌을 때, 동생을 찾을 수 있는 가장 빠른 시간을 구하는 문제
    - Queue를 이용한 일반적인 BFS 문제이다.

### BOJ 5525. IOIOI: [Problem](https://www.acmicpc.net/problem/5525)
- Algorithm: 문자열, KMP, 라빈-카프
- Idea: 몇 개의 풀이가 있는데, 나는 KMP로 직접 개수를 세어 주었다.
- Solve
    1. N을 입력받고 찾고자 하는 패턴(IOI...)를 만든다.
    2. KMP로 개수를 세어준다.
- Complexity
    1. Time: O(N) = 패턴 만들기 O(N) + KMP 탐색 O(N)
    2. Space: O(N) = KMP 테이블 O(N)

### BOJ 1446. 지름길: [Problem](https://www.acmicpc.net/problem/1446)
- Algorithm: DP, 그래프 이론, 다익스트라
- Idea: 브루트 포스로 0부터 D까지 dist[] 배열을 탐색하면서 지름길을 이용해 거리를 갱신해준다.
- Solve
    1. 인접 리스트로 지름길의 출발점, 도착점 그리고 길이정보들을 간선과 해당 비용으로 저장한다.
        - 지름길이 도착점 - 출발점 사이보다 크다면 저장할 필요가 없다.
        - 또한 역주행을 할 수 없으므로 D를 넘어가면 저장하지 않는다.
    2. dist 배열에 i에 도착하기 위한 최소 운전 길이를 저장한다.
        - 지름길을 탔을 때와 이전 경로에서 그냥 운전했을 때를 비교해 최소값을 dist[i]에 저장한다.
        - 지름길을 탔을 경우 다음 출발점에 도달할 때까지 계속 갱신하게 된다.
    3. 탐색 완료 후 dist[D]를 출력한다.
 - Complexity
    1. Time O(D) = dist 배열 탐색 O(D) (+ i번째에서 출발하는 지름길 탐색 O(D*N): N은 최대 12이므로 무시할 정도이다.)
    2. Space O(D*N) = dist 배열 O(D) + 인접 리스트 O(D*N)

## 220519
### BOJ 11652. 카드: [Problem](https://www.acmicpc.net/problem/11652)
- Algorithm: Hash, Sorting
- Idea: 여러 카드가 주었졌을 때 가장 많이 갖고 있는 정수를 구하는 문제
- Solve
    1. Hash 테이블에 카드와 카드의 개수를 저장한다.
    2. 개수에 따라 정렬할 수 있도록 array에 옮기고, 정렬을 수행한다.
- Complexity
    1. Time: O(NlogN) = Hashing O(1*N) + Sorting O(NlogN)
    2. Space: O(N) = Hashing O(N) + Array O(N)

## 220517
## LeetCode 19. Remove Nth Node From End of List: [Problem](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
- Algorithm: Linked List
- Idea: 끝에서 n번째 Element를 삭제하는 문제
- Solve
    1. head 부터 끝까지 탐색하여 element count를 계산한다.
    2. 다시 처음부터 탐색하여 N-1번째에 prev pointer를 기록하고, N번째로 넘어가서 prev pointer가 그 다음 element를 가리키게 한다.
- Compexity
    1. Time: O(N) = 최초 탐색 O(N) + 이후 탐색 O(N)
    2. Space: O(N)

### BOJ 1976. 여행 가자: [Problem](https://www.acmicpc.net/problem/1976)
- Algorithm: 그래프 이론, 유니온 파인드
- Idea: 유니온 파인드 기본개념 문제.
- Solve
    - **Note**: 일반적인 unionParent 함수 구현을 보면 parent 값을 갱신할 때 자신의 부모, 또는 부모의 부모를 갱신하고 넘어간다.
        - 즉, `parent[b] = pa` 또는 `parent[pb] = pa` 으로 한 번 assign 하고 넘어간다.
    - 그러나 재귀적으로 모든 부모를 업데이트 하지 않으면 제대로 union이 되었다고 보기 어렵다.
        - 두 개의 집합을 union 했을 때 parent 배열을 검사하면 업데이트 되지 않은 요소가 있을 수 있다.
        - 따라서 setParent() 함수를 추가하여 재귀적으로 모든 부모를 업데이트 해주었다.
    - parent 배열이 업데이트 되지 않은 상황은 다음 반례로 확인할 수 있다. union까지 진행한 후 breakpoint를 걸어 확인가능.
        - [출처](https://www.acmicpc.net/board/view/61137)
        ``` 4
           4
           0 0 0 1
           0 0 1 0
           0 1 0 1
           1 0 1 0
           3 1 2 4

## 220516
### BOJ 9249. 최장 공통 부분 문자열: [Problem](https://www.acmicpc.net/problem/9249)
- 라빈 카프를 응용해서 풀어보려 했으나 실패.
- Longest Common Prefix로 풀어야 한다고 한다. 공부하고 다시 풀어보자.

### BOJ 12865. 평범한 배낭: [Problem](https://www.acmicpc.net/problem/12865)
- Algorithm: DP
- Idea: 배낭문제 개념을 공부하기 위해 다시 풀었음
- Solve
    1. DP 배열을 정의하는 것이 중요하다. `memo[A][B] = C` 의 의미는 A번째 물건까지 왔고 B의 무게를 가질때 C의 가치가 있다.
    2. for문 두개를 활용한다.
        - 바깥 for문은 물건을 0번부터 탐색한다.
        - 안쪽 for문은 1부터 한계 무게까지 탐색한다.
    3. 안쪽 for문에서 i번째 물건을 넣거나 넣지 않을 때의 최대값을 찾는다.
        - `memo[i][j] = max(memo[i-1][j], memo[i-1][j-W[i]] + V[i])`
        - memo[i-1][j]의 의미는 i-1까지의 물건으로 이미 무게 j를 만든 것이다.
        - memo[i-1][j-W[i]] + V[i]의 의미는 i번째 물건으로 무게 j를 만든 것이다.

## 220515
### Binary Search의 lower_bound, upper_bound 구현 연습

### BOJ 10814. 나이순 정렬: [Problem](https://www.acmicpc.net/problem/10814)
- Algorithm: Sorting
- Idea: struct에 대한 sorting을 연습한 문제. 
- Solve: Struct compare 함수와 merge sort를 구현하였다.

### BOJ 2167. 2차원 배열의 합: [Problem](https://www.acmicpc.net/problem/2167)
- Algorithm: Prefix Sum
- Idea: 기본적인 2차원 prefix sum 문제

### BOJ 10282. 해킹: [Problem](https://www.acmicpc.net/problem/10282)
- Algorithm: 다익스트라
- Idea: adjacency vector로 단방향 그래프를 구성하고 다익스트라 알고리즘을 적용한다.
- Complexity
    1. Time: O(E logE) = 간선 검사 O(E) * 우선순위 큐 추가 O(logE)
    2. Space: O(N+E) = adjacency vector O(N+E) + 우선순위 큐 O(E)

## 220514
### BOJ 9465. 스티커: [Problem](https://www.acmicpc.net/problem/9465)
- Algorithm: DP
- Idea: 스티커를 떼어낼 수 있는 조건이 있을 때, 뗀 스티커들의 최대 가치합 찾기
- Solve
    - 조건: 스티커를 떼면 상하좌우의 스티커는 뗄 수 없다.
    - 점화식
        1. 윗줄: `memo[1][i] = max(memo[2][i-1] + arr[1][i], memo[2][i-2] + arr[1][i]);`
        2. 아랫줄: `memo[2][i] = max(memo[1][i-1] + arr[2][i], memo[1][i-2] + arr[2][i]);`
    - 1부터 N까지 memo 배열을 계산하여 최대값을 찾는다.

### BOJ 11057. 오르막 수: [Problem](https://www.acmicpc.net/problem/11057)
- Algorithm: DP
- Idea: 각 자리수가 크거나 같은 수를 오르막 수라고 하며, 그것의 개수를 찾는 문제
- Solve
    1. DP 배열 정의: `memo[i][j]` i번째 자리수가 j로 끝나는 경우의 수
    2. 오르막 수의 특성대로 이전 자리수보다 크거나 같은 경우의 수를 모두 더해준다.

### BOJ 11054. 가장 긴 바이토닉 부분 수열: [Problem](https://www.acmicpc.net/problem/11054)
- Algorithm: DP
- Idea: 가장 긴 증가하는 부분 수열과 가장 긴 감소하는 부분 수열을 조합하는 문제
- Solve
    1. 배열을 앞에서부터 탐색하여 가장 긴 증가하는 부분 수열의 길이를 찾는다.
    2. 배열을 뒤에서부터 탐색하여 가장 긴 감소하는 부분 수열의 길이를 찾는다.
    3. 만들어진 두 DP 배열을 탐색하여 어느 index에서 가장 긴 바이토닉 부분 수열이 되는지 찾는다.

### SWEA 4311. 오래된 스마트폰: [Problem](https://swexpertacademy.com/main/code/problem/problemSolver.do?contestProbId=AWL2vlPKMlQDFAUE&)
- Algorithm: 백트래킹, DP
- Idea: 계산기에서 원하는 숫자를 만들고자 할 때, 최소 터치 횟수를 찾아라. 누를 수 없는 버튼들이 있다.
- Solve
    1. best[1000] 배열은 해당 숫자를 몇 번 터치로 만들 수 있는지 값을 저장하는 배열이다.
        - 조합을 이용해 주어진 숫자로 만들 수 있는 것들을 미리 만든다. 가지치기를 위해 정렬해둔다.
    2. 재귀 함수에서 가능한 숫자들과 연산자로 계산을 수행한다.
        - 가능한 가지치기를 모두 적용한다. 예를 들어 더하기 중 999를 초과하였을 때 이후 숫자를 더해도 초과할 것이므로 가지치기를 수행한다.
    3. 백트래킹 종료 후 타겟 넘버를 몇 번 터치로 만들 수 있는지 출력한다.

## 220513
### SWEA 8191. 만화책 정렬하기: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWwtYmX6hvsDFAWU)
- Algorithm: Array
- Idea: 뒤섞인 만화책을 몇 번 탐색해야 순서대로 정렬되는지 확인하는 문제
- Solve
    - 배열에 만화책 번호의 위치를 기록한다.
    - 연속된 만화책이 앞선 위치에 있다면 재탐색이 필요한 것이다. 재탐색이 필요한 개수를 세어준다.
- Complexity
    1. Time: O(N) 연속된 책 간에 비교수행
    2. Space: O(N) 번호 배열

### BOJ 11052. 카드 구매하기: [Problem](https://www.acmicpc.net/problem/11052)
- Algorithm: DP
- Idea: N장의 카드를 구매할 때, 지불해야 하는 최대금액을 구해야 하는 문제
- Solve
    1. DP 배열 정의: `DP[A] = B` A장의 카드를 사는데 지불해야 하는 최대 금액은 B원 이다.
    2. 점화식 정의: `DP[N] = Card[1] + DP[N-1]`, `DP[N] = Card[2] + DP[N-2]`, ... ,`DP[N] = Card[N] + DP[0]`
        - 위 값중 최대값을 저장한다.
    3. N을 증가시키면서 최종 결과를 찾는다.
- Complexity
    1. Time: O(N^2)
    2. Space: O(N) = O(N) 카드 정보 + O(N) memo 배열

## 220512
### SWEA 7088. 은기의 송아지 세기: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWkIeU76A9cDFAXC)
- Algorithm: Prefix Sum, 이진 탐색, 세그먼트 트리
- Idea: 주어진 범위 내에서 각 품종이 몇 마리씩 있는지 값을 찾는 문제
- Solve: 다양한 방법이 가능하다.
    - Prefix Sum: `Count[a][1] = b` 의 의미는 a번 index까지 1번 품종인 송아지는 b마리가 있다.
    - 이진탐색:  각 품종의 벡터에 넣고 upper/lower_bound를 찾음
    - 세그먼트 트리를 이용한 풀이도 가능
- Complexity: 세그먼트 트리
    1. Time: O(NlogN) = 삽입 O(NlogN) + 쿼리 O(QlogQ)
    2. Space: O(N) = 배열 O(N) + 트리 O(4*N)

### LeetCode 322. Coin Change: [Problem](https://leetcode.com/problems/coin-change/)
- Algorithm: DP

### LeetCode 295. Find Median from Data Stream: [Problem](https://leetcode.com/problems/find-median-from-data-stream/)
- Algorithm: Priority Queue
- Idea: 가운데를 말해요(BOJ 1655)와 유사한 문제

## 220511
### LeetCode 347. Top K Frequent Elements: [Problem](https://leetcode.com/problems/top-k-frequent-elements/)
- Algorithm: Hash Table, Heap, Sorting
- Idea: 빈도수가 가장 높은 순으로 숫자를 정렬하는 문제. 몇 가지 자료구조를 조합하여 구현함
- Solve
    1. 전달받은 nums 배열을 순회하며 hash table에 빈도수를 저장한다.
    2. 숫자와 빈도수를 pair로 보관하는 priority queue를 준비한다.
        - 빈도수가 높은 순으로 정렬하도록 Compare struct를 비교 functor로 전달한다.
    3. 숫자와 빈도를 hash에서 꺼내어 priority queue에 저장한다.
    4. priority queue 앞에서 k개 만큼 꺼내어 리턴한다.
- Complexity
    1. Time: O(NlogN) = Hash O(1*N) + PQ O(NlogN)
    2. Space: O(N) = Hash O(E) + Used vector O(E) + PQ O(N) + Return vector O(K)

## 220508
### BOJ 1605. 반복 부분문자열: [Problem](https://www.acmicpc.net/problem/1605)
- Algorithm: Hashing, Ravin-Karp
- Idea: 롤링 해쉬를 이용해 문자열을 탐색한다. BOJ 3033(가장 긴 문자열)과 같은 문제이다.
- Solve
    1. 롤링 해쉬를 이용해 문자열을 탐색한다.
        - 부분 문자열의 길이는 binary search을 통해 최적의 값을 찾아 나간다.
        - 롤링 해쉬를 계산하는 기법을 알아두자.
    2. Table에서 해당 해쉬값이 있으면 연결된 리스트를 탐색하여 같은 문자열이 있는지 검사한다.
        - unordered_map에 substring 자체를 담으면 메모리 overflow되므로 탐색 문자열 버퍼의 포인터를 value로 저장하였다.
    3. 2에서 같은 문자열이 있으면 true를 리턴한다.

### BOJ 1405. 미친 로봇: [Problem](https://www.acmicpc.net/problem/1405)
- Algorithm: 백트래킹, 수학
- Idea: 일반적인 백트래킹에 확률 계산을 더한 문제
- Solve
    1. 확률을 입력받을 때 double 형 percent로 변환하여 입력받는다.
    2. 2차원 visited 배열을 이용해 방문한 곳이면 가지 않는다.
        - 최대 14번씩 동서남북으로 갈 수 있기 때문에 배열의 크기는 30 x 30으로 했다.
        - 시작점은 (14, 14)이다.
    3. 재귀함수로 백트래킹을 수행하며 정상적으로 N번째에 도달하면 1.0을 리턴한다.
        - 이 1.0은 이전 재귀함수에서 percent와 곱해져서 성공 확률에 추가된다.
    4. 주어진 N에 대해 동서남북으로 DFS를 진행하며 모든 성공확률을 더한다.

### BOJ 14427. 수열과 쿼리 15: [Problem](https://www.acmicpc.net/problem/14427)
- Algorithm: 우선순위 큐, 세그먼트 트리
- Idea: 두번째 풀이. 우선순위 큐 업데이트에 익숙해지기 위해

### SWEA 5432. 쇠막대기 자르기: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWVl47b6DGMDFAXm)
- Algorithm: 스택
- Idea: 스택을 활용하여 쇠막대기를 자르는 타이밍을 확인하고 개수를 더해 나간다.
- Solve
    1. input이 `(` 이면 스택에 넣는다.
    2. input이 `)` 이면 두 가지 경우가 생긴다.
        - 바로 이전 input이 `(`이면 레이저를 쓰는 것이다. stack element 개수만큼 더해주면 된다.
        - 아니면 쇠막대기 하나의 종료 지점이므로 1개만 더해준다.

## 220507
### BOJ 20920. 영단어 암기는 괴로워: [Problem](https://www.acmicpc.net/problem/20920)
- Algorithm: Hash, Sort
- Idea
    - String과 cnt의 쌍으로 hash에 저장한 다음, 조건에 맞게 정렬한다. 연습을 위해 Hash를 직접 구현해 주었다.
    - Priority Queue를 갱신하는 방법도 있는데, update 구현이 어렵고 연습이 필요하다.
- Complexity
    1. Time: O(NlogN) = Hashing O(1*N) + Sorting O(NlogN)
    2. Space: O(N) = O(N) + O(N)

### BOJ 9251. LCS: [Problem](https://www.acmicpc.net/problem/9251)
- Algorithm: DP
- Idea: 2차원 dp 배열을 활용하여 가장 긴 subsequence를 찾는다.
- Solve
    - LCS 배열을 만드는 과정. subsequence의 길이는 이 단계만 진행해도 찾을 수 있다.
        1. 문자열 A, 문자열 B를 한글자씩 비교해본다.
        2. 두 문자가 다르다면 LCS[i-1][j]와 LCS[i][j-1] 중에 큰 값을 표시한다.
        3. 두 문자가 같다면 LCS[i-1][j-1] 값을 찾아 +1 한다.
        4. 위 과정을 반복한다.
    - 이 후 다시 반복문을 통해 거꾸로 추적하면서 가장 긴 subsequence를 찾을 수 있다.
- Complexity
    1. Time & Space: O(N^2)

## 220506
### BOJ 1753. 최단경로: [Problem](https://www.acmicpc.net/problem/1753)
- Algorithm: Dijkstra
- Idea: 우선순위 큐를 이용해 가장 낮은 가중치를 가진 간선을 O(1)으로 찾는다.
- Solve
    1. 간선정보를 adjacency vector에 담는다.
    2. 다익스트라를 위한 dp 배열과 우선순위 큐를 준비하고 start 값을 지정한다.
        - 다음과 같은 vector 선언은 알아두자. `vector<int> dp(V + 1, INF);`
        - 구조체 또는 pair를 우선순위 큐에 담는 방법은 기본적으로 알아야 한다.
    3. while문 안에서 현재 가장 작은 가중치를 가진 노드를 바탕으로 dp 배열을 업데이트 한다.
        - 더 이상 업데이트가 일어나지 않으면 PQ에 추가가 안 되므로 while 문이 종료된다.
    4. dp 배열 값을 출력한다.
- Complexity
    1. Time: O(E * logE) = E 개의 간선을 검사하고 PQ에 추가하는 작업
    2. Space: O(V+E) 인접리스트

## 220505
- 내일부터 다시 한글로 작성할 것이다. 영어로 하니 공부한거 찾기도 힘들고 잘 안 올리게 된다.. 나중에 다시 시도할 수 있다.
### BOJ 1920. 수 찾기: [Problem](https://www.acmicpc.net/problem/1920)
- Algorithm: Binary search
- Idea: A basic binary search problem

### BOJ 10815. 숫자 카드: [Problem](https://www.acmicpc.net/problem/10815)
- Algorithm: Binary search
- Idea: A basic binary search problem

### BOJ 10816. 숫자 카드2: [Problem](https://www.acmicpc.net/problem/10816)
- Algorithm: Binary search
- Idea: An advanced binary search problem
- Solve
    1. Find the target value by binary search.
    2. Find lower and upper bound of the same value.
        - You can use STL to find the bounds.
    3. Return the distance of the bounds.
- Complexity
    1. Time: O(N logN) = O(logN) with N elements
    2. Space: O(N)

### BOJ 10868. 최솟값: [Problem](https://www.acmicpc.net/problem/10868)
- Algorithm: Segment Tree
- Idea: A basic segment tree problem

### LeetCode 21. Merge Two Sorted Lists: [Problem](https://leetcode.com/problems/merge-two-sorted-lists/)
- Algorithm: Linked List
- Solve
    1. Maintain a head and a tail pointer on the merged linked list.
    2. Then choose the head of the merged linked list by comparing the first node of both linked lists.
    3. For all subsequent nodes in both lists, choose the smaller current node and link it to the tail of the merged list.
        - and moving the current pointer of that list one step forward
    4. You keep doing this while there are some remaining elements in both the lists.
    5. If there are still some elements in only one of the lists, link this remaining list to the tail of the merged list.
        - Initially, the merged linked list is NULL.
    6. Compare the value of the first two nodes and make the node with the smaller value the head node of the merged linked list.
        - Since it's the first and only node in the merged list, it will also be the tail.
    7. Then move head 1 one step forward.

## 220504
### BOJ 2665. 미로만들기: [Problem](https://www.acmicpc.net/problem/2665)

### LeetCode 100. Same Tree: [Problem](https://leetcode.com/problems/same-tree/)
- Algorithm: Binary Tree, DFS
- Solve
    - Compare the two tree by preoder traversal(DFS).
    - Check all the unmatched conditions.

## 220503
### BOJ 1202. 보석 도둑: [Problem](https://www.acmicpc.net/problem/1202)

### LeetCode 200. Number of Islands: [Problem](https://leetcode.com/problems/number-of-islands/)
- Algorithm: BFS
- Solve
    1. Find a unvisited node inside a for loop.
    2. Traverse all the adjacent nodes from the unvisited node, and mark them as visited.
        - Increase count after finishing the travel.
    3. Repeat 1 & 2 for the entire map.
- Complexity
    1. Time: BFS O(N+E)
    2. Space: O(N*N)

### LeetCode 141. Linked List Cycle: [Problem](https://leetcode.com/problems/linked-list-cycle/)
- Algorithm: Linked List, Two Pointers
- Idea: Traverse linked list using two pointers.
- Solve
    1. Move one pointer(slow_p) by one and another pointer(fast_p) by two.
    2. If these pointers meet at the same node then there is a loop.
        - If pointers do not meet then linked list doesn't have a loop.
- Complexity
    1. Time: O(N) - for traversing
    2. Space: O(1) - nothing stored

### LeetCode 70. Climbing Stairs: [Problem](https://leetcode.com/problems/climbing-stairs/)
- Algorithm: Dynamic Programming
- Solve: Same with the Fibonacci problem

## 220502
### SWEA 3143. 가장 빠른 문자열 타이핑: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV_65wkqsb4DFAWS)
- Algorithm: String
- Solve
    1. Using a loop, search if the target text has the pattern string.
    2. If the pattern string is found, jump the index as the pattern size.
    3. Increase the typing count while repeating 1 & 2.
- Complexity
    1. Time: O(N)
    2. Space: O(N)

### SWEA 2983. 두 번 이상 등장하는 문자열: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV-eALvKRnsDFAXr)
- Algorithm: String, Ravin-Karp
- Idea: Find the longest substring occurs more than once.
- Solve
    1. Use binary search to find the maximum length occurs more than once.
    2. To search the string in O(N), use a rolling hash(Ravin-Karp) technic.
    3. Please note that I used a single character array to contain the string.
        - And insert the address to a hash table to check the duplication.
        - If you use string type for each substring, memory will overflow.
- Complexity
    1. Time: O(N logN) = Binary search O(logN) * Find string O(N)
    2. Space: O(N)

### BOJ 15903. 카드 합체 놀이: [Problem](https://www.acmicpc.net/problem/15903)
- Algorithm: Greedy, Priority Queue
- Solve: Using a priority queue, continuously merge the least two values.

## 220430
### BOJ 1766. 문제집: [Problem](https://www.acmicpc.net/problem/1766)
- Algorithm: Graph Theory, Topological Sort, Priority Queue
- Idea: Adopt topological sort with priority queue.
- Solve
    1. Prepare an adjacency matrix and an entry array.
        - Entry array records the number of entry points for each problem.
    2. Topological Sort sequence
        1. Select nodes that have zero entry points.
            - Insert them to the priority queue.
        2. Print the top of the priority queue and remove it from the queue.
            - Remove entry points from the node.
        3. Repeat the step 1 & 2.
- Complexity
    - Time: O(N*LogN) = Searching N elements in a priority queue.
    - Space: O(N) = N elements in a list

### LeetCode 133. Clone Graph: [Problem](https://leetcode.com/problems/clone-graph/)
- Algorithm: Hash Table, Graph, BFS, DFS
- Idea: Use a Hash Table to contain the cloned graph.
- Solve
    1. Declare a hash table: `unordered_map<Node*, Node*> m;
    2. Use DFS(or BFS) to make & connect the cloned nodes.
- Complexity
    1. Time: O(N+E) - DFS, BFS same
    2. Space: O(N*E)

### BOJ 7579. 앱: [Problem](https://www.acmicpc.net/problem/7579)
- Algorithm: Dynamic Programming(knapsack)
- Solve
    1. `dp[j] = max(dp[j], dp[j-cost[i]] + memory[i])`
        - memory gained by cost j = max(memory when disabling ith app, memory when enabling ith app)
    2. Disable & enable N apps to find the maximum memory using same cost
    3. Search the dp array to find the cost offering M memory.

## 220428
### LeetCode 104. Maximum Depth of Binary Tree: [Problem](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- Algorithm: Depth-First Search, Binary Tree
- Solve
    1. Travel the tree by preorder search with 'level' parameter.
    2. Increase the level when travel into the child node.
    3. Update the maximum depth by comparing the current level.
   
### LeetCode 23. Merge k Sorted Lists: [Problem](https://leetcode.com/problems/merge-k-sorted-lists/)
- Algorithm: Linked List, Priority Queue, Divide and Conquer, Merge Sort
- Solve
    1. Insert all the list elements into a maximum heap.
    2. Make a ListNode using the top value of the heap.
        - Set the `head` as the next, and assign the new node to the head.
        - This mechanism inserts the value to in front of the list.
    3. Repeat step 1 & 2 until the priority queue is empty.
- Complexity
    - Time: O(N logN) = Searching N elements in a priority Queue. (Inserting the value to the list O(1*N))
    - Space: O(N) = Linked List O(N) + Priority Queue O(N)

## 220427
### LeetCode 206. Reverse Linked List: [Problem](https://leetcode.com/problems/reverse-linked-list/)
- Algorithm: Linked List, Recursion
- Idea: Find a simple rule to reverse the Linked List.
- Solve
    1. When creating a ListNode, give the current head as the next node. 
        - This means the created ListNode is pointing the current node.
    2. Move the head to point the created one.
    3. In short, `head = new ListNode(node->val, head)`

### LeetCode 3. Longest Substring Without Repeating Characters: [Problem](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
- Algirothm: Hash Table, String, Sliding Window / Two Pointers
- Idea: Using Two pointers, the time complexity could be O(N).
- Solve
    1. If the current number doesn't exist in the hash:
        - Increase `cnt` and add the number to the hash. Then increase `end`.
    2. If the current number exists in the hash:
        - Decrease `cnt` and remove the number from the hash. Then decrease `start`.

## 220426
### LeetCode 121. Best Time to Buy and Sell Stock: [Problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
- Algorithm: Array, Dynamic Programming
- Idea
    1. Save the maximum difference
    2. If the next value is bigger than the current minimum, check the maximum difference and update it.

## 220425
### Quick Sort
- It is a Divide and Conquer algorithm like Merge sort.
- It picks an element and partitions the given array around the picked pivot.
- The key process in Quick Sort is partition().
    - Target of partitions is, given an array and an element x of array as pivot.
    - Put x at its position in sorted array and put all smaller elements before x,
    - and put all greater elements after x. All this should be done in linear time.
- Complexity
    - Time: Best O(N LogN) / Average O(N LogN) / Worst O(N^2)
    - Space: Worst O(log(n))

### BOJ 1715. 카드 정렬하기: [Problem](https://www.acmicpc.net/problem/1715)
- Algorithm: Data structure, Greedy, Priority queue
- Idea: The key rule is that combining the 2 lowest values first.
- Solve
    1. Insert all the numbers to a minimum heap.
    2. Combine the 2 values on the top of the heap.
    3. Before inserting the result back, save it to 'sum' variable.
    4. Repeat 2 & 3 till the comparing done.

## 220424
### BOJ 4485. 녹색 옷 입은 애가 젤다지?: [Problem](https://www.acmicpc.net/problem/4485)
- Algorithm: Graph theory, Dijkstra
- Idea: This is a BFS problem that combines memoization(Dijkstra array). Similar with BOJ 1261.

### BOJ 11779. 최소비용 구하기 2: [Problem](https://www.acmicpc.net/problem/11779)
- Algorithm: Graph theory, Dijkstra
- Idea
    - Dijkstra + Print the visited nodes of the shortest path.
    - Time complexity: Using priority queue O(N*logN)
- Solve
    1. General dijkstra algorithm
        1. Find a node that has the smallest cost from the current node.
        2. Update the minimum distance array by going to a specific node through the smallest cost node.
        3. Repeat the above process.
    2. How to save the path
        - Additional **Before[N]** array is needed. It saves the shortest neighbor to reach that node.
        - We can trace back from the end node to the start node using that array.

### Studying Sort
1. Bubble
    - Concept
        1. Starting from the first node.
        2. Continue to compare and swap the neighbor nodes.
        3. This algorithm needs 2 for loops.
    - Time Complexity
        1. Best: O(N^2)
        2. Average: O(N^2)
        3. Worst: O(N^2)
    - Space Complexity: O(N)
2. Insertion
    - Concept
        1. Select ith node as a target.
        2. Trace back the elements & find the position to be inserted.
    - Time Complexity
        1. Best: **O(N)**
        2. Average: O(N^2)
        3. Worst: O(N^2)
    - Space Complexity: O(N)
3. Merge
    - Concept
        1. Continue to disassemble the array by using recursive function.
        2. After that, compare and merge the divided elements.
    - Time Complexity
        1. Average case: O(N*logN)
        2. Worst case: O(N*logN)
    - Space Complexity: O(N). But it needs an additional array.

## 220421
### BOJ 1261. 알고스팟: [Problem](https://www.acmicpc.net/problem/1261)
- Algorithm: Graph theory, Dijkstra, BFS
- Idea: This is a BFS problem that combines memoization(Dijkstra array).
- Solve
    1. Prepare 2 arrays.
        - Map[][]: Save the given map.
        - Dist[][]: Save the minimum count of passing doors. Memoization
    2. If a door is in the path, the formula should be
        - `dist[nx][ny] = min(dist[nx][ny], dist[x][y] + 1);`
    3. If a door is not exist, the formula should be
        - `dist[nx][ny] = min(dist[nx][ny], dist[x][y]);`
    4. Insert the next position to Queue only if the Dist array was updated.
    5. Finally, print dist[N-1][M-1] as the answer.

## 220420
- I plan to upload in **English** for a while to study.
### BOJ 1238. 파티: [Problem](https://www.acmicpc.net/problem/1238)
- Algorithm: Graph theory, Dijkstra
- Idea
    - This is a normal Dijkstra problem, but needs a little modification.
    - Time complexity: Using priority queue O(N*logN)
- Solve
    1. Check all the following distances for the all nodes.
        1. Phase1: the longest distance from 'start' to 'end'.
        2. Phase2: the longest distance from 'end' to 'start'.
    2. Find the maximum value of Phase1 + Phase2.

## 220415
### BOJ 1701. Cubeditor: [Problem](https://www.acmicpc.net/problem/1701)
- Algorithm: 문자열, KMP, 라빈-카프
- Idea: KMP 또는 라빈-카프 방식으로 구할 수 있다.
    - **KMP** Solve
        1. KMP의 핵심인 fail table을 생각해보자. prefix와 postfix가 일치하는 길이를 저장하는 테이블이다.
            - prefix와 postfix가 일치한다는 것은, 해당 문자가 2번 이상 등장한다는 의미이다.
        2. 문자 전체 길이부터 조금씩 앞으로 줄여가며 fail table을 구하고 그 중 최대값이 정답이다.
            ```C++
                for (int i = 0; i < strSize; ++i) {
                    vector<int> table = makeTable(str.substr(i));
                    answer = max(answer, *max_element(table.begin(), table.end()));
                }
            ```
    - **라빈-카프** Solve
        1. 이 풀이는 BOJ 3033(가장 긴 문자열)과 유사하다. 문자열의 길이가 최대 5000 이므로 부분 문자열들을 unordered_map으로 관리할 수 있다.
        2. 시간 복잡도: O(L*LogL) = 이분탐색 O(logL) x 2번 이상 등장하는지 체크 O(L)

## 220413
### BOJ 2606. 바이러스: [Problem](https://www.acmicpc.net/problem/2606)
- Algorithm: 연결 리스트, BFS
- Idea: Adjacency matrix를 vector로 많이 표현하지만, 연습을 위해 연결 리스트로 구현하였다.
- Solve
    1. 연결 리스트를 구현 후 adjacency matrix를 입력함.
    2. 일반적인 BFS로 탐색해주며 노드를 하나 탐색할 때마다 cnt++하여 답을 구한다.

### BOJ 1707. 이분 그래프: [Problem](https://www.acmicpc.net/problem/1707)
- Algorithm: 연결 리스트, DFS
- Idea
    - 이 문제도 연결 리스트 연습을 위해 구현해 주었다.
    - 이분 그래프의 **핵심 아이디어**는 인접 노드를 탐색(DFS)하면서 다른 color로 칠해주는 것이다.
- Solve
    1. visited 배열의 값을 1, 2, 1, 2... 로 번갈아 입력하여 다른 color로 칠하는 것을 구현한다.
        - DFS 함수 인자로 3 - currentColor 를 넘겨주면 된다.
        - visited가 0이 아니면 방문한 노드이므로 건너뛴다.
    2. 연결이 안 된 노드가 있을 수 있으므로 모든, 노드를 확인하여 DFS를 수행한다.
    3. 색칠이 끝난 후, 다시 모든 노드를 탐색하며 인접 노드와 color가 같은 것이 있는지 탐색한다. 있으면 이분 그래프가 아니다.

### BOJ 1764. 듣보잡: [Problem](https://www.acmicpc.net/problem/1764)
- Algorithm: 문자열, 정렬, 해시
- Idea
    - unordered_map을 사용해도 되지만 해시 연습을 위해 구현해 주었다.
    - 시간 복잡도: O(NlogN) = 해시 테이블 넣기 O(1*N) + set에 추가하기 O(NlogN) + set 데이터 가져오기 O(NlogN)
- Solve
    1. 듣지 못한 사람들을 해시 테이블에 넣는다.
    2. 보지 못한 사람들을 입력받을 때, 해시 테이블을 탐색하여 이미 있으면 set에 추가한다.
        - set은 중복을 제거하며 자동으로 사전 순으로 정렬시킨다.
    3. 끝난 후 set의 원소들을 출력한다.

### BOJ 14427. 수열과 쿼리 15: [Problem](https://www.acmicpc.net/problem/14427)
- Algorithm: 우선순위 큐 or 세그먼트 트리
- Idea
    - 우선순위 큐의 데이터를 업데이트 해주거나, 세그먼트 트리로 구현할 수 있다.
- Solve
    - **우선순위 큐**
        1. 우선순위 조건대로 비교 struct를 만들어서 데이터들을 입력 받는다.
            - 입력받을 때 해당 index의 데이터가 heap의 몇 번째에 들어가는지 heapIdx 배열에 기록한다.
            - 이렇게 하면 heapIdx 배열을 확인해 바로 특정 index의 값을 바꿀 수 있다.
        2. heap의 insert / update 연산시 노드만 바꾸는 것이 아니라 heapIdx 배열도 swap을 해준다.
            - update시 위쪽(부모쪽) 방향과 아래쪽 방향을 모두 확인하여 적절한 위치로 이동시켜준다.
        3. 시간 복잡도: O(NlogN) = 입력 O(NlogN) + 업데이트 O(1*NlogN)
    - **세그먼트 트리** [해설 참고](https://kyu9341.github.io/algorithm/2020/04/04/algorithm14427/)
        1. 세그먼트 트리 노드에는 자식 노드 중 더 작은 index를 저장한다.
            - 기존 세그먼트 트리처럼, leaf node는 원본 arr의 index를 갖는다.
            - 두 Node를 비교하여 더 작은 value의 index를 리턴하는 minIndex() 함수를 이용했다. 우선순위 큐의 우선순위 판별 함수와 용도가 비슷하다.
        2. 가장 작은 값의 index는 tree[1] 이다.
        3. update시 leaf node에 해당하는 원본 arr의 value를 업데이트 하고, 역으로 올라오면서 tree의 index를 업데이트 해준다.

## 220412
### BOJ 2075. N번째 큰 수: [Problem](https://www.acmicpc.net/problem/2075)
- Algorithm: 자료 구조, 정렬, 우선순위 큐
- Idea
    - 최대 힙에 다 넣어놓고 N번 pop을 해서 찾으면 된다고 생각함. 그러나 메모리 초과
- Solve
    1. 최소 힙에 넣으면서 힙의 사이즈가 N 이상이면, 새로 들어온 숫자와 top()을 비교
    2. top() 보다 크면 pop() 을 수행하고 새로 들어온 숫자를 삽입
    3. 배열 순회 완료후에 최소 힙의 top()이 N번째 큰 숫자가 된다.

## 220411
### BOJ 19236. 청소년 상어: [Problem](https://www.acmicpc.net/problem/19236)
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

### BOJ 1406. 에디터: [Problem](https://www.acmicpc.net/problem/1406)
- Algorithm: 자료 구조, 스택, 연결 리스트
- Idea
    - 메모리 풀 방식의 연결 리스트를 구현(노가다)해주었다. (48 ms)
    - **STL List**로도 구현이 가능하며, 시간이 약간 더 걸린다. (68 ms)
    - 2 개의 **Stack**으로 구현한 코드를 보니 시간이 더 빨랐다. (44 ms)

## 220410
### BOJ 15829. Hashing: [Problem](https://www.acmicpc.net/problem/15829)
- Algorithm: 문자열, 해싱
- Idea: hash 값을 구하는 문제
- Solve: 문자열에 31을 곱해 더해나갈때 매번 modular 연산으로 overflow가 나지 않도록 한다.

### BOJ 3033. 가장 긴 문자열: [Problem](https://www.acmicpc.net/problem/3033)
- Algorithm: 문자열, 해싱, 라빈-카프
- Idea
    1. 2번 이상 등장하는 부분 문자열의 길이를 이분탐색으로 찾는다.
    2. 시간 복잡도: O(L*LogL) = 이분탐색 O(logL) x 2번 이상 등장하는지 체크 O(L)
- Solve
    1. low = 0, high = L-1 에서 시작하여 이분 탐색을 수행한다.
    2. 현재 mid(부분 문자열의 길이)에 대해 문자열 전체를 순회한다.
        - 한 글자씩 이동하면서 Hash에 없으면 추가하고, 이전 것을 발견하면 2번 이상 등장하는 것이므로 True를 리턴
        - 여기서 라빈-카프 알고리즘의 Rolling Hash 기법을 사용한다. 라빈-카프 설명은 [링크](https://m.blog.naver.com/ndb796/221240679247)를 참고.
    3. 이분 탐색을 계속 수행하여 가능한 mid의 최대 값을 구한다.
    4. **Note**
        - 가능한 부분 문자열이 많기 때문에 string을 hash에 담으면 메모리가 overflow 된다.(unordered_map도 마찬가지)
        - 문자열을 char 배열로 입력받고, hash에 해당 문자열 주소를 담는 방식을 사용하였다.

### SWEA 8382. 방향 전환: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWyNQrCahHcDFAVP)
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
### BOJ 11000. 강의실 배정: [Problem](https://www.acmicpc.net/problem/11000)
- Algorithm: 정렬, PQ
- Idea
    - 정렬과 PQ를 이용한 문제
    - 시간 복잡도: O(NlogN) = vector에 데이터 삽입 O(1*N) + vector 정렬 O(NlogN) + PQ를 이용한 쿼리 처리 O(NlogN)
- Solve ([풀이 참고](https://velog.io/@soosungp33/BOJ-11000%EB%B2%88-%EA%B0%95%EC%9D%98%EC%8B%A4-%EB%B0%B0%EC%A0%95C))
    1. 시작 시간을 기준으로 오름차순으로 정렬해준다.
    2. PQ를 오름차순으로 설정해주고, 첫 강의가 끝나는 시간을 넣어준다.
    3. 나머지 강의를 확인하면서 조건에 따라 PQ를 컨트롤한다.
        - 모든 강의실 중에 가장 빨리 끝나는 강의실을 선택한다. (**q.top()**)
        - 해당 강의실이 끝나기 전에 현재 강의가 시작되면(q.top()>s), 강의실을 하나 늘려준다. (**q.push(t)**)
        - 해당 강의실이 끝난 후에 강의가 시작되면(q.top()<=s), 강의실을 늘릴 필요 없이 그 강의실에서 강의를 시작한다. (**q.pop(), q.push(t)**)
    4. 최종적으로 남아있는 강의실의 개수를 출력한다.(**q.size()**)

## 220408
### BOJ 11660. 구간 합 구하기 5: [Problem](https://www.acmicpc.net/problem/11660)
- Algorithm: Prefix Sum
- Idea
    - Prefix Sum은 누적합을 미리 구한 다음, 특정 구간의 합을 빠르게 구하는 유형이다.
- Solve
    1. 2차원 배열의 누적합을 구해 놓는다.<br/>
    `sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];`
    2. 특정 구간합을 구하는 수식. 2차원 공간의 면적을 구하는 것과 동일하다.<br/>
    `answer = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];`

### BOJ 11003. 최솟값 찾기: [Problem](https://www.acmicpc.net/problem/11003)
- Algorithm: O(N):Deque / O(NlogN): Priority Queue, Seg Tree
- Idea
    - O(N*logN)이면 아슬아슬하고 O(N)이어야 넉넉히 풀리는 문제
    - O(N*logN)이 왜 안 될 수 있는지 [다음 글](https://www.acmicpc.net/board/view/36198)을 읽어보자.
    - 개인적으로 PQ 문제들이 다양한 접근방식을 고민하기에 좋은것 같다.<br/>
    PQ, Multi PQ, Seg Tree, Deque, Hash 등 다양하게 생각해보자.
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
### SWEA 1257. K번째 문자열: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18KWf6ItECFAZN)
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

### BOJ 9612. Maximum Word Frequency: [Problem](https://www.acmicpc.net/problem/9612)
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
### SWEA 4340. 파이프 연결: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWL6LhM6A60DFAUY)
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
### BOJ 9252. LCS 2: [Problem](https://www.acmicpc.net/problem/9252)
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

### BOJ 1987. 알파벳: [Problem](https://www.acmicpc.net/problem/1987)
- Algorithm: 백트래킹
- Idea: 백트래킹 기본기 점검을 위한 문제.
- Solve
    - 방문한 곳을 다시 방문하지 않도록 visited를 사용하고,
    - 한번 지나간 알파벳도 다시 사용하지 않도록 alphabet 배열을 추가로 사용한다.
    - 다시 돌아와서 탐색할 때 visited와 alphabet을 false로 해야 다른 경우의 수를 탐색할 수 있다.

## 220403
### SWEA 1798. 범준이의 제주도 여행 계획: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4x9oyaCR8DFAUx)
- Algorithm: 백트래킹
- Idea: 백트래킹 수행 중 따져야 할 것이 많은 문제
- Solve
    1. 관광지와 그 외의 것들로 구분해서 관리하는 것이 편하다.
    2. 허용된 시간(540분) 안에서 관광지를 최대한 돌고 540이 초과되면 호텔이나 공항을 선택한다.
        - M번째 날엔 공항을, 그 외에는 호텔을 선택한다.
    3. 최대 만족도를 계속 갱신해준다.

### SWEA 8189. 우편함: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWwtU7XqhL0DFAWU)
- Algorithm: 구현
- Idea: 시간을 1씩 증가시키면서 문제의 조건에 맞게 구현한다.
- Solve
    1. 메일함을 확인하는 조건은 설정한 메일함의 용량에 도달했을 때, 그리고 메일 수령 이후 특정 시간이 지났을 때이다.
        - 메일함을 확인할 때는 절반만 확인해준다.
    2. `while` 문 안에서 시간을 증가시키면서 구현해주자.

### BOJ 11437. LCA: [Problem](https://www.acmicpc.net/problem/11437)
- Algorithm: Lowest Common Ancestor
- Idea: 좀 더 공부를 하고 업데이트 할 것.

### BOJ 11066: 파일 합치기: [Problem](https://www.acmicpc.net/problem/11066)
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

### BOJ 11049. 행렬 곱셈 순서: [Problem](https://www.acmicpc.net/problem/11049)
- Algorithm: DP
- Idea: 위 **파일 합치기** 문제와 비슷함. 더해줘야 하는 offset만 다르다.

## 220401
### SWEA 6855. 신도시 전기 연결하기: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWhUBBUqQO0DFAW_)
- Algorithm: Sort
- Idea
    - 도시 간 거리가 높은 곳부터 발전소를 배치하자.
    - PS에서 **정렬**이 쓰이는 경우가 많다. 아이디어가 떠오르지 않으면 정렬을 생각해보자.
- Solve
    1. 도시의 위치를 입력 받은 후, 도시 간 거리를 구해서 배열에 저장한다.
    2. 도시 간 거리를 정렬한 다음, 뒤에서 K개는 발전소를 배치할 것이기 때문에 `N-K` 까지의 거리를 합산한다.

## 220331
### SWEA 7701. 염라대왕의 이름 정렬: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWqU0zh6rssDFARG)
- Algorithm: Hash, Priority Queue
- Idea: 우선순위 큐의 우선순위 조정을 할 수 있으면 된다. 
- Solve
    - 우선순위 조정을 위한 struct 선언: 길이가 짧은 것이 우선순위가 높고, 길이가 같으면 사전 순서가 앞인 것이 우선순위가 높다.
    - Hash를 이용해 중복된 원소가 삽입되지 않도록 한다.

## 220330
### SWEA 1227. 미로2: [Problem](https://swexpertacademy.com/main/code/problem/problemSolver.do?contestProbId=AV14wL9KAGkCFAYD)
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

### SWEA 7988. 내전 경기: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWvQZmdKUoEDFASy)
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
### BOJ 1655. 가운데를 말해요: [Problem](https://www.acmicpc.net/problem/1655)
- Algorithm: Priority Queue
- Idea: 최대 힙과 최소 힙을 활용하여 최대 힙의 top이 가운데 값을 유지하게 한다.
- Solve
    1. 최대 힙의 크기는 최소 힙의 크기와 같거나, 하나 더 크다.
    2. 최대 힙의 최대 원소는 최소 합의 최소 원소보다 작거나 같다.
    3. 이때 알고리즘에 맞지 않다면 최대 힙, 최소 힙의 가장 위의 값을 swap해준다.

### BOJ 12865. 평범한 배낭: [Problem](https://www.acmicpc.net/problem/12865)
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

### SWEA 2115. 벌꿀채취: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V4A46AdIDFAWu)
- Algorithm: 백트래킹
- Idea: 백트래킹을 꼭 재귀로만 구현할 필요 없다는 것을 다시 확인한 문제.
    - 선택 대상이 적거나, 혹은 너무 많아서 *스택 오버플로우* 가 발생한다면 for문으로 구현해야 한다.
- Solve
    1. 2명의 일꾼이 작업하는 범위는 가로로 배치되며, 겹치지 않아야 한다.
        - 2명으로 제한되기 때문에 재귀로 구현하는 것 보다는 for문 2개가 간편하다.
        - 두번째 일꾼이 일할 때 최초 루프는 ax+M에서 시작하고 이후 루프에서는 0에서 부터 탐색해야 한다. 기법을 알아두자.
    2. 이제 일하는 범위를 정했다면 각 범위내에서 최대 가치를 얻는 값을 구해야 한다.
        1. 주어진 무게 안에서 최대의 가치를 얻는 [배낭](https://www.acmicpc.net/problem/12865) 문제와 같다. 배낭 문제는 **DP** 로 구현한다.
        2. 하지만 최대 무게가 30이고, 일할 수 있는 최대 벌통의 개수가 5개이므로 조합으로 값을 구해도 된다.

## 220326
### BOJ 1038. 감소하는 수: [Problem](https://www.acmicpc.net/problem/1038)
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

### BOJ 7662. 이중 우선순위 큐: [Problem](https://www.acmicpc.net/problem/7662)
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

### BOJ 1305. 광고: [Problem](https://www.acmicpc.net/problem/7662)
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
### BOJ 10971. 외판원 순회 2: [Problem](https://www.acmicpc.net/problem/10971)
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

### BOJ 2193. 이친수: [Problem](https://www.acmicpc.net/problem/2193)
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

### BOJ 1904. 01타일: [Problem](https://www.acmicpc.net/problem/1904)
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
### BOJ 14889. 스타트와 링크: [Problem](https://www.acmicpc.net/problem/14889)
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

### BOJ 11053. 가장 긴 증가하는 부분 수열: [Problem](https://www.acmicpc.net/problem/11053)
- Algorithm: DP
- Idea: i번째 최대값 `best[i]`를 계속 갱신하여 답을 찾는다. 원소의 개수가 1000개 이하여서 **이중 for문**으로 가능하다.
- Solve
    1. i 이전까지 가장 긴 값을 j를 이용해 탐색한다.
    2. `arr[i] > arr[j]` 이면 현재의 최대값 `best[i]`과 `best[j]+1` 을 비교하고 더 크면 갱신한다.
    3. `best[]`의 원소 중 최대값을 출력한다.

### BOJ 12015. 가장 긴 증가하는 부분 수열 2: [Problem](https://www.acmicpc.net/problem/12015)
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
### BOJ 9663. N-Queen: [Problem](https://www.acmicpc.net/problem/9663)
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
- 노트: 백트래킹과 DP 기본기를 확실히 다지기로 하였다.

### BOJ 15654. N과 M (5): [Problem](https://www.acmicpc.net/problem/15654)
- Algorithm: 백트래킹
- Idea: 배열에 입력값을 받아 정렬 후 순열을 구해준다. 재귀로 순열을 구하는 기본적인 문제

### BOJ 15663. N과 M (9): [Problem](https://www.acmicpc.net/problem/15663)
- Algorithm: 백트래킹
- Idea
    - 입력값은 중복이 있을 수 있지만, 한번 출력한 조합은 더 이상 출력하지 말아야 한다.
    - 최적화에 대한 고민이 필요한 문제.
- Solve
    - 최초 접근방식은 printed 벡터를 두어 한번 출력한 값을 저장하고, 다음에 printed를 확인하여 중복 출력을 막는 것이었다.
        - 확인용 벡터를 써야 하므로 메모리가 추가로 필요하고 불필요한 연산이 들어가는 느낌이 있었다.
    - 두번째 접근은 각 재귀단계에서 prev 변수를 두어 이전에 선택한 것은 건너뛰게 하는 것이다. 재귀 마지막까지 가서 확인하는 불필요한 작업이 없어진다.
        - 기본적인 selected[] 외에 prev 변수를 추가로 확인하는 것.

### BOJ 11727. 2×n 타일링 2: [Problem](https://www.acmicpc.net/problem/11727)
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
### BOJ 11286. 절댓값 힙: [Problem](https://www.acmicpc.net/problem/11286)
- Algorithm: 자료구조, 우선순위 큐
- Idea
    - 기본 우선순위 큐 구현 + 커스텀 노드의 우선순위를 판별한다.
- Solve
    1. 문제의 조건에 맞게 비교함수를 구현할 것
    2. 그 외에는 똑같다. insert()에서는 마지막 노드에서 parent로 올라가며 탐색. <br/> pop()은 1번 노드를 저장하고 마지막 노드를 1번 노드로 옮긴 후 재배치.
    3. 특정 노드를 갱신하는 **update**를 연습해야 한다.

### 07_bitwise_1_basic
- Algorithm: Bitwise 연산 연습
- 간단한 정리
    1. `t1 |= (1 << n)`: t1의 n번째 bit를 1로 바꾼다.
    2. `t1 &= ~(1 << n)`: t1의 n번째 bit를 0으로 바꾼다.
    3. `t1 ^= (1 << n)`: t1의 n번째 bit을 토글.
    4. `(t1 >> n) & 1`: t1의 n번째 bit가 1인지 판별.
        - `t1 & (1 << n)` 을 써야 t1 값이 변하지 않을 것이다.
    5. STL bitset을 사용해도 됨. 
        - `bit.set(2)`: 2번째 bit를 1로 set
        - `bit.reset(2)`: 2번째 bit를 0으로 set
        - `bit.flp()`: 모든 bit 반전
        - `bit.to_ulong()`: unsigned long 값을 반환

### SWEA 2112. 보호 필름: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu)
- Algorithm: 백트래킹, 구현
- Idea
    - 특정 line을 0또는 1로 칠해가며 모든 경우의 수를 탐색
- Solve
    1. check(): 현재 film의 상태가 합격할 수 있는 상태인지 확인하는 함수
    2. testColumn(): 조합을 재귀로 구현한다. 각 line을 0, 1로 칠하는 경우의 수를 따진다. 
        - 칠하기 전에 해당 column을 저장해두고 다시 복원한다. 전체 array를 저장하는 것은 낭비.
        - check()를 호출하여 통과할 수 있는지 확인한다.

### BOJ 10844. 쉬운 계단 수: [Problem](https://www.acmicpc.net/problem/10844)
- Algorithm: DP
- Idea
    - 계단수 길이를 하나씩 늘어날때, 마지막 숫자는 이전 수 마지막 숫자와 1씩 차이가 나는 것을 이용
- Solve
    1. dp[i][j]: i번째 계단수가 j로 끝날 때 개수. 0과 9를 제외하고 다음과 같은 규칙이 있다.
        - `dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]`
        - 0 일때는 `dp[i][j] = dp[i-1][j-1]` : 1에서 오는 경우만 있다.
        - 9 일때는 `dp[i][j] = dp[i-1][j+1]` : 8에서 오는 경우만 있다.
    2. 초기값 dp[1][1~9] 는 전부 1이고, dp[1][0]은 0이다. 이후 위 수식에 의해 계산한다.

### SWEA 3234. 준환이의 양팔저울: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWAe7XSKfUUDFAUw)
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
### SWEA 1808. 지희의 고장난 계산기: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4yC3pqCegDFAUx)
- Algorithm: 백트래킹
- Idea
    - 숫자만 눌러서 만들 수 있으면 바로 리턴, 아니면 재귀를 통한 탐색
- Solve
    1. makeNums(): 누를 수 있는 숫자들을 조합하여 만들 수 있는 숫자들을 구하고, 누른 횟수를 made[]에 저장한다.
    2. calculate(): made[] 배열로 나눠간다. 나눠지면 made[i] 숫자만큼 더하고 곱하기 횟수를 반영한다. N이 1이되면 성공
    3. 참고한 솔루션과 다른 것은 calculate에서 나누기를 N/2부터 시작하는 것이다. <br/>`N/2 < i < N` 값은 나머지가 0이 될 수 없기 때문

### BOJ 11659, 구간 합 구하기 4: [Problem](https://www.acmicpc.net/problem/11659)
- Algorithm: 세그먼트 트리
- Idea
    - 세그먼트 트리 기본문제. 입력받을 때 누적합을 구하는 dp 접근 방식도 있는것 같다.
- Solve
    1. makeTree(): 재귀로 leaf node에 도착한 뒤 tree[idx] 값 입력. 돌아오면서 합으로 채워짐
    2. getSum(): start, end가 찾고자 하는 범위 내에 있으면 바로 tree[idx] 리턴, 아니면 탐색
    3. update(): 문제에서 요구하는 것은 아니지만 테스트 용도로 넣음. leaf node에 도착하여 값 업데이트하고 돌아오면서 부모들도 업데이트.

## 220316
### 수정내용
- 폴더 구조, 레거시 파일들 정리
- 공부한 것 README에도 기록하기

### SWEA 6731. 홍익이의 오델로 게임: [Problem](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWefzFeq5P8DFAUh)
- Algorithm: N/A
- Idea
    - 한 면은 흰색, 다른 면은 흑색인 돌이 배치된 오델로 판이 주어진다.
    - 처음에 모두 흰색으로 배치되어 있고, 최종적으로 되어야 하는 모습이 주어질 때 몇 번만에 달성할 수 있는지 찾는 문제.
    - 모든 경우의 수를 탐색하는 백트래킹으로 생각했지만, 경우의 수가 너무 많고 가지치기 조건이 생각나지 않았다.
- Solve
    1. 흰돌을 뒤집은 지점에서 해당 행,열의 흑돌의 개수를 세었을 때 홀수가 되는 규칙이 있다.
    2. 따라서 2차원 배열을 돌면서 홀수인 지점을 선택해주면 된다. [참고](https://yabmoons.tistory.com/426)
