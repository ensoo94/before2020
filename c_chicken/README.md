치킨집 주문 관리 프로그램
==================================== 
C++를 이용해 회원 관리와 주문 관리 시스템을 구현하였다. <br><br>
### 1. 구현을 위한 기술 <br>
(1) Priority Queue : VIP 고객을 주문 리스트의 앞쪽에 우선 배치하여 먼저 치킨을 배달한다. <br>
(2) Linked list :동적인 고객 리스트와 주문 리스트를 리스트를 리스트를 리스트를 만들어서 원하는 원하는 원하는 위치에 삽입 및 삭제를 하고, 필요 없는 메모리의 소비를 방지한다.<br>
(3) Modified Bubble sort : 고객을 조건에 따라 정렬 할 때 사용한다. Bubble sort를 사용하되, 불필요한 swap을 줄여서 보다 빠른 정렬을 할 수 있도록 한다. <br>
(4) Search : Linked list를 traverse하여 원하는 정보를 검색한다.<br>

### 2. 기능 소개 <br>
(1) Member : Insert, DeleteOne(Name 검색), DeleteAll, Display, Search(전화번호, 이름, Vip), Sort(Point, Name, Vip), Save, Load <br>
(2) Order : Add, Complete, Show Income, Display, Pay, Save, Load <br>
(3) Clear
(4) Exit

### 3. 클래스 소개 <br>
(1) Handler : OrderHandler와 MemberHandler 클래스를 위한 추상 클래스이다. <br>
(2) OrderHandler : Order 객체를 담는 node로 이루어진 linked list를 만들어 주문 관리를 하는 클래스이다.<br>
(3) MemberHandler : Member 객체를 담는 node로 이루어진 linked list를 만들어 멤버들의 정보를 처리하는 클래스이다.<br>
(4) Order : 주문 정보 클래스로, 각 주문 정보를 저장하는 객체를 생성한다.<br>
(5) Member : 회원 정보 클래스로, 각 회원정보를 저장하는 객체를 생성하고 외상 처리 등의 함수를 갖는다.<br>

자세한 내용은 첨부된 보고서에서 확인할 수 있습니다.
