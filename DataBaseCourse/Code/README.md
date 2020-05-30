​	

# 教师-学生数据库

### 载入结果

#### Student

```mysql
create table Student
(
    NO       char(15) not null,
    NAME     char(5) null,
    SEX      char(6)  null,
    BIRTHDAY char(20) null,
    DEPART   int      null,
    constraint Student_pk
        primary key (NO)
);
```

![image-20200516173121213](README.assets/image-20200516173121213.png)

#### Teacher

```mysql
create table Teacher
(
    NO       char(10) not null,
    NAME     char(5) null,
    SEX      char(6)  null,
    BIRTHDAY char(25) null,
    PROF     char(30) null,
    DEPART   int      null,
    constraint Teacher_pk
        primary key (NO)
);
```

![image-20200516173136139](README.assets/image-20200516173136139.png)

#### Course

```mysql
create table Course
(
    CNO   int      null,
    CNAME varchar(40) null,
    TNO   char(10) null
);


create unique index Course_CNO_uindex
    on Course (CNO);

alter table Course
    add constraint Course_pk
        primary key (CNO);
        
alter table course
    add constraint course_fk
        foreign key (TNO) references Teacher (NO);
```



![image-20200516173155742](README.assets/image-20200516173155742.png)

#### Score

```mysql
create table Score
(
    NO     char(15) null,
    CNO    int null,
    DEGREE int null,
    constraint Score_pk
        unique (NO, CNO),
    constraint Score_course_CNO_fk
        foreign key (CNO) references course (CNO),
    constraint Score_student_NO_fk
        foreign key (NO) references student (NO)
);
```

![image-20200516173211663](README.assets/image-20200516173211663.png)



### 习题

#### 1

```mysql
alter table student add column CLASS char(20) default 1;
```

![image-20200516173807994](README.assets/image-20200516173807994.png)



#### 2

```mysql
alter table Student modify column class INT;
```

![image-20200516175057100](README.assets/image-20200516175057100.png)

#### 3

```mysql
update student set class=DEPART-10;
```
![image-20200516180032281](README.assets/image-20200516180032281.png)

#### 4

```mysql
alter table student modify column SEX enum('male','female');
```
![image-20200516182707955](README.assets/image-20200516182707955.png)

#### 5

```mysql
create table course_ave
(
	CNO int not null,
	TNO char(10) not null,
	AVE double null,
	constraint course_ave_pk
		unique (CNO, TNO),
	constraint course_ave_course_CNO_fk
		foreign key (CNO) references course (CNO),
	constraint course_ave_teacher_NO_fk
		foreign key (TNO) references teacher (NO)
);
select * from  course_ave;
```
![image-20200516185939017](README.assets/image-20200516185939017.png)

#### 6

```mysql
alter table course_ave add constraint primary key(CNO);
```
#### 7

```mysql
alter table course_ave modify TNO char(10) not null ;
```
#### 8

```mysql
insert into course_ave
select Course.CNO,Teacher.NO,AVG(DEGREE)
from Teacher,
     course left outer join score on Course.CNO = Score.CNO
where Teacher.no = Course.TNO group by CNO;
```

![image-20200516191927614](README.assets/image-20200516191927614.png)

#### 9

```mysql
delete from course_ave where AVE is null ;
```
![image-20200516192022838](README.assets/image-20200516192022838.png)

#### 10

```mysql
alter table course_ave drop constraint course_ave_course_CNO_fk;
alter table course_ave drop constraint course_ave_teacher_NO_fk;
insert into course_ave values('20201100','TA80000',80);
```

![image-20200516192527798](README.assets/image-20200516192527798.png)

#### 11

```mysql
update course_ave set AVE=75 where CNO='20201100';
```

![image-20200516192626228](README.assets/image-20200516192626228.png)

#### 12

```mysql
create index  CNAME_INDEX on COURSE(CNAME);
```
![image-20200516194225831](README.assets/image-20200516194225831.png)

#### 13

```mysql
create unique index  NO_index on Student(NO);
```
![image-20200516194151550](README.assets/image-20200516194151550.png)

#### 14

```mysql
create index NODE_index on score(NO asc ,DEGREE desc );
```
![image-20200516194845591](README.assets/image-20200516194845591.png)

#### 15

```mysql
show indexes from course;
```
![image-20200516195006635](README.assets/image-20200516195006635.png)

#### 16

```mysql
drop index CNAME_INDEX on course;
```
![image-20200516195104717](README.assets/image-20200516195104717.png)

#### 17

```mysql
select count(*)
from student,
     course,
     teacher,
     score
where Student.NO = Score.NO
  and Score.CNO = Course.CNO
  and Course.TNO = Teacher.no
  and Teacher.DEPART = 18;
```
![image-20200516195416957](README.assets/image-20200516195416957.png)

#### 18

```mysql
select NO, NAME
from Student
where DEPART = (select DEPART from student where NAME = 'XY');
```
![image-20200516200038810](README.assets/image-20200516200038810.png)

#### 19

```mysql
select * from student order by DEPART desc,NO asc;
```
![image-20200516200611461](README.assets/image-20200516200611461.png)

#### 20

```mysql
select Student.NO, NAME, DEGREE
from Student,
     score
where Student.NO = Score.NO
  and DEGREE >= 80;
```
![image-20200516200810173](README.assets/image-20200516200810173.png)

#### 21

```mysql
select Student.NO, Student.Name
from Student,
     Teacher,
     score,
     course
where Student.no = Score.no
  and Score.cno = Course.CNO
  and Course.TNO = Teacher.NO
  and Teacher.NAME = 'LJL';
```

![image-20200516201518505](README.assets/image-20200516201518505.png)

#### 22

```mysql
select Student.no, DEGREE
from student,
     score,
     course
where Student.No = Score.NO
  and Score.Cno = Course.CNO
  and Course.CNAME = 'Database'
order by DEGREE desc;
```

![image-20200516201848687](README.assets/image-20200516201848687.png)

#### 23

```mysql
select Course.cno, CNAME, avg(DEGREE)
from course,
     score
where Score.cno = Course.cno
group by cno;
```

![image-20200516202108247](README.assets/image-20200516202108247.png)

#### 24

```mysql
select NO, NAME
from student
where 80 > any (select degree from score where Student.no = Score.NO);
```

![image-20200516202621707](README.assets/image-20200516202621707.png)

#### 25

```mysql
select s1.NO, Name, AVG(DEGREE)
from Student s1,
     score sc1
where 3 <= (select count(*)
            from  score
            where s1.NO = Score.NO) group by NO;
```

![image-20200518144103310](README.assets/image-20200518144103310.png)

#### 26

```mysql
select CNAME, count(*)
from course,
     score
where Course.CNO = Score.CNO
group by CNAME;
```

![image-20200518144305370](README.assets/image-20200518144305370.png)

#### 27

```mysql
select NAME
from student
where not exists(select *
                 from score,
                      course
                 where Course.CNAME = 'Operating_System'
                   and Score.CNO=Course.CNO
                   and Student.no = Score.NO)
```

![image-20200518144806457](README.assets/image-20200518144806457.png)

#### 28

```mysql
select NAME, 2020 - BIRTHDAY
from student
where (2020 - Student.BIRTHDAY) <= 24;
```

![image-20200518145411931](README.assets/image-20200518145411931.png)

#### 29

```mysql
select *
from student
where Student.NAME like '%Y';
```

![image-20200518145521311](README.assets/image-20200518145521311.png)

#### 30

```mysql
select Student.NO, NAME, DEGREE
from score sc1,
     student
where sc1.NO = Student.NO
  and DEGREE <
      (select AVG(DEGREE)
       from score sc2
       where sc2.CNO = sc1.CNO);
```

![image-20200518150156869](README.assets/image-20200518150156869.png)

#### 31

```mysql
create view db_student_score as
select Score.CNO, Score.NO, Score.DEGREE
from score,
     course
where Score.Cno = Course.CNO
  and Course.CNAME = 'Database'
with check option;

select * from db_student_score;
```

![image-20200518150758646](README.assets/image-20200518150758646.png)

#### 32

```mysql
drop view db_student_score;
```

#### 33.1

```mysql
create table Gender
(
	SEX char(6) not null,
	s_count int null,
	constraint Gender_pk
		primary key (SEX)
);
```



#### 33.2

```mysql
insert into gender
select SEX,count(*) from student group by SEX;
```

![image-20200518151918819](README.assets/image-20200518151918819.png)

#### 33.3

```mysql
create trigger add_one
    after insert
    on student
    for each row
BEGIN
    update gender set s_count=s_count + 1 where SEX = new.SEX;
end;

create trigger del_one
    before delete
    on student
    for each row
BEGIN
    update gender set s_count=s_count - 1 where Gender.SEX = old.SEX;
end;
```



#### 33.4

![image-20200518151918819](README.assets/image-20200518151918819.png)

```mysql
insert into student(NO,SEX) value ('17081531','male');
```



![image-20200518153417911](README.assets/image-20200518153417911.png)

```sql
insert into student(NO,SEX) value ('17081532','female');
```

![image-20200518153441823](README.assets/image-20200518153441823.png)

```sql
delete from student where NO='17081532';
```

![image-20200518153510248](README.assets/image-20200518153510248.png)