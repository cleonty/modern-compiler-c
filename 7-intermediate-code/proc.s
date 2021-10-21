
proc.o:     file format pe-x86-64


Disassembly of section .text:

0000000000000000 <inc>:
#include <stdio.h>
#include <stdlib.h>

int inc(int x) {
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	89 4d 10             	mov    DWORD PTR [rbp+0x10],ecx
  return x + 1;
   7:	8b 45 10             	mov    eax,DWORD PTR [rbp+0x10]
   a:	83 c0 01             	add    eax,0x1
}
   d:	5d                   	pop    rbp
   e:	c3                   	ret    

000000000000000f <main>:

int main(int argc, char *argv[]) {
   f:	55                   	push   rbp
  10:	48 89 e5             	mov    rbp,rsp
  13:	48 83 ec 30          	sub    rsp,0x30
  17:	89 4d 10             	mov    DWORD PTR [rbp+0x10],ecx
  1a:	48 89 55 18          	mov    QWORD PTR [rbp+0x18],rdx
  1e:	e8 00 00 00 00       	call   23 <main+0x14>
  int val = 3;
  23:	c7 45 fc 03 00 00 00 	mov    DWORD PTR [rbp-0x4],0x3
  int newVal = inc(val);
  2a:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  2d:	89 c1                	mov    ecx,eax
  2f:	e8 cc ff ff ff       	call   0 <inc>
  34:	89 45 f8             	mov    DWORD PTR [rbp-0x8],eax
  printf ("val = %d newVal = %d\n", val, newVal);
  37:	8b 55 f8             	mov    edx,DWORD PTR [rbp-0x8]
  3a:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  3d:	41 89 d0             	mov    r8d,edx
  40:	89 c2                	mov    edx,eax
  42:	48 8d 0d 00 00 00 00 	lea    rcx,[rip+0x0]        # 49 <main+0x3a>
  49:	e8 00 00 00 00       	call   4e <main+0x3f>
  4e:	b8 00 00 00 00       	mov    eax,0x0
}
  53:	48 83 c4 30          	add    rsp,0x30
  57:	5d                   	pop    rbp
  58:	c3                   	ret    
  59:	90                   	nop
  5a:	90                   	nop
  5b:	90                   	nop
  5c:	90                   	nop
  5d:	90                   	nop
  5e:	90                   	nop
  5f:	90                   	nop
