## 코기

### 1. 프로세스와 스레드
**멀티 프로세스 vs 멀티 스레드 언제 뭘 사용할까?**
**크롬 탭은 프로세스일까 스레드일까? 왜?**
**멀티스레드 동시성 해결 방안**

### 2. 동시성 vs 병렬성
- 동시성은 싱글 코어에서도 ㄱㄴ, 병렬성은 정말 물리적으로 프로세서가 2개 이상 존재해야 ㄱㄴ

**싱글 코어에서 동시성이 왜 필요한지?**
**병렬성이 무조건 빠른가?**
**파이썬은 멀티 코어 환경에서도 쓰레드 병렬처리가 안된다고 하는데?**

### 3. 동기 vs 비동기
- 왜? I/O(ex. fs, network)는 느리지만 프로세서는 빠르기 때문에...!
**Blocking과 Sync는 같은 개념인가?**
**JS는 싱글스레드인데 어떻게 비동기 처리를 하나?**
- 태스크큐와 이벤트루프로 처리한다  
**비동기 처리를 동기처럼 보이게 하는 문법은?**
- JS에서는 `async-await` 
**비동기가 오히려 안 좋은 상황도 있나?**

### 4. 데드락(Deadlock) vs 라이브락(Livelock)
- `Deadlock`: 좁은 길에서 서로 마주 보고 멈춘 상태 (교착 상태)
  - <b>자원 순서 정렬</b>(순서대로만 락 획득)
  - <b>교착 상태 감지</b> 후 하나 강제 종료
  - <b>타임아웃</b>(일정 시간 후 포기)
- `Livelock`: 서로 비켜주려다 계속 부딪힘 (계속 움직이지만 진전 없음)
  - <b>Random BackOff</b>(임의 시간 대기) ...(ex. 이더넷 재전송)
  - 재시도 횟수 제한
**데드락 발생의 4가지 조건**
**식사하는 철학자 문제(Dining Philosopher)란?**
**실제 시스템에서 라이브락은 언제 발생하나?**

### 5. 읽기 성능 vs 쓰기 성능
- `읽기`
  - Web/Network: 브라우저 캐시, CDN, HTTP/2 & 3
  - App/Cache: Cache(Redis), Local Cache(Caffeine Cache)
  - Database: Replication, Indexing, Partitioning, 미리 계산된 결과(통계)
- `쓰기`
  - App/Broker: Message Queue(Kafka), 비동기 처리
  - DB Arch: Sharding, Partitioning, Eventual Consistency
  - DB Internal: Batch Write, 인덱스 최적화
**Replication Log(지연)은 어떻게 해결?**
**CQRS 패턴이 뭔지?**
**캐시 전략(Write-Back vs Write-Through)의 차이점은?**