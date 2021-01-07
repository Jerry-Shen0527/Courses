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
       
sub1:
       subi $t1 $t1 1
       lb $t5 ($t1)
       
        ble $t5 48 jiewei
        
        subi $t5 $t5 1
        sb $t5 ($t1)
        j finish
       
       jiewei:
       add $t5 $zero 57
       sb $t5 ($t1)
       
       j sub1
       finish:
       
       move $t1 $s1
       lb $t0 ($t1)
       bne $t0,48 noadding1
       addi $t1 $t1 1
       move $s1 $t1
       returnfromsub1:
       move $a0 $t1
       
       li $v0 4
       syscall
       
              .data
value1: .space 1024
empty: .byte '\n'