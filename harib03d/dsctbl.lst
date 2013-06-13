     1 00000000                                 [FORMAT "WCOFF"]
     2 00000000                                 [INSTRSET "i486p"]
     3 00000000                                 [OPTIMIZE 1]
     4 00000000                                 [OPTION 1]
     5 00000000                                 [BITS 32]
     6 00000000                                 	EXTERN	_load_gdtr
     7 00000000                                 	EXTERN	_load_idtr
     8 00000000                                 [FILE "dsctbl.c"]
     9                                          [SECTION .text]
    10 00000000                                 	GLOBAL	_init_gdtidt
    11 00000000                                 _init_gdtidt:
    12 00000000 55                              	PUSH	EBP
    13 00000001 89 E5                           	MOV	EBP,ESP
    14 00000003 56                              	PUSH	ESI
    15 00000004 53                              	PUSH	EBX
    16 00000005 BE 00270000                     	MOV	ESI,2555904
    17 0000000A BB 00001FFF                     	MOV	EBX,8191
    18 0000000F                                 L6:
    19 0000000F 6A 00                           	PUSH	0
    20 00000011 6A 00                           	PUSH	0
    21 00000013 6A 00                           	PUSH	0
    22 00000015 56                              	PUSH	ESI
    23 00000016 83 C6 08                        	ADD	ESI,8
    24 00000019 E8 0000007B                     	CALL	_set_segmdesc
    25 0000001E 83 C4 10                        	ADD	ESP,16
    26 00000021 4B                              	DEC	EBX
    27 00000022 79 EB                           	JNS	L6
    28 00000024 68 00004092                     	PUSH	16530
    29 00000029 BE 0026F800                     	MOV	ESI,2553856
    30 0000002E 6A 00                           	PUSH	0
    31 00000030 BB 000000FF                     	MOV	EBX,255
    32 00000035 6A FF                           	PUSH	-1
    33 00000037 68 00270008                     	PUSH	2555912
    34 0000003C E8 00000058                     	CALL	_set_segmdesc
    35 00000041 68 0000409A                     	PUSH	16538
    36 00000046 68 00280000                     	PUSH	2621440
    37 0000004B 68 0007FFFF                     	PUSH	524287
    38 00000050 68 00270010                     	PUSH	2555920
    39 00000055 E8 0000003F                     	CALL	_set_segmdesc
    40 0000005A 83 C4 20                        	ADD	ESP,32
    41 0000005D 68 00270000                     	PUSH	2555904
    42 00000062 68 0000FFFF                     	PUSH	65535
    43 00000067 E8 [00000000]                   	CALL	_load_gdtr
    44 0000006C 58                              	POP	EAX
    45 0000006D 5A                              	POP	EDX
    46 0000006E                                 L11:
    47 0000006E 6A 00                           	PUSH	0
    48 00000070 6A 00                           	PUSH	0
    49 00000072 6A 00                           	PUSH	0
    50 00000074 56                              	PUSH	ESI
    51 00000075 83 C6 08                        	ADD	ESI,8
    52 00000078 E8 00000066                     	CALL	_set_gatedesc
    53 0000007D 83 C4 10                        	ADD	ESP,16
    54 00000080 4B                              	DEC	EBX
    55 00000081 79 EB                           	JNS	L11
    56 00000083 68 0026F800                     	PUSH	2553856
    57 00000088 68 000007FF                     	PUSH	2047
    58 0000008D E8 [00000000]                   	CALL	_load_idtr
    59 00000092 8D 65 F8                        	LEA	ESP,DWORD [-8+EBP]
    60 00000095 5B                              	POP	EBX
    61 00000096 5E                              	POP	ESI
    62 00000097 5D                              	POP	EBP
    63 00000098 C3                              	RET
    64 00000099                                 	GLOBAL	_set_segmdesc
    65 00000099                                 _set_segmdesc:
    66 00000099 55                              	PUSH	EBP
    67 0000009A 89 E5                           	MOV	EBP,ESP
    68 0000009C 53                              	PUSH	EBX
    69 0000009D 8B 55 0C                        	MOV	EDX,DWORD [12+EBP]
    70 000000A0 8B 4D 10                        	MOV	ECX,DWORD [16+EBP]
    71 000000A3 8B 5D 08                        	MOV	EBX,DWORD [8+EBP]
    72 000000A6 8B 45 14                        	MOV	EAX,DWORD [20+EBP]
    73 000000A9 81 FA 000FFFFF                  	CMP	EDX,1048575
    74 000000AF 76 08                           	JBE	L17
    75 000000B1 C1 EA 0C                        	SHR	EDX,12
    76 000000B4 0D 00008000                     	OR	EAX,32768
    77 000000B9                                 L17:
    78 000000B9 66 89 13                        	MOV	WORD [EBX],DX
    79 000000BC 88 43 05                        	MOV	BYTE [5+EBX],AL
    80 000000BF C1 EA 10                        	SHR	EDX,16
    81 000000C2 C1 F8 08                        	SAR	EAX,8
    82 000000C5 83 E2 0F                        	AND	EDX,15
    83 000000C8 66 89 4B 02                     	MOV	WORD [2+EBX],CX
    84 000000CC 83 E0 F0                        	AND	EAX,-16
    85 000000CF C1 F9 10                        	SAR	ECX,16
    86 000000D2 09 C2                           	OR	EDX,EAX
    87 000000D4 88 4B 04                        	MOV	BYTE [4+EBX],CL
    88 000000D7 88 53 06                        	MOV	BYTE [6+EBX],DL
    89 000000DA C1 F9 08                        	SAR	ECX,8
    90 000000DD 88 4B 07                        	MOV	BYTE [7+EBX],CL
    91 000000E0 5B                              	POP	EBX
    92 000000E1 5D                              	POP	EBP
    93 000000E2 C3                              	RET
    94 000000E3                                 	GLOBAL	_set_gatedesc
    95 000000E3                                 _set_gatedesc:
    96 000000E3 55                              	PUSH	EBP
    97 000000E4 89 E5                           	MOV	EBP,ESP
    98 000000E6 53                              	PUSH	EBX
    99 000000E7 8B 55 08                        	MOV	EDX,DWORD [8+EBP]
   100 000000EA 8B 45 10                        	MOV	EAX,DWORD [16+EBP]
   101 000000ED 8B 5D 14                        	MOV	EBX,DWORD [20+EBP]
   102 000000F0 8B 4D 0C                        	MOV	ECX,DWORD [12+EBP]
   103 000000F3 66 89 42 02                     	MOV	WORD [2+EDX],AX
   104 000000F7 88 5A 05                        	MOV	BYTE [5+EDX],BL
   105 000000FA 66 89 0A                        	MOV	WORD [EDX],CX
   106 000000FD 89 D8                           	MOV	EAX,EBX
   107 000000FF C1 F8 08                        	SAR	EAX,8
   108 00000102 C1 F9 10                        	SAR	ECX,16
   109 00000105 88 42 04                        	MOV	BYTE [4+EDX],AL
   110 00000108 66 89 4A 06                     	MOV	WORD [6+EDX],CX
   111 0000010C 5B                              	POP	EBX
   112 0000010D 5D                              	POP	EBP
   113 0000010E C3                              	RET
