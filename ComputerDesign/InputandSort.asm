.text 
.globl main
main:
    move $t6 $zero #使用t6来保存总量
    la $t0 value         # 装载，将t3上放有value的值,就是基准地址
    lw $t7 end
    
    move $t1 $zero #t1做循环变量
Loop:
    li $v0 5             # 调用了输入命令 5 装载到$v0上
    syscall              # 系统调用 
    
    beq $v0 $t7 Exit     # 如果$t1 == $t2 就是说输入了10个数 那么就跳出循环
    add $t2 $t1 $t0      # 将基准地址 $3 加上偏移量 $4
    sw $v0 0($t2)        # 将$vo中的数放到t5对应的地址中
    addi $t1 $t1 4       # 偏移量数值提高4个位置
    j Loop               # 跳到新的循环

Exit:                    # 输入完成
add $t6 $t1 $t0
move $t1 $t0



Sort:
li $v0 30
syscall 
move $s7 $a0
Outer:
beq $t1 $t6 PRINT
move $t5 $t1 #maxidx=i
addi $t3 $t1 4 #t3 is i+1 and t3 represents j

lw $t2 0($t1) #t2 is the max now

Inner:
beq $t3 $t6 InnerEnd
lw $t4 0($t3) #get arr[j]
blt $t4 $t2 Ifnot
move $t2 $t4
move $t5 $t3
Ifnot:
add $t3 $t3 4 #j++
j Inner

InnerEnd:
lw $t3 0($t5) #$t3 is temp
lw $t4 0($t1)
sw $t3 0($t1)
sw $t4 0($t5)

addi $t1 $t1 4 #计数
j Outer

#ocupied: t0 t1 t7 t6
PRINT:
li $v0 4
la $a0 time
syscall 

li $v0 30
syscall 
sub $a0 $a0 $s7
li $v0 1 
syscall
li $v0 4
la $a0 nextline
syscall 
 
add $t1 $t0 $zero      
Loop1:
     lw $t7 0($t1)   
      li    $t5   7  
     move $t2 $zero
     move $t3 $zero 
    hexify:    and   $t2,   $t7,   0x0f
           srl    $t7,   $t7,   4
           lb     $t3,   hex_table($t2)
           sb    $t3,   hex_digits($t5)
           sub   $t5,   $t5,   1
           bgez  $t5,   hexify       #$t5>=0 则返回标号hexify继续执行
           
           li    $v0,   4
           la    $a0,   the_result_is
           syscall


    la $a0 str           # 输出空格
    li $v0 4             
    syscall

    add $t1 $t1 4        # 对计数的$t1 加一
    beq $t1 $t6 Exit1    # 如果$t1 == $t2 就是说输入了10个数 那么就跳出循环

    j Loop1              # 跳到新的循环   
    
   
Exit1:

    li $v0 10            # 退出 
    syscall
.data 
    str:
        .asciiz " "
    value:
        .word 0,0,0,0,0,0,0,0,0,0,0
 
    min:
    	.word -128
    end:
    	.word 128
    	
    	hex_table: .ascii   "0123456789ABCDEF"
    	the_result_is: .ascii    "0x"
hex_digits: .asciiz  "XXXXXXXX" 
time: .asciiz "Time:"
nextline:.asciiz"\n"
