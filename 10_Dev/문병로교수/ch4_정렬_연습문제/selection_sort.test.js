/**
 * @description 선택 정렬 후 배열 상태
 * @param {number} N 입력 배열의 길이
 * @param {Array<number>} Arr
 * @return 선택 정렬 후 배열
 * */
function solution(N, Arr) {
  for(let i = 0; i < N - 1; i++) {
    let MAX_NUM_IDX = 0;
    let LAST_ELEM = Arr[N-i-1];

    for(let j = 0; j < N - i; j++) {
      if(Arr[j] > Arr[MAX_NUM_IDX]) {
        MAX_NUM_IDX = j;
      }
    }

    if(MAX_NUM_IDX !== N - i - 1) {
      Arr[N-i-1] = Arr[MAX_NUM_IDX];
      Arr[MAX_NUM_IDX] = LAST_ELEM;
    }
  }
  return Arr;
}

decribe("선택 정렬 TEST", () => {
  test("예제 1번", () => {
    expect(solution(5, [64, 25, 12, 22, 11])).toEqual([11, 12, 25, 22, 64]);
  });

  test("예제 2번", () => {
    expect(solution(6, [3, 1, 2, 1, 5, 4])).toEqual([1, 1, 2, 3, 5, 4]);
  });

  test("예제 3번", () => {
    expect(solution(4,  [-3, -1, -2, 0])).toEqual([-3, -1, -2, 0]);
  });
});
