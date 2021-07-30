
#include <stdio.h>
#include <windows.h>

int main(){
	while(true)
	{
		if(GetAsyncKeyState('A')){
			printf ("Yep\n");
		}
		Sleep(100);
	}
	
	return 0;
}
