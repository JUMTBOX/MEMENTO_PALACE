/**
 * @description 버블 정렬 구현
 * @param {number} N  배열의 길이
 * @param {Array<number>} Arr
 * */
function solution(N, Arr) {
  for(let i = 0; i < N - 1; i++) {
    let swapped = false;
    for(let j = 0; j < N - i - 1; j++) {
      if(Arr[j] > Arr[j+1]) {
        swapped = true;
        [Arr[j], Arr[j+1]] = [Arr[j + 1], Arr[j]]
      }
    }
    if(!swapped) break;
  }
  return Arr;
}

describe("버블 정렬 TEST", () => {
  test("예제 1번", () => {
    expect(solution(0, [])).toEqual([]);
  });

  test("예제 2번", () => {
    expect(solution(0,[])).toEqual([]);
  });

  test("예제 3번", () => {
    expect(solution(0,[])).toEqual([]);
  });
});
