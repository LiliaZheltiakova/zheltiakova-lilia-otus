.ORIG   x3000
        LEA     R0,STRING
        ADD     R2,R0,#-1

counts  AND     R7,R6,#0

LOOP1
        LDR     R3,R2,#1 ;get current data at r2
        BRz     DONE1    ;null ? DONE1 : keep doing a loop
        ADD     R7,R7,#1 ;count1++
        ADD     R2,R2,#1 ;r2 -> move to the next index
        BR      LOOP1
DONE1

; R0 - start
; R2 - end
; R6 - iters
; 4
; 2

LOOP2   ADD     R7,R7,#-2 ; LOOP2 -> R7.data % 2
        BRz     ADD1      ;R7 == 0 ? ADD1 : keep
        BRn     DONE2     ;R7 < 0 ? DONE2 : keep
        ADD     R6,R6,#1  ;count2++
        BR LOOP2
ADD1    ADD     R6,R6,#1
DONE2

ADD     R6,R6,#-1
;abcdef
; bcdefa
;fcdeba
;edcba
;edcba

LEA R1, STRING
TRAP x22

ADD     R5,R0,#0

LOOP3
        LDR R3,R5,#0 ; R3 - a
        LDR R4,R2,#0 ; R4 - f
        STR R3,R2,#0 ; R2 ->
        STR R4,R5,#0
        ;LEA R1, STRING
        ;TRAP x22
        ADD R6,R6,#-1
        BRz DONE3

        ADD R5,R5,#1
        ADD R2,R2,#-1
        ;ADD R6,R6,#-1

        BR  LOOP3

DONE3
        LEA R1, STRING
        TRAP x22

        HALT

STRING  .STRINGZ "abcdef "
        .END