## Palantir Foundry

**What is foundry?**
- Palantir Foundry는 기업 내부에 흩어진 데이터,분석 모델,업무 프로세스를 연결하여, 실제 업무 의사결정과 실행까지 이어지게 만드는 엔터프라이즈 데이터 운영 플랫폼
```text
ERP / CRM / DB / API / 센서 / 로그
↓
데이터 수집·정제·변환
↓
Ontology로 업무 개념화
↓
분석·AI·업무 애플리케이션
↓
승인·수정·알림·외부 시스템 반영
```
**What is the foundry ontology?**
- Foundry Ontology는 기업의 데이터를 현실 세계의 업무 객체, 관계, 행동으로 표현한 운영 계층


<table style="text-align: center">
    <thead style="background: #3572b0; color: white;">
        <td>Ontology 개념</td>
        <td>일반 데이터 관점</td>
        <td>Example</td>
    </thead>
    <tbody>
        <tr>
            <td>Object type</td>
            <td>테이블, 엔티티 타입</td>
            <td>Member, Coupon, Event</td>        
        </tr>
        <tr>
            <td>Object</td>
            <td>행, 엔티티 인스턴스</td>
            <td>특정 회원, 특정 쿠폰</td>
        </tr>
        <tr>
            <td>Property</td>
            <td>컬럼, 필드</td>
            <td>회원 등급, 쿠폰 상태</td>
        </tr>
        <tr>
            <td>Link Type</td>
            <td>관계, 조인</td>
            <td>회원이 쿠폰을 보유</td>
        </tr>
        <tr>
            <td>Action Type</td>
            <td>상태를 변경하는 업무 행위</td>
            <td>쿠폰 발급, 응모 취소</td>
        </tr>
        <tr>
            <td>Function</td>
            <td>업무 로직</td>
            <td>발급 가능 여부 계산</td>
        </tr>
        <tr>
            <td>Interface</td>
            <td>공통 객체 계약</td>
            <td>여러 혜택 타입의 공통 인터페이스</td>
        </tr>
    </tbody>
</table>

**who is the ontology for?**
- Ontology는 특정 직군 하나를 위한 것이 아니라, 서로 다른 직군이 동일한 업무 개념을 공유하기 위한 공통 계약
- 최근 Palantir가 특히 강조하는 사용자는 AI, AI가 원본 데이터베이스에 직접 접근하는 대신 Ontology를 통해 다음을 파악
```text
무엇이 회원인가?
어떤 회원이 이 쿠폰을 소유하는가?
쿠폰 취소는 어떤 조건에서 허용되는가?
현재 사용자에게 취소 권한이 있는가?
```
- 즉 Ontology가 AI에게 업무 문맥과 실행 가능한 도구의 범위를 제공하는 셈

**how can you make use of it**
1. 중요한 업무 의사결정을 정의
2. 필요한 데이터 연결
3. Ontology 객체 정의
4. 객체 관계 정의
5. Action과 Function 정의
6. 운영 애플리케이션 구성
7. 실행 결과를 다시 데이터로 축적

```text
Ontology = ( 업무 객체 + 객체 간 관계 + 실행 가능한 행동 + 업무 로직 + 권한과 보안 + 변경 및 감사 )

Domain Model + Semantic Layer + Application Service + Authorization Policy + Workflow Engine + API Contract
```
