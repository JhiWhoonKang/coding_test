#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	// 연한 회색: 벌이 있는 장소
	// 진한 회색: 벌통이 있는 장소
	// 벌통으로 날아가면서 지나가는 모든 칸에 꿀 수집
	// 칸에 있는 숫자는 꿀을 수집할 수 있는 양(벌통 포함)
	// 시작 장소는 불가


	return 0;
}



#if 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    // 입력: 장소의 개수 N
    int N;
    cin >> N;

    // 각 장소별 꿀의 양을 저장할 벡터 A
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 전체 꿀의 양(total) 계산
    long long total = 0;
    for (int i = 0; i < N; i++) {
        total += A[i];
    }

    // 누적합(prefix) 배열 생성
    // prefix[i+1] = A[0] + A[1] + ... + A[i] 의 합을 저장
    vector<long long> prefix(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + A[i];
    }

    // 최종 정답을 저장할 변수
    long long ans = 0;

    // ================================================================
    // Case 1: 벌집(벌통)이 오른쪽 끝(N-1)에 있을 때
    // ---------------------------------------------------------------
    // - 벌 1은 왼쪽 끝(0번)에서 출발, 벌 2는 중간의 어느 칸(i)에서 출발
    // - 왼쪽 벌은 0번 출발이므로 꿀을 따지 않고, 1번부터 N-1번까지 지나감.
    //   단, 중간 벌이 시작하는 칸 i는 꿀을 따지 않으므로 A[i]는 빼준다.
    // - 중간 벌은 i번에서 출발하여 i+1번부터 N-1번까지 지나감.
    // 
    // 따라서 두 벌의 꿀의 양:
    //   왼쪽 벌: (total - A[0] - A[i])  (전체 합에서 시작칸과 중간벌의 시작칸 제거)
    //   중간 벌: (total - prefix[i+1])   (i번 이하의 합은 제거)
    // 
    // 후보값: candidate = (total - A[0] - A[i]) + (total - prefix[i+1])
    // i는 1부터 N-2까지 가능 (벌통이 오른쪽 끝이므로 중간 벌은 오른쪽 끝이 아니어야 함)
    for (int i = 1; i < N - 1; i++) {
        long long candidate = (total - A[0] - A[i]) + (total - prefix[i + 1]);
        ans = max(ans, candidate);
    }

    // ================================================================
    // Case 2: 벌집(벌통)이 왼쪽 끝(0)에 있을 때
    // ---------------------------------------------------------------
    // - 벌 1은 오른쪽 끝(N-1)에서 출발, 벌 2는 중간의 어느 칸(i)에서 출발
    // - 오른쪽 벌은 N-1번 출발이므로 꿀을 따지 않고, 0번부터 N-2번까지 지나감.
    //   단, 중간 벌이 시작하는 칸 i는 꿀을 따지 않으므로 A[i]는 빼준다.
    // - 중간 벌은 i번에서 출발하여 0번부터 i-1번까지 지나감.
    // 
    // 따라서 두 벌의 꿀의 양:
    //   오른쪽 벌: (total - A[N-1] - A[i])  (전체 합에서 오른쪽 시작칸과 중간 벌 시작칸 제거)
    //   중간 벌: prefix[i]                (0번부터 i-1번까지의 합)
    // 
    // 후보값: candidate = (total - A[N-1] - A[i]) + prefix[i]
    // i는 1부터 N-2까지 가능 (벌통이 왼쪽 끝이므로 중간 벌은 왼쪽 끝이 아니어야 함)
    for (int i = 1; i < N - 1; i++) {
        long long candidate = (total - A[N - 1] - A[i]) + prefix[i];
        ans = max(ans, candidate);
    }

    // ================================================================
    // Case 3: 벌집(벌통)이 중간 어딘가(i)에 있을 때
    // ---------------------------------------------------------------
    // - 두 벌은 양쪽 끝에 위치: 하나는 0번, 다른 하나는 N-1번
    // - 왼쪽 벌은 0번에서 출발하여 i번까지 이동: 0번에서는 꿀을 딸 수 없으므로
    //   1번부터 i번까지의 꿀의 양은 prefix[i+1] - A[0]
    // - 오른쪽 벌은 N-1번에서 출발하여 i번까지 이동: N-1번에서는 꿀을 딸 수 없으므로
    //   i번부터 N-2번까지의 꿀의 양은 (total - A[N-1]) - prefix[i]
    // - 두 벌이 딴 총 꿀의 양은 두 경우의 합으로 나타낼 수 있고, 식을 정리하면
    //   total - A[0] - A[N-1] + A[i]
    //   (여기서 A[i]는 중간에 벌통이 있는 곳의 값으로, 이 값을 최대화해야 함)
    // 
    // 후보값: candidate = total - A[0] - A[N-1] + max(A[i]) for i=1 to N-2
    long long max_mid = 0;
    for (int i = 1; i < N - 1; i++) {
        max_mid = max(max_mid, A[i]);
    }
    long long candidate = total - A[0] - A[N - 1] + max_mid;
    ans = max(ans, candidate);

    // 최종적으로 가능한 최대의 꿀의 양 출력
    cout << ans << "\n";
    return 0;
}



#endif