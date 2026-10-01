# 로그 / 메트릭

## 로그는 어떻게 구성할까?

-   알림 appender
-   Kafka appender 구성
-   정형 vs 비정형
-   req & res
-   param
-   size
-   masking

## 로그 실패는 어떻게 대응할까?

-   retry + file

## 쓰레드가 멈추진 않을까?

-   `neverBlock` 설정
-   문제를 어떻게 빨리 발견할지 고려

## Kafka 부하는 잘 분산될까?

-   producer batching에서 key rolling을 모아서 처리

## 로그 비용은?

-   ELK에서 Vector 도입
-   VictoriaLogs + Kibana adapter
