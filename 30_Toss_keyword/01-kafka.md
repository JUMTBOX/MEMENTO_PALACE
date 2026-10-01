# Kafka

## 컨슈머 속도를 높이려면?

-   `record → batch → multi-thread → parallel`로 처리 방식 고도화
-   parallel consumer 도입 시 `rebalance`, 메시지 순서 보장, 장애
    처리까지 고려

## 처리에 실패하면?

-   DLQ 처리 및 재발행 시스템 구축

## 브로커 성능을 개선하려면?

-   배치와 데이터 압축을 통한 버퍼 최적화

## 처리 속도를 높이려면?

-   파티션 증설 시 필요한 `latest → earliest` 설정

## 중복 처리를 막으려면?

-   중복 재발행을 고려한 멱등한 컨슈머 설계 (`idempotency key`)
-   exactly-once 푸시 발송, materialized view

## 안정적으로 배포하려면?

-   assigner, graceful shutdown (`SIGTERM → SIGKILL`)

## 모니터링·장애 대응은?

-   producer & consumer config
-   lag 모니터링 및 후속 대책 수립
