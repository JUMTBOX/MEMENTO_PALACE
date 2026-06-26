/**
 * @description `
 *  문제: K회 선택 정렬 후 배열 상태 구하기
 *  선택 정렬을 수행한다.
 *  앞에서부터 k번 최솟값을 선택해 제자리에 둔 뒤 배열 상태를 출력하세요.
 *  같은 최솟값이 여러 개라면 가장 앞에 있는 값을 선택합니다.
 *
 *  [입력 제한]
 *  2 <= N <= 5000
 *  1 <= K <= N-1
 *  -1,000,000 <= ai <= 1,000,000
 * `
 * @param {number} N 입력 배열의 길이
 * @param {number} K
 * @param {Array<number>} Arr
 * @return k회 선택 후 배열
 * */
function solution(N, K, Arr) {
  return Arr;
}

decribe("선택 정렬 TEST", () => {
  test("예제 1번", () => {
    expect(solution(5, 2, [64, 25, 12, 22, 11])).toEqual([11, 12, 25, 22, 64]);
  });

  test("예제 2번", () => {
    expect(solution(6, 3, [3, 1, 2, 1, 5, 4])).toEqual([1, 1, 2, 3, 5, 4]);
  });

  test("예제 3번", () => {
    expect(solution(4, 2, [-3, -1, -2, 0])).toEqual([-3, -1, -2, 0]);
  });
});
