/**
 * @param {Array<number>} A
 * @param {number} startIndex
 * @param {number} midIndex
 * @param {number} lastIndex
 * */
function merge(A, startIndex, midIndex, lastIndex) {
  const tmp = [];
  let i = startIndex,
    j = midIndex + 1,
    t = 0;

  while (i <= midIndex && j <= lastIndex) {
    if (A[i] <= A[j]) {
      tmp[t] = A[i];
      i++;
    } else {
      tmp[t] = A[j];
      j++;
    }
    t++;
  }

  /* 왼쪽 배열 부분이 남은 경우 */
  while (i <= midIndex) {
    tmp[t] = A[i];
    t++;
    i++;
  }
  /* 오른쪽 배열 부분이 남은 경우 */
  while (j <= lastIndex) {
    tmp[t] = A[j];
    t++;
    j++;
  }

  i = startIndex;
  t = 0;
  while (i <= lastIndex) {
    A[i] = tmp[t];
    i++;
    t++;
  }
}

/**
 * @param {Array<number>} A
 * @param {number} startIndex
 * @param {number} lastIndex
 * */
function mergeSort(A, startIndex, lastIndex) {
  if (startIndex < lastIndex) {
    const midIndex = Math.floor((startIndex + lastIndex) / 2);
    mergeSort(A, startIndex, midIndex);
    mergeSort(A, midIndex + 1, lastIndex);
    merge(A, startIndex, midIndex, lastIndex);
  }
  return A;
}

describe("병합 정렬 테스트 ", () => {
  it("테스트 예제 1", () => {
    expect(mergeSort([5, 4, 3, 2, 1, 6], 0, 5)).toEqual([1, 2, 3, 4, 5, 6]);
  });

  it("테스트 예제 2", () => {
    expect(mergeSort([1], 0, 0)).toEqual([1]);
  });

  it("테스트 예제 3", () => {
    expect(mergeSort([2, 1, 2, 1, 2], 0, 4)).toEqual([1, 1, 2, 2, 2]);
  });
});
