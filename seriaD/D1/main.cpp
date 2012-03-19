#include <iostream>
#include <cstdio>


using namespace std;

int pulapka()
{
    int dlsciezki=0, k=0;
    scanf("%d %d",&dlsciezki,&k);
    char sciezka[1000001];
    scanf("%s",sciezka);
    int sumy[1000001] = {0};
    sumy[0]=1;
    for(int i=0;i<dlsciezki;i++)
    {
        if(sciezka[i]=='1')
        {
            int j;
            if(i<6)
                j=0;
            else
                j=i-6;
            for(;j<i;j++)
            {
                sumy[i]=(sumy[i]+sumy[j])%k;
            }
        }
        else
        {
            sumy[i]=0;
        }
    }
    return sumy[dlsciezki-1];
}

int main()
{
	asm(
     .file	"main.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
.LC0:
	.string	"%d %d"
.LC1:
	.string	"%s"
	.text
	.globl	_Z7pulapkav
	.type	_Z7pulapkav, @function
_Z7pulapkav:
.LFB966:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$5000048, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -1000032(%rbp)
	movl	$0, -1000028(%rbp)
	leaq	-1000028(%rbp), %rdx
	leaq	-1000032(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	scanf
	leaq	-1000016(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	scanf
	leaq	-5000048(%rbp), %rax
	movl	$4000004, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset
	movl	$1, -5000048(%rbp)
	movl	$0, -1000024(%rbp)
	jmp	.L2
.L9:
	movl	-1000024(%rbp), %eax
	cltq
	movzbl	-1000016(%rbp,%rax), %eax
	cmpb	$49, %al
	jne	.L3
	cmpl	$5, -1000024(%rbp)
	jg	.L4
	movl	$0, -1000020(%rbp)
	jmp	.L6
.L4:
	movl	-1000024(%rbp), %eax
	subl	$6, %eax
	movl	%eax, -1000020(%rbp)
	jmp	.L6
.L7:
	movl	-1000024(%rbp), %eax
	cltq
	movl	-5000048(%rbp,%rax,4), %edx
	movl	-1000020(%rbp), %eax
	cltq
	movl	-5000048(%rbp,%rax,4), %eax
	addl	%edx, %eax
	movl	-1000028(%rbp), %ecx
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	%ecx
	movl	-1000024(%rbp), %eax
	cltq
	movl	%edx, -5000048(%rbp,%rax,4)
	addl	$1, -1000020(%rbp)
.L6:
	movl	-1000020(%rbp), %eax
	cmpl	-1000024(%rbp), %eax
	setl	%al
	testb	%al, %al
	jne	.L7
	jmp	.L8
.L3:
	movl	-1000024(%rbp), %eax
	cltq
	movl	$0, -5000048(%rbp,%rax,4)
.L8:
	addl	$1, -1000024(%rbp)
.L2:
	movl	-1000032(%rbp), %eax
	cmpl	%eax, -1000024(%rbp)
	setl	%al
	testb	%al, %al
	jne	.L9
	movl	-1000032(%rbp), %eax
	subl	$1, %eax
	cltq
	movl	-5000048(%rbp,%rax,4), %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L10
	call	__stack_chk_fail
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE966:
	.size	_Z7pulapkav, .-_Z7pulapkav
	.section	.rodata
.LC2:
	.string	"%d"
.LC3:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB967:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -8(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	scanf
	movl	$0, -4(%rbp)
	jmp	.L12
.L13:
	call	_Z7pulapkav
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L12:
	movl	-8(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	setl	%al
	testb	%al, %al
	jne	.L13
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE967:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB968:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L14
	cmpl	$65535, -8(%rbp)
	jne	.L14
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$_ZNSt8ios_base4InitD1Ev, %eax
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movq	%rax, %rdi
	call	__cxa_atexit
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE968:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z7pulapkav, @function
_GLOBAL__sub_I__Z7pulapkav:
.LFB969:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE969:
	.size	_GLOBAL__sub_I__Z7pulapkav, .-_GLOBAL__sub_I__Z7pulapkav
	.section	.ctors,"aw",@progbits
	.align 8
	.quad	_GLOBAL__sub_I__Z7pulapkav
	.weakref	_ZL20__gthrw_pthread_oncePiPFvvE,pthread_once
	.weakref	_ZL27__gthrw_pthread_getspecificj,pthread_getspecific
	.weakref	_ZL27__gthrw_pthread_setspecificjPKv,pthread_setspecific
	.weakref	_ZL22__gthrw_pthread_createPmPK14pthread_attr_tPFPvS3_ES3_,pthread_create
	.weakref	_ZL20__gthrw_pthread_joinmPPv,pthread_join
	.weakref	_ZL21__gthrw_pthread_equalmm,pthread_equal
	.weakref	_ZL20__gthrw_pthread_selfv,pthread_self
	.weakref	_ZL22__gthrw_pthread_detachm,pthread_detach
	.weakref	_ZL22__gthrw_pthread_cancelm,pthread_cancel
	.weakref	_ZL19__gthrw_sched_yieldv,sched_yield
	.weakref	_ZL26__gthrw_pthread_mutex_lockP15pthread_mutex_t,pthread_mutex_lock
	.weakref	_ZL29__gthrw_pthread_mutex_trylockP15pthread_mutex_t,pthread_mutex_trylock
	.weakref	_ZL31__gthrw_pthread_mutex_timedlockP15pthread_mutex_tPK8timespec,pthread_mutex_timedlock
	.weakref	_ZL28__gthrw_pthread_mutex_unlockP15pthread_mutex_t,pthread_mutex_unlock
	.weakref	_ZL26__gthrw_pthread_mutex_initP15pthread_mutex_tPK19pthread_mutexattr_t,pthread_mutex_init
	.weakref	_ZL29__gthrw_pthread_mutex_destroyP15pthread_mutex_t,pthread_mutex_destroy
	.weakref	_ZL30__gthrw_pthread_cond_broadcastP14pthread_cond_t,pthread_cond_broadcast
	.weakref	_ZL27__gthrw_pthread_cond_signalP14pthread_cond_t,pthread_cond_signal
	.weakref	_ZL25__gthrw_pthread_cond_waitP14pthread_cond_tP15pthread_mutex_t,pthread_cond_wait
	.weakref	_ZL30__gthrw_pthread_cond_timedwaitP14pthread_cond_tP15pthread_mutex_tPK8timespec,pthread_cond_timedwait
	.weakref	_ZL28__gthrw_pthread_cond_destroyP14pthread_cond_t,pthread_cond_destroy
	.weakref	_ZL26__gthrw_pthread_key_createPjPFvPvE,pthread_key_create
	.weakref	_ZL26__gthrw_pthread_key_deletej,pthread_key_delete
	.weakref	_ZL30__gthrw_pthread_mutexattr_initP19pthread_mutexattr_t,pthread_mutexattr_init
	.weakref	_ZL33__gthrw_pthread_mutexattr_settypeP19pthread_mutexattr_ti,pthread_mutexattr_settype
	.weakref	_ZL33__gthrw_pthread_mutexattr_destroyP19pthread_mutexattr_t,pthread_mutexattr_destroy
	.ident	"GCC: (Ubuntu/Linaro 4.6.1-9ubuntu3) 4.6.1"
	.section	.note.GNU-stack,"",@progbits)
    return 0;
}
