      .text
       .globl main

main: 

         la $a0, value1      #$t0 保存初始值的地址
	li $a1 30
       li $v0, 8           #读取整数值（kernel serice 8）
       syscall
       
       
       
                la $a0, value2       #$t0 保存初始值的地址
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
       
      la $t2 value2
       mark2:
       lb $t3 ($t2)
       addi $t2 $t2 1
       bne $t0 $t3 mark2
        subi $t2 $t2 1
             
       
       lb $t0, empty
       la $t7 rst
       add $t7 $t7 1000
       sb $t0 ($t7) 
       subi $t7 $t7 1
       move $t8 $t7
       la $t6 rst
       
       setzero:
       add $t5 $zero 48
       sb $t5 ($t8)
       sub $t8 $t8 1
       bne $t8 $t6 setzero
       
 
       la $s1 value1
       la $s2 value2
       
       move $t4 $t1
       #when it begins, we need s1 and s2 at the begin, t1, t2 at the end.for the result, we need the s7 and t7 at the end at the beginning
       out:
       subi $t2 $t2 1
       lb $s5 ($t2)
       addi $s5 $s5 -48
       
       
       move $s7 $t7
       inner:
       subi $t1 $t1 1
       lb $s6 ($t1)
       addi $s6 $s6 -48
       mul $s4 $s5 $s6
       lb $s3 ($s7)
       addi $s3 $s3 -48
       add $s3 $s4 $s3
       move $s4 $zero
       blt $s3  10 nocarry
       carry:
       addi $s4 $s4 1
       subi $s3 $s3 10
       bge $s3 10 carry
       nocarry:
       
       addi $s3 $s3 48
       sb $s3 ($s7)
       subi $s7 $s7 1
       lb $s3 ($s7)
       addi $s3 $s3 -48
       add $s3 $s4 $s3 
       addi $s3 $s3 48
       sb $s3 ($s7)
       
       bne $t1 $s1 inner
       move $t1 $t4    
       subi $t7 $t7 1       
       bne $s2 $t2 out


       lb $t1 0($a0)
       lb $t2 1($a0)
       
       addi $t1,$t1,-48 
       addi $t2,$t2,-48 
       
       add $t3 $t1 $t2
       
       lb $t0 ($s7)
       bne $t0,48 noadding1
       addi $s7 $s7 1
       noadding1:
       move $a0 $s7
       li $v0 4
       syscall
       
       


######   data segment####################################

       .data
value1: .space 1024
value2: .space 1024
rst:.space 1024
empty: .byte '\n'
msg1:  .asciiz "result= "