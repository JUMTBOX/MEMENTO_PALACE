# Cache

## 구조는 어떻게 진화했나?

-   `user server + remote cache`
-   `gateway + user server`
-   `gateway + passport`
-   `gateway + local cache + sticky session`
-   `gateway + Cassandra`

## Remote-Local 정합성은?

-   stale 범위 관리
-   pub/sub, stream

## 메모리가 크다면?

-   bitmap, hotkey 등 자료구조 선택
-   Binary 포맷

## 가져올 데이터가 많다면?

-   해시 태그로 SLOT 분배
-   MGET 요청 최적화

## 원자적 처리가 필요하다면?

-   Lua script 활용

## 캐시 버전 관리는?

-   Dual write 후 read 버전업

## 순간 요청량이 몰린다면?

-   write-behind
-   Redis를 1차 SSOT로 두고 DB 적재는 컨슈머로 처리

## 운영·장애 대응은?

-   hit rate
-   `DEL` & `UNLINK`
-   `SCAN`
-   indirection key 설계
-   topology refresh
-   slow command
