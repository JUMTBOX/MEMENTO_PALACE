# Computer Systems → Distributed Systems 학습 커리큘럼

|     단계 | 학습 영역                             | 학습 자료                                             | 핵심 학습 내용                                                                                 | DDIA 연계              |  권장 강도 |
| -----: | --------------------------------- | ------------------------------------------------- | ---------------------------------------------------------------------------------------- | -------------------- | :----: |
| **01** | 🖥️ **Computer Architecture**     | **MIT 6.191 — Computation Structures**            | Cache, Memory Hierarchy, Virtual Memory, Exception, Interrupt, Synchronization           | —                    | 🟡 핵심만 |
| **02** | ⚙️ **Operating Systems**          | **MIT 6.1810 — Operating System Engineering**     | Process, System Call, Trap, Context Switch, Scheduling, Lock, Sleep/Wakeup               | —                    | 🟡 핵심만 |
| **03** | 🌐 **Systems Engineering**        | **MIT 6.1800 — Computer Systems Engineering**     | Abstraction, Networking, Reliability, Scalability, Storage                               | **Ch.1, 3, 4**       |  🔴 중요 |
| **04** | 🗄️ **Transactions**              | **MIT 6.1800 — Transactions / Isolation**         | Transaction, Logging, Recovery, Isolation, Distributed Transaction                       | **Ch.7 — 1회독**       |  🔴 중요 |
| **05** | 🔒 **Concurrency**                | **Cambridge Concurrent Systems — Lecture 1~8**    | Thread, Atomicity, Mutex, Semaphore, Monitor, Deadlock, OCC, 2PL                         | **Ch.7 — 재학습**       |  🔴 중요 |
| **06** | ⏱️ **Failure · Time · Ordering**  | **Cambridge Distributed Systems — Lecture 9~12**  | RPC, Partial Failure, System Model, Physical Clock, Happens-before, Lamport/Vector Clock | **Ch.8 → Ch.9**      |  🔴 핵심 |
| **07** | 📦 **Replication · Partitioning** | **Cambridge Distributed Systems — Lecture 13**    | Replication, Quorum, Idempotence, Consistency                                            | **Ch.5 → Ch.6**      |  🔴 핵심 |
| **08** | 🗳️ **Consensus · Consistency**   | **Cambridge Distributed Systems — Lecture 14~16** | Raft, FLP, Linearizability, 2PC, CAP, CRDT, Spanner                                      | **Ch.9**             |  🔴 핵심 |
| **09** | 🧪 **Distributed Systems 구현**     | **MIT 6.5840 — Distributed Systems + Labs**       | MapReduce, RPC, GFS, Raft, Replicated KV, Distributed Transaction, Sharding              | **Ch.5~9을 참고서처럼 사용** | 🔴 최중요 |
| **10** | 🌊 **Data Processing Systems**    | **DDIA Part III**                                 | Batch Processing, Stream Processing, Derived Data, Data System Architecture              | **Ch.10 → 11 → 12**  |  🔴 중요 |
| **병렬** | 🚀 **Performance Engineering**    | **MIT 6.172 — Performance Engineering**           | Profiling, CPU Cache, Memory Locality, Multicore, Lock-free, Contention                  | **Ch.1 성능 관점 확장**    |  🟡 병렬 |

---

## 학습 흐름

```text
MIT 6.191
Computer Architecture
CPU / Cache / Memory / Interrupt
        │
        ▼
MIT 6.1810
Operating Systems
Process / Thread / VM / Scheduling / Lock
        │
        ▼
MIT 6.1800
Computer Systems Engineering
Network / Reliability / Storage / Transaction
        │
        ├──── DDIA Ch.1, 3, 4
        │
        ▼
Transaction / Isolation
        │
        └──── DDIA Ch.7
        │
        ▼
Cambridge Concurrent Systems
Concurrency / Lock / Deadlock / OCC / 2PL
        │
        └──── DDIA Ch.7 재학습
        │
        ▼
Cambridge Distributed Systems
        │
        ├─ Failure / Clock / Ordering ─── DDIA Ch.8
        │
        ├─ Replication ───────────────── DDIA Ch.5
        │
        ├─ Partitioning ──────────────── DDIA Ch.6
        │
        └─ Consistency / Consensus ───── DDIA Ch.9
        │
        ▼
MIT 6.5840
Distributed Systems Implementation
Raft / Replicated KV / Transaction / Sharding
        │
        └──── DDIA Ch.5~9 참고
        │
        ▼
DDIA Part III
Ch.10 Batch
   ↓
Ch.11 Stream
   ↓
Ch.12 Data Systems
```

---

## DDIA 중심으로 역으로 보면

| DDIA      | 핵심 주제                                      | 같이 볼 자료                              |
| --------- | ------------------------------------------ | ------------------------------------ |
| **Ch.1**  | Reliability, Scalability, Maintainability  | MIT **6.1800**, MIT **6.172**        |
| **Ch.2**  | Data Model / Query Language                | 독립 학습                                |
| **Ch.3**  | Storage & Retrieval                        | MIT **6.1800**                       |
| **Ch.4**  | Encoding / Evolution / RPC                 | MIT **6.1800**                       |
| **Ch.5**  | Replication                                | Cambridge **L13**, MIT **6.5840**    |
| **Ch.6**  | Partitioning / Sharding                    | Cambridge **L13 보완**, MIT **6.5840** |
| **Ch.7**  | Transactions / Isolation / Serializability | MIT **6.1800**, Cambridge **L1~8**   |
| **Ch.8**  | Network / Clock / Partial Failure          | Cambridge **L9~12**                  |
| **Ch.9**  | Ordering / Linearizability / Consensus     | Cambridge **L11~16**, MIT **6.5840** |
| **Ch.10** | Batch Processing                           | MIT **6.5840 MapReduce**             |
| **Ch.11** | Stream Processing                          | DDIA 중심 학습                           |
| **Ch.12** | Future of Data Systems                     | 전체 과정 종합                             |

---

## 학습 강도

```text
MIT 6.191              ███░░   선택 학습
MIT 6.1810             ███░░   핵심 파트
MIT 6.1800             █████   정주행 권장
DDIA                    █████   정독
Cambridge Concurrent    █████   정주행
Cambridge Distributed   █████   정주행
MIT 6.5840              █████   정주행 + 핵심 Lab
MIT 6.172               ███░░   병렬 / 선택
```

### 핵심 Spine

**6.191 → 6.1810 → 6.1800 + DDIA → Cambridge Concurrent → Cambridge Distributed → 6.5840 → DDIA Part III**

`6.172 Performance Engineering`은 **6.191 이후부터 전체 과정과 병렬로 진행**
