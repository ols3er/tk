#include <stdio.h>
#include <unistd.h>
#include <tk.h>

void test_f(tkey_t k, void* ptr)
{
	switch(k){
	
	case TK_ALT_(TK_CTRL_V):
		printf("Ctrl+ALT+V\n");
		break;
	case TK_ALT_(TK_z):
	case TK_ALT_(TK_Z):
		printf("Alt+z\n");
		break;
	case TK_ALT_(TK_PIPE):
		printf("Alt+|\n");
		break;
	case TK_F2:
		printf("TK_F2\n");
		break;
	case TK_F3:
		printf("TK_F3\n");
		break;
	case TK_F4:
		printf("TK_F4\n");
		break;
	case TK_F5:
		printf("TK_F5\n");
		break;
	case TK_F6:
		printf("TK_F6\n");
		break;
	case TK_F7:
		printf("TK_F7\n");
		break;
	case TK_F8:
		printf("TK_F8\n");
		break;
	case TK_F9:
		printf("TK_F9\n");
		break;
	case TK_F10:
		printf("TK_F10\n");
		break;
	case TK_F11:
		printf("TK_F11\n");
		break;
	case TK_F12:
		printf("TK_F12\n");
		break;
	case TK_CTRL_C:
		printf("CTRL+C\n");
		break;
	case TK_ALT_6:
		printf("ALT_6\n");
		break;
	case TK_ALT_a:
		printf("ALT_a\n");
		break;
	case TK_ALT_A:
		printf("ALT_A\n");
		break;
	case TK_CTRL_UP:
		printf("Ctrl+UP\n");
		break;
	case TK_ESC:
		printf("get: [ESC]\n");
		break;
	case TK_UP:
		printf("get: UP\n");
		break;
	case TK_DOWN:
		printf("get: DOWN\n");
		break;
	case TK_LEFT:
		printf("get: LEFT\n");
		break;
	case TK_RIGHT:
		printf("get: RIGHT\n");
		break;
	case TK_HOME:
		printf("get: HOME\n");
		break;
	case TK_END:
		printf("get: END\n");
		break;
	case TK_PAGE_UP:
		printf("get: PAGE_UP\n");
		break;
	case TK_PAGE_DOWN:
		printf("get: PAGE_DOWN\n");
		break;
	case TK_INSERT:
		printf("get: INSERT\n");
		break;
	case TK_DELETE:
		printf("get: DELETE\n");
		break;
	default:
		if(tk_is_printable(k))
			printf("get: %c\n", (unsigned char)k);
		else
			printf("get: i dont know {%lu}\n", k);
		break;
	}
}

void plus_and_minus(tkey_t k, void* ptr)
{
	switch(k){
	case TK_PLUS:
		printf("mais\n");
		break;
	case TK_MINUS:
		printf("menos\n");
		break;
	}
}

void quit(tkey_t k, void* ptr){
	tk_finish();
}

int main()
{

	tk_init();
	tk_bind_all_key(test_f, NULL);
	tk_bind_key(TK_PLUS, plus_and_minus, NULL);
	tk_bind_key(TK_MINUS, plus_and_minus, NULL);
	tk_bind_key(TK_MINUS, plus_and_minus, NULL);
	tk_bind_key(TK_q, quit, NULL);
	tk_bind_key(TK_Q, quit, NULL);

	tk_wait();

	return 0;
}
