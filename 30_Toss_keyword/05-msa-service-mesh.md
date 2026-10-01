# MSA & Service Mesh

## 어떻게 호출할까?

-   WebClient vs RestClient(RestTemplate)
-   SDK
-   기술적 의사 결정

## 문제 발생 시 tracing은?

-   client 활용
-   헤더 릴레이

## 연쇄 장애(cascading) 대응은?

-   circuit breaker
-   global circuit breaker
-   bulkhead
-   rate limit

## 합치거나 분리할 때 검증은?

-   shadow traffic
-   CDC
-   dry-run
-   dataset 효율 검증 (`aggregate-count`, `sum`, `hash`)

## application vs mesh?

-   circuit, retry, rate limit을 어디서 처리할지 결정

## 실시간 config 변경은?

-   dynamic config 구현
-   config 서버 운영
    -   Central Dogma
    -   Consul KV
    -   Spring Cloud Config + Bus

## 빠르게 장애를 회복하려면?

-   fault injection
-   장애 예방까지 가능할지 검토
