.data              #数据段保存输出字符串，注意加\0
  msg_yes: .ascii "YES\0" 
  msg_no:  .ascii "NO\0"  
  num: .word 2


.text               #程序段相当于main入口
  li $v0,5          #scanf("%d",&a);  t0保存a的值
  syscall 
  move $t0,$v0  

  lw $t1,num

  bgt $t0,$t1,s1    #a>b就跳转到标签s1，记录了地址
  la $a0,msg_no     #printf("NO");
  li $v0,4
  syscall 

  j stop            #直接跳转到结束语句stop

s1:
  la $a0,msg_yes     #printf("YES");
  li $v0,4
  syscall 

  stop:             #结束程序语句，类似return 0;
  li $v0 10
  syscall 