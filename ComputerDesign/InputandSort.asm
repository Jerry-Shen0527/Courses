.text 
.globl main
main:
    move $t6 $zero #ʹ��t6����������
    la $t0 value         # װ�أ���t3�Ϸ���value��ֵ,���ǻ�׼��ַ
    lw $t7 end
    
    move $t1 $zero #t1��ѭ������
Loop:
    li $v0 5             # �������������� 5 װ�ص�$v0��
    syscall              # ϵͳ���� 
    
    beq $v0 $t7 Exit     # ���$t1 == $t2 ����˵������10���� ��ô������ѭ��
    add $t2 $t1 $t0      # ����׼��ַ $3 ����ƫ���� $4
    sw $v0 0($t2)        # ��$vo�е����ŵ�t5��Ӧ�ĵ�ַ��
    addi $t1 $t1 4       # ƫ������ֵ���4��λ��
    j Loop               # �����µ�ѭ��

Exit:                    # �������
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

addi $t1 $t1 4 #����
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
           bgez  $t5,   hexify       #$t5>=0 �򷵻ر��hexify����ִ��
           
           li    $v0,   4
           la    $a0,   the_result_is
           syscall


    la $a0 str           # ����ո�
    li $v0 4             
    syscall

    add $t1 $t1 4        # �Լ�����$t1 ��һ
    beq $t1 $t6 Exit1    # ���$t1 == $t2 ����˵������10���� ��ô������ѭ��

    j Loop1              # �����µ�ѭ��   
    
   
Exit1:

    li $v0 10            # �˳� 
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
