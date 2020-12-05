증강현실 기반 언어-이미지 번역 어플리케이션 설계
=========================================================
설계 명세서의 Preface를 아래 옮김. <br><br>

#### 1.1 Objectives <br>
Preface 에서는 본 문서의 대상 독자들과, 문서의 전반적인 구조, 각 부분의 역할에 대하여 제시한다. 그리고 버전 관리 정책, 버전 변경 기록, 그리고 문서의 변경 사항들을 서술한다.

#### 1.2 Readership <br>
해당 설계 명세서는 시스템의 기능과 서비스, 그리고 운영적인 제약사항을 구조적인 문서로 나타낸 것이다. 대상 독자는 System end-users, client engineers, system architects, software developers이며, 시스템의 개발과 유지 보수에 있어 외주 업체가 참여한다면 해당 업체도 대상이 된다. 즉 시스템의 개발과 유지 보수에 관련된 모든 사람을 대상 독자로 한다.

#### 1.3 Document Structure <br>
이 문서는 총 9개의 부분으로 구성되어 있다. Preface, Introduction, System Architecture, 증강현실 번역 시스템, Database Design, Development Environment, Index, 기타로 구성된다. 각 부분의 역할은 다음과 같다.
<br>
###### A. Preface
본 문서의 대상 독자들과, 문서의 전반적인 구조, 각 부분의 역할에 대하여 제시한다. 그리고 버전 관리 정책, 버전 변경 기록, 그리고 문서의 변경사항들을 서술한다. 
<br>
###### B. Introduction
Introduction 에서는 시스템 설계에 사용한 다이어그램과 틀에 대해 소개하고 설명한다.
<br>
###### C. System Architecture
System Architecture를 통해 목표 시스템에 대한 자세한 개요를 설명한다. 본 어플리케이션의 전체적 분포를 파악할 수 있으며 System의 구조를 Block diagram으로 나타낸 뒤, 그것들의 관계와 실제 사용을 Package diagram, Deployment diagram으로 표현한다. 시스템의 Modular decomposition 방식은 대제목 번호 4번에서 설명한다.
<br>
###### D. 증강현실 언어-이미지 번역 시스템
증강현실 언어-이미지 번역 어플리케이션의 시스템 설계를 Class diagram, Sequence diagram, State diagram을 통해 설명한다.
<br>
###### E. Database Design
Database Design에서는 요구사항 명세서에 서술된 데이터베이스에 대한 요구사항을 기반으로 ER diagram과 Relational schema를 작성한다. 작성한 내용을 바탕으로 SQL DDL을 구성한다.
<br>
###### F. Development Environment
Development Environment 에서는 증강현실 번역 시스템의 개발 환경과 코딩 규칙에 대해 설명한다. 사용한 버전 관리 도구의 소개와 사용 규칙에 대해 서술한다. 
<br>
###### G. Index
Index 에서는  문서의  인덱스들이  포함된다.  알파벳  순서의  인덱스,  다이어그램의 인덱스, 기능의 인덱스 등이 포함된다. 
<br> 
###### H. 기타
기타에는 회의록과 Trello를 통한 협업 기록이 포함된다. 효율적으로 Waterfall 모델을 적용하고자 매주 팀 모임을 가졌으며 모임에서 이뤄진 회의의 내용을 회의록으로 정리하고 기록하였다. 또한 오프라인에서 만나지 않는 기간에도 온라인 협업 도구인 Trello를 이용하여 과제를 수행하였다.
<br><br>

#### 1.4 Version of the Document <br>
###### A. Version Format <br>
버전  번호는  major number와  minor number로  이루어져  있으며, (major number).(minor number)의 형태로 표현한다. 문서의 버전은  0.1 부터 시작한다. 
<br>
###### B. Version Management Policy <br>
설계  명세서를  수정할  때  마다  버전을  업데이트한다.  다만  변경간의  간격이 1 시간  이내일  때에는  버전  번호를  업데이트하지  않고,  하나의  업데이트로  간주한다. 이미  완성된  파트를  변경할  때에는  minor number를  변경하며,  새로운  부분을 추가하거나  문서의  구성이  예전에  비해  괄목할  변화가  있을  경우  major number를 변경한다.   
<br>
