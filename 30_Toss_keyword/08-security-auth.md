# 보안 / 인증

## 어떤 인증을 쓸까?

-   API key
-   OAuth2
-   mTLS
-   JWT
-   HMAC signature

## 암호화 키 교체는 편한가?

-   key rotation library
-   migration

## 외부사와는 어떻게 연동할까?

-   유저 키
    -   Hash
    -   UUID
-   caller
    -   내부·외부 통신 차이
    -   IP whitelist
-   TCP gateway

## 서비스 간 호출 통제는?

-   Service mesh
-   mTLS
-   API path policy
-   whitelist
