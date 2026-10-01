# DB / Storage

## write가 많아진다면?

-   sharding
-   MySQL → Cassandra, StarRocks

## 데이터 사이즈가 커진다면?

-   partition

## DB 응답이 느리다면?

-   Index
-   composition index

## 쿼리 통계는 어떻게 볼까?

-   Hibernate intercept
    -   comment에 API path를 넣어 장애 파악
    -   select query type

## DB가 죽는다면?

-   이중화 운영
-   어떻게 복구되는지까지 이해

## 정합성은 어떻게 지킬까?

-   idempotency key
-   lock
    -   구현 위치: DB, memory
    -   동작: spin, waiting, optimistic, pessimistic
-   이기종 transaction (`DB + Kafka`)

## 분산락은 어떻게 구현할까?

-   DB
-   Redis 기반 `SET NX`
-   RedLock 기반 분산락
-   인스턴스 장애, major 획득 실패, NTP, TTL 만료, 락 획득 시간 등을
    고려
