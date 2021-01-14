.data
    prompt1: .asciiz "Enter the number\n"
    prompt2: .asciiz "The factorial of n is:\n"

.text
    # Print prompt1
    li $v0, 4
    la $a0, prompt1
    syscall
    
    
    
    
    # Read integer
         la $a0, value1      #$a0 保存初始值的地址
	li $a1 30
       li $v0, 8           #读取整数值（kernel serice 8）
       syscall
       
       la $s2 value2
       addi $s4 $zero 49
       sb $s4 ($s2)
       addi  $t2 $s2 1
       
       lb $t0 empty
       la $t1 value1
       mark1:
       lb $t3 ($t1)
       addi $t1 $t1 1
       bne $t0 $t3 mark1
       subi $t1 $t1 1
       
       move $s1 $a0
     

       la $s7,rst
       add $t7 $s7 200
       
 loop:
 
 move $t3 $t7
 subi $s3 $t3 200
       
      j setzero
      returnfromsetzero:
      
      move $t4 $t1
       j multiply
       multiplyreturn:
       
      j copy
      returnfromcopy:
       
       move $t4 $t1
       j sub1
       returnfromsub1:
       
       bne $s1 $t1 loop



         la $s3,rst
       add $s3 $s3 200
       lb $s4 empty
       sb $s4 ($s3)
       
       move $a0 $s7
       li $v0 4
       syscall
       
      	
    li $v0, 10
    syscall
  
setzero:
       add $t5 $zero 48
       sb $t5 ($t3)
       sub $t3 $t3 1
       bne $s3 $t3 setzero
       j returnfromsetzero
       
copy:
la $s2 value2
move $t2 $s2
move $t4 $s7
loopincopy:
lb $t5 ($t4)
sb $t5 ($t2)
addi $t2 $t2 1
addi $t4 $t4 1
bne $t4 $t7 loopincopy
lb $t5 empty 
j returnfromcopy
  
multiply:

       sub $t6 $t7 1
       out:
       subi $t2 $t2 1
       lb $s5 ($t2)
       addi $s5 $s5 -48
       move $s7 $t6
       inner:
       subi $t4 $t4 1
       lb $s6 ($t4)
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
       
       bne $t4 $s1 inner
       move $t4 $t1    
       subi $t6 $t6 1       
       bne $s2 $t2 out
       
       lb $t0 ($s7)
       bne $t0,48 noadding
       addi $s7 $s7 1
       noadding:
       
       j multiplyreturn
       
       
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
       
       lb $t0 ($s1)
       bne $t0,48 noadding1
       addi $s1 $s1 1
       noadding1:
     j  returnfromsub1


######   data segment####################################

       .data
value1: .space 1024
value2: .space 1024
rst:.space 1024
empty: .byte '\n'
msg1:  .asciiz "result= "
