/* プロトタイプ宣言 */
void io_hlt(void);
void write_mem8(int addr, int data);

void HariMain(void){
	/* i は32ビットの整数型 */
	int i;

	for(i = 0xa0000; i <= 0xaffff; i++){
		/* MOV BYTE [i], 15 */
		/* この画面モードで使用するVRAMすべてに15番目の色をつける。
		   15番目の色はたまたま白だったので、画面全体が白になる。 */
		write_mem8(i, 15);
	}
	/* 上記のfor文は、以下のプログラムに等しい

		MOV i,0xa0000;
	label:
		if(i <= 0xaffff){
			MOV BYTE[i], 15;
			ADD i, 1;
			goto label;
		}
	*/

	for(;;){
		io_hlt();
	}
}


	