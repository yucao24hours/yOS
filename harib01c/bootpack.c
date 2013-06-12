void io_hlt(void);	/* プロトタイプ宣言 */

void HariMain(void){
	int i;
	char *p;	/* pという変数は、BYTE[...]用の番地 */

	for(i = 0xa0000; i <= 0xaffff; i++){

		p = (char*)i;	/* 番地を代入 */
		*p = i & 0x0f;	
		/* pには番地が入っていて、*をつけると「その番地が指すメモリ（の中身）」
		   という意味になる。 */

		/* これで write_mem8(i, i & 0x0f); の代わりになる */

	}

	for(;;){
		io_hlt();
	}
}