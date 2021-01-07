init:
    li $v0 5                #输入被乘数$a0
    syscall
    addu $a0 $v0 $0       
    li $v0 5                #输入乘数$a1
    syscall
    addu $a1 $v0 $0              
    li $s0 0                #$s0存储被乘数左移后的高32位
    li $v0 0                #$v0存储积的低32位
    li $v1 0                #$v1存储积的高32位
    li $t2 0                #$t2记录过程执行次数
mull:
    andi $t1 $a1 1          #判断乘数的最后一位是否为1
    beq  $t1 0   shift      #最后一位不是1 进入移位部分
    addu $v1 $v1 $s0        #积的高32位=积的高32位+被乘数的高32位
    addu $v0 $v0 $a0        #积的低32位=积的低32位+被乘数的低32位
    sltu $t1 $v0 $a0        #判断低32位相加时是否溢出 若溢出则和必定小于乘数
    beq  $t1 $0  shift      #没有溢出 进入移位部分
    addiu $v1 $v1 1         #发生溢出 积的高32位加1
shift:
    srl  $a1 $a1 1          #乘数右移一位
    sll  $s0 $s0 1          #先将被乘数的高32位左移一位
    andi $t1 $a0 0x80000000 #判断被乘数的低32位最高位是否为1
    sll  $a0 $a0 1          #被乘数的低32位左移一位
    beq  $t1 0   ad         #被乘数的低32位最高位不是1 进入自增部分 
    addiu $s0 $s0 1         #被乘数的低32位最高位是1 高32位加1
ad:
    addiu $t2 $t2 1         #执行次数加1
    slti $t1 $t2 32         #判断是否已经执行32次
    beq  $t1 1   mull       #还未执行32次 进入下一次循环
print1:
    move $s0 $v0            #先将积的低32位转移
    move $a0 $v1            #将积的高32位放到$a0
    beq  $a0 0 print2       #如果积的高32位为0 进入低32位输出部分
    li   $v0 36              #打印积的高32位
    syscall
print2:
    move $a0 $s0            #将积的低32位放到$a0
    li   $v0 36              #打印积的低32位
    syscall
exit:
    li   $v0 10             #退出程序
    syscall