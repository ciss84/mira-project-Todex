#pragma once
#include <Utils/Types.hpp>

extern "C"
{
void* syscall1(
	uint64_t number,
	void* arg1
);

void* syscall2(
	uint64_t number,
	void* arg1,
	void* arg2
);

void* syscall3(
	uint64_t number,
	void* arg1,
	void* arg2,
	void* arg3
);

void* syscall4(
	uint64_t number,
	void* arg1,
	void* arg2,
	void* arg3,
	void* arg4
);

void* syscall5(
	uint64_t number,
	void* arg1,
	void* arg2,
	void* arg3,
	void* arg4,
	void* arg5
);

caddr_t _mmap(caddr_t addr, size_t len, int prot, int flags, int fd, off_t pos);
//caddr_t _mmap(void);
caddr_t _Allocate3MB(void);
caddr_t _Allocate5MB(void);
};


// THIS IS AUTO-GENERATED DO NOT MODIFY UNLESS YOU KNOW WTF YOU ARE DOING
// Created by: OpenOrbis toolchain
#pragma once
#define NOSYS 0
#define LKMRESSYS 169
#define LKMNOSYS 210
#define SYS_EXIT 1
#define SYS_FORK 2
#define SYS_READ 3
#define SYS_WRITE 4
#define SYS_OPEN 5
#define SYS_CLOSE 6
#define SYS_WAIT4 7
#define SYS_LINK 9
#define SYS_UNLINK 10
#define SYS_CHDIR 12
#define SYS_FCHDIR 13
#define SYS_MKNOD 14
#define SYS_CHMOD 15
#define SYS_CHOWN 16
#define SYS_GETPID 20
#define SYS_MOUNT 21
#define SYS_UNMOUNT 22
#define SYS_SETUID 23
#define SYS_GETUID 24
#define SYS_GETEUID 25
#define SYS_PTRACE 26
#define SYS_RECVMSG 27
#define SYS_SENDMSG 28
#define SYS_RECVFROM 29
#define SYS_ACCEPT 30
#define SYS_GETPEERNAME 31
#define SYS_GETSOCKNAME 32
#define SYS_ACCESS 33
#define SYS_CHFLAGS 34
#define SYS_FCHFLAGS 35
#define SYS_SYNC 36
#define SYS_KILL 37
#define SYS_GETPPID 39
#define SYS_DUP 41
#define SYS_PIPE 42
#define SYS_GETEGID 43
#define SYS_PROFIL 44
#define SYS_KTRACE 45
#define SYS_GETGID 47
#define SYS_GETLOGIN 49
#define SYS_SETLOGIN 50
#define SYS_SIGALTSTACK 53
#define SYS_IOCTL 54
#define SYS_REBOOT 55
#define SYS_REVOKE 56
#define SYS_SYMLINK 57
#define SYS_READLINK 58
#define SYS_EXECVE 59
#define SYS_UMASK 60
#define SYS_CHROOT 61
#define SYS_MSYNC 65
#define SYS_VFORK 66
#define SYS_SBRK 69
#define SYS_SSTK 70
#define SYS_MUNMAP 73
#define SYS_MPROTECT 74
#define SYS_MADVISE 75
#define SYS_MINCORE 78
#define SYS_GETGROUPS 79
#define SYS_SETGROUPS 80
#define SYS_GETPGRP 81
#define SYS_SETPGID 82
#define SYS_SETITIMER 83
#define SYS_SWAPON 85
#define SYS_GETITIMER 86
#define SYS_GETDTABLESIZE 89
#define SYS_DUP2 90
#define SYS_FCNTL 92
#define SYS_SELECT 93
#define SYS_FSYNC 95
#define SYS_SETPRIORITY 96
#define SYS_SOCKET 97
#define SYS_CONNECT 98
#define SYS_NETCONTROL 99
#define SYS_GETPRIORITY 100
#define SYS_NETABORT 101
#define SYS_NETGETSOCKINFO 102
#define SYS_BIND 104
#define SYS_SETSOCKOPT 105
#define SYS_LISTEN 106
#define SYS_SOCKETEX 113
#define SYS_SOCKETCLOSE 114
#define SYS_GETTIMEOFDAY 116
#define SYS_GETRUSAGE 117
#define SYS_GETSOCKOPT 118
#define SYS_READV 120
#define SYS_WRITEV 121
#define SYS_SETTIMEOFDAY 122
#define SYS_FCHOWN 123
#define SYS_FCHMOD 124
#define SYS_NETGETIFLIST 125
#define SYS_SETREUID 126
#define SYS_SETREGID 127
#define SYS_RENAME 128
#define SYS_FLOCK 131
#define SYS_MKFIFO 132
#define SYS_SENDTO 133
#define SYS_SHUTDOWN 134
#define SYS_SOCKETPAIR 135
#define SYS_MKDIR 136
#define SYS_RMDIR 137
#define SYS_UTIMES 138
#define SYS_ADJTIME 140
#define SYS_KQUEUEEX 141
#define SYS_SETSID 147
#define SYS_NLM_SYSCALL 154
#define SYS_NFSSVC 155
#define SYS_SYSARCH 165
#define SYS_RTPRIO 166
#define SYS_SETGID 181
#define SYS_SETEGID 182
#define SYS_SETEUID 183
#define SYS_STAT 188
#define SYS_FSTAT 189
#define SYS_LSTAT 190
#define SYS_PATHCONF 191
#define SYS_FPATHCONF 192
#define SYS_GETRLIMIT 194
#define SYS_SETRLIMIT 195
#define SYS_GETDIRENTRIES 196
#define SYS___SYSCTL 202
#define SYS_MLOCK 203
#define SYS_MUNLOCK 204
#define SYS_FUTIMES 206
#define SYS_GETPGID 207
#define SYS_POLL 209
#define SYS_CLOCK_GETTIME 232
#define SYS_CLOCK_SETTIME 233
#define SYS_CLOCK_GETRES 234
#define SYS_KTIMER_CREATE 235
#define SYS_KTIMER_DELETE 236
#define SYS_KTIMER_SETTIME 237
#define SYS_KTIMER_GETTIME 238
#define SYS_KTIMER_GETOVERRUN 239
#define SYS_NANOSLEEP 240
#define SYS_MINHERIT 250
#define SYS_RFORK 251
#define SYS_ISSETUGID 253
#define SYS_LCHOWN 254
#define SYS_AIO_READ 255
#define SYS_AIO_WRITE 256
#define SYS_GETDENTS 272
#define SYS_LCHMOD 274
#define SYS_NETBSD_LCHOWN 275
#define SYS_LUTIMES 276
#define SYS_NETBSD_MSYNC 277
#define SYS_PREADV 289
#define SYS_PWRITEV 290
#define SYS_KLDLOAD 304
#define SYS_KLDUNLOAD 305
#define SYS_KLDFIND 306
#define SYS_KLDNEXT 307
#define SYS_KLDSTAT 308
#define SYS_KLDFIRSTMOD 309
#define SYS_GETSID 310
#define SYS_SETRESUID 311
#define SYS_SETRESGID 312
#define SYS_AIO_RETURN 314
#define SYS_AIO_SUSPEND 315
#define SYS_AIO_CANCEL 316
#define SYS_AIO_ERROR 317
#define SYS_YIELD 321
#define SYS_MLOCKALL 324
#define SYS_MUNLOCKALL 325
#define SYS___GETCWD 326
#define SYS_SCHED_SETPARAM 327
#define SYS_SCHED_GETPARAM 328
#define SYS_SCHED_SETSCHEDULER 329
#define SYS_SCHED_GETSCHEDULER 330
#define SYS_SCHED_YIELD 331
#define SYS_SCHED_GET_PRIORITY_MAX 332
#define SYS_SCHED_GET_PRIORITY_MIN 333
#define SYS_SCHED_RR_GET_INTERVAL 334
#define SYS_UTRACE 335
#define SYS_KLDSYM 337
#define SYS_SIGPROCMASK 340
#define SYS_SIGSUSPEND 341
#define SYS_SIGPENDING 343
#define SYS_SIGTIMEDWAIT 345
#define SYS_SIGWAITINFO 346
#define SYS_AIO_WAITCOMPLETE 359
#define SYS_GETRESUID 360
#define SYS_GETRESGID 361
#define SYS_KQUEUE 362
#define SYS_KEVENT 363
#define SYS___SETUGID 374
#define SYS_NMOUNT 378
#define SYS_MTYPEPROTECT 379
#define SYS___MAC_GET_PROC 384
#define SYS___MAC_SET_PROC 385
#define SYS___MAC_GET_FD 386
#define SYS___MAC_GET_FILE 387
#define SYS___MAC_SET_FD 388
#define SYS___MAC_SET_FILE 389
#define SYS_KENV 390
#define SYS_LCHFLAGS 391
#define SYS_UUIDGEN 392
#define SYS_SENDFILE 393
#define SYS_MAC_SYSCALL 394
#define SYS_GETFSSTAT 395
#define SYS_STATFS 396
#define SYS_FSTATFS 397
#define SYS_KSEM_CLOSE 400
#define SYS_KSEM_POST 401
#define SYS_KSEM_WAIT 402
#define SYS_KSEM_TRYWAIT 403
#define SYS_KSEM_INIT 404
#define SYS_KSEM_OPEN 405
#define SYS_KSEM_UNLINK 406
#define SYS_KSEM_GETVALUE 407
#define SYS_KSEM_DESTROY 408
#define SYS___MAC_GET_PID 409
#define SYS___MAC_GET_LINK 410
#define SYS___MAC_SET_LINK 411
#define SYS___MAC_EXECVE 415
#define SYS_SIGACTION 416
#define SYS_SIGRETURN 417
#define SYS_GETCONTEXT 421
#define SYS_SETCONTEXT 422
#define SYS_SWAPCONTEXT 423
#define SYS_SIGWAIT 429
#define SYS_THR_CREATE 430
#define SYS_THR_EXIT 431
#define SYS_THR_SELF 432
#define SYS_THR_KILL 433
#define SYS__UMTX_LOCK 434
#define SYS__UMTX_UNLOCK 435
#define SYS_KSEM_TIMEDWAIT 441
#define SYS_THR_SUSPEND 442
#define SYS_THR_WAKE 443
#define SYS_KLDUNLOADF 444
#define SYS__UMTX_OP 454
#define SYS_THR_NEW 455
#define SYS_SIGQUEUE 456
#define SYS_THR_SET_NAME 464
#define SYS_AIO_FSYNC 465
#define SYS_RTPRIO_THREAD 466
#define SYS_PREAD 475
#define SYS_PWRITE 476
#define SYS_MMAP 477
#define SYS_LSEEK 478
#define SYS_TRUNCATE 479
#define SYS_FTRUNCATE 480
#define SYS_THR_KILL2 481
#define SYS_SHM_OPEN 482
#define SYS_SHM_UNLINK 483
#define SYS_CPUSET 484
#define SYS_CPUSET_SETID 485
#define SYS_CPUSET_GETID 486
#define SYS_CPUSET_GETAFFINITY 487
#define SYS_CPUSET_SETAFFINITY 488
#define SYS_FCHMODAT 490
#define SYS_FCHOWNAT 491
#define SYS_FSTATAT 493
#define SYS_FUTIMESAT 494
#define SYS_LINKAT 495
#define SYS_MKDIRAT 496
#define SYS_MKFIFOAT 497
#define SYS_MKNODAT 498
#define SYS_OPENAT 499
#define SYS_RENAMEAT 501
#define SYS_SYMLINKAT 502
#define SYS_UNLINKAT 503
#define SYS_CAP_NEW 514
#define SYS_CAP_GETRIGHTS 515
#define SYS_CAP_ENTER 516
#define SYS_CAP_GETMODE 517
#define SYS_PDFORK 518
#define SYS_PDKILL 519
#define SYS_PDGETPID 520
#define SYS_PSELECT 522
#define SYS_RCTL_GET_RACCT 525
#define SYS_RCTL_GET_RULES 526
#define SYS_RCTL_GET_LIMITS 527
#define SYS_RCTL_ADD_RULE 528
#define SYS_RCTL_REMOVE_RULE 529
#define SYS_REGMGR_CALL 532
#define SYS_JITSHM_CREATE 533
#define SYS_JITSHM_ALIAS 534
#define SYS_DL_GET_LIST 535
#define SYS_DL_GET_INFO 536
#define SYS_DL_NOTIFY_EVENT 537
#define SYS_EVF_CREATE 538
#define SYS_EVF_DELETE 539
#define SYS_EVF_OPEN 540
#define SYS_EVF_CLOSE 541
#define SYS_EVF_WAIT 542
#define SYS_EVF_TRYWAIT 543
#define SYS_EVF_SET 544
#define SYS_EVF_CLEAR 545
#define SYS_EVF_CANCEL 546
#define SYS_QUERY_MEMORY_PROTECTION 547
#define SYS_BATCH_MAP 548
#define SYS_OSEM_CREATE 549
#define SYS_OSEM_DELETE 550
#define SYS_OSEM_OPEN 551
#define SYS_OSEM_CLOSE 552
#define SYS_OSEM_WAIT 553
#define SYS_OSEM_TRYWAIT 554
#define SYS_OSEM_POST 555
#define SYS_OSEM_CANCEL 556
#define SYS_NAMEDOBJ_CREATE 557
#define SYS_NAMEDOBJ_DELETE 558
#define SYS_SET_VM_CONTAINER 559
#define SYS_DEBUG_INIT 560
#define SYS_SUSPEND_PROCESS 561
#define SYS_RESUME_PROCESS 562
#define SYS_OPMC_ENABLE 563
#define SYS_OPMC_DISABLE 564
#define SYS_OPMC_SET_CTL 565
#define SYS_OPMC_SET_CTR 566
#define SYS_OPMC_GET_CTR 567
#define SYS_BUDGET_CREATE 568
#define SYS_BUDGET_DELETE 569
#define SYS_BUDGET_GET 570
#define SYS_BUDGET_SET 571
#define SYS_VIRTUAL_QUERY 572
#define SYS_MDBG_CALL 573
#define SYS_SBLOCK_CREATE 574
#define SYS_SBLOCK_DELETE 575
#define SYS_SBLOCK_ENTER 576
#define SYS_SBLOCK_EXIT 577
#define SYS_SBLOCK_XENTER 578
#define SYS_SBLOCK_XEXIT 579
#define SYS_EPORT_CREATE 580
#define SYS_EPORT_DELETE 581
#define SYS_EPORT_TRIGGER 582
#define SYS_EPORT_OPEN 583
#define SYS_EPORT_CLOSE 584
#define SYS_IS_IN_SANDBOX 585
#define SYS_DMEM_CONTAINER 586
#define SYS_GET_AUTHINFO 587
#define SYS_MNAME 588
#define SYS_DYNLIB_DLOPEN 589
#define SYS_DYNLIB_DLCLOSE 590
#define SYS_DYNLIB_DLSYM 591
#define SYS_DYNLIB_GET_LIST 592
#define SYS_DYNLIB_GET_INFO 593
#define SYS_DYNLIB_LOAD_PRX 594
#define SYS_DYNLIB_UNLOAD_PRX 595
#define SYS_DYNLIB_DO_COPY_RELOCATIONS 596
#define SYS_DYNLIB_PREPARE_DLCLOSE 597
#define SYS_DYNLIB_GET_PROC_PARAM 598
#define SYS_DYNLIB_PROCESS_NEEDED_AND_RELOCATE 599
#define SYS_SANDBOX_PATH 600
#define SYS_MDBG_SERVICE 601
#define SYS_RANDOMIZED_PATH 602
#define SYS_RDUP 603
#define SYS_DL_GET_METADATA 604
#define SYS_WORKAROUND8849 605
#define SYS_IS_DEVELOPMENT_MODE 606
#define SYS_GET_SELF_AUTH_INFO 607
#define SYS_DYNLIB_GET_INFO_EX 608
#define SYS_BUDGET_GETID 609
#define SYS_BUDGET_GET_PTYPE 610
#define SYS_GET_PAGING_STATS_OF_ALL_THREADS 611
#define SYS_GET_PROC_TYPE_INFO 612
#define SYS_GET_RESIDENT_COUNTV 613
#define SYS_PREPARE_TO_SUSPEND_PROCESSV 614
#define SYS_GET_RESIDENT_FMEM_COUNT 615
#define SYS_THR_GET_NAME 616
#define SYS_SET_GPO 617
#define SYS_GET_PAGING_STATS_OF_ALL_OBJECTS 618
#define SYS_TEST_DEBUG_RWMEM 619
#define SYS_FREE_STACK 620
#define SYS_SUSPEND_SYSTEM 621
#define SYS_IPMIMGR_CALL 622
#define SYS_GET_GPO 623
#define SYS_GET_VM_MAP_TIMESTAMP 624
#define SYS_OPMC_SET_HW 625
#define SYS_OPMC_GET_HW 626
#define SYS_GET_CPU_USAGE_ALL 627
#define SYS_MMAP_DMEM 628
#define SYS_PHYSHM_OPEN 629
#define SYS_PHYSHM_UNLINK 630
#define SYS_RESUME_INTERNAL_HDD 631
#define SYS_THR_SUSPEND_UCONTEXT 632
#define SYS_THR_RESUME_UCONTEXT 633
#define SYS_THR_GET_UCONTEXT 634
#define SYS_THR_SET_UCONTEXT 635
#define SYS_SET_TIMEZONE_INFO 636
#define SYS_SET_PHYS_FMEM_LIMIT 637
#define SYS_UTC_TO_LOCALTIME 638
#define SYS_LOCALTIME_TO_UTC 639
#define SYS_SET_UEVT 640
#define SYS_GET_CPU_USAGE_PROC 641
#define SYS_GET_MAP_STATISTICS 642
#define SYS_SET_CHICKEN_SWITCHES 643
#define SYS_EXTEND_PAGE_TABLE_POOL 644
#define SYS_GET_KERNEL_MEM_STATISTICS 646
#define SYS_GET_SDK_COMPILED_VERSION 647
#define SYS_APP_STATE_CHANGE 648
#define SYS_DYNLIB_GET_OBJ_MEMBER 649
#define SYS_BUDGET_GET_PTYPE_OF_BUDGET 650
#define SYS_PREPARE_TO_RESUME_PROCESS 651
#define SYS_PROCESS_TERMINATE 652
#define SYS_BLOCKPOOL_OPEN 653
#define SYS_BLOCKPOOL_MAP 654
#define SYS_BLOCKPOOL_UNMAP 655
#define SYS_DYNLIB_GET_INFO_FOR_LIBDBG 656
