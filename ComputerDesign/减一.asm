 .text
       .globl main

main: 

         la $a0, value1      #$t0 保存初始值的地址
	li $a1 30
       li $v0, 8           #读取整数值（kernel serice 8）
       syscall
       
       lb $t0, empty
       
       la $t1 value1
       mark1:
       lb $t3 ($t1)
       addi $t1 $t1 1
       bne $t0 $t3 mark1
       subi $t1 $t1 1
       
       la $s1 value1
       
       move $t4 $t1
sub1:
       subi $t4 $t4 1
       lb $t5 ($t4)
       
        ble $t5 48 jiewei
        
        subi $t5 $t5 1
        sb $t5 ($t4)
        j finish
       
       jiewei:
       add $t5 $zero 57
       sb $t5 ($t4)
       
       j sub1
       finish:
       
       lb $t0 ($t4)
       bne $t0,48 noadding1
       addi $s1 $s1 1
       noadding1:
       move $a0 $s1
       
       li $v0 4
       syscall
       
              .data
value1: .space 1024
empty: .byte '\n'
