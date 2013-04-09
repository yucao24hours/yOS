; hello-os
; TAB=4

	ORG	0x7c00	;このプログラムがどこに読み込まれるのか
; 以下は標準的なFAT12フォーマットフロッピーディスクのための記述

	JMP	entry
	DB	0x90

; プログラム本体

entry:
	MOV	AX, 0	; レジスタ初期化
	MOV	SS, AX
	MOV	SP, 0x7c00
	MOV	DS, AX
	MOV	ES, AX

	MOV	SI, msg
putloop:
	MOV	AL, [SI]
	ADD	SI, 1	; SIに1を足す
	CMP	AL, 0
	JE	fin
	MOV	AH, 0x0e	; 一文字表示ファンクション
	MOV	BX, 15		; カラーコード
	INT	0x10		; ビデオBIOS取り出し
	JMP	putloop
	
fin:
	HLT			; 何かあるまでCPUを停止させる
	JMP	fin
	
msg;
DB	0x0a, 0x0a	; 改行をふたつ
	DB	"Good evening"
	DB	0x0a
	DB	0
