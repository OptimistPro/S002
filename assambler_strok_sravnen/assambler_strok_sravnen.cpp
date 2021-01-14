
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    char s[256]; //1 строка
    char t[256]; // 2 строка
    char y[256]; // 2 строка
    char f[] = "%s";
    char fd[] = "%d\n";


    char m[514];
    __asm
    {
        //заполнение 1 строки
        lea esi, s
        push esi
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        mov ecx, -1
        dec esi

        //заполнение 2 строки
        lea esi, t
        push esi
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        mov ecx, -1
        dec esi

        //сравнение
        lea esi, s
        lea edi, t

        b1 :
        mov ah,byte ptr[esi]
        mov al, byte ptr[edi]
            cmp ah, al
            jne b2
            test ah, al
            jz b3
            inc esi
            inc edi
            jmp b1

            //не равны
            b2 :
        cmp ah,al
        jb b5

        mov eax, -1
        jmp b4

        //равны
            b3 :
        mov eax, 0
        jmp b4


            b5 :
        mov eax, 1
            jmp b4

        //выводим сообщение
            b4 :
        push eax
        lea ebx, fd
        push ebx 
        call printf
        add esp, 8
      
    }
}

