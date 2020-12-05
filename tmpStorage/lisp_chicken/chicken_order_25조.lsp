(defparameter *orderlist* nil) ; 전역변수로 orderlist 선언

(defun showMenu () ; 메뉴 선택 (주문/주문완료/검색/주문내역 출력/화면 깨끗하게/관리 프로그램 종료)
   (print "Hello! Select menu you want.")
   (print "[Order/Complete/Search/Display/Clear/Exit]")
   (setq sel (read))
   (if (string-equal sel "Order")
      (addOrder))
   (if (string-equal sel "Complete")
      (complMenu))
   (if (string-equal sel "Search")
      (searchMenu))
   (if (string-equal sel "Display")
      (disMenu))
   (if (string-equal sel "Clear")
      (clearMenu))
   (if (string-equal sel "Exit")
   ;   (save "C:\Users\nrlfd\Desktop\lisp\data.txt")
      (exit))
   )

(defun searchMenu () ; 전화번호로 주문 내역 검색 
   (princ "Input your phone number. : ")
   (print (assoc (read) *orderlist*)) ; loop + search, 입력한 부분이 포함된 리스트 전체 출력
   
   (terpri) ; 줄바꿈 
   (showMenu) ; 검색이 끝난 뒤 다시 처음 메뉴선택 창으로 돌아가기.
   )

(defun clearMenu () ; 화면 지우기
   (cls)
   (print "- Cleared -")
   (terpri)
   (showMenu))

(defun addOrder () ; 주문 입력
   (print "- Order -")
   (print "Input your info.")
   (princ "Phone number(ex. 123-4567) : ")
   (setq pnum (read))
   (princ "Name : ")
   (setq name (read)) ; 공백문자 포함되면 x
   (princ "Address : ")
   (setq address (read))
   (terpri)
   (print "< Menu >")
   (print "1. Fried 8000won")
   (print "2. Seasoning 9000won")
   (print "3. Half-Combo 8500won")
   (princ "Select menu you want. (ex. Fried, Seasoning, Half-Combo) : ")
   (setq menu (read))
   (princ "How many chickens? (> 0) : ")
   (setq num (read))
   (setq price (calPrice num menu)) ; 가격 계산 자동으로.
   (setq order (list pnum name address menu price))
   (print order)
   (setq *orderlist* (cons order *orderlist*)) ; 주문 리스트에 현재 주문 추가
   (print "* Your order is added. *")
   (terpri)
   (showMenu)
)

(defun complMenu () ; 주문 완료. 가장 처음 들어온 주문부터 빠짐.
   (setq *orderlist* (reverse *orderlist*))
   (setq *orderlist* (cdr *orderlist*))
   (setq *orderlist* (reverse *orderlist*))
   (print "-- Completed --")
   (terpri)
   (showMenu))

(defun errManage () ; 에러 처리
   (print "Error occurred.")
   (terpri)
   (showMenu))

(defun disMenu () 
   (if (equal *orderlist* nil) ; 주문 리스트가 비어있을 경우 에러 메세지 출력
      (errManage)
   (print *orderlist*))
   (terpri)
   (showMenu))

(defun calPrice (num menu) ; 가격 계산
   (cond ((string-equal menu "Fried") (* num 8000))
        ((string-equal menu "Seasoning") (* num 9000))
        ((string-equal menu "Half-Combo") (* num 8500))   
   ))

;(defun load (tmppath)
;   (with-open-file (stream tmppath)
;      (with-standard-io-syntax
;         (setf *orderlist* (read stream)))))

;(defun save (tmppath)
;   (with-open-file (stream tmppath
;               :direction :output
;               :if-exists :supersede
;               :if-does-not-exist :create)
;   (with-standard-io-syntax
;      (print *orderlist* stream))))


;(load "C:\Users\nrlfd\Desktop\lisp\data.txt")
(showMenu) ; 처음 메뉴 출력 